#pragma once
#include "antlr4_generated/TonBaseListener.h"
#include"core/Scope.h"
#include <memory>
#include <string>

class TonDeclarationListener : public TonBaseListener {
    private:
        std::shared_ptr<Scope<int>> currentScope;
    public:
        TonDeclarationListener(){
            currentScope = std::make_shared<Scope<int>>();
        }

        void enterVarDecl(TonParser::VarDeclContext *ctx) override;
        void enterTrackDecl(TonParser::TrackDeclContext *ctx) override;
        void enterBlock(TonParser::BlockContext *ctx) override;
        void exitBlock(TonParser::BlockContext *ctx) override;
};