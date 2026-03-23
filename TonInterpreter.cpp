#include "TonInterpreter.h"

std::any TonInterpreter::visitProgram(TonParser::ProgramContext *ctx){
    return visitChildren(ctx);
}

std::any TonInterpreter::visitBlock(TonParser::BlockContext *ctx) {
    return visitChildren(ctx);
}

std::any TonInterpreter::visitStatement(TonParser::StatementContext *ctx) {
    return visitChildren(ctx);
}

std::any TonInterpreter::visitVarDecl(TonParser::VarDeclContext *ctx){
    std::string varName = ctx->ID()->getText();
    std::any value = visit(ctx->expr());
    memory[varName] = value;
    return value;
}