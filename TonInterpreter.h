#pragma once

#include "antlr4_generated/TonBaseVisitor.h"
#include <map>
class TonInterpreter: public TonBaseVisitor{
    private:
    
    std::map<std::string, std::any> memory;

    public:

    std::any visitProgram(TonParser::ProgramContext *ctx) override;
    std::any visitBlock(TonParser::BlockContext *ctx) override;
    std::any visitStatement(TonParser::StatementContext *ctx) override;
    std::any visitVarDecl(TonParser::VarDeclContext *ctx) override;

    // 3rd functions batch
    virtual std::any visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx);
    virtual std::any visitStringValExpr(TonParser::StringValExprContext *ctx) override;
    virtual std::any visitNoteValExpr(TonParser::NoteValExprContext *ctx) override;
    virtual std::any visitIntValExpr(TonParser::IntValExprContext *ctx) override;


};