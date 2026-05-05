#include "listener/TonDeclarationListener.h"
#include <string>
#include <stdexcept>

void TonDeclarationListener::enterVarDecl(TonParser::VarDeclContext *ctx){
    std::string varName = ctx->ID()->getText();
    std::string typeName = ctx->type()->getText();

    int currentLine = ctx-> getStart()->getLine();

    if(currentScope->existsLocally(varName)){
        int prevLine = currentScope->get(varName);
        throw std::runtime_error("Error in line " + std::to_string(currentLine) + 
                                 ": Variable redeclaration '" + varName + 
                                 "'. Previous declaration is on line " + std::to_string(prevLine) + ".");
    }

    currentScope->define(varName, typeName, currentLine);
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

void TonDeclarationListener::enterBlock(TonParser::BlockContext *ctx){
    currentScope = std::make_shared<Scope<int>>(currentScope);
}

void TonDeclarationListener::exitBlock(TonParser::BlockContext *ctx){
    if(currentScope-> parent){
        currentScope = currentScope->parent;
    }
}