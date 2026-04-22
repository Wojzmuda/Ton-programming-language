
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TonListener.h"


/**
 * This class provides an empty implementation of TonListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TonBaseListener : public TonListener {
public:

  virtual void enterProgram(TonParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(TonParser::ProgramContext * /*ctx*/) override { }

  virtual void enterHeader(TonParser::HeaderContext * /*ctx*/) override { }
  virtual void exitHeader(TonParser::HeaderContext * /*ctx*/) override { }

  virtual void enterBlock(TonParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(TonParser::BlockContext * /*ctx*/) override { }

  virtual void enterStatement(TonParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(TonParser::StatementContext * /*ctx*/) override { }

  virtual void enterVarDecl(TonParser::VarDeclContext * /*ctx*/) override { }
  virtual void exitVarDecl(TonParser::VarDeclContext * /*ctx*/) override { }

  virtual void enterTrackDecl(TonParser::TrackDeclContext * /*ctx*/) override { }
  virtual void exitTrackDecl(TonParser::TrackDeclContext * /*ctx*/) override { }

  virtual void enterTarget(TonParser::TargetContext * /*ctx*/) override { }
  virtual void exitTarget(TonParser::TargetContext * /*ctx*/) override { }

  virtual void enterAssignment(TonParser::AssignmentContext * /*ctx*/) override { }
  virtual void exitAssignment(TonParser::AssignmentContext * /*ctx*/) override { }

  virtual void enterReturnStat(TonParser::ReturnStatContext * /*ctx*/) override { }
  virtual void exitReturnStat(TonParser::ReturnStatContext * /*ctx*/) override { }

  virtual void enterShoutStat(TonParser::ShoutStatContext * /*ctx*/) override { }
  virtual void exitShoutStat(TonParser::ShoutStatContext * /*ctx*/) override { }

  virtual void enterIfStat(TonParser::IfStatContext * /*ctx*/) override { }
  virtual void exitIfStat(TonParser::IfStatContext * /*ctx*/) override { }

  virtual void enterLoopStat(TonParser::LoopStatContext * /*ctx*/) override { }
  virtual void exitLoopStat(TonParser::LoopStatContext * /*ctx*/) override { }

  virtual void enterUntilStat(TonParser::UntilStatContext * /*ctx*/) override { }
  virtual void exitUntilStat(TonParser::UntilStatContext * /*ctx*/) override { }

  virtual void enterFuncDef(TonParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(TonParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterAudioOpStat(TonParser::AudioOpStatContext * /*ctx*/) override { }
  virtual void exitAudioOpStat(TonParser::AudioOpStatContext * /*ctx*/) override { }

  virtual void enterSaveStat(TonParser::SaveStatContext * /*ctx*/) override { }
  virtual void exitSaveStat(TonParser::SaveStatContext * /*ctx*/) override { }

  virtual void enterPlayStat(TonParser::PlayStatContext * /*ctx*/) override { }
  virtual void exitPlayStat(TonParser::PlayStatContext * /*ctx*/) override { }

  virtual void enterType(TonParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(TonParser::TypeContext * /*ctx*/) override { }

  virtual void enterAndExpr(TonParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(TonParser::AndExprContext * /*ctx*/) override { }

  virtual void enterAddSubMixExpr(TonParser::AddSubMixExprContext * /*ctx*/) override { }
  virtual void exitAddSubMixExpr(TonParser::AddSubMixExprContext * /*ctx*/) override { }

  virtual void enterBoolValExpr(TonParser::BoolValExprContext * /*ctx*/) override { }
  virtual void exitBoolValExpr(TonParser::BoolValExprContext * /*ctx*/) override { }

  virtual void enterCreateSoundExpr(TonParser::CreateSoundExprContext * /*ctx*/) override { }
  virtual void exitCreateSoundExpr(TonParser::CreateSoundExprContext * /*ctx*/) override { }

  virtual void enterStringValExpr(TonParser::StringValExprContext * /*ctx*/) override { }
  virtual void exitStringValExpr(TonParser::StringValExprContext * /*ctx*/) override { }

  virtual void enterNumValExpr(TonParser::NumValExprContext * /*ctx*/) override { }
  virtual void exitNumValExpr(TonParser::NumValExprContext * /*ctx*/) override { }

  virtual void enterTargetExpr(TonParser::TargetExprContext * /*ctx*/) override { }
  virtual void exitTargetExpr(TonParser::TargetExprContext * /*ctx*/) override { }

  virtual void enterRelationalExpr(TonParser::RelationalExprContext * /*ctx*/) override { }
  virtual void exitRelationalExpr(TonParser::RelationalExprContext * /*ctx*/) override { }

  virtual void enterUnaryExpr(TonParser::UnaryExprContext * /*ctx*/) override { }
  virtual void exitUnaryExpr(TonParser::UnaryExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(TonParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(TonParser::OrExprContext * /*ctx*/) override { }

  virtual void enterIndexExpr(TonParser::IndexExprContext * /*ctx*/) override { }
  virtual void exitIndexExpr(TonParser::IndexExprContext * /*ctx*/) override { }

  virtual void enterConcatExpr(TonParser::ConcatExprContext * /*ctx*/) override { }
  virtual void exitConcatExpr(TonParser::ConcatExprContext * /*ctx*/) override { }

  virtual void enterArrayExpr(TonParser::ArrayExprContext * /*ctx*/) override { }
  virtual void exitArrayExpr(TonParser::ArrayExprContext * /*ctx*/) override { }

  virtual void enterFunctionCallExpr(TonParser::FunctionCallExprContext * /*ctx*/) override { }
  virtual void exitFunctionCallExpr(TonParser::FunctionCallExprContext * /*ctx*/) override { }

  virtual void enterMulDivExpr(TonParser::MulDivExprContext * /*ctx*/) override { }
  virtual void exitMulDivExpr(TonParser::MulDivExprContext * /*ctx*/) override { }

  virtual void enterNoteValExpr(TonParser::NoteValExprContext * /*ctx*/) override { }
  virtual void exitNoteValExpr(TonParser::NoteValExprContext * /*ctx*/) override { }

  virtual void enterEmptySoundExpr(TonParser::EmptySoundExprContext * /*ctx*/) override { }
  virtual void exitEmptySoundExpr(TonParser::EmptySoundExprContext * /*ctx*/) override { }

  virtual void enterIntValExpr(TonParser::IntValExprContext * /*ctx*/) override { }
  virtual void exitIntValExpr(TonParser::IntValExprContext * /*ctx*/) override { }

  virtual void enterCharValExpr(TonParser::CharValExprContext * /*ctx*/) override { }
  virtual void exitCharValExpr(TonParser::CharValExprContext * /*ctx*/) override { }

  virtual void enterParensExpr(TonParser::ParensExprContext * /*ctx*/) override { }
  virtual void exitParensExpr(TonParser::ParensExprContext * /*ctx*/) override { }

  virtual void enterTrackEventExpr(TonParser::TrackEventExprContext * /*ctx*/) override { }
  virtual void exitTrackEventExpr(TonParser::TrackEventExprContext * /*ctx*/) override { }

  virtual void enterSliceExpr(TonParser::SliceExprContext * /*ctx*/) override { }
  virtual void exitSliceExpr(TonParser::SliceExprContext * /*ctx*/) override { }

  virtual void enterNotExpr(TonParser::NotExprContext * /*ctx*/) override { }
  virtual void exitNotExpr(TonParser::NotExprContext * /*ctx*/) override { }

  virtual void enterLengthOfExpr(TonParser::LengthOfExprContext * /*ctx*/) override { }
  virtual void exitLengthOfExpr(TonParser::LengthOfExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

