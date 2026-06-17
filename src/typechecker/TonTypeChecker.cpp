#include "typechecker/TonTypeChecker.h"

template <typename T>
static std::shared_ptr<Scope<T>> resolveElderScopeTC(std::shared_ptr<Scope<T>> currentScope, int elderCount, size_t line) {
    auto targetScope = currentScope;
    for (int i = 0; i < elderCount; ++i) {
        if (targetScope->parent != nullptr) {
            targetScope = targetScope->parent;
        } else {
            throw std::runtime_error("Type Error in line " + std::to_string(line) + ": 'ELDER::' reached beyond global scope.");
        }
    }
    return targetScope;
}


std::any TonTypeChecker::visitTargetExpr(TonParser::TargetExprContext *ctx) {
    int elderCount = ctx->target()->elderRef().size();
    auto targetScope = resolveElderScopeTC(currentScope, elderCount, ctx->getStart()->getLine());
    
    std::string baseVarName = ctx->target()->ID(0)->getText();
   
    std::string type = targetScope->resolveType(baseVarName); 
    
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

    if (hasUnknown(type)) {
        return std::string("BOOL");
    }

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

    if (hasUnknown(left, right)) {
        return std::string("BOOL");
    }
    // TODO for now we are letting INT and NUMERICAL to be compared.
    // Later on we should delete in because there will be implicit type conversion (int -> num)
    if (left == "SOUND" && right == "SOUND") {
        return std::string("BOOL");
    }
    if (left == "NOTE" && right == "NOTE") {
        return std::string("BOOL");
    }
    if (left != right && !( (left == "INT" || left == "NUMERICAL") && (right == "INT" || right == "NUMERICAL") )) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + ": Cannot compare " + left + " with " + right);
    }
    return std::string("BOOL");
}

std::any TonTypeChecker::visitUnaryExpr(TonParser::UnaryExprContext *ctx) {
    std::string type = std::any_cast<std::string>(visit(ctx->expr()));

    if (hasUnknown(type)) {
        return std::string("UNKNOWN");
    }

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

    if (hasUnknown(left, right)) {
        return std::string("UNKNOWN");
    }

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

    if (hasUnknown(left, right)) {
        return std::string("UNKNOWN");
    }

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

    if (hasUnknown(left, right)) {
        return std::string("UNKNOWN");
    }

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

std::any TonTypeChecker::visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) { 
    std::string type = std::any_cast<std::string>(visit(ctx->expr()));
    
    if (type != "STRING" && type != "ARRAY" && type != "SOUND" && 
        type != "TRACK" && type != "TIMELINE" && type != "UNKNOWN") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
            ": LENGTH operator requires STRING, ARRAY, SOUND, TRACK, or TIMELINE. Given: " + type);
    }
    
    return std::string("INT"); 
}
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
    std::string arg3Type = "UNKNOWN";
    if (ctx->expr().size() > 2) {
        std::string arg3Type = std::any_cast<std::string>(visit(ctx->expr(2)));
    }

    if (hasUnknown(arg1Type, arg2Type, arg3Type)) {
        return std::string("SOUND");
    }

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

    if (hasUnknown(soundType, timeType)) {
        return std::string("TRACK_EVENT");
    }

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

    if (hasUnknown(baseType, indexType)) {
        if (baseType == "STRING") {
            return std::string("CHAR"); // indexing a string
        }
        return std::string("UNKNOWN"); // indexing an array
    }

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
    return std::string("UNKNOWN"); 
}


std::any TonTypeChecker::visitSliceExpr(TonParser::SliceExprContext *ctx) {
    std::string baseType = std::any_cast<std::string>(visit(ctx->expr(0)));
    std::string startType = std::any_cast<std::string>(visit(ctx->expr(1)));
    std::string endType = std::any_cast<std::string>(visit(ctx->expr(2)));

    if (hasUnknown(baseType, startType, endType)) {
        return std::string("UNKNOWN");
    }

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
std::any TonTypeChecker::visitPopExpr(TonParser::PopExprContext *ctx) {
    int elderCount = ctx->target()->elderRef().size();
    auto targetScope = resolveElderScopeTC(currentScope, elderCount, ctx->getStart()->getLine());
    
    std::string varName = ctx->target()->ID(0)->getText();

    if (!targetScope->exists(varName)) { 
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Array '" + varName + "' is not defined.");
    }

    std::string targetType = targetScope->resolveType(varName);


    if (hasUnknown(targetType)) {
        return std::string("UNKNOWN");
    }
    if (targetType != "ARRAY") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": POP requires an ARRAY variable. Given: " + targetType);
    }

    return std::string("UNKNOWN");
}

std::any TonTypeChecker::visitArrayOpStat(TonParser::ArrayOpStatContext *ctx) {
    int elderCount = ctx->target()->elderRef().size();
    auto targetScope = resolveElderScopeTC(currentScope, elderCount, ctx->getStart()->getLine());
    
    std::string varName = ctx->target()->ID(0)->getText();

    if (!targetScope->exists(varName)) {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Array '" + varName + "' is not defined.");
    }

    std::string targetType = targetScope->resolveType(varName);
    if (targetType != "ARRAY") {
        size_t line = ctx->getStart()->getLine();
        throw std::runtime_error("Type Error in line " + std::to_string(line) + 
                                 ": Array operation requires an ARRAY variable. Given: " + targetType);
    }

    if (ctx->APPEND()) {
         visit(ctx->expr());
    }

    return {}; 
}



std::any TonTypeChecker::visitCastExpr(TonParser::CastExprContext *ctx) {

    std::string targetType = ctx->type()->getText();
    

    std::string exprType = std::any_cast<std::string>(visit(ctx->expr()));
    size_t line = ctx->getStart()->getLine();

    
    if (exprType == "UNKNOWN") {
        return targetType;
    }

    if (targetType == "INT") {
        if (exprType == "NUMERICAL" || exprType == "BOOL" || exprType == "INT") return std::string("INT");
    }

    else if (targetType == "NUMERICAL") {
        if (exprType == "INT" || exprType == "NUMERICAL") return std::string("NUMERICAL");
    }
   
    else if (targetType == "BOOL") {
        if (exprType == "INT" || exprType == "BOOL") return std::string("BOOL");
    }

    else if (targetType == "STRING") {
        if (exprType == "CHAR" || exprType == "INT" || exprType == "NUMERICAL" || exprType == "STRING") return std::string("STRING");
    }

else if (targetType == "CHAR") {
        if (exprType == "STRING" || exprType == "CHAR") return std::string("CHAR");
    }

    throw std::runtime_error("Type Error in line " + std::to_string(line) +
                             ": Cannot explicitly cast <" + exprType + "> to <" + targetType + ">.");
}
