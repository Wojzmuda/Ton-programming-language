#pragma once

#include "antlr4_generated/TonBaseVisitor.h"
#include "core/Timeline.h"
#include <map>
#include <string>
#include <any>
#include <vector>

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

        std::any visitTrackDecl(TonParser::TrackDeclContext *ctx) override;

        std::any visitAssignment(TonParser::AssignmentContext *ctx) override;
        std::any visitArrayExpr(TonParser::ArrayExprContext *ctx);
        std::any visitTrackEventExpr(TonParser::TrackEventExprContext *ctx);
        std::any visitShoutStat(TonParser::ShoutStatContext *ctx) override;
        std::any visitSaveStat(TonParser::SaveStatContext *ctx) override;

        std::any visitTargetExpr(TonParser::TargetExprContext *ctx) override;

        std::any visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx);
        std::any visitStringValExpr(TonParser::StringValExprContext *ctx) override;
        std::any visitNoteValExpr(TonParser::NoteValExprContext *ctx) override;
        std::any visitIntValExpr(TonParser::IntValExprContext *ctx) override;
        std::any visitAudioOpStat(TonParser::AudioOpStatContext *ctx) override;
        std::any visitIsolateExpr(TonParser::IsolateExprContext *ctx) override;

    // logic operations
        std::any visitBoolValExpr(TonParser::BoolValExprContext *ctx) override;
        std::any visitNotExpr(TonParser::NotExprContext *ctx) override;
        std::any visitAndExpr(TonParser::AndExprContext *ctx) override;
        std::any visitOrExpr(TonParser::OrExprContext *ctx) override;
        std::any visitRelationalExpr(TonParser::RelationalExprContext *ctx) override;

    // bracketing (is that a word in english xD?)
        std::any visitParensExpr(TonParser::ParensExprContext *ctx) override;

    // math
        std::any visitUnaryExpr(TonParser::UnaryExprContext *ctx) override;
        std::any visitMulDivExpr(TonParser::MulDivExprContext *ctx) override;
        std::any visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) override;
        std::any visitNumValExpr(TonParser::NumValExprContext *ctx) override;
};
