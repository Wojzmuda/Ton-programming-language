#include "TonDeclarationListener.h"
#include <string>
#include <stdexcept>

void TonDeclarationListener::enterVarDecl(TonParser::VarDeclContext *ctx){
    std::string varName = ctx->ID()->getText();
    std::string typeName = ctx->type()->getText();

    int currentLine = ctx-> getStart()->getLine();

    if(declaredTypes.find(varName) != declaredTypes.end()){
        int prevLine = declarationLines[varName];
        throw std::runtime_error("Error in line " + std::to_string(currentLine) + 
                                 ": Variable redeclaration '" + varName + 
                                 "'. Previous declaration is on line " + std::to_string(prevLine) + ".");
    }

    declaredTypes[varName] = typeName;
    declarationLines[varName] = currentLine;
}

void TonDeclarationListener::enterTrackDecl(TonParser::TrackDeclContext *ctx){
    std::string trackName = ctx->ID(1)->getText();
    int currentLine = ctx->getStart()->getLine();
    if (declaredTypes.find(trackName) != declaredTypes.end()) {
        int previousLine = declarationLines[trackName];
        
        throw std::runtime_error("Error in line " + std::to_string(currentLine) + 
                                 ": Variable redeclaration '" + trackName + 
                                 "'. Previous declaration is on line " + std::to_string(previousLine) + ".");
    }

    declaredTypes[trackName] = "TRACK"; 
    declarationLines[trackName] = currentLine;
}