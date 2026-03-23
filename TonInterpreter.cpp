#include "TonInterpreter.h"

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

std::any TonInterpreter::visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) {
    std::string instrumentOrSoundId = ctx->ID()->getText();
    std::any arg1 = visit(ctx->expr(0));
    std::any arg2 = visit(ctx->expr(1));

    // TODO returning just instrument id for now. Need Sound class for further work
    return instrumentOrSoundId;
}

std::any TonInterpreter::visitStringValExpr(TonParser::StringValExprContext *ctx) {
    std::string rawString = ctx->STRING_VAL()->getText();
    return rawString.substr(1, rawString.length() - 2);
}

std::any TonInterpreter::visitNoteValExpr(TonParser::NoteValExprContext *ctx) {
    return ctx->NOTE_VAL()->getText();
}

std::any TonInterpreter::visitIntValExpr(TonParser::IntValExprContext *ctx) {
    return std::stoi(ctx->INT_VAL()->getText());
}
