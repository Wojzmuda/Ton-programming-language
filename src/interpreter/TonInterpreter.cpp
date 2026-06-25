#define _USE_MATH_DEFINES
#include "interpreter/TonInterpreter.h"
#include <cmath>
#include <filesystem>
#define TSF_IMPLEMENTATION
#include "core/tsf.h"
#include <iomanip> 

const std::unordered_map<std::string, int> TonInterpreter::SAMPLE_INSTRUMENTS = {
    {"piano",      0}, // YAMAHA GRAND PIANO
    {"organ",      19}, // CHURCH ORGAN
    {"rock_organ", 18}, // ROCK ORGAN
    {"guitar",     24}, // NYLON STRING GUITAR
    {"overdrive",  29}, // OVERDRIVE GUITAR
    {"bass",       33}, // Fingered Bass
    {"violin",     40}, // Violin
    {"cello",      42}, // Cello
    {"contrabass", 43}, // Contrabass
    {"strings",    48}, // Strings
    {"trumpet",    56}, // Trumpet
    {"flute",      73}, // Flute
    {"drums",      116} // Taiko Drum
};

const std::unordered_set<std::string> TonInterpreter::SYNTHS = {
    "sine",
    "saw",
    "square"
};

std::shared_ptr<Scope<std::any>> TonInterpreter::resolveScope(TonParser::TargetContext *ctx) {
int elderCount = ctx->elderRef().size();
    auto targetScope = currentScope;

    if (elderCount == 0) {
        return targetScope;
    }

    std::string baseName = ctx->ID(0)->getText();
    int skippedDefinitions = 0;

    while (targetScope != nullptr) {

        if (targetScope->values.find(baseName) != targetScope->values.end()) {
   
            if (skippedDefinitions == elderCount) {
                return targetScope;
            }
 
            skippedDefinitions++;
        }
        
        targetScope = targetScope->parent;
    }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Error in line " + std::to_string(line) + 
                             ": 'ELDER::' failed. Variable '" + baseName + 
                             "' is not shadowed " + std::to_string(elderCount) + " time(s).");
}


bool TonInterpreter::coerceType(const std::string &expectedTypeName, std::any &value)
{
    if (expectedTypeName == "INT" && value.type() == typeid(int)) return true;
    if (expectedTypeName == "NUMERICAL" && value.type() == typeid(double)) return true;
    if (expectedTypeName == "BOOL" && value.type() == typeid(bool)) return true;
    if (expectedTypeName == "CHAR" && value.type() == typeid(char)) return true;
    if (expectedTypeName == "STRING" && value.type() == typeid(std::string)) return true;
    if (expectedTypeName == "ARRAY" && value.type() == typeid(std::vector<std::any>)) return true;
    if (expectedTypeName == "NOTE" && value.type() == typeid(Note)) return true;
    if (expectedTypeName == "SOUND" && value.type() == typeid(Sound)) return true;
    if (expectedTypeName == "INSTRUMENT" && value.type() == typeid(Instrument)) return true;
    if (expectedTypeName == "TIMELINE" && value.type() == typeid(Timeline)) return true;
    if (expectedTypeName == "TRACK" && value.type() == typeid(Track)) return true;
    // edge case: empty strings or arrays that may come as empty `any` object.
    if (!value.has_value() && expectedTypeName != "VOID") return false;

    // implicit conversions:
    if (expectedTypeName == "INT") {
        if (value.type() == typeid(double)) {
            value = static_cast<int>(std::any_cast<double>(value));
            return true;
        }
        if (value.type() == typeid(bool)) {
            value = std::any_cast<bool>(value) ? 1 : 0;
            return true;
        }
        if (value.type() == typeid(float)) {
            value = static_cast<int>(std::any_cast<float>(value));
            return true;
        }
    }
    else if (expectedTypeName == "NUMERICAL") {
        if (value.type() == typeid(int)) {
            value = static_cast<double>(std::any_cast<int>(value));
            return true;
        }
        if (value.type() == typeid(bool)) {
            value = std::any_cast<bool>(value) ? 1.0 : 0.0;
            return true;
        }
        if (value.type() == typeid(float)) {
            value = static_cast<double>(std::any_cast<float>(value));
            return true;
        }
    }
    else if (expectedTypeName == "BOOL") {
        if (value.type() == typeid(int)) {
            value = (std::any_cast<int>(value) != 0); return true;
        }
        if (value.type() == typeid(double)) {
            value = (std::any_cast<double>(value) != 0.0); return true;
        }
        if (value.type() == typeid(float)) {
            value = (std::any_cast<float>(value) != 0.0f); return true;
        }
    }
    return false;
}

std::string TonInterpreter::findSoundFontPath() {
    std::string fileName = "FluidR3_GM.sf2";

    // 1. Env Path - optional
    if (const char* envPath = std::getenv("TON_SOUNDFONT_PATH")) {
        std::filesystem::path p(envPath);
        if (std::filesystem::exists(p)) {
            return p.string();
        }
    }

    // possible directories
    // for debug purposes when running Ton from ./{PROJECT_ROOT} or ./{PROJECT_ROOT}/build
    std::vector<std::filesystem::path> possiblePaths = {
        std::filesystem::path("data") / fileName,              // Terminal w głównym folderze
        std::filesystem::path("..") / "data" / fileName,       // Terminal w folderze build/
        std::filesystem::path("..") / ".." / "data" / fileName // Typowe dla IDE na Windowsie
    };

    // Fetching home directory
    const char* homeDir = std::getenv("HOME"); // Linux / macOS
    if (!homeDir) {
        homeDir = std::getenv("USERPROFILE");  // Windows
    }

    if (homeDir) {
        std::filesystem::path home(homeDir);
        // Looking for file named FluidR3_GM.sf2 in $HOME/.ton/ directory
        possiblePaths.push_back(home / ".ton" / fileName);
    }

    // One by one verification in created possible paths.
    // searching order is: EnvPath ; debug directories ; $HOME/.ton
    for (const auto& path : possiblePaths) {
        if (std::filesystem::exists(path)) {
            return path.string();
        }
    }

    // Returning data/fileName if the file was not found.
    return (std::filesystem::path("data") / fileName).string();
}

TonInterpreter::TonInterpreter() : currentStackDepth{0} {
    currentScope = std::make_shared<Scope<std::any>>();

    std::string sfPath = findSoundFontPath();
    soundFont = tsf_load_filename(sfPath.c_str());
    if (!this->soundFont) {
        std::cerr << "Could not load SoundFont from data/FluidR3_GM.sf2!" << std::endl;
    } else {
        tsf_set_output(soundFont, TSF_MONO, Sound::sampleRate, 0);
    }

    for (const std::string& synthName : SYNTHS) {
        loadedInstruments.emplace(synthName, Instrument(synthName));
    }
}

TonInterpreter::~TonInterpreter() {
    if (this->soundFont != nullptr) {
        tsf_close(this->soundFont);
    }
}

void TonInterpreter::printValue(const std::any& value) {
    if (value.type() == typeid(std::string)) {
        std::cout << std::any_cast<std::string>(value);
    }
    else if (value.type() == typeid(int)) {
        std::cout << std::any_cast<int>(value);
    }
    else if (value.type() == typeid(double)) {
        std::cout << std::any_cast<double>(value);
    }
    else if (value.type() == typeid(char)) {
        std::cout << "'" << std::any_cast<char>(value) << "'";
    }
    else if (value.type() == typeid(bool)) {
        std::cout << (std::any_cast<bool>(value) ? "TRUE" : "FALSE");
    }
    else if (value.type() == typeid(Note)) {
        Note currentNote = std::any_cast<Note>(value);
        std::cout << "NOTE(" << currentNote.pitchClass << currentNote.octave << ")";
    }
    else if (value.type() == typeid(Instrument)) {
        Instrument currentInstrument = std::any_cast<Instrument>(value);
        std::cout << "INSTRUMENT(" << currentInstrument.getName() << ")";
    }
    else if (value.type() == typeid(std::vector<std::any>)) {
        auto arrayElements = std::any_cast<std::vector<std::any>>(value);
        std::cout << "[ ";
        for (size_t j = 0; j < arrayElements.size(); j++) {
            printValue(arrayElements[j]);

            if (j < arrayElements.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]";
    }
    else if (!value.has_value()) {
        std::cout << "[VOID / EMPTY]";
    }
    else {
        // Obiekty SOUND itp. (i tak nie da się ich sensownie wydrukować w tekście)
        std::cout << "[Complex Object]";
    }
}

std::any TonInterpreter::visitExprStat(TonParser::ExprStatContext *ctx) {
    return visit(ctx->expr());
}

std::any TonInterpreter::visitProgram(TonParser::ProgramContext *ctx) {
    for (auto stmt : ctx->statement()) {
        if (auto funcDefCtx = stmt->funcDef()) {
            std::string funcName = funcDefCtx->ID(0)->getText();
            currentScope->define(funcName, "FUNCTION", funcDefCtx);
        }
    }


    return visitChildren(ctx);
}

std::any TonInterpreter::visitBlock(TonParser::BlockContext *ctx) {
    bool isFuncBody = (dynamic_cast<TonParser::FuncDefContext*>(ctx->parent) != nullptr);
    bool isLoopBody = (dynamic_cast<TonParser::LoopStatContext*>(ctx->parent) != nullptr);
    bool skipScope = isFuncBody || isLoopBody;

    auto previousScope = currentScope;

    if (!skipScope) {
        currentScope = std::make_shared<Scope<std::any>>(previousScope);
    }

    std::any result;
    try {
        result = visitChildren(ctx);
    } catch (...) {
        if (!skipScope) {
            currentScope = previousScope;
        }
        throw;
    }

    if (!skipScope) {
        currentScope = previousScope;
    }
    return result;
}

std::any TonInterpreter::visitStatement(TonParser::StatementContext *ctx) {
    return visitChildren(ctx);
}

std::any TonInterpreter::visitVarDecl(TonParser::VarDeclContext *ctx) {
    std::string varName = ctx->ID()->getText();
    std::string typeName = ctx->type()->getText(); 

    std::any value;
    bool hasValue = false;

    if (ctx->expr()) {
        value = visit(ctx->expr());

        hasValue = true;

        if (!coerceType(typeName, value)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                ": Cannot assign this value to a variable of type " +
                typeName + ".");
        }
    } else {
        if (typeName == "TIMELINE") {
            Timeline tl; 
            tl.name = varName; 
            value = tl;
            hasValue = true;
        }
        else if (typeName == "SOUND") value = Sound();
        else if (typeName == "TRACK") value = Track(); 
        else if (typeName == "ARRAY") value = std::vector<std::any>{};
        else if (typeName == "BOOL") value = false;   
        else if (typeName == "INT") value = 0;
        else if (typeName == "NUMERICAL") value = 0.0;
        else if (typeName == "NOTE") value = Note();
        else if (typeName == "STRING") value = std::string("");
        else if (typeName == "CHAR") value = '\0'; 
        else value = {};
    }
    currentScope->define(varName, typeName, value, hasValue);
    return {};
}

std::any TonInterpreter::visitTargetExpr(TonParser::TargetExprContext *ctx) {
    auto targetNode = ctx->target(); 
    std::string baseName = targetNode->ID(0)->getText();

    auto targetScope = resolveScope(targetNode);

    if (!targetScope->exists(baseName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Error in line " + std::to_string(line) + ": Undefined variable or timeline '" + baseName + "'.");
    }

    if (targetNode->ID().size() == 1) {
         try {
            return targetScope->get(baseName);
        } catch (const std::runtime_error& e) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": " + e.what());
    }
    }

    std::string trackName = targetNode->ID(1)->getText();
    
    std::any baseObj = targetScope->get(baseName);
    if (baseObj.type() != typeid(Timeline)) {
        throw std::runtime_error("Error: '" + baseName + "' is not a TIMELINE, cannot access tracks.");
    }

    Timeline timeline = std::any_cast<Timeline&>(baseObj);

    if (timeline.tracks.find(trackName) == timeline.tracks.end()) {
        throw std::runtime_error("Error: Track '" + trackName + "' does not exist in timeline '" + baseName + "'.");
    }

    if (targetNode->STRING_VAL()) {
        std::string rawAlias = targetNode->STRING_VAL()->getText();
        std::string aliasName = rawAlias.substr(1, rawAlias.length() - 2); 

        for (const auto& event : timeline.tracks[trackName].events) {
            if (event.alias == aliasName) {
                return event;
            }
        }
        
        throw std::runtime_error("Error: Event alias '" + aliasName + "' does not exist in track '" + trackName + "'.");
    }

    return timeline.tracks[trackName];
}




std::any TonInterpreter::visitHeader(TonParser::HeaderContext *ctx) {
    std::string instrName = ctx->ID()->getText();

    if (!soundFont) {
        throw std::runtime_error("SoundFont library is not initialized!");
    }

    auto it = SAMPLE_INSTRUMENTS.find(instrName);

    if (it != SAMPLE_INSTRUMENTS.end()) {
        loadedInstruments.emplace(instrName, Instrument(instrName, it->second));
    }
    else {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Unknown standard instrument '" + instrName + "'.");
    }

    return {};
}





std::any TonInterpreter::visitAssignment(TonParser::AssignmentContext *ctx) {
    auto targetNode = ctx->target();

    auto targetScope = resolveScope(targetNode);

    if (targetNode->ID().size() == 1) {
        std::string varName = targetNode->ID(0)->getText();
        if (!targetScope->exists(varName)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Variable '" + varName + "' must be declared first.");
        }
        std::any rightSide = visit(ctx->expr());
        std::string declaredType = currentScope->resolveType(varName);
        if (!coerceType(declaredType, rightSide)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Cannot assign this value to a variable of type " +
                                     declaredType + ".");
        }
        
        targetScope->set(varName, rightSide); 
        return {};
    }

    std::string timelineName = targetNode->ID(0)->getText();
    std::string trackName = targetNode->ID(1)->getText();

    if (!targetScope->exists(timelineName)) throw std::runtime_error("Timeline not found");
    
    std::any& baseObj = targetScope->get(timelineName);
    Timeline& timeline = std::any_cast<Timeline&>(baseObj);

    if (timeline.tracks.find(trackName) == timeline.tracks.end()) throw std::runtime_error("Track not found");

    std::any rightSide = visit(ctx->expr());

    if (targetNode->STRING_VAL()) {
        std::string rawAlias = targetNode->STRING_VAL()->getText();
        std::string aliasName = rawAlias.substr(1, rawAlias.length() - 2);

        bool found = false;
        for (auto& event : timeline.tracks[trackName].events) {
            if (event.alias == aliasName) {
                found = true;
                if (rightSide.type() == typeid(Sound)) {
                    event.sound = std::any_cast<Sound>(rightSide);
                }
                else if (rightSide.type() == typeid(TrackEvent)) {
                    TrackEvent newEv = std::any_cast<TrackEvent>(rightSide);
                    event.sound = newEv.sound;
                    event.startTimeMs = newEv.startTimeMs;
                }
                else {
                    throw std::runtime_error("Error: Can only assign a SOUND or TrackEvent to a specific alias.");
                }
                break;
            }
        }
        if (!found) throw std::runtime_error("Error: Event alias '" + aliasName + "' not found.");
        return {};
    }

    std::vector<TrackEvent> newEventsBuffer;

    if (rightSide.type() == typeid(std::vector<std::any>)) {
        auto elements = std::any_cast<std::vector<std::any>>(rightSide);
        for (auto& el : elements) {
            if (el.type() == typeid(TrackEvent)) {
                newEventsBuffer.push_back(std::any_cast<TrackEvent>(el));
            } else {
                throw std::runtime_error("Error: Array contains non-event items.");
            }
        }
    } else if (rightSide.type() == typeid(TrackEvent)) {
        newEventsBuffer.push_back(std::any_cast<TrackEvent>(rightSide));
    } else {
        throw std::runtime_error("Error: Right side of assignment must be an event or array of events.");
    }

    timeline.tracks[trackName].events = newEventsBuffer;

    return {};
}

std::any TonInterpreter::visitCharValExpr(TonParser::CharValExprContext *ctx){
    std::string rawChar = ctx->CHAR_VAL()->getText();
    return rawChar[1];
}

std::any TonInterpreter::visitArrayExpr(TonParser::ArrayExprContext *ctx) {
    std::vector<std::any> elements;
    for (auto exprCtx : ctx->expr()) {
        elements.push_back(visit(exprCtx));
    }
    return elements;
}


std::any TonInterpreter::visitTrackEventExpr(TonParser::TrackEventExprContext *ctx) {
    TrackEvent event;


    std::any soundAny = visit(ctx->expr(0));
    if (soundAny.type() != typeid(Sound)) throw std::runtime_error("Error: Track event requires a SOUND.");
    event.sound = std::any_cast<Sound>(soundAny);


    std::any timeAny = visit(ctx->expr(1));
    if (timeAny.type() != typeid(int)) throw std::runtime_error("Error: AT requires an integer time.");
    event.startTimeMs = std::any_cast<int>(timeAny);


    if (ctx->STRING_VAL()) {
        std::string aliasStr = ctx->STRING_VAL()->getText();
        event.alias = aliasStr.substr(1, aliasStr.length() - 2);
    }

    return event;
}



std::any TonInterpreter::visitShoutStat(TonParser::ShoutStatContext *ctx) {

    auto expressions = ctx->expr();
    for (size_t i = 0; i <  expressions.size(); ++i){
        std::any value = visit(expressions[i]);
        this->printValue(value);
        if (i < expressions.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    return {};
}

std::any TonInterpreter::visitSaveStat(TonParser::SaveStatContext *ctx) {
    std::string rawFileName = ctx->STRING_VAL()->getText();
    std::string fileName = rawFileName.substr(1, rawFileName.length() - 2);
    std::any exportedValue = visit(ctx->expr());

    Sound soundToSave;

    if (exportedValue.type() == typeid(Sound)) {
        soundToSave = std::any_cast<Sound>(exportedValue);
    }
    else if (exportedValue.type() == typeid(Timeline)) {
        Timeline tl = std::any_cast<Timeline>(exportedValue);
        soundToSave = tl.renderFinalSound();
    }
    else {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": !save command requires a SOUND or TIMELINE type.");
    }

    soundToSave.normalize();

    AudioFile<float> audioFile;
    audioFile.setNumChannels(1);
    audioFile.setNumSamplesPerChannel(soundToSave.samples.size());
    audioFile.setSampleRate(Sound::sampleRate);
    audioFile.samples[0] = soundToSave.samples;

    std::filesystem::path filePath(fileName);
    std::filesystem::path parentDir = filePath.parent_path();

    if (!parentDir.empty() && !std::filesystem::exists(parentDir)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Directory does not exist: " + parentDir.string());
    }

    if (audioFile.save(fileName)) {
        std::cout << ">>> [SYSTEM] Successfully exported SOUND to: " << fileName << std::endl;
    }
    else {
        throw std::runtime_error("Error: Failed to write WAV.");
    }

    return {};
}


std::any TonInterpreter::visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) {
    std::string soundId = ctx->ID()->getText();
    std::any arg1 = visit(ctx->expr(0));
    std::any arg2 = visit(ctx->expr(1));

    if (!coerceType("NOTE", arg1)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": First argument of SOUND definition must be a NOTE.");
    }
    if (!coerceType("INT", arg2)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Second argument of SOUND definition must be an INT.");
    }

    Note note = std::any_cast<Note>(arg1);
    int durationMs = std::any_cast<int>(arg2);
    float volume = 0.5f;

    if (ctx->expr().size() > 2) {
        std::any arg3 = visit(ctx->expr(2));

        if (!coerceType("NUMERICAL", arg3) && !coerceType("INT", arg3)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Volume must be a number in range [0, 2].");
        }

        if (arg3.type() == typeid(int)) {
            volume = static_cast<float>(std::any_cast<int>(arg3));
        }
        else if (arg3.type() == typeid(double)) {
            volume = static_cast<float>(std::any_cast<double>(arg3));
        }
        else if (arg3.type() == typeid(float)) {
            volume = std::any_cast<float>(arg3);
        }
        else {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Volume must be a number in range [0, 2].");
        }
        if (volume < 0.0f || volume > 2.0f) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Volume must be a number in range [0, 2]. Given: " + std::to_string(volume));
        }
        volume /= 2;
    }
    Sound generatedSound;
    int totalSamples = (durationMs / 1000.0) * generatedSound.sampleRate;

    auto it = loadedInstruments.find(soundId);

    if (it == loadedInstruments.end()) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Instrument or synth '"
            + soundId + "' not found. Did you USE it?");
    }

    Instrument& instr = it->second;


    if (instr.getType() == InstrumentType::Synth) {
        try {
            generatedSound.generateSynthWave(instr.getName(), note, durationMs);
        }
        catch(std::runtime_error& ex) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": There is no synth named'"
                                     + soundId + ".");
        }
    }
    else if (instr.getType() == InstrumentType::SoundFont) {
        if (!soundFont) throw std::runtime_error("SoundFont library is not initialized.");
        int realPresetIndex = tsf_get_presetindex(soundFont, 0, instr.getMidiPresetIndex());

        if (realPresetIndex < 0) {
            std::cerr << ">>> [WARNING] MIDI Preset " << instr.getMidiPresetIndex() << " not found in SoundFont! Using default.\n";
            realPresetIndex = 0;
        }

        std::vector<float> floatSamples(totalSamples);
        tsf_note_on(soundFont, realPresetIndex, note.toMidiNumber(), volume);
        tsf_render_float(soundFont, floatSamples.data(), totalSamples, 0);
        tsf_note_off(soundFont, realPresetIndex, note.toMidiNumber());

        generatedSound.samples.assign(floatSamples.begin(), floatSamples.end());
    }

    return generatedSound;
}

std::any TonInterpreter::visitStringValExpr(TonParser::StringValExprContext *ctx) {
    std::string rawString = ctx->STRING_VAL()->getText();
    return rawString.substr(1, rawString.length() - 2);
}

std::any TonInterpreter::visitNoteValExpr(TonParser::NoteValExprContext *ctx) {
    std::string noteStr = ctx->NOTE_VAL()->getText();
    Note note = Note{
        noteStr.substr(0,noteStr.length() - 1),
        std::stoi(noteStr.substr(noteStr.length() - 1))
    };
    return note;
}

std::any TonInterpreter::visitIntValExpr(TonParser::IntValExprContext *ctx) {
    return std::stoi(ctx->INT_VAL()->getText());
}


std::any TonInterpreter::visitTrackDecl(TonParser::TrackDeclContext *ctx) {
    auto targetNode = ctx->target();
    std::string timelineName = targetNode->ID(0)->getText(); 
    std::string trackName = ctx->ID()->getText();

    auto targetScope = resolveScope(targetNode);

    if (!targetScope->exists(timelineName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Timeline '" + timelineName + "' not found.");
    }

    std::any& baseObj = targetScope->get(timelineName);
    if (baseObj.type() != typeid(Timeline)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ":" + timelineName + "' is not a TIMELINE.");
    }

    Timeline& timeline = std::any_cast<Timeline&>(baseObj);

    if (timeline.tracks.find(trackName) != timeline.tracks.end()) {
        throw std::runtime_error("Error: Track '" + trackName + "' already exists in timeline '" + timelineName + "'.");
    }

    Track newTrack;
    newTrack.name = trackName;
    timeline.tracks[trackName] = newTrack;

    return {};
}


std::any TonInterpreter::visitAudioOpStat(TonParser::AudioOpStatContext *ctx) {
    auto targetNode = ctx->target();
    std::string timelineName = targetNode->ID(0)->getText();

    auto targetScope = resolveScope(targetNode);

    if (!targetScope->exists(timelineName)) {
        throw std::runtime_error("Error: Timeline '" + timelineName + "' not found.");
    }
    std::any& baseObj = targetScope->get(timelineName);
    if (baseObj.type() != typeid(Timeline)) throw std::runtime_error("Error: Target is not a TIMELINE.");
    Timeline& timeline = std::any_cast<Timeline&>(baseObj);

    std::string trackName = "";
    if (targetNode->ID().size() > 1) {
        trackName = targetNode->ID(1)->getText();
        if (timeline.tracks.find(trackName) == timeline.tracks.end()) {
            throw std::runtime_error("Error: Track '" + trackName + "' not found.");
        }
    }

    std::string aliasName = "";
    if (targetNode->STRING_VAL()) {
        std::string rawAlias = targetNode->STRING_VAL()->getText();
        aliasName = rawAlias.substr(1, rawAlias.length() - 2); 
    }

    if (ctx->SHIFT()) {
        if (trackName.empty() || aliasName.empty()) {
            throw std::runtime_error("Error: SHIFT requires a track and an event alias (e.g., t1.pianos.\"intro\").");
        }
        int shiftMs = std::any_cast<int>(visit(ctx->expr()));

        bool found = false;
        for (auto& ev : timeline.tracks[trackName].events) {
            if (ev.alias == aliasName) {
                ev.startTimeMs += shiftMs;
                found = true;
            }
        }
        if (!found) throw std::runtime_error("Error: Alias '" + aliasName + "' not found on track.");
    }

    if (ctx->MUTE()) {
        if (targetNode->ID().size() != 2 || targetNode->STRING_VAL() != nullptr) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": The MUTE operation can only be applied to a TRACK.");
        }
        try {
            timeline.tracks.at(trackName).isMuted = true;
        } catch (std::out_of_range& ex) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Given TRACK does not exist.");
        }
    }

    if (ctx->UNMUTE()) {
        if (targetNode->ID().size() != 2 || targetNode->STRING_VAL() != nullptr) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": The MUTE operation can only be applied to a TRACK.");
        }
        try {
            timeline.tracks.at(trackName).isMuted = false;
        } catch (std::out_of_range& ex) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Given TRACK does not exist.");
        }
    }

    if (ctx->VOL()) {
        auto targetCtx = ctx->target();

        if (targetCtx->ID().size() != 2 || targetCtx->STRING_VAL() != nullptr) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": The VOL operation can only be applied to a TRACK.");
        }
        std::any volAny = visit(ctx->expr());
        float newVolume = 1.0f;

        if (volAny.type() == typeid(int)) {
            newVolume = static_cast<float>(std::any_cast<int>(volAny));
        } else if (volAny.type() == typeid(double)) {
            newVolume = static_cast<float>(std::any_cast<double>(volAny));
        } else if (volAny.type() == typeid(float)) {
            newVolume = std::any_cast<float>(volAny);
        } else {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Volume must be a number in range [0, 2].");
        }

        if (newVolume < 0.0f) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Track volume must be positive. Given: " + std::to_string(newVolume));
        }

        try {
            auto& track = timeline.tracks.at(trackName);
            track.volume = newVolume;
        } catch(const std::out_of_range& ex) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Given TRACK does not exist.");
        }
    }
    return {};
}


std::any TonInterpreter::visitIsolateExpr(TonParser::IsolateExprContext *ctx) {
    auto targetNode = ctx -> target();
    std::string timelineName = targetNode->ID(0)->getText();

    auto targetScope = resolveScope(targetNode);

    if (!targetScope->exists(timelineName)){
        throw std::runtime_error("Error: Timeline '" + timelineName + "' not found.");
    }

    std::any& baseObj = targetScope->get(timelineName);
    if (baseObj.type() != typeid(Timeline)){
        throw std::runtime_error("Error: Target is not a TIMELINE.");
    }
    Timeline& timeline = std::any_cast<Timeline&>(baseObj);

    if (targetNode->ID().size() < 2) {
        throw std::runtime_error("Error: ISOLATE requires a track...");
    }
    std::string trackName = targetNode->ID(1)->getText();

    if (timeline.tracks.find(trackName) == timeline.tracks.end()) {
        throw std::runtime_error("Error: Track '" + trackName + "' not found...");
    }

    Timeline isolatedTimeline;
    isolatedTimeline.name = timeline.name + "_isolated";
    isolatedTimeline.tracks[trackName] = timeline.tracks[trackName];
    isolatedTimeline.tracks[trackName].isMuted = false;

    return isolatedTimeline;
}




std::any TonInterpreter::visitBoolValExpr(TonParser::BoolValExprContext *ctx)
{
    std::string text = ctx->BOOL_VAL()->getText();
    if (text == "true" || text == "TRUE") {
        return true;
    }
    return false;
}


std::any TonInterpreter::visitNotExpr(TonParser::NotExprContext *ctx) {
    std::any val = visit(ctx->expr());

    if (val.type() == typeid(bool)) {
        return !std::any_cast<bool>(val);
    }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Line " + std::to_string(line) + ": NOT operator requires a BOOL expression.");
}


std::any TonInterpreter::visitAndExpr(TonParser::AndExprContext *ctx) {
    std::any leftVal = visit(ctx->expr(0));
    std::any rightVal = visit(ctx->expr(1));

    if (leftVal.type() == typeid(bool) && rightVal.type() == typeid(bool)) {
        return std::any_cast<bool>(leftVal) && std::any_cast<bool>(rightVal);
    }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Line " + std::to_string(line) + ": AND operator requires both operands to be BOOL.");
}


std::any TonInterpreter::visitOrExpr(TonParser::OrExprContext *ctx) {
    std::any leftVal = visit(ctx->expr(0));
    std::any rightVal = visit(ctx->expr(1));

    if (leftVal.type() == typeid(bool) && rightVal.type() == typeid(bool)) {
        return std::any_cast<bool>(leftVal) || std::any_cast<bool>(rightVal);
    }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Line " + std::to_string(line) + ": OR operator requires both operands to be BOOL.");
}


std::any TonInterpreter::visitRelationalExpr(TonParser::RelationalExprContext *ctx)
{
    std::any leftVal = visit(ctx->expr(0));
    std::any rightVal = visit(ctx->expr(1));

    if (leftVal.type() == typeid(std::string) && rightVal.type() == typeid(std::string)) {
        std::string l = std::any_cast<std::string>(leftVal);
        std::string r = std::any_cast<std::string>(rightVal);

        if (ctx->EQ() != nullptr) return l == r;
        if (ctx->NEQ() != nullptr) return l != r;
        if (ctx->L_ANGLE() != nullptr) return l < r;
        if (ctx->L_ANGLE_EQ() != nullptr) return l <= r;
        if (ctx->R_ANGLE() != nullptr) return l > r;
        if (ctx->R_ANGLE_EQ() != nullptr) return l >= r;
    }

    if (leftVal.type() == typeid(bool) && rightVal.type() == typeid(bool)) {
        bool l = std::any_cast<bool>(leftVal);
        bool r = std::any_cast<bool>(rightVal);

        if (ctx->EQ() != nullptr) return l == r;
        if (ctx->NEQ() != nullptr) return l != r;

        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Runtime Error in line " + std::to_string(line) + ": Invalid relational operator for BOOL.");
    }

    if ((leftVal.type() == typeid(int) || leftVal.type() == typeid(double)) &&
        (rightVal.type() == typeid(int) || rightVal.type() == typeid(double))) {

        double l = (leftVal.type() == typeid(int)) ? std::any_cast<int>(leftVal) : std::any_cast<double>(leftVal);
        double r = (rightVal.type() == typeid(int)) ? std::any_cast<int>(rightVal) : std::any_cast<double>(rightVal);

        if (ctx->EQ() != nullptr) return l == r;
        if (ctx->NEQ() != nullptr) return l != r;
        if (ctx->L_ANGLE() != nullptr) return l < r;
        if (ctx->L_ANGLE_EQ() != nullptr) return l <= r;
        if (ctx->R_ANGLE() != nullptr) return l > r;
        if (ctx->R_ANGLE_EQ() != nullptr) return l >= r;
    }

    if (leftVal.type() == typeid(Sound) && rightVal.type() == typeid(Sound)) {
        Sound l = std::any_cast<Sound>(leftVal);
        Sound r = std::any_cast<Sound>(rightVal);

        if (ctx->EQ() != nullptr) return l == r;
        if (ctx->NEQ() != nullptr) return l != r;
        if (ctx->L_ANGLE() != nullptr) return l < r;
        if (ctx->L_ANGLE_EQ() != nullptr) return l <= r;
        if (ctx->R_ANGLE() != nullptr) return l > r;
        if (ctx->R_ANGLE_EQ() != nullptr) return l >= r;
    }
    if (leftVal.type() == typeid(Note) && rightVal.type() == typeid(Note)) {
        Note l = std::any_cast<Note>(leftVal);
        Note r = std::any_cast<Note>(rightVal);

        if (ctx->EQ() != nullptr) return l == r;
        if (ctx->NEQ() != nullptr) return l != r;
        if (ctx->L_ANGLE() != nullptr) return l < r;
        if (ctx->L_ANGLE_EQ() != nullptr) return l <= r;
        if (ctx->R_ANGLE() != nullptr) return l > r;
        if (ctx->R_ANGLE_EQ() != nullptr) return l >= r;
    }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("in line " + std::to_string(line) + ": Cannot evaluate relational operator for these types.");
}

std::any TonInterpreter::visitParensExpr(TonParser::ParensExprContext *ctx) {
    return visit(ctx->expr());
}


std::any TonInterpreter::visitUnaryExpr(TonParser::UnaryExprContext *ctx) {
    std::any val = visit(ctx->expr());
    bool isMinus = ctx->MINUS() != nullptr;
    if (val.type() == typeid(int)){
        int v = std::any_cast<int>(val);
        return isMinus ? -v : v;
    }
    else if (val.type()==typeid(double)){
        double v = std::any_cast<double>(val);
        return isMinus ? -v : v;
    }
    throw std::runtime_error("Line " + std::to_string(ctx->getStart()->getLine()) + ": Unary operators (+, -) require INT or NUM.");

}

std::any TonInterpreter::visitNumValExpr(TonParser::NumValExprContext *ctx) {
    return std::stod(ctx->NUM_VAL()->getText());
}


std::any TonInterpreter::visitMulDivExpr(TonParser::MulDivExprContext *ctx) {
    std::any left = visit(ctx->expr(0));
    std::any right = visit(ctx->expr(1));

    if (ctx->MULT()) {
        bool isLeftSound = (left.type() == typeid(Sound));
        bool isRightSound = (right.type() == typeid(Sound));

        if (isLeftSound || isRightSound) {
            std::any numberAny = isLeftSound ? right : left;

            if (numberAny.type() == typeid(double) || numberAny.type() == typeid(int)) {
                Sound s = isLeftSound ? std::any_cast<Sound>(left) : std::any_cast<Sound>(right);
                double multiplier = (numberAny.type() == typeid(double))
                    ? std::any_cast<double>(numberAny)
                    : static_cast<double>(std::any_cast<int>(numberAny));
                return s * multiplier;
            }
            else {
                size_t line = ctx->getStart()->getLine();
                throw std::runtime_error("Line " + std::to_string(line) + ": Error - SOUND can only be multiplied by INT or NUMERICAL.");
            }
        }

        if ((left.type() != typeid(int) && left.type() != typeid(double)) ||
            (right.type() != typeid(int) && right.type() != typeid(double))) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Error - Mathematical multiplication requires numbers.");
        }

        double leftVal = (left.type() == typeid(int)) ? std::any_cast<int>(left) : std::any_cast<double>(left);
        double rightVal = (right.type() == typeid(int)) ? std::any_cast<int>(right) : std::any_cast<double>(right);

        if (left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal * rightVal);
        return (leftVal * rightVal);
    }
    else if (ctx->DIV_OP()) {
        if ((left.type() != typeid(int) && left.type() != typeid(double)) ||
            (right.type() != typeid(int) && right.type() != typeid(double))) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Error - Mathematical division requires numbers.");
        }

        double leftVal = (left.type() == typeid(int)) ? std::any_cast<int>(left) : std::any_cast<double>(left);
        double rightVal = (right.type() == typeid(int)) ? std::any_cast<int>(right) : std::any_cast<double>(right);

        if (rightVal == 0.0) {
            throw std::runtime_error("Line " + std::to_string(ctx->getStart()->getLine()) + ": ERROR - Division by zero!");
        }

        if (left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal / rightVal);
        return leftVal / rightVal;
    }

    return {};
}

std::any TonInterpreter::visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) {
    std::any left = visit(ctx->expr(0));
    std::any right = visit(ctx->expr(1));

    if (ctx->PLUS()) {
        if (left.type() == typeid(Sound) && right.type() == typeid(Sound)) {
            Sound s1 = std::any_cast<Sound>(left);
            Sound s2 = std::any_cast<Sound>(right);

            Sound mixedSound;

            size_t maxSize = std::max(s1.samples.size(), s2.samples.size());
            mixedSound.samples.reserve(maxSize);

            for (size_t i = 0; i < maxSize; ++i) {
                double val1 = (i < s1.samples.size()) ? s1.samples[i] : 0.0;
                double val2 = (i < s2.samples.size()) ? s2.samples[i] : 0.0;
                mixedSound.samples.push_back((val1 + val2));

            }
            std::cout << *std::max_element(mixedSound.samples.begin(), mixedSound.samples.end());
            return mixedSound;
        }

        // --- DODAWANIE STRINGÓW ---
        if (left.type() == typeid(std::string) && right.type() == typeid(std::string)) {
            return std::any_cast<std::string>(left) + std::any_cast<std::string>(right);
        }

        // --- ZWYKŁE DODAWANIE MATEMATYCZNE ---
        double leftVal = (left.type() == typeid(int)) ? std::any_cast<int>(left) : std::any_cast<double>(left);
        double rightVal = (right.type() == typeid(int)) ? std::any_cast<int>(right) : std::any_cast<double>(right);

        if (left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal + rightVal);
        return leftVal + rightVal;
    }
    else if (ctx->MINUS()) {
        double leftVal = (left.type() == typeid(int)) ? std::any_cast<int>(left) : std::any_cast<double>(left);
        double rightVal = (right.type() == typeid(int)) ? std::any_cast<int>(right) : std::any_cast<double>(right);

        if (left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal - rightVal);
        return leftVal - rightVal;
    }

    return {};
}

std::any TonInterpreter::visitConcatExpr(TonParser::ConcatExprContext *ctx)
{
    std::any left = visit(ctx->expr(0));
    std::any right = visit(ctx->expr(1));
    if (left.type() == typeid(Sound) && right.type() == typeid(Sound)) {
        Sound s1 = std::any_cast<Sound>(left);
        Sound s2 = std::any_cast<Sound>(right);

        Sound concatSound;

        concatSound.samples.reserve(s1.samples.size() + s2.samples.size());

        concatSound.samples.insert(concatSound.samples.end(), s1.samples.begin(), s1.samples.end());
        concatSound.samples.insert(concatSound.samples.end(), s2.samples.begin(), s2.samples.end());

        return concatSound;
    }
    if (left.type() == typeid(std::string) && right.type() == typeid(std::string)) {
        return std::any_cast<std::string>(left) + std::any_cast<std::string>(right);
    }

    return {};
}



std::any TonInterpreter::visitBreakStat(TonParser::BreakStatContext *ctx){
    throw BreakException();
}

std::any TonInterpreter::visitContinueStat(TonParser::ContinueStatContext *ctx) {
    throw ContinueException();
}

std::any TonInterpreter::visitUntilStat(TonParser::UntilStatContext *ctx) {
    while (true){
        std::any conditionAny = visit(ctx->expr());
        if (conditionAny.type() != typeid(bool)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Error - UNTIL condition must be a BOOL.");
        }

        bool condition = std::any_cast<bool>(conditionAny);
        if (condition){
            break;
        }
        try {
            visit(ctx->block());
        }
        catch (BreakException&) {
            break;
        }
        catch (ContinueException&) {
            continue;
        }
    }
    return {};
}

std::any TonInterpreter::visitLoopStat(TonParser::LoopStatContext *ctx) {
    
    if (ctx->TIMES()) {
        std::any timesAny = visit(ctx->expr(0));
        int times = 0;

        if (timesAny.type() == typeid(int)) {
            times = std::any_cast<int>(timesAny);
        } else if (timesAny.type() == typeid(double)) {
            times = static_cast<int>(std::any_cast<double>(timesAny));
        } else {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Error - TIMES loop requires an integer count.");
        }

        for (int i=0; i<times; i++) {
            try { visit(ctx->block()); }
            catch (BreakException&) { break; }
            catch (ContinueException&) { continue; }
        }
    }

    else if (ctx->FROM()) {
        std::string varName = ctx->ID()->getText();

        int start = std::any_cast<int>(visit(ctx->expr(0)));
        int end = std::any_cast<int>(visit(ctx->expr(1)));

        int step = (start <= end) ? 1 : -1;

        if (ctx->BY() != nullptr) {
            step = std::any_cast<int>(visit(ctx->expr(2)));

            if (step == 0) {
                size_t line = ctx->getStart()->getLine();
                throw std::runtime_error("Line " + std::to_string(line) + ": Error - Loop step cannot be zero.");
            }
        }

        auto previousScope = currentScope;
        
    
        if (ctx->type() != nullptr) {
            std::string typeName = ctx->type()->getText();
            currentScope = std::make_shared<Scope<std::any>>(previousScope);
            currentScope->define(varName, typeName, start);
        } else {
            if (!currentScope->exists(varName)) {
                size_t line = ctx->getStart()->getLine();
                throw std::runtime_error("Line " + std::to_string(line) + ": Error - Variable '" + varName + "' not found.");
            }
           
            currentScope->set(varName, start);
        }

     
        while (true) {
    
            int currentVal = std::any_cast<int>(currentScope->get(varName));
            
      
            if (step > 0 ? currentVal > end : currentVal < end) {
                break;
            }
            
        
            try { 
                visit(ctx->block()); 
            } 
            catch (BreakException&) { 
                break; 
            } 
            catch (ContinueException&) { 
              
            }

           
            int valAfterBlock = std::any_cast<int>(currentScope->get(varName));
            currentScope->set(varName, valAfterBlock + step);
        }

        currentScope = previousScope;
    }

    else if (ctx->ASSIGN()) {
        std::string varName = ctx->ID()->getText();
        
        std::any arrayAny = visit(ctx->expr(0));
        if (arrayAny.type() != typeid(std::vector<std::any>)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Error - Foreach loop requires an ARRAY on the right side of <");
        }
        auto arrayVec = std::any_cast<std::vector<std::any>>(arrayAny);

        auto previousScope = currentScope;

        if (ctx->type() != nullptr) {
            std::string typeName = ctx->type()->getText();
            currentScope = std::make_shared<Scope<std::any>>(previousScope);
            currentScope->define(varName, typeName, std::any{});
        } else {
            if (!currentScope->exists(varName)) {
                size_t line = ctx->getStart()->getLine();
                throw std::runtime_error("Line " + std::to_string(line) + ": Error - Variable '" + varName + "' not found.");
            }
        }

        for (auto& item : arrayVec) {
            currentScope->set(varName, item);

            try { visit(ctx->block()); }
            catch (BreakException&) { break; }
            catch (ContinueException&) { continue; }
        }

        currentScope = previousScope;
    }

    return {};
}

std::any TonInterpreter::visitFuncDef(TonParser::FuncDefContext *ctx){
        return {};
    }

std::any TonInterpreter::visitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx){
        std::string funcName = ctx->ID()->getText();
        return executeFunctionLogic(funcName, ctx->expr());
}

std::any TonInterpreter::visitCallStat(TonParser::CallStatContext *ctx){
    std::string funcName = ctx-> ID()->getText();
    executeFunctionLogic(funcName, ctx->expr());
    return {};
}
std::any TonInterpreter::visitReturnStat(TonParser::ReturnStatContext *ctx){
    std::any valueToReturn = {};

    if(ctx->expr()){
        valueToReturn = visit(ctx->expr());
    }
    throw ReturnException(valueToReturn);
}

void TonInterpreter::validateStackDepth() {
    if (currentStackDepth >= TonInterpreter::MAX_STACK_DEPTH) {
        throw std::runtime_error("Stack depth limit reached.");
    }
}

std::any TonInterpreter::executeFunctionLogic(const std::string& funcName, const std::vector<TonParser::ExprContext*>& argsCtx){

    this->validateStackDepth();

    if(!currentScope-> exists(funcName)){
        throw std::runtime_error("Function doesn't exist.");
    }
    std::any func = currentScope->get(funcName);
    auto funcdefctx = std::any_cast<TonParser::FuncDefContext*>(func);

    std::string expectedReturnType = funcdefctx->type(0)->getText();

    size_t expectedargs = funcdefctx->ID().size()-1;
    size_t providedargs = argsCtx.size();

    if(expectedargs != providedargs){
        throw std::runtime_error("Function '"+ funcName + "' expects " + std::to_string(expectedargs) + " recieved only " + std::to_string(providedargs) + "arguments.");
    }
    std::vector<std::any> evaluatedArgs;
    for(auto exprctx : argsCtx){
        evaluatedArgs.push_back(visit(exprctx));
    }

    auto previousScope = currentScope;


    auto globalScope = currentScope;
    while (globalScope->parent != nullptr) {
        globalScope = globalScope->parent;
    }
    
    currentScope = std::make_shared<Scope<std::any>>(globalScope);

    this->currentStackDepth++;

    for(size_t i = 0; i < expectedargs; i++){
        std::string paramType = funcdefctx->type(i+1)->getText();
        std::string paramName = funcdefctx->ID(i+1)->getText();
        std::any argval = evaluatedArgs[i];

        bool typeMatch = coerceType(paramType, argval);
        if (!typeMatch) {
            currentScope = previousScope;
            this->currentStackDepth--;
            throw std::runtime_error("Argument '" + paramName + "' in function '" + funcName + "' must be of type " + paramType + ".");
        }
        currentScope->define(paramName, paramType, argval);
    }
    std::any result = {};

    try{
        visit(funcdefctx->block());
        if (expectedReturnType != "VOID") {
            throw std::runtime_error("Function '" + funcName + "' missing return statement (!out).");
        }
    } catch( const ReturnException& ret){
      result = ret.returnValue;

        if (expectedReturnType == "VOID") {

            if (result.has_value()) {
                throw std::runtime_error("Function '" + funcName + "' is of type VOID and cannot return a value.");
            }
        }
        else {

            if (!result.has_value()) {
                throw std::runtime_error("Function '" + funcName + "' must return a value of type " + expectedReturnType + ".");
            }

            bool typeMatch = coerceType(expectedReturnType, result);
            if (!typeMatch) {
                throw std::runtime_error("Function '" + funcName + "' returned wrong type. Expected " + expectedReturnType + ".");
            }
        }
    }catch(...){
        currentScope = previousScope;
        this->currentStackDepth--;
        throw;
    }
    currentScope = previousScope;
    this->currentStackDepth--;
    return result;

}



std::any TonInterpreter::visitIfStat(TonParser::IfStatContext *ctx) {

    size_t conditionsCount = ctx->expr().size();

    for (size_t i = 0; i < conditionsCount; ++i) {
        std::any conditionAny = visit(ctx->expr(i));

        if (conditionAny.type() != typeid(bool)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) + ": Error - IF condition must be a BOOL.");
        }

        bool condition = std::any_cast<bool>(conditionAny);

        if (condition) {
            return visit(ctx->block(i));
        }
    }


    if (ctx->block().size() > conditionsCount) {
        return visit(ctx->block(conditionsCount));
    }

    return {};
}

std::any TonInterpreter::visitIndexExpr(TonParser::IndexExprContext *ctx){
    std::any arrayAny = visit(ctx->expr(0));
    std::any indexAny = visit(ctx->expr(1));

    if(arrayAny.type() != typeid(std::vector<std::any>)){
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Indexing requires an ARRAY.");
    }

    if (indexAny.type() != typeid(int)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Array index must be an INT.");
    }
    auto arrayVec = std::any_cast<std::vector<std::any>>(arrayAny);
    int index = std::any_cast<int>(indexAny);

    if (index < 0) {
        index += arrayVec.size();
    }

    if (index < 0 || index >= arrayVec.size()) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Array index out of bounds.");
    }
    return arrayVec[index];
}

std::any TonInterpreter::visitSliceExpr(TonParser::SliceExprContext *ctx) {
    std::any arrayAny = visit(ctx->expr(0));
    std::any startAny = visit(ctx->expr(1));
    std::any endAny = visit(ctx->expr(2));

    if (arrayAny.type() != typeid(std::vector<std::any>)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Slicing requires an ARRAY.");
    }

    if (startAny.type() != typeid(int) || endAny.type() != typeid(int)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Slice indices must be INT.");
    }

    auto arrayVec = std::any_cast<std::vector<std::any>>(arrayAny);
    int start = std::any_cast<int>(startAny);
    int end = std::any_cast<int>(endAny);

    if (start < 0) start += arrayVec.size();
    if (end < 0) end += arrayVec.size();

    if (start < 0) start = 0;
    if (end > arrayVec.size()) end = arrayVec.size();

    if (start >= end) {
        return std::vector<std::any>{};
    }

    std::vector<std::any> slicedVec(arrayVec.begin() + start, arrayVec.begin() + end);
    return slicedVec;
}


std::any TonInterpreter::visitArrayOpStat(TonParser::ArrayOpStatContext *ctx) {
    auto targetNode = ctx->target(); 
    std::string varName = targetNode->ID(0)->getText(); 

    auto targetScope = resolveScope(targetNode);

    if (!targetScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Array '" + varName + "' not found.");
    }

    std::any arrayVal = targetScope->get(varName);
    
    if (arrayVal.type() != typeid(std::vector<std::any>)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - '" + varName + "' is not an ARRAY.");
    }

    auto vec = std::any_cast<std::vector<std::any>>(arrayVal);

    if (ctx->APPEND()) {
        std::any newVal = visit(ctx->expr());
        vec.push_back(newVal);
    }
    else if (ctx->CLEAR()) {
        vec.clear();
    }

    targetScope->set(varName, vec);
    return {};
}


std::any TonInterpreter::visitPopExpr(TonParser::PopExprContext *ctx) {
    auto targetNode = ctx->target(); 
    std::string varName = targetNode->ID(0)->getText();

    auto targetScope = resolveScope(targetNode);

    if (!targetScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Array '" + varName + "' not found.");
    }

    std::any arrayVal = targetScope->get(varName);
    
    if (arrayVal.type() != typeid(std::vector<std::any>)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - POP requires an ARRAY variable.");
    }

    auto vec = std::any_cast<std::vector<std::any>>(arrayVal);

    if (vec.empty()) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) + ": Error - Cannot POP from an empty array.");
    }

    std::any poppedItem = vec.back();
    vec.pop_back();

    targetScope->set(varName, vec);
    
    return poppedItem;
}

std::any TonInterpreter::visitCastExpr(TonParser::CastExprContext *ctx) {
    std::string targetType = ctx->type()->getText();
    std::any val = visit(ctx->expr());
    size_t line = ctx->getStart()->getLine();

    if (targetType == "INT") {
        if (val.type() == typeid(double)) return static_cast<int>(std::any_cast<double>(val));
        if (val.type() == typeid(bool)) return std::any_cast<bool>(val) ? 1 : 0;
        if (val.type() == typeid(int)) return val; 
        if (val.type() == typeid(std::string)) {
            try {
                return std::stoi(std::any_cast<std::string>(val));
            } catch (const std::exception& e) {
                throw std::runtime_error("Line " + std::to_string(line) + 
                                         ": Cannot cast STRING to INT. Invalid format.");
            }
        }
    }
    

    else if (targetType == "NUMERICAL") {
        if (val.type() == typeid(int)) return static_cast<double>(std::any_cast<int>(val));
        if (val.type() == typeid(bool)) return val;
        if (val.type() == typeid(double)) return val;
        if (val.type() == typeid(std::string)) {
            try {
                return std::stod(std::any_cast<std::string>(val));
            } catch (const std::exception& e) {
                throw std::runtime_error("Line " + std::to_string(line) + 
                                         ": Cannot cast STRING to NUMERICAL. Invalid format.");
            }
        }
    }


    else if (targetType == "BOOL") {
        if (val.type() == typeid(int)) return std::any_cast<int>(val) != 0;
        if (val.type() == typeid(double)) return std::any_cast<int>(val) != 0;
        if (val.type() == typeid(bool)) return val;
    }


    else if (targetType == "STRING") {
        if (val.type() == typeid(char)) return std::string(1, std::any_cast<char>(val));
        if (val.type() == typeid(int)) return std::to_string(std::any_cast<int>(val));
        if (val.type() == typeid(double)) {
            std::string s = std::to_string(std::any_cast<double>(val));
            s.erase(s.find_last_not_of('0') + 1, std::string::npos); 
            if (s.back() == '.') s.pop_back(); 
            return s;
        }
        if (val.type() == typeid(std::string)) return val;
    }

else if (targetType == "CHAR") {
        if (val.type() == typeid(std::string)) {
            std::string s = std::any_cast<std::string>(val);
            if (s.length() != 1) { 
                throw std::runtime_error("Line " + std::to_string(line) + 
                                         ": Cannot cast STRING to CHAR. String must have exactly 1 character, given " + std::to_string(s.length()) + ".");
            }
            return s[0];
        }
        if (val.type() == typeid(char)) return val;
    }
    throw std::runtime_error("Line " + std::to_string(line) + ": Invalid explicit cast to <" + targetType + "> from the given expression.");
}
std::any TonInterpreter::visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) {
    std::any val = visit(ctx->expr());


    if (val.type() == typeid(std::string)) {
        return static_cast<int>(std::any_cast<std::string>(val).length());
    }

    else if (val.type() == typeid(std::vector<std::any>)) {
        return static_cast<int>(std::any_cast<std::vector<std::any>>(val).size());
    }

    else if (val.type() == typeid(Sound)) {
        Sound s = std::any_cast<Sound>(val);
        double durationSec = static_cast<double>(s.samples.size()) / s.sampleRate;
        return static_cast<int>(durationSec * 1000.0);
    }

    else if (val.type() == typeid(Track)) {
        Track t = std::any_cast<Track>(val);
        int maxMs = 0;
        for (const auto& ev : t.events) {
            double durationSec = static_cast<double>(ev.sound.samples.size()) / ev.sound.sampleRate;
            int endMs = ev.startTimeMs + static_cast<int>(durationSec * 1000.0);
            if (endMs > maxMs) maxMs = endMs;
        }
        return maxMs;
    }

    
    else if (val.type() == typeid(Timeline)) {
        Timeline tl = std::any_cast<Timeline>(val);
        int maxMs = 0;
        for (const auto& trackPair : tl.tracks) {
            for (const auto& ev : trackPair.second.events) {
                double durationSec = static_cast<double>(ev.sound.samples.size()) / ev.sound.sampleRate;
                int endMs = ev.startTimeMs + static_cast<int>(durationSec * 1000.0);
                if (endMs > maxMs) maxMs = endMs;
            }
        }
        return maxMs;
    }


    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Line " + std::to_string(line) +
                             ": LENGTH operator requires STRING, ARRAY, SOUND, TRACK, or TIMELINE.");
}

std::any TonInterpreter::visitDebugDumpStat(TonParser::DebugDumpStatContext *ctx) {

    std::cout << "\n==================== [TON DEBUG DUMP] ====================" << std::endl;
    size_t line = ctx->getStart()->getLine();
    std::cout << "Triggered at line: " << line << "\n" << std::endl;
    
    std::cout << "  " << std::left 
              << std::setw(20) << "VARIABLE NAME" 
              << std::setw(15) << "TYPE" 
              << std::setw(15) << "INITIALIZED" 
              << "CURRENT VALUE" << std::endl;
    std::cout << "  -----------------------------------------------------------------" << std::endl;

    auto scopeTracker = currentScope;
    int level = 0;

    while (scopeTracker != nullptr) {
        if (level > 0) {
            std::cout << "  --- Parent Scope (Level " << level << ") ---" << std::endl;
        }

        if (scopeTracker->values.empty()) {
            std::cout << "  (no variables defined in this scope)" << std::endl;
        }

        for (const auto& pair : scopeTracker->values) {
            std::string name = pair.first;
            std::string type = scopeTracker->types[name];
            bool isInit = scopeTracker->initialized[name];
            std::string initStr = isInit ? "TRUE" : "FALSE";
            std::string valStr = "[Uninitialized / Complex Type]";

            if (isInit) {
                std::any val = pair.second;
                if (val.type() == typeid(int)) {
                    valStr = std::to_string(std::any_cast<int>(val));
                }
                else if (val.type() == typeid(double)) {
                    valStr = std::to_string(std::any_cast<double>(val));
                }
                else if (val.type() == typeid(std::string)) {
                    valStr = "\"" + std::any_cast<std::string>(val) + "\"";
                }
                else if (val.type() == typeid(char)) {
                    valStr = "'" + std::string(1, std::any_cast<char>(val)) + "'";
                }
                else if (val.type() == typeid(bool)) {
                    valStr = std::any_cast<bool>(val) ? "TRUE" : "FALSE";
                }
                else if (type == "ARRAY") {
                    valStr = "[Array Object]";
                }
                else if (type == "SOUND") {
                    valStr = "[Sound Object]";
                }
                else if (type == "TIMELINE") {
                    valStr = "[Timeline Object]";
                }
            }

            std::cout << "  " << std::left 
                      << std::setw(20) << name 
                      << std::setw(15) << type 
                      << std::setw(15) << initStr 
                      << valStr << std::endl;
        }
        
        scopeTracker = scopeTracker->parent;
        level++;
    }

    std::cout << "===========================================================\n" << std::endl;
    return {};
}
