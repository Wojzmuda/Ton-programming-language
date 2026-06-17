#pragma once

#include <map>
#include <string>
#include <any>
#include <vector>
#include <memory>

#include "TonBaseVisitor.h"
#include "core/Scope.h"

class TonTypeChecker : public TonBaseVisitor
{
private:
    std::shared_ptr<Scope<int>> currentScope;

    // this one is crazy: It takes any number of strings and
    // returns true if any of them equals to "UNKNOWN", else otherwise.
    template<typename... Args>
    bool hasUnknown(const Args&... types) {
        return ((types == "UNKNOWN") || ...);
    }



public:

    bool isConvertible(const std::string& expected, const std::string& given) {
        if (expected == given || given == "UNKNOWN" || expected == "UNKNOWN") {
            return true;
        }
        if ((expected == "INT" && given == "NUMERICAL") ||
            (expected == "NUMERICAL" && given == "INT")) {
            return true;
        }
        if ((expected == "INT" && given == "BOOL") ||
            (expected == "BOOL" && given == "INT")) {
            return true;
        }
        if ((expected == "NUMERICAL" && given == "BOOL") ||
            (expected == "BOOL" && given == "NUMERICAL")) {
            return true;
        }
        return false;
    }

    TonTypeChecker(std::shared_ptr<Scope<int>> scope) : currentScope{scope} { };

    std::any visitIntValExpr(TonParser::IntValExprContext *ctx) override { return std::string("INT"); }
    std::any visitNumValExpr(TonParser::NumValExprContext *ctx) override { return std::string("NUMERICAL"); }
    std::any visitBoolValExpr(TonParser::BoolValExprContext *ctx) override { return std::string("BOOL"); }
    std::any visitCharValExpr(TonParser::CharValExprContext *ctx) override { return std::string("CHAR"); }
    std::any visitStringValExpr(TonParser::StringValExprContext *ctx) override { return std::string("STRING"); }
    std::any visitNoteValExpr(TonParser::NoteValExprContext *ctx) override { return std::string("NOTE"); }
    std::any visitEmptySoundExpr(TonParser::EmptySoundExprContext *ctx) override { return std::string("SOUND"); }

    std::any visitTargetExpr(TonParser::TargetExprContext *ctx) override;

    // 3. Nawiasy
    std::any visitParensExpr(TonParser::ParensExprContext *ctx) override;

    // 4. Operatory logiczne i relacyjne
    std::any visitNotExpr(TonParser::NotExprContext *ctx) override;
    std::any visitAndExpr(TonParser::AndExprContext *ctx) override;
    std::any visitOrExpr(TonParser::OrExprContext *ctx) override;
    std::any visitRelationalExpr(TonParser::RelationalExprContext *ctx) override;

    // 5. Operatory matematyczne i muzyczne
    std::any visitUnaryExpr(TonParser::UnaryExprContext *ctx) override;
    std::any visitMulDivExpr(TonParser::MulDivExprContext *ctx) override;
    std::any visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) override;
    std::any visitConcatExpr(TonParser::ConcatExprContext *ctx) override;

    // 6. Zaawansowane struktury (Na razie mogą zwracać typ domyślny lub być zaimplementowane później)
    std::any visitArrayExpr(TonParser::ArrayExprContext *ctx) override;
    std::any visitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) override;
    std::any visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) override;
    std::any visitTrackEventExpr(TonParser::TrackEventExprContext *ctx) override;
    std::any visitIndexExpr(TonParser::IndexExprContext *ctx) override;
    std::any visitSliceExpr(TonParser::SliceExprContext *ctx) override;
    std::any visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) override;
    std::any visitIsolateExpr(TonParser::IsolateExprContext *ctx) override;

    std::any visitPopExpr(TonParser::PopExprContext *ctx) override;

    std::any visitArrayOpStat(TonParser::ArrayOpStatContext *ctx) override;
    std::any visitCastExpr(TonParser::CastExprContext *ctx) override;
};
