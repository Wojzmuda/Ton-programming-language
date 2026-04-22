
// Generated from Ton.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  TonLexer : public antlr4::Lexer {
public:
  enum {
    TYPE_BOOL = 1, TYPE_INT = 2, TYPE_NUM = 3, TYPE_CHAR = 4, TYPE_STRING = 5, 
    TYPE_NOTE = 6, TYPE_SOUND = 7, TYPE_VOID = 8, TYPE_ARRAY = 9, TYPE_INSTR = 10, 
    TYPE_TIMELINE = 11, MAKE = 12, IF = 13, OTHERWISE = 14, UNTIL = 15, 
    LOOP = 16, DEFINE = 17, OUT = 18, SHOUT = 19, SAVE = 20, NEW = 21, TRACK = 22, 
    AS = 23, AT = 24, SHIFT = 25, BY = 26, MOVE = 27, ALL = 28, ISOLATE = 29, 
    LENGTH = 30, PLAY = 31, FROM = 32, TO = 33, TIMES = 34, USE = 35, TRASH = 36, 
    MUTE = 37, UNMUTE = 38, DIVIDE = 39, EMPTYSOUND = 40, ASSIGN = 41, ADD_ASSIGN = 42, 
    SUB_ASSIGN = 43, MULT_ASSIGN = 44, DIV_ASSIGN = 45, AND_OP = 46, OR_OP = 47, 
    NOT_KW = 48, EQ = 49, NEQ = 50, PLUS = 51, MINUS = 52, MULT = 53, DIV_OP = 54, 
    COLON = 55, DOT = 56, AMPERSAND = 57, L_ANGLE_EQ = 58, R_ANGLE_EQ = 59, 
    L_ANGLE = 60, R_ANGLE = 61, L_BRACE = 62, R_BRACE = 63, L_BRACKET = 64, 
    R_BRACKET = 65, L_PAREN = 66, R_PAREN = 67, SEMI = 68, COMMA = 69, EXCLAM_MARK = 70, 
    NOTE_VAL = 71, INT_VAL = 72, NUM_VAL = 73, BOOL_VAL = 74, CHAR_VAL = 75, 
    STRING_VAL = 76, ID = 77, WS = 78, COMMENT = 79
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

