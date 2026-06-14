#pragma once
#include "TonBaseListener.h"
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

        void exitVarDecl(TonParser::VarDeclContext *ctx) override;
        void exitAssignment(TonParser::AssignmentContext *ctx) override;
        void exitTargetExpr(TonParser::TargetExprContext *ctx) override;
        void enterFuncDef(TonParser::FuncDefContext *ctx) override;
        void exitFuncDef(TonParser::FuncDefContext *ctx) override;
        void exitReturnStat(TonParser::ReturnStatContext *ctx) override;

        virtual void enterLoopStat(TonParser::LoopStatContext *ctx) override;
        virtual void exitLoopStat(TonParser::LoopStatContext *ctx) override;
        void exitArrayOpStat(TonParser::ArrayOpStatContext *ctx) override;
};
