
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TonParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by TonParser.
 */
class  TonListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(TonParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(TonParser::ProgramContext *ctx) = 0;

  virtual void enterHeader(TonParser::HeaderContext *ctx) = 0;
  virtual void exitHeader(TonParser::HeaderContext *ctx) = 0;

  virtual void enterBlock(TonParser::BlockContext *ctx) = 0;
  virtual void exitBlock(TonParser::BlockContext *ctx) = 0;

  virtual void enterStatement(TonParser::StatementContext *ctx) = 0;
  virtual void exitStatement(TonParser::StatementContext *ctx) = 0;

  virtual void enterVarDecl(TonParser::VarDeclContext *ctx) = 0;
  virtual void exitVarDecl(TonParser::VarDeclContext *ctx) = 0;

  virtual void enterTrackDecl(TonParser::TrackDeclContext *ctx) = 0;
  virtual void exitTrackDecl(TonParser::TrackDeclContext *ctx) = 0;

  virtual void enterTarget(TonParser::TargetContext *ctx) = 0;
  virtual void exitTarget(TonParser::TargetContext *ctx) = 0;

  virtual void enterAssignment(TonParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(TonParser::AssignmentContext *ctx) = 0;

  virtual void enterReturnStat(TonParser::ReturnStatContext *ctx) = 0;
  virtual void exitReturnStat(TonParser::ReturnStatContext *ctx) = 0;

  virtual void enterShoutStat(TonParser::ShoutStatContext *ctx) = 0;
  virtual void exitShoutStat(TonParser::ShoutStatContext *ctx) = 0;

  virtual void enterIfStat(TonParser::IfStatContext *ctx) = 0;
  virtual void exitIfStat(TonParser::IfStatContext *ctx) = 0;

  virtual void enterLoopStat(TonParser::LoopStatContext *ctx) = 0;
  virtual void exitLoopStat(TonParser::LoopStatContext *ctx) = 0;

  virtual void enterUntilStat(TonParser::UntilStatContext *ctx) = 0;
  virtual void exitUntilStat(TonParser::UntilStatContext *ctx) = 0;

  virtual void enterFuncDef(TonParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(TonParser::FuncDefContext *ctx) = 0;

  virtual void enterAudioOpStat(TonParser::AudioOpStatContext *ctx) = 0;
  virtual void exitAudioOpStat(TonParser::AudioOpStatContext *ctx) = 0;

  virtual void enterSaveStat(TonParser::SaveStatContext *ctx) = 0;
  virtual void exitSaveStat(TonParser::SaveStatContext *ctx) = 0;

  virtual void enterPlayStat(TonParser::PlayStatContext *ctx) = 0;
  virtual void exitPlayStat(TonParser::PlayStatContext *ctx) = 0;

  virtual void enterType(TonParser::TypeContext *ctx) = 0;
  virtual void exitType(TonParser::TypeContext *ctx) = 0;

  virtual void enterAndExpr(TonParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(TonParser::AndExprContext *ctx) = 0;

  virtual void enterAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) = 0;
  virtual void exitAddSubMixExpr(TonParser::AddSubMixExprContext *ctx) = 0;

  virtual void enterCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) = 0;
  virtual void exitCreateSoundExpr(TonParser::CreateSoundExprContext *ctx) = 0;

  virtual void enterNumValExpr(TonParser::NumValExprContext *ctx) = 0;
  virtual void exitNumValExpr(TonParser::NumValExprContext *ctx) = 0;

  virtual void enterTargetExpr(TonParser::TargetExprContext *ctx) = 0;
  virtual void exitTargetExpr(TonParser::TargetExprContext *ctx) = 0;

  virtual void enterRelationalExpr(TonParser::RelationalExprContext *ctx) = 0;
  virtual void exitRelationalExpr(TonParser::RelationalExprContext *ctx) = 0;

  virtual void enterIndexExpr(TonParser::IndexExprContext *ctx) = 0;
  virtual void exitIndexExpr(TonParser::IndexExprContext *ctx) = 0;

  virtual void enterNoteValExpr(TonParser::NoteValExprContext *ctx) = 0;
  virtual void exitNoteValExpr(TonParser::NoteValExprContext *ctx) = 0;

  virtual void enterTrackEventExpr(TonParser::TrackEventExprContext *ctx) = 0;
  virtual void exitTrackEventExpr(TonParser::TrackEventExprContext *ctx) = 0;

  virtual void enterNotExpr(TonParser::NotExprContext *ctx) = 0;
  virtual void exitNotExpr(TonParser::NotExprContext *ctx) = 0;

  virtual void enterIsolateExpr(TonParser::IsolateExprContext *ctx) = 0;
  virtual void exitIsolateExpr(TonParser::IsolateExprContext *ctx) = 0;

  virtual void enterBoolValExpr(TonParser::BoolValExprContext *ctx) = 0;
  virtual void exitBoolValExpr(TonParser::BoolValExprContext *ctx) = 0;

  virtual void enterStringValExpr(TonParser::StringValExprContext *ctx) = 0;
  virtual void exitStringValExpr(TonParser::StringValExprContext *ctx) = 0;

  virtual void enterUnaryExpr(TonParser::UnaryExprContext *ctx) = 0;
  virtual void exitUnaryExpr(TonParser::UnaryExprContext *ctx) = 0;

  virtual void enterOrExpr(TonParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(TonParser::OrExprContext *ctx) = 0;

  virtual void enterConcatExpr(TonParser::ConcatExprContext *ctx) = 0;
  virtual void exitConcatExpr(TonParser::ConcatExprContext *ctx) = 0;

  virtual void enterArrayExpr(TonParser::ArrayExprContext *ctx) = 0;
  virtual void exitArrayExpr(TonParser::ArrayExprContext *ctx) = 0;

  virtual void enterFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) = 0;
  virtual void exitFunctionCallExpr(TonParser::FunctionCallExprContext *ctx) = 0;

  virtual void enterMulDivExpr(TonParser::MulDivExprContext *ctx) = 0;
  virtual void exitMulDivExpr(TonParser::MulDivExprContext *ctx) = 0;

  virtual void enterEmptySoundExpr(TonParser::EmptySoundExprContext *ctx) = 0;
  virtual void exitEmptySoundExpr(TonParser::EmptySoundExprContext *ctx) = 0;

  virtual void enterIntValExpr(TonParser::IntValExprContext *ctx) = 0;
  virtual void exitIntValExpr(TonParser::IntValExprContext *ctx) = 0;

  virtual void enterCharValExpr(TonParser::CharValExprContext *ctx) = 0;
  virtual void exitCharValExpr(TonParser::CharValExprContext *ctx) = 0;

  virtual void enterParensExpr(TonParser::ParensExprContext *ctx) = 0;
  virtual void exitParensExpr(TonParser::ParensExprContext *ctx) = 0;

  virtual void enterSliceExpr(TonParser::SliceExprContext *ctx) = 0;
  virtual void exitSliceExpr(TonParser::SliceExprContext *ctx) = 0;

  virtual void enterLengthOfExpr(TonParser::LengthOfExprContext *ctx) = 0;
  virtual void exitLengthOfExpr(TonParser::LengthOfExprContext *ctx) = 0;


};

