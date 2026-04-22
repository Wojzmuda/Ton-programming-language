#define _USE_MATH_DEFINES
#include "TonInterpreter.h"
#include <cmath>


std::any TonInterpreter::visitProgram(TonParser::ProgramContext *ctx) {
    return visitChildren(ctx);
}

std::any TonInterpreter::visitBlock(TonParser::BlockContext *ctx) {
    return visitChildren(ctx);
}

std::any TonInterpreter::visitStatement(TonParser::StatementContext *ctx) {
    return visitChildren(ctx);
}

std::any TonInterpreter::visitVarDecl(TonParser::VarDeclContext *ctx) {
    std::string varName = ctx->ID()->getText();
    std::string typeName = ctx->type()->getText(); 

    std::any value;

    if (ctx->expr()) {
        value = visit(ctx->expr());
    } else {
        if (typeName == "TIMELINE") {
            Timeline tl; tl.name = varName; value = tl;
        }
        else if (typeName == "SOUND") value = Sound();
        else if (typeName == "INT") value = 0;
        else if (typeName == "NUMERICAL") value = 0.0;
        else if (typeName == "NOTE") value = Note();
        else if (typeName == "STRING") value = std::string("");
        else value = {};
    }

    memory[varName] = value;
    return value;
}


std::any TonInterpreter::visitTargetExpr(TonParser::TargetExprContext *ctx) {

    auto targetNode = ctx->target(); 
    std::string baseName = targetNode->ID(0)->getText();

    if (memory.find(baseName) == memory.end()) {
        throw std::runtime_error("Error: Undefined variable or timeline '" + baseName + "'.");
    }

    if (targetNode->ID().size() == 1) {
        return memory[baseName];
    }

    std::string trackName = targetNode->ID(1)->getText();
    
    std::any baseObj = memory[baseName];
    if (baseObj.type() != typeid(Timeline)) {
        throw std::runtime_error("Error: '" + baseName + "' is not a TIMELINE, cannot access tracks.");
    }

    Timeline timeline = std::any_cast<Timeline>(baseObj);
   
    if (timeline.tracks.find(trackName) == timeline.tracks.end()) {
        throw std::runtime_error("Error: Track '" + trackName + "' does not exist in timeline '" + baseName + "'.");
    }

    if (targetNode->STRING_VAL()) {
        std::string rawAlias = targetNode->STRING_VAL()->getText();
        std::string aliasName = rawAlias.substr(1, rawAlias.length() - 2); // usuwamy " "


        for (const auto& event : timeline.tracks[trackName].events) {
            if (event.alias == aliasName) {
                return event;
            }
        }
        
    
        throw std::runtime_error("Error: Event alias '" + aliasName + "' does not exist in track '" + trackName + "'.");
        
    }

    return timeline.tracks[trackName];
}





std::any TonInterpreter::visitAssignment(TonParser::AssignmentContext *ctx) {
    auto targetNode = ctx->target();

    if (targetNode->ID().size() == 1) {
        std::string varName = targetNode->ID(0)->getText();
        if (memory.find(varName) == memory.end()) {
            throw std::runtime_error("Error: Variable '" + varName + "' must be declared first.");
        }
        memory[varName] = visit(ctx->expr());
        return {};
    }

    std::string timelineName = targetNode->ID(0)->getText();
    std::string trackName = targetNode->ID(1)->getText();

    if (memory.find(timelineName) == memory.end()) throw std::runtime_error("Timeline not found");
    
    std::any& baseObj = memory[timelineName];
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

    std::any value = visit(ctx->expr());

    if (value.type() == typeid(std::string)) {
        std::cout << std::any_cast<std::string>(value) << std::endl;
    }
    else if (value.type() == typeid(int)) {
        std::cout << std::any_cast<int>(value) << std::endl;
    }
    else if (value.type() == typeid(double)) {
        std::cout << std::any_cast<double>(value) << std::endl;
    }
    else if (value.type() == typeid(char)) {
        std::cout << "'" << std::any_cast<char>(value) << "'" << std::endl;
    }
    else if (value.type() == typeid(bool)) {
        std::cout << (std::any_cast<bool>(value) ? "TRUE" : "FALSE") << std::endl;
    }
    else if (value.type() == typeid(Note)) {
        Note currentNote = std::any_cast<Note>(value);
        std::cout << "NOTE(" << currentNote.pitchClass << currentNote.octave << ")" << std::endl;
    }
    else if (value.type() == typeid(Instrument)) {
        Instrument currentInstrument = std::any_cast<Instrument>(value);
        std::cout << "INSTRUMENT(" << currentInstrument.name << ")" << std::endl;
    }
    else if (value.type() == typeid(std::vector<std::any>)) {
        auto arrayElements = std::any_cast<std::vector<std::any>>(value);
        std::cout << "[ ";

        for (size_t i = 0; i < arrayElements.size(); i++) {
            if (arrayElements[i].type() == typeid(int)) {
                std::cout << std::any_cast<int>(arrayElements[i]);
            }
            else if (arrayElements[i].type() == typeid(double)) {
                std::cout << std::any_cast<double>(arrayElements[i]);
            }
            else if (arrayElements[i].type() == typeid(std::string)) {
                std::cout << "\"" << std::any_cast<std::string>(arrayElements[i]) << "\"";
            }
            else if (arrayElements[i].type() == typeid(char)) {
                std::cout << "'" << std::any_cast<char>(arrayElements[i]) << "'";
            }
            else if (arrayElements[i].type() == typeid(Note)) {
                Note n = std::any_cast<Note>(arrayElements[i]);
                std::cout << n.pitchClass << n.octave;
            }
            else {
                std::cout << "?";
            }

            if (i < arrayElements.size() - 1) std::cout << ", ";
        }
        std::cout << " ]" << std::endl;
    }
    else {
        std::cout << "[Complex Object: SOUND]" << std::endl;
    }

    return {};
}

std::any TonInterpreter::visitSaveStat(TonParser::SaveStatContext *ctx) {
    std::string rawFileName = ctx->STRING_VAL()->getText();
    std::string fileName = rawFileName.substr(1, rawFileName.length() - 2);
    std::any exportedValue = visit(ctx->expr());

    if (exportedValue.type() == typeid(Sound)) {
        Sound soundToSave = std::any_cast<Sound>(exportedValue);
        AudioFile<double> audioFile;
        audioFile.setNumChannels(1);
        audioFile.setNumSamplesPerChannel(soundToSave.samples.size());
        audioFile.setSampleRate(soundToSave.sampleRate);
        audioFile.samples[0] = soundToSave.samples;
        
        if (audioFile.save(fileName)) {
            std::cout << ">>> [SYSTEM] Successfully exported SOUND to: " << fileName << std::endl;
        } else throw std::runtime_error("Error: Failed to write WAV.");
    } 
    else if (exportedValue.type() == typeid(Timeline)) {
  
        Timeline tl = std::any_cast<Timeline>(exportedValue);
        int sampleRate = 44100;
        int maxSamples = sampleRate; 

   
        for (const auto& pair : tl.tracks) {
            if (pair.second.isMuted) continue;
            for (const auto& ev : pair.second.events) {
                int endSample = (ev.startTimeMs / 1000.0) * sampleRate + ev.sound.samples.size();
                if (endSample > maxSamples) maxSamples = endSample;
            }
        }

        std::vector<double> mixedSamples(maxSamples, 0.0);

    
        for (const auto& pair : tl.tracks) {
            if (pair.second.isMuted) continue;
            for (const auto& ev : pair.second.events) {
                int startSample = (ev.startTimeMs / 1000.0) * sampleRate;
                for (size_t i = 0; i < ev.sound.samples.size(); ++i) {
                    mixedSamples[startSample + i] += ev.sound.samples[i];
                }
            }
        }


        AudioFile<double> audioFile;
        audioFile.setNumChannels(1);
        audioFile.setSampleRate(sampleRate);
        audioFile.setNumSamplesPerChannel(maxSamples);
        audioFile.samples[0] = mixedSamples;
        
        if (audioFile.save(fileName)) {
            std::cout << ">>> [SYSTEM] Successfully mixed and exported TIMELINE to: " << fileName << std::endl;
        } else throw std::runtime_error("Error: Failed to write WAV.");
    }
    else {
        throw std::runtime_error("Error: !save command requires a SOUND or TIMELINE type.");
    }

    return {};
}


std::any TonInterpreter::visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) {
    std::string instrumentOrSoundId = ctx->ID()->getText();
    std::any arg1 = visit(ctx->expr(0));
    std::any arg2 = visit(ctx->expr(1));

    Note note;
    int durationMs;
    if (arg1.type() == typeid(Note)) {
        note = std::any_cast<Note>(arg1);
    }
    else {
        // ? How are we handling this ?
        throw std::runtime_error{"Error: got wrong argument - not Note type"};
    }
    if (arg2.type() == typeid(int)) {
        durationMs = std::any_cast<int>(arg2);
    }
    else {
        // ? How are we handling this ?
        throw std::runtime_error{"Error: got wrong argument - not int type"};
    }

    // TODO choose right sample instead of using temp lambda
    // -----
    auto createTemporarySinWave = [](Note note, int dur) {
        Sound generatedSound;
        int totalSamples = (dur / 1000.0) * generatedSound.sampleRate;
        for (int i = 0; i < totalSamples; ++i) {
            double time = (double)i / generatedSound.sampleRate;
            double sampleValue = std::sin(2.0 * M_PI * note.getFrequency() * time);
            generatedSound.samples.push_back(sampleValue);
        }
        return generatedSound;
    };
    // ------
    
    Sound sound = createTemporarySinWave(note, durationMs);

    
    return sound;
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

    std::string timelineName = ctx->ID(0)->getText(); 
    std::string trackName = ctx->ID(1)->getText();    


    if (memory.find(timelineName) == memory.end()) {
        throw std::runtime_error("Error: Timeline '" + timelineName + "' not found.");
    }


    std::any& baseObj = memory[timelineName];
    if (baseObj.type() != typeid(Timeline)) {
        throw std::runtime_error("Error: '" + timelineName + "' is not a TIMELINE.");
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


    if (memory.find(timelineName) == memory.end()) {
        throw std::runtime_error("Error: Timeline '" + timelineName + "' not found.");
    }
    std::any& baseObj = memory[timelineName];
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
        aliasName = rawAlias.substr(1, rawAlias.length() - 2); // usuwamy " "
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

    return {};
}

std::any TonInterpreter::visitIsolateExpr(TonParser::IsolateExprContext *ctx) {
    auto targetNode = ctx -> target();
    std::string timelineName = targetNode->ID(0)->getText();
    if (memory.find(timelineName) == memory.end()){
        throw std::runtime_error("Error: Timeline '" + timelineName + "' not found.");
    }

    std::any& baseObj = memory[timelineName];
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

    // FIXME for now only works for INT and DOUBLE. No type validation !
    double l = (leftVal.type() == typeid(int)) ? std::any_cast<int>(leftVal) : std::any_cast<double>(leftVal);
    double r = (rightVal.type() == typeid(int)) ? std::any_cast<int>(rightVal) : std::any_cast<double>(rightVal);

    if (ctx->EQ() != nullptr) {
        return l == r;
    }
    else if (ctx->NEQ() != nullptr) {
        return l != r;
    }
    else if (ctx->L_ANGLE() != nullptr) {
        return l < r;
    }
    else if (ctx->L_ANGLE_EQ() != nullptr) {
        return l <= r;
    }
    else if (ctx->R_ANGLE() != nullptr) { 
        return l > r;
    }
    else if (ctx->R_ANGLE_EQ() != nullptr) {
        return l >= r;
    }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Line " + std::to_string(line) + ": Relational operators (==, !=, <, >) currently only support INT values.");
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
    std::any left = visit(ctx -> expr(0));
    std::any right = visit(ctx -> expr(1));
    
    double leftVal =(left.type() == typeid(int)) ? std::any_cast<int>(left) : std::any_cast<double>(left);
    double rightVal = (right.type() == typeid(int)) ? std::any_cast<int>(right) : std::any_cast<double>(right);

    if (ctx-> MULT()){
        if(left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal * rightVal);
        return (leftVal * rightVal);   
    }
    else if (ctx->DIV_OP()){
        if (rightVal==0.0){
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

    double leftVal = (left.type() == typeid(int)) ? std::any_cast<int>(left) : std::any_cast<double>(left);
    double rightVal = (right.type() == typeid(int)) ? std::any_cast<int>(right) : std::any_cast<double>(right);

    if (ctx->PLUS()){
        if (left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal + rightVal);
        return leftVal + rightVal;
    }
    else if (ctx->MINUS()){
        if (left.type() == typeid(int) && right.type() == typeid(int)) return (int)(leftVal - rightVal);
        return leftVal - rightVal;
    }
    return {};
}
