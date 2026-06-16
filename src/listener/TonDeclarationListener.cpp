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

        if (expectedType != actualType && actualType != "UNKNOWN") {
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
    auto targetNode = ctx->target();
    std::string varName = targetNode->ID(0)->getText();

    if (!currentScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Cannot assign to undefined variable '" + varName + "'.");
    }
    // std::string expectedType = currentScope->resolveType(varName);
    TonTypeChecker typeChecker(currentScope);
    std::any result = typeChecker.visit(ctx->expr());
    std::string actualType = std::any_cast<std::string>(result);

    // --- SCENARIUSZ A: Zwykłe przypisanie (np. tempo <- 120) ---
    if (targetNode->ID().size() == 1) {
        std::string expectedType = currentScope->resolveType(varName);
        if (expectedType != actualType && actualType != "UNKNOWN") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Cannot assign " + actualType + " to variable '" + varName + "' of type " + expectedType + ".");
        }
        return; // Zwykłe przypisanie pomyślne!
    }

    // --- SCENARIUSZ B: Przypisanie do tracka w TIMELINE (np. mySong.bassline <- ...) ---
    std::string expectedBaseType = currentScope->resolveType(varName);
    if (expectedBaseType != "TIMELINE" ) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                 ": '" + varName + "' is not a TIMELINE.");
    }

    // SCENARIUSZ B1: Przypisanie do konkretnego aliasu (mySong.bassline."start" <- beep)
    if (targetNode->STRING_VAL()) {
        if (actualType != "SOUND" && actualType != "TRACK_EVENT" && actualType != "UNKNOWN") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Can only assign SOUND or TRACK_EVENT to a specific alias. Given: " + actualType);
        }
    }

    // SCENARIUSZ B2: Całościowe przypisanie na ścieżkę (mySong.bassline <- [bass AT 0])
    else {
        if (actualType != "ARRAY" && actualType != "TRACK_EVENT" && actualType != "UNKNOWN") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Track assignment requires an ARRAY of events or a single TRACK_EVENT. Given: " + actualType);
        }
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

void TonDeclarationListener::enterFuncDef(TonParser::FuncDefContext *ctx) {
    std::string funcName = ctx->ID(0)->getText();
    std::string returnType = ctx->type(0)->getText();
    int currentLine = ctx->getStart()->getLine();
    currentScope->define(funcName, returnType, currentLine);
    currentScope = std::make_shared<Scope<int>>(currentScope);
    for (size_t i = 1; i < ctx->ID().size(); ++i) {
        std::string paramName = ctx->ID(i)->getText();
        std::string paramType = ctx->type(i)->getText();
        currentScope->define(paramName, paramType, currentLine);
    }
}

void TonDeclarationListener::exitReturnStat(TonParser::ReturnStatContext *ctx) {
    if (ctx->expr()) {
        TonTypeChecker typeChecker(currentScope);
        typeChecker.visit(ctx->expr()); 
    }
}

void TonDeclarationListener::exitFuncDef(TonParser::FuncDefContext *ctx) {
    if (currentScope->parent) {
        currentScope = currentScope->parent;
    }
}

void TonDeclarationListener::enterBlock(TonParser::BlockContext *ctx)
{
    bool isFuncBody = dynamic_cast<TonParser::FuncDefContext*>(ctx->parent) != nullptr;
    bool isLoopBody = dynamic_cast<TonParser::LoopStatContext*>(ctx->parent) != nullptr;
    if (!isFuncBody && !isLoopBody) {
        currentScope = std::make_shared<Scope<int>>(currentScope);
    }
}

void TonDeclarationListener::exitBlock(TonParser::BlockContext *ctx){
    bool isFuncBody = dynamic_cast<TonParser::FuncDefContext*>(ctx->parent) != nullptr;
    bool isLoopBody = dynamic_cast<TonParser::LoopStatContext*>(ctx->parent) != nullptr;
    if (!isFuncBody && !isLoopBody) {
        if (currentScope->parent) {
            currentScope = currentScope->parent;
        }
    }
}

void TonDeclarationListener::enterLoopStat(TonParser::LoopStatContext *ctx) {
    currentScope = std::make_shared<Scope<int>>(currentScope);

    int currentLine = ctx->getStart()->getLine();
    if (ctx->FROM() || ctx->ASSIGN()) {
        std::string varName = ctx->ID()->getText();
        

        if (ctx->type() != nullptr) {
            std::string typeName = ctx->type()->getText();
            currentScope->define(varName, typeName, currentLine);
        } else {
            if (!currentScope->parent || !currentScope->parent->exists(varName)) {
                throw std::runtime_error("Validation Error in line " + std::to_string(currentLine) + 
                         ": Variable '" + varName + "' used in loop declaration is not defined.");
            }
        }
    }
}

void TonDeclarationListener::exitLoopStat(TonParser::LoopStatContext *ctx) {
    if (currentScope->parent) {
        currentScope = currentScope->parent;
    }
}

void TonDeclarationListener::exitArrayOpStat(TonParser::ArrayOpStatContext *ctx) {
    std::string varName = ctx->ID()->getText();

    if (!currentScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Variable '" + varName + "' is not defined.");
    }

    std::string targetType = currentScope->resolveType(varName);
    if (targetType != "ARRAY") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                 ": Cannot perform array operations on type " + targetType + ".");
    }

    // Jeśli to operacja APPEND, sprawdzamy też wyrażenie (np. zeby wyłapać błąd w 'APPEND 10 + "tekst" TO lista')
    if (ctx->APPEND()) {
        TonTypeChecker typeChecker(currentScope);
        typeChecker.visit(ctx->expr());
    }
}
