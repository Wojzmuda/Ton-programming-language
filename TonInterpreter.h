#pragma once

#include "antlr4_generated/TonBaseVisitor.h"
#include <map>
#include <string>
#include <any>
#include <vector>
#include "AudioFile.h"


struct Instrument {
    std::string name;
    std::vector<double> sampleData;
    // Tutaj w przyszłości można dodać wskaźnik do mapy sampli
    Instrument(std::string n) : name(n) {}
    Instrument(std::string n, std::string filePath) : name(n) {
        AudioFile<double> audioFile;
        if (audioFile.load(filePath)) {
            sampleData = audioFile.samples[0];
            std::cout << ">>> [SYSTEM] Loaded sample for " << name << " (" << sampleData.size() << " samples)\n";
        } else {
            std::cerr << ">>> [ERROR] Could not load sample: " << filePath << "\n";
        }
    }
    Instrument() : name("SineWave") {}
};


struct Note {
    std::string pitchClass; 
    int octave;            

    Note(std::string p, int o) {
        pitchClass = p;
        octave = o;
    }
    
    Note() {
        pitchClass = "C";
        octave = 4;
    }

    double getFrequency() const {
        std::map<std::string, int> pitchToSemitone = {
            {"C", -9}, {"C#", -8}, {"Db", -8}, {"D", -7}, {"D#", -6}, {"Eb", -6},
            {"E", -5}, {"F", -4}, {"F#", -3}, {"Gb", -3}, {"G", -2}, {"G#", -1},
            {"Ab", -1}, {"A", 0}, {"A#", 1}, {"Bb", 1}, {"B", 2}
        };
        
        int semitoneOffset = pitchToSemitone[pitchClass];
        int octaveOffset = (octave - 4) * 12;
        int totalOffset = semitoneOffset + octaveOffset;
        
        return 440.0 * std::pow(2.0, totalOffset / 12.0);
    }
};


struct Sound {
    std::vector<double> samples;
    int sampleRate = 44100;

    Sound() {}
};


struct TrackEvent {
    Sound sound;
    int startTimeMs;
    std::string alias;
};

struct Track {
    std::string name;
    std::vector<TrackEvent> events;
    bool isMuted = false;
};

struct Timeline {
    std::string name;
    std::map<std::string, Track> tracks;
};

class TonInterpreter: public TonBaseVisitor {
    private:
        std::map<std::string, std::string>& declaredTypes;
        std::map<std::string, std::any>& memory;

    public:
        TonInterpreter(std::map<std::string, std::string>& typesRef, std::map<std::string, std::any>& memoryRef): declaredTypes(typesRef), memory(memoryRef){}
        
        std::any visitProgram(TonParser::ProgramContext *ctx) override;
        std::any visitBlock(TonParser::BlockContext *ctx) override;
        std::any visitStatement(TonParser::StatementContext *ctx) override;
        std::any visitVarDecl(TonParser::VarDeclContext *ctx) override;

        std::any visitAssignment(TonParser::AssignmentContext *ctx) override;
        std::any visitArrayExpr(TonParser::ArrayExprContext *ctx);
        std::any visitTrackEventExpr(TonParser::TrackEventExprContext *ctx);
        std::any visitShoutStat(TonParser::ShoutStatContext *ctx) override;
        std::any visitSaveStat(TonParser::SaveStatContext *ctx) override;

        std::any visitTargetExpr(TonParser::TargetExprContext *ctx) override;

    virtual std::any visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx);
    virtual std::any visitStringValExpr(TonParser::StringValExprContext *ctx) override;
    virtual std::any visitNoteValExpr(TonParser::NoteValExprContext *ctx) override;
    virtual std::any visitIntValExpr(TonParser::IntValExprContext *ctx) override;
    virtual std::any visitAudioOpStat(TonParser::AudioOpStatContext *ctx) override;
    virtual std::any visitIsolateExpr(TonParser::IsolateExprContext *ctx) override;

        // logic operations
        std::any visitBoolValExpr(TonParser::BoolValExprContext *ctx) override;
        std::any visitNotExpr(TonParser::NotExprContext *ctx) override;
        std::any visitAndExpr(TonParser::AndExprContext *ctx) override;
        std::any visitOrExpr(TonParser::OrExprContext *ctx) override;


    // logic operations
    virtual std::any visitBoolValExpr(TonParser::BoolValExprContext *ctx) override;
    virtual std::any visitNotExpr(TonParser::NotExprContext *ctx) override;
    virtual std::any visitAndExpr(TonParser::AndExprContext *ctx) override;
    virtual std::any visitOrExpr(TonParser::OrExprContext *ctx) override;

    // bracketing (is that a word in english xD?)
    virtual std::any visitParensExpr(TonParser::ParensExprContext *ctx) override;

    
};
