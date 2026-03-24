#pragma once

#include "antlr4_generated/TonBaseVisitor.h"
#include <map>
#include <string>
#include <any>
#include <vector>

struct Instrument {
    std::string name;
    // Tutaj w przyszłości można dodać wskaźnik do mapy sampli
    Instrument(std::string n) : name(n) {}
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
};


struct Sound {
    std::vector<double> samples;
    int sampleRate = 44100;

    Sound() {}
};


class TonInterpreter: public TonBaseVisitor {
    private:
        std::map<std::string, std::any> memory;

    public:
        std::any visitProgram(TonParser::ProgramContext *ctx) override;
        std::any visitBlock(TonParser::BlockContext *ctx) override;
        std::any visitStatement(TonParser::StatementContext *ctx) override;
        std::any visitVarDecl(TonParser::VarDeclContext *ctx) override;

        std::any visitAssignment(TonParser::AssignmentContext *ctx) override;
        std::any visitShoutStat(TonParser::ShoutStatContext *ctx) override;
        std::any visitSaveStat(TonParser::SaveStatContext *ctx) override;
        std::any visitIdExpr(TonParser::IdExprContext *ctx) override;

};