#include "typechecker/TonTypeChecker.h"

std::any TonTypeChecker::visitTargetExpr(TonParser::TargetExprContext *ctx) {
    std::string baseVarName = ctx->target()->ID(0)->getText();
    std::string type = currentScope->resolveType(baseVarName);
    if (ctx->target()->ID().size() > 1) {
        return std::string("SOUND");
    }
    return type;
}

std::any TonTypeChecker::visitParensExpr(TonParser::ParensExprContext *ctx) {
    return visit(ctx->expr());
}

std::any TonTypeChecker::visitNotExpr(TonParser::NotExprContext *ctx) {
    std::string type = std::any_cast<std::string>(visit(ctx->expr()));
    if (type != "BOOL") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) +
                                 ": NOT operator requires a BOOL. Given: " + type);
    }
    return std::string("BOOL");
}


std::any TonTypeChecker::visitAndExpr(TonParser::AndExprContext *ctx) { return std::string("BOOL"); }
std::any TonTypeChecker::visitOrExpr(TonParser::OrExprContext *ctx) { return std::string("BOOL"); }
std::any TonTypeChecker::visitRelationalExpr(TonParser::RelationalExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    // TODO for now we are letting INT and NUMERICAL to be compared.
    // Later on we should delete in because there will be implicit type conversion (int -> num)
    if (left != right && !( (left == "INT" || left == "NUMERICAL") && (right == "INT" || right == "NUMERICAL") )) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + ": Cannot compare " + left + " with " + right);
    }
    return std::string("BOOL");
}

std::any TonTypeChecker::visitUnaryExpr(TonParser::UnaryExprContext *ctx) {
    std::string type = std::any_cast<std::string>(visit(ctx->expr()));
    if (type != "INT" && type != "NUMERICAL") {
        throw std::runtime_error("Type Error: Unary signs (+, -) require INT or NUMERICAL. Given: " + type);
    }
    return type;
}

std::any TonTypeChecker::visitMulDivExpr(TonParser::MulDivExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    if ((left == "INT" || left == "NUMERICAL") && (right == "INT" || right == "NUMERICAL")) {
        return (left == "NUMERICAL" || right == "NUMERICAL") ? std::string("NUMERICAL") : std::string("INT");
    }

    throw std::runtime_error("Type Error: Multiplication/Division requires INT or NUMERICAL.");
}

std::any TonTypeChecker::visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    if ((left == "INT" || left == "NUMERICAL") && (right == "INT" || right == "NUMERICAL")) {
        return (left == "NUMERICAL" || right == "NUMERICAL") ? std::string("NUMERICAL") : std::string("INT");
    }
    if (left == "SOUND" && right == "SOUND") {
        return std::string("SOUND");
    }
    if (left == "STRING" && right == "STRING") {
        return std::string("STRING");
    }

    throw std::runtime_error("Type Error: Cannot apply +/- to " + left + " and " + right);
}

std::any TonTypeChecker::visitConcatExpr(TonParser::ConcatExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (left == "SOUND" && right == "SOUND") { return std::string("SOUND"); }
    if (left == "STRING" && right == "STRING") { return std::string("STRING"); }

    throw std::runtime_error("Type Error: Concat operator (&) requires SOUND or STRING on both sides.");
}

std::any TonTypeChecker::visitArrayExpr(TonParser::ArrayExprContext *ctx) { return std::string("ARRAY"); }
std::any TonTypeChecker::visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) { return std::string("INT"); }
std::any TonTypeChecker::visitIsolateExpr(TonParser::IsolateExprContext *ctx) { return std::string("SOUND"); }


std::any TonTypeChecker::visitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) { 
    for (auto exprCtx : ctx->expr()) {
        visit(exprCtx);
    }
    std::string funcName = ctx->ID()->getText();
    std::string returnType = currentScope->resolveType(funcName);
    return returnType;
}

// TODO to be implemented
std::any TonTypeChecker::visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) {
    std::string arg1Type = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string arg2Type = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (arg1Type != "NOTE") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": First argument of CreateSound must be a NOTE. Given: " + arg1Type);
    }
    
    if (arg2Type != "INT") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Second argument (duration) of CreateSound must be an INT. Given: " + arg2Type);
    }
    return std::string("SOUND");
}

std::any TonTypeChecker::visitTrackEventExpr(TonParser::TrackEventExprContext *ctx) {
    std::string soundType = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string timeType = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (soundType != "SOUND") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Track event requires a SOUND. Given: " + soundType);
    }
    
    if (timeType != "INT") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Track event AT clause requires an INT (time). Given: " + timeType);
    }

    // Zwracamy typ "TRACK_EVENT" (wcześniej miałeś "SOUND", ale Interpreter używa struktury TrackEvent, 
    // więc bezpieczniej jest rozróżnić typ EVENT od czystego SOUND).
    return std::string("TRACK_EVENT"); 
}

std::any TonTypeChecker::visitIndexExpr(TonParser::IndexExprContext *ctx) { return std::string("UNKNOWN"); }
std::any TonTypeChecker::visitSliceExpr(TonParser::SliceExprContext *ctx) { return std::string("UNKNOWN"); }
