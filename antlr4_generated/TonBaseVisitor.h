
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TonVisitor.h"


/**
 * This class provides an empty implementation of TonVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TonBaseVisitor : public TonVisitor {
public:

  virtual std::any visitProgram(TonParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitHeader(TonParser::HeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(TonParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStatement(TonParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDecl(TonParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrackDecl(TonParser::TrackDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTarget(TonParser::TargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignment(TonParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnStat(TonParser::ReturnStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitShoutStat(TonParser::ShoutStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStat(TonParser::IfStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLoopStat(TonParser::LoopStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUntilStat(TonParser::UntilStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFuncDef(TonParser::FuncDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAudioOpStat(TonParser::AudioOpStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSaveStat(TonParser::SaveStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlayStat(TonParser::PlayStatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitType(TonParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(TonParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumValExpr(TonParser::NumValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTargetExpr(TonParser::TargetExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRelationalExpr(TonParser::RelationalExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIndexExpr(TonParser::IndexExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNoteValExpr(TonParser::NoteValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTrackEventExpr(TonParser::TrackEventExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotExpr(TonParser::NotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsolateExpr(TonParser::IsolateExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolValExpr(TonParser::BoolValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringValExpr(TonParser::StringValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryExpr(TonParser::UnaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(TonParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConcatExpr(TonParser::ConcatExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr(TonParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMulDivExpr(TonParser::MulDivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptySoundExpr(TonParser::EmptySoundExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntValExpr(TonParser::IntValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCharValExpr(TonParser::CharValExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParensExpr(TonParser::ParensExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSliceExpr(TonParser::SliceExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) override {
    return visitChildren(ctx);
  }


};

