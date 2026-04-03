
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  TonLexer : public antlr4::Lexer {
public:
  enum {
    TYPE_BOOL = 1, TYPE_INT = 2, TYPE_NUM = 3, TYPE_CHAR = 4, TYPE_STRING = 5, 
    TYPE_NOTE = 6, TYPE_SOUND = 7, TYPE_VOID = 8, TYPE_ARRAY = 9, TYPE_INSTR = 10, 
    TYPE_TIMELINE = 11, MAKE = 12, IF = 13, IF_PLAIN = 14, OTHERWISE = 15, 
    UNTIL = 16, LOOP = 17, DEFINE = 18, OUT = 19, SHOUT = 20, SAVE = 21, 
    NEW = 22, TRACK = 23, AS = 24, AT = 25, SHIFT = 26, BY = 27, MOVE = 28, 
    ALL = 29, ISOLATE = 30, LENGTH = 31, PLAY = 32, FROM = 33, TO = 34, 
    TIMES = 35, USE = 36, MIXWITH = 37, TRASH = 38, MUTE = 39, UNMUTE = 40, 
    DIVIDE = 41, EMPTYSOUND = 42, ASSIGN = 43, ADD_ASSIGN = 44, AND_OP = 45, 
    OR_OP = 46, NOT_KW = 47, EQ = 48, NEQ = 49, PLUS = 50, MINUS = 51, MULT = 52, 
    DIV_OP = 53, COLON = 54, DOT = 55, AMPERSAND = 56, L_ANGLE = 57, R_ANGLE = 58, 
    L_BRACE = 59, R_BRACE = 60, L_BRACKET = 61, R_BRACKET = 62, L_PAREN = 63, 
    R_PAREN = 64, SEMI = 65, COMMA = 66, NOTE_VAL = 67, INT_VAL = 68, NUM_VAL = 69, 
    BOOL_VAL = 70, CHAR_VAL = 71, STRING_VAL = 72, ID = 73, WS = 74, COMMENT = 75
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

