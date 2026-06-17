#pragma once
#include "TonBaseListener.h"
#include"core/Scope.h"
#include <memory>
#include <string>

class TonDeclarationListener : public TonBaseListener {
    private:
        std::shared_ptr<Scope<int>> currentScope;
        int loopLevel = 0;
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


        void exitArrayOpStat(TonParser::ArrayOpStatContext *ctx) override;

        void enterLoopStat(TonParser::LoopStatContext *ctx) override;
        void exitLoopStat(TonParser::LoopStatContext *ctx) override;
        void enterUntilStat(TonParser::UntilStatContext *ctx) override;
        void exitUntilStat(TonParser::UntilStatContext *ctx) override;
        void enterBreakStat(TonParser::BreakStatContext *ctx) override;
        void enterContinueStat(TonParser::ContinueStatContext *ctx) override;

        void exitDebugDumpStat(TonParser::DebugDumpStatContext *ctx) override;
};
