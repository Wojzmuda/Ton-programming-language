#include "listener/TonDeclarationListener.h"
#include "typechecker/TonTypeChecker.h"
#include <string>
#include <stdexcept>

void TonDeclarationListener::enterVarDecl(TonParser::VarDeclContext *ctx){
    std::string varName = ctx->ID()->getText();
    std::string typeName = ctx->type()->getText();

    int currentLine = ctx->getStart()->getLine();

    if(currentScope->existsLocally(varName)){
        int prevLine = currentScope->get(varName);
        throw std::runtime_error("Error in line " + std::to_string(currentLine) + 
                                 ": Variable redeclaration '" + varName + 
                                 "'. Previous declaration is on line " + std::to_string(prevLine) + ".");
    }

    currentScope->define(varName, typeName, currentLine);
}

void TonDeclarationListener::exitVarDecl(TonParser::VarDeclContext *ctx) {
    if (ctx->expr() != nullptr) {
        std::string expectedType = ctx->type()->getText();
        TonTypeChecker typeChecker(currentScope);
        std::any result = typeChecker.visit(ctx->expr());
        std::string actualType = std::any_cast<std::string>(result);

        if (expectedType != actualType) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Cannot assign " + actualType + " to a variable of type " + expectedType + ".");
        }
    }
}

void TonDeclarationListener::enterTrackDecl(TonParser::TrackDeclContext *ctx){
    std::string trackName = ctx->ID(1)->getText();
    int currentLine = ctx->getStart()->getLine();
    if (currentScope->existsLocally(trackName)) {
        int previousLine = currentScope->get(trackName);
        
        throw std::runtime_error("Error in line " + std::to_string(currentLine) + 
                                 ": Variable redeclaration '" + trackName + 
                                 "'. Previous declaration is on line " + std::to_string(previousLine) + ".");
    }

    currentScope->define(trackName, "TRACK", currentLine);
}

void TonDeclarationListener::exitAssignment(TonParser::AssignmentContext *ctx) {
    std::string varName = ctx->target()->ID(0)->getText();

    if (!currentScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Cannot assign to undefined variable '" + varName + "'.");
    }
    std::string expectedType = currentScope->resolveType(varName);
    TonTypeChecker typeChecker(currentScope);
    std::any result = typeChecker.visit(ctx->expr());
    std::string actualType = std::any_cast<std::string>(result);
    if (expectedType != actualType) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                 ": Cannot assign " + actualType + " to variable '" + varName + "' of type " + expectedType + ".");
    }
}

void TonDeclarationListener::exitTargetExpr(TonParser::TargetExprContext *ctx) {
    std::string varName = ctx->target()->ID(0)->getText();

    if (!currentScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Variable '" + varName + "' is not defined.");
    }
}

void TonDeclarationListener::enterBlock(TonParser::BlockContext *ctx){
    currentScope = std::make_shared<Scope<int>>(currentScope);
}

void TonDeclarationListener::exitBlock(TonParser::BlockContext *ctx){
    if(currentScope-> parent){
        currentScope = currentScope->parent;
    }
}
