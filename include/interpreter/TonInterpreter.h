#pragma once



#include "TonBaseVisitor.h"
#include "core/Timeline.h"
#include "core/Scope.h"

#include <filesystem>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <any>
#include <vector>
#include <exception>
#include <cstdlib>

struct tsf;

class ReturnException : public std::exception{
public:
    std::any returnValue;
    ReturnException(std::any val) : returnValue(std::move(val)){}
};
class TonInterpreter: public TonBaseVisitor {
private:
    bool doTypesMatch(const std::string& expectedTypeName, const std::any& val);
    std::string findSoundFontPath();
    tsf* soundFont = nullptr;
    std::unordered_map<std::string, Instrument> loadedInstruments;
    static const std::unordered_map<std::string, int> SAMPLE_INSTRUMENTS;
    static const std::unordered_set<std::string> SYNTHS;

    std::shared_ptr<Scope<std::any>> currentScope;
    static constexpr int MAX_STACK_DEPTH = 1000;
    int currentStackDepth;

    struct BreakException : public std::exception {};
    struct ContinueException : public std::exception {};

    std::any executeFunctionLogic(const std:: string& funcName, const std::vector<TonParser::ExprContext*>& argsCtx);
    void validateStackDepth();

public:
    TonInterpreter();
    ~TonInterpreter();

    std::any visitProgram(TonParser::ProgramContext *ctx) override;
    std::any visitBlock(TonParser::BlockContext *ctx) override;
    std::any visitStatement(TonParser::StatementContext *ctx) override;
    std::any visitVarDecl(TonParser::VarDeclContext *ctx) override;

    std::any visitTrackDecl(TonParser::TrackDeclContext *ctx) override;

    std::any visitAssignment(TonParser::AssignmentContext *ctx) override;
    std::any visitArrayExpr(TonParser::ArrayExprContext *ctx) override;
    std::any visitTrackEventExpr(TonParser::TrackEventExprContext *ctx) override;
    std::any visitShoutStat(TonParser::ShoutStatContext *ctx) override;
    std::any visitSaveStat(TonParser::SaveStatContext *ctx) override;
    std::any visitCharValExpr(TonParser::CharValExprContext *ctx) override;
    std::any visitTargetExpr(TonParser::TargetExprContext *ctx) override;

    std::any visitHeader(TonParser::HeaderContext *ctx) override;
    std::any visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) override;
    std::any visitStringValExpr(TonParser::StringValExprContext *ctx) override;
    std::any visitNoteValExpr(TonParser::NoteValExprContext *ctx) override;
    std::any visitIntValExpr(TonParser::IntValExprContext *ctx) override;
    std::any visitAudioOpStat(TonParser::AudioOpStatContext *ctx) override;
    std::any visitIsolateExpr(TonParser::IsolateExprContext *ctx) override;

    // logic operations
    std::any visitBoolValExpr(TonParser::BoolValExprContext *ctx) override;
    std::any visitNotExpr(TonParser::NotExprContext *ctx) override;
    std::any visitAndExpr(TonParser::AndExprContext *ctx) override;
    std::any visitOrExpr(TonParser::OrExprContext *ctx) override;
    std::any visitRelationalExpr(TonParser::RelationalExprContext *ctx) override;

    // bracketing
    std::any visitParensExpr(TonParser::ParensExprContext *ctx) override;

    // math
    std::any visitUnaryExpr(TonParser::UnaryExprContext *ctx) override;
    std::any visitMulDivExpr(TonParser::MulDivExprContext *ctx) override;
    std::any visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) override;
    std::any visitConcatExpr(TonParser::ConcatExprContext *ctx) override;
    std::any visitNumValExpr(TonParser::NumValExprContext *ctx) override;

    std::any visitLoopStat(TonParser::LoopStatContext *ctx) override;
    std::any visitUntilStat(TonParser::UntilStatContext *ctx) override;
    std::any visitBreakStat(TonParser::BreakStatContext *ctx) override;
    std::any visitContinueStat(TonParser::ContinueStatContext *ctx) override;
    //functions
    std::any visitFuncDef(TonParser::FuncDefContext *ctx) override;
    std::any visitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) override;
    std::any visitCallStat(TonParser::CallStatContext *ctx) override;
    std::any visitReturnStat(TonParser::ReturnStatContext *ctx) override;

    std::any visitIfStat(TonParser::IfStatContext *ctx) override;

    std::any visitIndexExpr(TonParser::IndexExprContext *ctx) override;
    std::any visitSliceExpr(TonParser::SliceExprContext *ctx) override;
    std::any visitArrayOpStat(TonParser::ArrayOpStatContext *ctx) override;
    std::any visitPopExpr(TonParser::PopExprContext *ctx) override;

    std::any visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) override;
};
