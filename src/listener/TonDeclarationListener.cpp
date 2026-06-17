#include "listener/TonDeclarationListener.h"
#include "typechecker/TonTypeChecker.h"
#include <string>
#include <stdexcept>
#include "diagnostics/Diagnostics.h"

static std::shared_ptr<Scope<int>> resolveElderScope(std::shared_ptr<Scope<int>> currentScope, int elderCount, size_t line) {
    auto targetScope = currentScope;
    for (int i = 0; i < elderCount; ++i) {
        if (targetScope->parent != nullptr) {
            targetScope = targetScope->parent;
        } else {
            throw std::runtime_error("Error in line " + std::to_string(line) + ": 'ELDER::' reached beyond global scope.");
        }
    }
    return targetScope;
}


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

        if (!typeChecker.isConvertible(expectedType, actualType)) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Cannot assign " + actualType + " to a variable of type " + expectedType + ".");
        }
    }
}

void TonDeclarationListener::enterTrackDecl(TonParser::TrackDeclContext *ctx){
    int elderCount = ctx->target() -> elderRef().size();
    auto targetScope = resolveElderScope(currentScope, elderCount, ctx->getStart()->getLine());  
    
    std::string timelineName = ctx->target()->ID(0)->getText(); 
    std::string trackName = ctx->ID()->getText(); 

    int currentLine = ctx->getStart()->getLine();
    if (targetScope->existsLocally(trackName)) { 
        int previousLine = targetScope->get(trackName); 

        throw std::runtime_error("Error in line " + std::to_string(currentLine) + 
                                 ": Variable redeclaration '" + trackName + 
                                 "'. Previous declaration is on line " + std::to_string(previousLine) + ".");
    }

    targetScope->define(trackName, "TRACK", currentLine); 
}

void TonDeclarationListener::exitAssignment(TonParser::AssignmentContext *ctx) {
    auto targetNode = ctx->target();
    std::string varName = targetNode->ID(0)->getText();

    int elderCount = targetNode->elderRef().size();
    auto targetScope = resolveElderScope(currentScope, elderCount, ctx->getStart()->getLine());

    if (!targetScope->exists(varName)) { 
        size_t line = ctx->getStart()->getLine();
        auto visibleNames = targetScope->getAllVisibleNames();
        std::string suggestion = suggestSimilarName(varName, visibleNames);
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Cannot assign to undefined variable '" + varName + "'."+ suggestion);
    }
    
    TonTypeChecker typeChecker(currentScope); 
    std::any result = typeChecker.visit(ctx->expr());
    std::string actualType = std::any_cast<std::string>(result);

    // --- SCENARIUSZ A: Zwykłe przypisanie ---
    if (targetNode->ID().size() == 1) {
        std::string expectedType = targetScope->resolveType(varName); 
        if (expectedType != actualType && actualType != "UNKNOWN") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Cannot assign " + actualType + " to variable '" + varName + "' of type " + expectedType + ".");
        }
        return; 
    }

    // --- SCENARIUSZ B: Przypisanie do tracka w TIMELINE ---
    std::string expectedBaseType = targetScope->resolveType(varName); 
    if (expectedBaseType != "TIMELINE" ) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                 ": '" + varName + "' is not a TIMELINE.");
    }

    if (targetNode->STRING_VAL()) {
        if (actualType != "SOUND" && actualType != "TRACK_EVENT" && actualType != "UNKNOWN") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Can only assign SOUND or TRACK_EVENT to a specific alias. Given: " + actualType);
        }
    } else {
        if (actualType != "ARRAY" && actualType != "TRACK_EVENT" && actualType != "UNKNOWN") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                     ": Track assignment requires an ARRAY of events or a single TRACK_EVENT. Given: " + actualType);
        }
    }
}

void TonDeclarationListener::exitTargetExpr(TonParser::TargetExprContext *ctx) {
    std::string varName = ctx->target()->ID(0)->getText();

    int elderCount = ctx->target()->elderRef().size();
    auto targetScope = resolveElderScope(currentScope, elderCount, ctx->getStart()->getLine());

    if (!targetScope->exists(varName)) { 
        auto visibleNames = targetScope->getAllVisibleNames();
        std::string suggestion = suggestSimilarName(varName, visibleNames);
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Variable '" + varName + "' is not defined." + suggestion);
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
    loopLevel++;
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
    loopLevel--; 
    if (currentScope->parent) {
        currentScope = currentScope->parent;
    }
}

void TonDeclarationListener::exitArrayOpStat(TonParser::ArrayOpStatContext *ctx) {
    std::string varName = ctx->target()->ID(0)->getText();
    int elderCount = ctx->target()->elderRef().size();
    auto targetScope = resolveElderScope(currentScope, elderCount, ctx->getStart()->getLine());

    if (!targetScope->exists(varName)) { 
        size_t line = ctx->getStart()->getLine();
        auto visibleNames = targetScope->getAllVisibleNames();
        std::string suggestion = suggestSimilarName(varName, visibleNames);
        throw std::runtime_error("Error in line " + std::to_string(line) +
                                 ": Variable '" + varName + "' is not defined."+suggestion);
    }

    std::string targetType = targetScope->resolveType(varName); 
    if (targetType != "ARRAY") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                 ": Cannot perform array operations on type " + targetType + ".");
    }
    
    if (ctx->APPEND()) {
        TonTypeChecker typeChecker(currentScope); 
        typeChecker.visit(ctx->expr());
    }
}
void TonDeclarationListener::enterUntilStat(TonParser::UntilStatContext *ctx) {
    loopLevel++;
}

void TonDeclarationListener::exitUntilStat(TonParser::UntilStatContext *ctx) {
    loopLevel--;
}

void TonDeclarationListener::enterBreakStat(TonParser::BreakStatContext *ctx) {
    if (loopLevel == 0) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Validation Error in line " + std::to_string(line) + 
                                 ": '!break' statement is not allowed outside of a loop.");
    }
}

void TonDeclarationListener::enterContinueStat(TonParser::ContinueStatContext *ctx) {
    if (loopLevel == 0) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Validation Error in line " + std::to_string(line) + 
                                 ": '!continue' statement is not allowed outside of a loop.");
    }
}

void TonDeclarationListener::exitDebugDumpStat(TonParser::DebugDumpStatContext *ctx) {
}
