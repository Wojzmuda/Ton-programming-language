
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  TonLexer : public antlr4::Lexer {
public:
  enum {
    TYPE_BOOL = 1, TYPE_INT = 2, TYPE_NUM = 3, TYPE_CHAR = 4, TYPE_STRING = 5, 
    TYPE_NOTE = 6, TYPE_SOUND = 7, TYPE_VOID = 8, TYPE_ARRAY = 9, TYPE_INSTR = 10, 
    TYPE_TIMELINE = 11, MAKE = 12, IF = 13, OTHERWISE = 14, UNTIL = 15, 
    LOOP = 16, DEFINE = 17, OUT = 18, SHOUT = 19, SAVE = 20, BREAK = 21, 
    CONTINUE = 22, NEW = 23, TRACK = 24, AS = 25, AT = 26, SHIFT = 27, BY = 28, 
    MOVE = 29, ALL = 30, ISOLATE = 31, LENGTH = 32, PLAY = 33, FROM = 34, 
    TO = 35, TIMES = 36, USE = 37, TRASH = 38, MUTE = 39, UNMUTE = 40, DIVIDE = 41, 
    EMPTYSOUND = 42, ASSIGN = 43, ADD_ASSIGN = 44, SUB_ASSIGN = 45, MULT_ASSIGN = 46, 
    DIV_ASSIGN = 47, AND_OP = 48, OR_OP = 49, NOT_KW = 50, EQ = 51, NEQ = 52, 
    PLUS = 53, MINUS = 54, MULT = 55, DIV_OP = 56, COLON = 57, DOT = 58, 
    AMPERSAND = 59, L_ANGLE_EQ = 60, R_ANGLE_EQ = 61, L_ANGLE = 62, R_ANGLE = 63, 
    L_BRACE = 64, R_BRACE = 65, L_BRACKET = 66, R_BRACKET = 67, L_PAREN = 68, 
    R_PAREN = 69, SEMI = 70, COMMA = 71, EXCLAM_MARK = 72, NOTE_VAL = 73, 
    INT_VAL = 74, NUM_VAL = 75, BOOL_VAL = 76, CHAR_VAL = 77, STRING_VAL = 78, 
    ID = 79, WS = 80, COMMENT = 81
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

