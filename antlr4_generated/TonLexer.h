
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  TonLexer : public antlr4::Lexer {
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

  explicit TonLexer(antlr4::CharStream *input);

  ~TonLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

