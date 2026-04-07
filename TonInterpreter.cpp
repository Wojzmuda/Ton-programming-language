#include "TonInterpreter.h"
#include <cmath>
#include "AudioFile.h"

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
    std::any value = visit(ctx->expr());
    memory[varName] = value;
    return value;
}

// std::any TonInterpreter::visitIdExpr(TonParser::IdExprContext *ctx) {
//     std::string varName = ctx->ID()->getText(); 
//     if (memory.find(varName) != memory.end()) {
//         return memory[varName]; 
//     }

//     throw std::runtime_error("Error: Use of undefined variable '" + varName + "'.");
// }

std::any TonInterpreter::visitTargetExpr(TonParser::TargetExprContext *ctx) {
    std::string targetName = ctx->getText(); 

    // TODO: how to memory ?
    if (memory.find(targetName) != memory.end()) {
        return memory[targetName]; 
    }

    throw std::runtime_error("Error: Use of undefined target '" + targetName + "'.");
}


std::any TonInterpreter::visitAssignment(TonParser::AssignmentContext *ctx) {
    std::string varName = ctx->target()->getText();

    if (memory.find(varName) == memory.end()) {
        throw std::runtime_error("Error: Variable '" + varName + "' must be declared using !make before assignment.");
    }

    std::any newValue = visit(ctx->expr());
    memory[varName] = newValue;

    return {};
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

        bool success = audioFile.save(fileName);

        if (success) {
            std::cout << ">>> [SYSTEM] Successfully exported " << soundToSave.samples.size() 
                      << " samples to: " << fileName << std::endl;
        } else {
            throw std::runtime_error("Error: Failed to write WAV file to disk.");
        }
    } 
    else {
        throw std::runtime_error("Error: !save command requires a SOUND type.");
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
