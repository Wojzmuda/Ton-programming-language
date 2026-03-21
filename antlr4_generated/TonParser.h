
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  TonParser : public antlr4::Parser {
public:
  enum {
    TYPE_BOOL = 1, TYPE_INT = 2, TYPE_NUM = 3, TYPE_CHAR = 4, TYPE_STRING = 5, 
    TYPE_NOTE = 6, TYPE_SOUND = 7, TYPE_VOID = 8, TYPE_ARRAY = 9, TYPE_INSTR = 10, 
    MAKE = 11, IF = 12, IF_PLAIN = 13, OTHERWISE = 14, UNTIL = 15, LOOP = 16, 
    DEFINE = 17, OUT = 18, SHOUT = 19, SAVE = 20, FROM = 21, TO = 22, TIMES = 23, 
    USE = 24, MIXWITH = 25, TRASH = 26, MUTE = 27, DIVIDE = 28, EMPTYSOUND = 29, 
    ASSIGN = 30, AND_OP = 31, OR_OP = 32, NOT_KW = 33, EQ = 34, NEQ = 35, 
    PLUS = 36, MINUS = 37, MULT = 38, DIV_OP = 39, COLON = 40, L_ANGLE = 41, 
    R_ANGLE = 42, L_BRACE = 43, R_BRACE = 44, L_BRACKET = 45, R_BRACKET = 46, 
    L_PAREN = 47, R_PAREN = 48, SEMI = 49, COMMA = 50, NOTE_VAL = 51, INT_VAL = 52, 
    NUM_VAL = 53, BOOL_VAL = 54, CHAR_VAL = 55, STRING_VAL = 56, ID = 57, 
    WS = 58, COMMENT = 59
  };

  enum {
    RuleProgram = 0, RuleHeader = 1, RuleBlock = 2, RuleStatement = 3, RuleVarDecl = 4, 
    RuleAssignment = 5, RuleShoutStat = 6, RuleIfStat = 7, RuleLoopStat = 8, 
    RuleUntilStat = 9, RuleFuncDef = 10, RuleAudioOpStat = 11, RuleSaveStat = 12, 
    RuleType = 13, RuleExpr = 14
  };

  explicit TonParser(antlr4::TokenStream *input);

  TonParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~TonParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class HeaderContext;
  class BlockContext;
  class StatementContext;
  class VarDeclContext;
  class AssignmentContext;
  class ShoutStatContext;
  class IfStatContext;
  class LoopStatContext;
  class UntilStatContext;
  class FuncDefContext;
  class AudioOpStatContext;
  class SaveStatContext;
  class TypeContext;
  class ExprContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<HeaderContext *> header();
    HeaderContext* header(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  HeaderContext : public antlr4::ParserRuleContext {
  public:
    HeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *USE();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  HeaderContext* header();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *L_BRACE();
    antlr4::tree::TerminalNode *R_BRACE();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDeclContext *varDecl();
    AssignmentContext *assignment();
    IfStatContext *ifStat();
    LoopStatContext *loopStat();
    UntilStatContext *untilStat();
    ShoutStatContext *shoutStat();
    FuncDefContext *funcDef();
    AudioOpStatContext *audioOpStat();
    SaveStatContext *saveStat();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MAKE();
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  ShoutStatContext : public antlr4::ParserRuleContext {
  public:
    ShoutStatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SHOUT();
    ExprContext *expr();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ShoutStatContext* shoutStat();

  class  IfStatContext : public antlr4::ParserRuleContext {
  public:
    IfStatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<antlr4::tree::TerminalNode *> L_ANGLE();
    antlr4::tree::TerminalNode* L_ANGLE(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> R_ANGLE();
    antlr4::tree::TerminalNode* R_ANGLE(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OTHERWISE();
    antlr4::tree::TerminalNode* OTHERWISE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> IF_PLAIN();
    antlr4::tree::TerminalNode* IF_PLAIN(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatContext* ifStat();

  class  LoopStatContext : public antlr4::ParserRuleContext {
  public:
    LoopStatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LOOP();
    antlr4::tree::TerminalNode *L_ANGLE();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *TIMES();
    antlr4::tree::TerminalNode *R_ANGLE();
    BlockContext *block();
    TypeContext *type();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *FROM();
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *ASSIGN();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopStatContext* loopStat();

  class  UntilStatContext : public antlr4::ParserRuleContext {
  public:
    UntilStatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UNTIL();
    antlr4::tree::TerminalNode *L_ANGLE();
    ExprContext *expr();
    antlr4::tree::TerminalNode *R_ANGLE();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UntilStatContext* untilStat();

  class  FuncDefContext : public antlr4::ParserRuleContext {
  public:
    FuncDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEFINE();
    std::vector<TypeContext *> type();
    TypeContext* type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *L_ANGLE();
    antlr4::tree::TerminalNode *R_ANGLE();
    BlockContext *block();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDefContext* funcDef();

  class  AudioOpStatContext : public antlr4::ParserRuleContext {
  public:
    AudioOpStatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *TRASH();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *SEMI();
    antlr4::tree::TerminalNode *MUTE();
    antlr4::tree::TerminalNode *DIVIDE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AudioOpStatContext* audioOpStat();

  class  SaveStatContext : public antlr4::ParserRuleContext {
  public:
    SaveStatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SAVE();
    ExprContext *expr();
    antlr4::tree::TerminalNode *STRING_VAL();
    antlr4::tree::TerminalNode *SEMI();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SaveStatContext* saveStat();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE_BOOL();
    antlr4::tree::TerminalNode *TYPE_INT();
    antlr4::tree::TerminalNode *TYPE_NUM();
    antlr4::tree::TerminalNode *TYPE_CHAR();
    antlr4::tree::TerminalNode *TYPE_STRING();
    antlr4::tree::TerminalNode *TYPE_NOTE();
    antlr4::tree::TerminalNode *TYPE_SOUND();
    antlr4::tree::TerminalNode *TYPE_VOID();
    antlr4::tree::TerminalNode *TYPE_ARRAY();
    antlr4::tree::TerminalNode *TYPE_INSTR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprContext() = default;
    void copyFrom(ExprContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  AndExprContext : public ExprContext {
  public:
    AndExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *AND_OP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExprContext : public ExprContext {
  public:
    IdExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BoolValExprContext : public ExprContext {
  public:
    BoolValExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *BOOL_VAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CreateSoundExprContext : public ExprContext {
  public:
    CreateSoundExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringValExprContext : public ExprContext {
  public:
    StringValExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *STRING_VAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumValExprContext : public ExprContext {
  public:
    NumValExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NUM_VAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MixWithExprContext : public ExprContext {
  public:
    MixWithExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MIXWITH();
    antlr4::tree::TerminalNode *FROM();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RelationalExprContext : public ExprContext {
  public:
    RelationalExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NEQ();
    antlr4::tree::TerminalNode *L_ANGLE();
    antlr4::tree::TerminalNode *R_ANGLE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrExprContext : public ExprContext {
  public:
    OrExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *OR_OP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IndexExprContext : public ExprContext {
  public:
    IndexExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *R_BRACKET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArrayExprContext : public ExprContext {
  public:
    ArrayExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *L_BRACKET();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *R_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallExprContext : public ExprContext {
  public:
    FunctionCallExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *L_PAREN();
    antlr4::tree::TerminalNode *R_PAREN();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulDivExprContext : public ExprContext {
  public:
    MulDivExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV_OP();
    antlr4::tree::TerminalNode *COLON();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NoteValExprContext : public ExprContext {
  public:
    NoteValExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *NOTE_VAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EmptySoundExprContext : public ExprContext {
  public:
    EmptySoundExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *EMPTYSOUND();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntValExprContext : public ExprContext {
  public:
    IntValExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *INT_VAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharValExprContext : public ExprContext {
  public:
    CharValExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *CHAR_VAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParensExprContext : public ExprContext {
  public:
    ParensExprContext(ExprContext *ctx);

    antlr4::tree::TerminalNode *L_PAREN();
    ExprContext *expr();
    antlr4::tree::TerminalNode *R_PAREN();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SliceExprContext : public ExprContext {
  public:
    SliceExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *L_BRACKET();
    antlr4::tree::TerminalNode *COLON();
    antlr4::tree::TerminalNode *R_BRACKET();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotExprContext : public ExprContext {
  public:
    NotExprContext(ExprContext *ctx);

    ExprContext *expr();
    antlr4::tree::TerminalNode *NOT_KW();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AddSubExprContext : public ExprContext {
  public:
    AddSubExprContext(ExprContext *ctx);

    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

