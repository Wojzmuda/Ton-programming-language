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
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
        ": Unary signs (+, -) require INT or NUMERICAL. Given: " + type);
    }
    return type;
}

std::any TonTypeChecker::visitMulDivExpr(TonParser::MulDivExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (left == "SOUND" || right == "SOUND") {
        if (ctx->DIV_OP() != nullptr) {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Type Error in line " + std::to_string(line) + 
               ": Cannot divide a SOUND. Use multiplication with fractions (e.g. SOUND * 0.5) instead.");
        }
        if (left == "SOUND" && (right == "INT" || right == "NUMERICAL")) {
            return std::string("SOUND");
        }
        if (right == "SOUND" && (left == "INT" || left == "NUMERICAL")) {
            return std::string("SOUND");
        }
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
            ": A SOUND can only be multiplied by an INT or NUMERICAL.");
    }
    
    if ((left == "INT" || left == "NUMERICAL") && (right == "INT" || right == "NUMERICAL")) {
        return (left == "NUMERICAL" || right == "NUMERICAL") ? std::string("NUMERICAL") : std::string("INT");
    }
    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Type Error in line " + std::to_string(line) + 
        ": Multiplication/Division requires INT or NUMERICAL.");
}

std::any TonTypeChecker::visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    if ((left == "INT" || left == "NUMERICAL") && (right == "INT" || right == "NUMERICAL")) {
        return (left == "NUMERICAL" || right == "NUMERICAL") ? std::string("NUMERICAL") : std::string("INT");
    }
    if (ctx->PLUS()) {
        if (left == "SOUND" && right == "SOUND") {
            return std::string("SOUND");
        }
        if (left == "STRING" && right == "STRING") {
            return std::string("STRING");
        }
    }
    size_t line = ctx->getStart()->getLine();
    std::string op = ctx->PLUS() ? "+" : "-";
    throw std::runtime_error("Type Error in line " + std::to_string(line) + 
        ": Cannot apply operator " + op + " to " + left + " and " + right);
}

std::any TonTypeChecker::visitConcatExpr(TonParser::ConcatExprContext *ctx) {
    std::string left = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string right = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (left == "SOUND" && right == "SOUND") { return std::string("SOUND"); }
    if (left == "STRING" && right == "STRING") { return std::string("STRING"); }

    size_t line = ctx->getStart()->getLine();
    throw std::runtime_error("Type Error in line " + std::to_string(line) + 
    ": Concat operator (&) requires SOUND or STRING on both sides.");
}

std::any TonTypeChecker::visitArrayExpr(TonParser::ArrayExprContext *ctx) { 
    for (auto exprCtx : ctx->expr()) {
        visit(exprCtx);
    }
    return std::string("ARRAY"); 
}

std::any TonTypeChecker::visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) { return std::string("INT"); }
std::any TonTypeChecker::visitIsolateExpr(TonParser::IsolateExprContext *ctx) { return std::string("SOUND"); }


std::any TonTypeChecker::visitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) { 
    for (auto exprCtx : ctx->expr()) {
        visit(exprCtx);
    }
    std::string funcName = ctx->ID()->getText();

    if (!currentScope->exists(funcName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) +
                                 ": Function '" + funcName + "' is not defined.");
    }
    std::string returnType = currentScope->resolveType(funcName);
    return returnType;
}

std::any TonTypeChecker::visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) {
    std::string arg1Type = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string arg2Type = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (arg1Type != "NOTE") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) +
                                 ": First argument of CreateSound must be a NOTE. Given: " + arg1Type);
    }
    
    if (arg2Type != "INT") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Line " + std::to_string(line) +
                                 ": Second argument (duration) of CreateSound must be an INT. Given: " + arg2Type);
    }

    if (ctx->expr().size() > 2) {
        std::string arg3Type = std::any_cast<std::string>(visit(ctx->expr(2)));

        if (arg3Type != "INT" && arg3Type != "NUMERICAL") {
            size_t line = ctx->getStart()->getLine();
            throw std::runtime_error("Line " + std::to_string(line) +
                                     ": Third argument (volume) of SOUND must be INT or NUMERICAL. Given: " + arg3Type);
        }
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
    return std::string("TRACK_EVENT"); 
}

std::any TonTypeChecker::visitIndexExpr(TonParser::IndexExprContext *ctx) {
    std::string baseType = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string indexType = std::any_cast<std::string>(visit(ctx->expr(1)));

    if (indexType != "INT") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Index must be an INT. Given: " + indexType);
    }

    if (baseType != "ARRAY" && baseType != "STRING") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Cannot index type " + baseType + ".");
    }

    if (baseType == "STRING") {
        return std::string("CHAR"); 
    }

    // 4. Jeśli to ARRAY, zwracamy UNKNOWN.
    // Dlaczego? Ponieważ w Ton tablice mogą trzymać mieszane typy [1, "tekst", note].
    // Statycznie (przed uruchomieniem) nie zgadniemy, jaki typ kryje się pod indeksem [2].
    return std::string("UNKNOWN"); 
}


std::any TonTypeChecker::visitSliceExpr(TonParser::SliceExprContext *ctx) {
    std::string baseType = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string startType = std::any_cast<std::string>(visit(ctx->expr(1)));
    std::string endType = std::any_cast<std::string>(visit(ctx->expr(2)));

    if (startType != "INT" || endType != "INT") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Slice indices must be INT.");
    }

    if (baseType != "ARRAY" && baseType != "STRING") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Cannot slice type " + baseType + ".");
    }

    return baseType; 
}
