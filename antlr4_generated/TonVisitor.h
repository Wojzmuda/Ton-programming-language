
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TonParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by TonParser.
 */
class  TonVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by TonParser.
   */
    virtual std::any visitProgram(TonParser::ProgramContext *context) = 0;

    virtual std::any visitHeader(TonParser::HeaderContext *context) = 0;

    virtual std::any visitBlock(TonParser::BlockContext *context) = 0;

    virtual std::any visitStatement(TonParser::StatementContext *context) = 0;

    virtual std::any visitVarDecl(TonParser::VarDeclContext *context) = 0;

    virtual std::any visitAssignment(TonParser::AssignmentContext *context) = 0;

    virtual std::any visitShoutStat(TonParser::ShoutStatContext *context) = 0;

    virtual std::any visitIfStat(TonParser::IfStatContext *context) = 0;

    virtual std::any visitLoopStat(TonParser::LoopStatContext *context) = 0;

    virtual std::any visitUntilStat(TonParser::UntilStatContext *context) = 0;

    virtual std::any visitFuncDef(TonParser::FuncDefContext *context) = 0;

    virtual std::any visitAudioOpStat(TonParser::AudioOpStatContext *context) = 0;

    virtual std::any visitType(TonParser::TypeContext *context) = 0;

    virtual std::any visitAndExpr(TonParser::AndExprContext *context) = 0;

    virtual std::any visitIdExpr(TonParser::IdExprContext *context) = 0;

    virtual std::any visitBoolValExpr(TonParser::BoolValExprContext *context) = 0;

    virtual std::any visitStringValExpr(TonParser::StringValExprContext *context) = 0;

    virtual std::any visitNumValExpr(TonParser::NumValExprContext *context) = 0;

    virtual std::any visitConstructorExpr(TonParser::ConstructorExprContext *context) = 0;

    virtual std::any visitMixWithExpr(TonParser::MixWithExprContext *context) = 0;

    virtual std::any visitRelationalExpr(TonParser::RelationalExprContext *context) = 0;

    virtual std::any visitOrExpr(TonParser::OrExprContext *context) = 0;

    virtual std::any visitIndexExpr(TonParser::IndexExprContext *context) = 0;

    virtual std::any visitArrayExpr(TonParser::ArrayExprContext *context) = 0;

    virtual std::any visitFunctionCallExpr(TonParser::FunctionCallExprContext *context) = 0;

    virtual std::any visitMulDivExpr(TonParser::MulDivExprContext *context) = 0;

    virtual std::any visitNoteValExpr(TonParser::NoteValExprContext *context) = 0;

    virtual std::any visitEmptySoundExpr(TonParser::EmptySoundExprContext *context) = 0;

    virtual std::any visitIntValExpr(TonParser::IntValExprContext *context) = 0;

    virtual std::any visitCharValExpr(TonParser::CharValExprContext *context) = 0;

    virtual std::any visitParensExpr(TonParser::ParensExprContext *context) = 0;

    virtual std::any visitSliceExpr(TonParser::SliceExprContext *context) = 0;

    virtual std::any visitNotExpr(TonParser::NotExprContext *context) = 0;

    virtual std::any visitInstrumentPlayExpr(TonParser::InstrumentPlayExprContext *context) = 0;

    virtual std::any visitAddSubExpr(TonParser::AddSubExprContext *context) = 0;


};

