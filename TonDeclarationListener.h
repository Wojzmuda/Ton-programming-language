#pragma once
#include "antlr4_generated/TonBaseListener.h"
#include <map>
#include <string>

class TonDeclarationListener : public TonBaseListener {
    private:
        std::map<std::string, std::string>& declaredTypes;
        std::map<std::string, int>& declarationLines;
    public:
        TonDeclarationListener(std::map<std::string, std::string>& types, std::map<std::string, int>& lines) : declaredTypes(types), declarationLines(lines) {}

        void enterVarDecl(TonParser::VarDeclContext *ctx) override;
        void enterTrackDecl(TonParser::TrackDeclContext *ctx) override;
};