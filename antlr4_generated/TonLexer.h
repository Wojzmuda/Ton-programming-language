
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  TonLexer : public antlr4::Lexer {
public:
  enum {
    TYPE_BOOL = 1, TYPE_INT = 2, TYPE_NUM = 3, TYPE_CHAR = 4, TYPE_STRING = 5, 
    TYPE_NOTE = 6, TYPE_SOUND = 7, TYPE_VOID = 8, TYPE_ARRAY = 9, TYPE_INSTR = 10, 
    MAKE = 11, IF = 12, IF_PLAIN = 13, OTHERWISE = 14, UNTIL = 15, LOOP = 16, 
    DEFINE = 17, OUT = 18, SHOUT = 19, FROM = 20, TO = 21, TIMES = 22, USE = 23, 
    MIXWITH = 24, TRASH = 25, MUTE = 26, DIVIDE = 27, EMPTYSOUND = 28, ASSIGN = 29, 
    AND_OP = 30, OR_OP = 31, NOT_KW = 32, EQ = 33, NEQ = 34, PLUS = 35, 
    MINUS = 36, MULT = 37, DIV_OP = 38, COLON = 39, L_ANGLE = 40, R_ANGLE = 41, 
    L_BRACE = 42, R_BRACE = 43, L_BRACKET = 44, R_BRACKET = 45, L_PAREN = 46, 
    R_PAREN = 47, SEMI = 48, COMMA = 49, NOTE_VAL = 50, INT_VAL = 51, NUM_VAL = 52, 
    BOOL_VAL = 53, CHAR_VAL = 54, STRING_VAL = 55, ID = 56, WS = 57, COMMENT = 58
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

