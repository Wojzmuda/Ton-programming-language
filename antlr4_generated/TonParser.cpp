
// Generated from Ton.g4 by ANTLR 4.13.2


#include "TonListener.h"
#include "TonVisitor.h"

#include "TonParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct TonParserStaticData final {
  TonParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TonParserStaticData(const TonParserStaticData&) = delete;
  TonParserStaticData(TonParserStaticData&&) = delete;
  TonParserStaticData& operator=(const TonParserStaticData&) = delete;
  TonParserStaticData& operator=(TonParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tonParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<TonParserStaticData> tonParserStaticData = nullptr;

void tonParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tonParserStaticData != nullptr) {
    return;
  }
#else
  assert(tonParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TonParserStaticData>(
    std::vector<std::string>{
      "program", "header", "block", "statement", "varDecl", "trackDecl", 
      "target", "callStat", "assignment", "returnStat", "shoutStat", "ifStat", 
      "loopStat", "untilStat", "funcDef", "audioOpStat", "saveStat", "playStat", 
      "type", "expr"
    },
    std::vector<std::string>{
      "", "'BOOL'", "'INT'", "'NUMERICAL'", "'CHAR'", "'STRING'", "'NOTE'", 
      "'SOUND'", "'VOID'", "'ARRAY'", "'INSTRUMENT'", "'TIMELINE'", "'make'", 
      "'if'", "'otherwise'", "'until'", "'loop'", "'define'", "'out'", "'shout'", 
      "'save'", "'NEW'", "'TRACK'", "'AS'", "'AT'", "'SHIFT'", "'BY'", "'MOVE'", 
      "'ALL'", "'ISOLATE'", "'LENGTH'", "'PLAY'", "'FROM'", "'TO'", "'TIMES'", 
      "'USE'", "'TRASH'", "'MUTE'", "'UNMUTE'", "'DIVIDE'", "'EMPTYSOUND'", 
      "'<-'", "'+<-'", "'-<-'", "'*<-'", "'/<-'", "'AND'", "'OR'", "'NOT'", 
      "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", "':'", "'.'", "'&'", "'<='", 
      "'>='", "'<'", "'>'", "'{'", "'}'", "'['", "']'", "'('", "')'", "';'", 
      "','", "'!'"
    },
    std::vector<std::string>{
      "", "TYPE_BOOL", "TYPE_INT", "TYPE_NUM", "TYPE_CHAR", "TYPE_STRING", 
      "TYPE_NOTE", "TYPE_SOUND", "TYPE_VOID", "TYPE_ARRAY", "TYPE_INSTR", 
      "TYPE_TIMELINE", "MAKE", "IF", "OTHERWISE", "UNTIL", "LOOP", "DEFINE", 
      "OUT", "SHOUT", "SAVE", "NEW", "TRACK", "AS", "AT", "SHIFT", "BY", 
      "MOVE", "ALL", "ISOLATE", "LENGTH", "PLAY", "FROM", "TO", "TIMES", 
      "USE", "TRASH", "MUTE", "UNMUTE", "DIVIDE", "EMPTYSOUND", "ASSIGN", 
      "ADD_ASSIGN", "SUB_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "AND_OP", 
      "OR_OP", "NOT_KW", "EQ", "NEQ", "PLUS", "MINUS", "MULT", "DIV_OP", 
      "COLON", "DOT", "AMPERSAND", "L_ANGLE_EQ", "R_ANGLE_EQ", "L_ANGLE", 
      "R_ANGLE", "L_BRACE", "R_BRACE", "L_BRACKET", "R_BRACKET", "L_PAREN", 
      "R_PAREN", "SEMI", "COMMA", "EXCLAM_MARK", "NOTE_VAL", "INT_VAL", 
      "NUM_VAL", "BOOL_VAL", "CHAR_VAL", "STRING_VAL", "ID", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,79,388,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,1,0,5,0,42,8,0,10,
  	0,12,0,45,9,0,1,0,5,0,48,8,0,10,0,12,0,51,9,0,1,0,1,0,1,1,1,1,1,1,1,1,
  	1,2,1,2,5,2,61,8,2,10,2,12,2,64,9,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,82,8,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,
  	90,8,4,1,4,1,4,1,5,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,3,6,105,8,
  	6,3,6,107,8,6,1,7,1,7,1,7,1,7,1,7,5,7,114,8,7,10,7,12,7,117,9,7,3,7,119,
  	8,7,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,149,8,8,1,9,1,9,1,9,
  	3,9,154,8,9,1,9,1,9,1,10,1,10,1,10,1,10,1,10,5,10,163,8,10,10,10,12,10,
  	166,9,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,5,11,184,8,11,10,11,12,11,187,9,11,1,11,1,11,1,11,
  	3,11,192,8,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,3,12,224,8,12,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,244,
  	8,14,10,14,12,14,247,9,14,3,14,249,8,14,1,14,1,14,1,14,1,15,1,15,1,15,
  	1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,
  	1,15,1,15,3,15,273,8,15,1,15,1,15,1,15,1,15,1,15,3,15,280,8,15,1,16,1,
  	16,1,16,1,16,1,16,1,16,1,17,1,17,1,17,1,17,1,18,1,18,1,19,1,19,1,19,1,
  	19,1,19,5,19,299,8,19,10,19,12,19,302,9,19,3,19,304,8,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,5,19,312,8,19,10,19,12,19,315,9,19,3,19,317,8,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,3,19,344,8,19,1,
  	19,1,19,1,19,3,19,349,8,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,
  	19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,383,8,19,10,19,12,
  	19,386,9,19,1,19,0,1,38,20,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,0,4,1,0,1,11,1,0,51,52,1,0,53,55,2,0,49,50,58,61,434,0,43,
  	1,0,0,0,2,54,1,0,0,0,4,58,1,0,0,0,6,81,1,0,0,0,8,83,1,0,0,0,10,93,1,0,
  	0,0,12,99,1,0,0,0,14,108,1,0,0,0,16,148,1,0,0,0,18,150,1,0,0,0,20,157,
  	1,0,0,0,22,169,1,0,0,0,24,223,1,0,0,0,26,225,1,0,0,0,28,232,1,0,0,0,30,
  	279,1,0,0,0,32,281,1,0,0,0,34,287,1,0,0,0,36,291,1,0,0,0,38,343,1,0,0,
  	0,40,42,3,2,1,0,41,40,1,0,0,0,42,45,1,0,0,0,43,41,1,0,0,0,43,44,1,0,0,
  	0,44,49,1,0,0,0,45,43,1,0,0,0,46,48,3,6,3,0,47,46,1,0,0,0,48,51,1,0,0,
  	0,49,47,1,0,0,0,49,50,1,0,0,0,50,52,1,0,0,0,51,49,1,0,0,0,52,53,5,0,0,
  	1,53,1,1,0,0,0,54,55,5,35,0,0,55,56,5,77,0,0,56,57,5,68,0,0,57,3,1,0,
  	0,0,58,62,5,62,0,0,59,61,3,6,3,0,60,59,1,0,0,0,61,64,1,0,0,0,62,60,1,
  	0,0,0,62,63,1,0,0,0,63,65,1,0,0,0,64,62,1,0,0,0,65,66,5,63,0,0,66,5,1,
  	0,0,0,67,82,3,8,4,0,68,82,3,10,5,0,69,82,3,16,8,0,70,82,3,22,11,0,71,
  	82,3,24,12,0,72,82,3,26,13,0,73,82,3,20,10,0,74,82,3,28,14,0,75,82,3,
  	30,15,0,76,82,3,32,16,0,77,82,3,34,17,0,78,82,3,18,9,0,79,82,3,14,7,0,
  	80,82,3,4,2,0,81,67,1,0,0,0,81,68,1,0,0,0,81,69,1,0,0,0,81,70,1,0,0,0,
  	81,71,1,0,0,0,81,72,1,0,0,0,81,73,1,0,0,0,81,74,1,0,0,0,81,75,1,0,0,0,
  	81,76,1,0,0,0,81,77,1,0,0,0,81,78,1,0,0,0,81,79,1,0,0,0,81,80,1,0,0,0,
  	82,7,1,0,0,0,83,84,5,70,0,0,84,85,5,12,0,0,85,86,3,36,18,0,86,89,5,77,
  	0,0,87,88,5,41,0,0,88,90,3,38,19,0,89,87,1,0,0,0,89,90,1,0,0,0,90,91,
  	1,0,0,0,91,92,5,68,0,0,92,9,1,0,0,0,93,94,5,77,0,0,94,95,5,21,0,0,95,
  	96,5,22,0,0,96,97,5,77,0,0,97,98,5,68,0,0,98,11,1,0,0,0,99,106,5,77,0,
  	0,100,101,5,56,0,0,101,104,5,77,0,0,102,103,5,56,0,0,103,105,5,76,0,0,
  	104,102,1,0,0,0,104,105,1,0,0,0,105,107,1,0,0,0,106,100,1,0,0,0,106,107,
  	1,0,0,0,107,13,1,0,0,0,108,109,5,77,0,0,109,118,5,66,0,0,110,115,3,38,
  	19,0,111,112,5,69,0,0,112,114,3,38,19,0,113,111,1,0,0,0,114,117,1,0,0,
  	0,115,113,1,0,0,0,115,116,1,0,0,0,116,119,1,0,0,0,117,115,1,0,0,0,118,
  	110,1,0,0,0,118,119,1,0,0,0,119,120,1,0,0,0,120,121,5,67,0,0,121,122,
  	5,68,0,0,122,15,1,0,0,0,123,124,3,12,6,0,124,125,5,41,0,0,125,126,3,38,
  	19,0,126,127,5,68,0,0,127,149,1,0,0,0,128,129,3,12,6,0,129,130,5,42,0,
  	0,130,131,3,38,19,0,131,132,5,68,0,0,132,149,1,0,0,0,133,134,3,12,6,0,
  	134,135,5,43,0,0,135,136,3,38,19,0,136,137,5,68,0,0,137,149,1,0,0,0,138,
  	139,3,12,6,0,139,140,5,44,0,0,140,141,3,38,19,0,141,142,5,68,0,0,142,
  	149,1,0,0,0,143,144,3,12,6,0,144,145,5,45,0,0,145,146,3,38,19,0,146,147,
  	5,68,0,0,147,149,1,0,0,0,148,123,1,0,0,0,148,128,1,0,0,0,148,133,1,0,
  	0,0,148,138,1,0,0,0,148,143,1,0,0,0,149,17,1,0,0,0,150,151,5,70,0,0,151,
  	153,5,18,0,0,152,154,3,38,19,0,153,152,1,0,0,0,153,154,1,0,0,0,154,155,
  	1,0,0,0,155,156,5,68,0,0,156,19,1,0,0,0,157,158,5,70,0,0,158,159,5,19,
  	0,0,159,164,3,38,19,0,160,161,5,69,0,0,161,163,3,38,19,0,162,160,1,0,
  	0,0,163,166,1,0,0,0,164,162,1,0,0,0,164,165,1,0,0,0,165,167,1,0,0,0,166,
  	164,1,0,0,0,167,168,5,68,0,0,168,21,1,0,0,0,169,170,5,70,0,0,170,171,
  	5,13,0,0,171,172,5,60,0,0,172,173,3,38,19,0,173,174,5,61,0,0,174,185,
  	3,4,2,0,175,176,5,70,0,0,176,177,5,14,0,0,177,178,5,13,0,0,178,179,5,
  	60,0,0,179,180,3,38,19,0,180,181,5,61,0,0,181,182,3,4,2,0,182,184,1,0,
  	0,0,183,175,1,0,0,0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,1,0,0,0,186,
  	191,1,0,0,0,187,185,1,0,0,0,188,189,5,70,0,0,189,190,5,14,0,0,190,192,
  	3,4,2,0,191,188,1,0,0,0,191,192,1,0,0,0,192,23,1,0,0,0,193,194,5,70,0,
  	0,194,195,5,16,0,0,195,196,5,60,0,0,196,197,3,38,19,0,197,198,5,34,0,
  	0,198,199,5,61,0,0,199,200,3,4,2,0,200,224,1,0,0,0,201,202,5,70,0,0,202,
  	203,5,16,0,0,203,204,5,60,0,0,204,205,3,36,18,0,205,206,5,77,0,0,206,
  	207,5,32,0,0,207,208,3,38,19,0,208,209,5,33,0,0,209,210,3,38,19,0,210,
  	211,5,61,0,0,211,212,3,4,2,0,212,224,1,0,0,0,213,214,5,70,0,0,214,215,
  	5,16,0,0,215,216,5,60,0,0,216,217,3,36,18,0,217,218,5,77,0,0,218,219,
  	5,41,0,0,219,220,3,38,19,0,220,221,5,61,0,0,221,222,3,4,2,0,222,224,1,
  	0,0,0,223,193,1,0,0,0,223,201,1,0,0,0,223,213,1,0,0,0,224,25,1,0,0,0,
  	225,226,5,70,0,0,226,227,5,15,0,0,227,228,5,60,0,0,228,229,3,38,19,0,
  	229,230,5,61,0,0,230,231,3,4,2,0,231,27,1,0,0,0,232,233,5,70,0,0,233,
  	234,5,17,0,0,234,235,3,36,18,0,235,236,5,77,0,0,236,248,5,60,0,0,237,
  	238,3,36,18,0,238,245,5,77,0,0,239,240,5,69,0,0,240,241,3,36,18,0,241,
  	242,5,77,0,0,242,244,1,0,0,0,243,239,1,0,0,0,244,247,1,0,0,0,245,243,
  	1,0,0,0,245,246,1,0,0,0,246,249,1,0,0,0,247,245,1,0,0,0,248,237,1,0,0,
  	0,248,249,1,0,0,0,249,250,1,0,0,0,250,251,5,61,0,0,251,252,3,4,2,0,252,
  	29,1,0,0,0,253,254,5,25,0,0,254,255,3,12,6,0,255,256,5,26,0,0,256,257,
  	3,38,19,0,257,258,5,68,0,0,258,280,1,0,0,0,259,260,5,27,0,0,260,261,3,
  	12,6,0,261,262,5,33,0,0,262,263,3,38,19,0,263,264,5,68,0,0,264,280,1,
  	0,0,0,265,266,5,37,0,0,266,267,3,12,6,0,267,268,5,68,0,0,268,280,1,0,
  	0,0,269,272,5,38,0,0,270,273,3,12,6,0,271,273,5,28,0,0,272,270,1,0,0,
  	0,272,271,1,0,0,0,273,274,1,0,0,0,274,280,5,68,0,0,275,276,5,36,0,0,276,
  	277,3,12,6,0,277,278,5,68,0,0,278,280,1,0,0,0,279,253,1,0,0,0,279,259,
  	1,0,0,0,279,265,1,0,0,0,279,269,1,0,0,0,279,275,1,0,0,0,280,31,1,0,0,
  	0,281,282,5,70,0,0,282,283,5,20,0,0,283,284,3,38,19,0,284,285,5,76,0,
  	0,285,286,5,68,0,0,286,33,1,0,0,0,287,288,5,31,0,0,288,289,3,12,6,0,289,
  	290,5,68,0,0,290,35,1,0,0,0,291,292,7,0,0,0,292,37,1,0,0,0,293,294,6,
  	19,-1,0,294,303,5,64,0,0,295,300,3,38,19,0,296,297,5,69,0,0,297,299,3,
  	38,19,0,298,296,1,0,0,0,299,302,1,0,0,0,300,298,1,0,0,0,300,301,1,0,0,
  	0,301,304,1,0,0,0,302,300,1,0,0,0,303,295,1,0,0,0,303,304,1,0,0,0,304,
  	305,1,0,0,0,305,344,5,65,0,0,306,307,5,77,0,0,307,316,5,66,0,0,308,313,
  	3,38,19,0,309,310,5,69,0,0,310,312,3,38,19,0,311,309,1,0,0,0,312,315,
  	1,0,0,0,313,311,1,0,0,0,313,314,1,0,0,0,314,317,1,0,0,0,315,313,1,0,0,
  	0,316,308,1,0,0,0,316,317,1,0,0,0,317,318,1,0,0,0,318,344,5,67,0,0,319,
  	320,5,77,0,0,320,321,3,38,19,0,321,322,3,38,19,23,322,344,1,0,0,0,323,
  	324,5,66,0,0,324,325,3,38,19,0,325,326,5,67,0,0,326,344,1,0,0,0,327,328,
  	5,48,0,0,328,344,3,38,19,18,329,330,7,1,0,0,330,344,3,38,19,17,331,344,
  	5,71,0,0,332,344,5,72,0,0,333,344,5,73,0,0,334,344,5,74,0,0,335,344,5,
  	75,0,0,336,344,5,76,0,0,337,344,3,12,6,0,338,339,5,30,0,0,339,344,3,12,
  	6,0,340,344,5,40,0,0,341,342,5,29,0,0,342,344,3,12,6,0,343,293,1,0,0,
  	0,343,306,1,0,0,0,343,319,1,0,0,0,343,323,1,0,0,0,343,327,1,0,0,0,343,
  	329,1,0,0,0,343,331,1,0,0,0,343,332,1,0,0,0,343,333,1,0,0,0,343,334,1,
  	0,0,0,343,335,1,0,0,0,343,336,1,0,0,0,343,337,1,0,0,0,343,338,1,0,0,0,
  	343,340,1,0,0,0,343,341,1,0,0,0,344,384,1,0,0,0,345,348,10,22,0,0,346,
  	347,5,23,0,0,347,349,5,76,0,0,348,346,1,0,0,0,348,349,1,0,0,0,349,350,
  	1,0,0,0,350,351,5,24,0,0,351,383,3,38,19,23,352,353,10,16,0,0,353,354,
  	7,2,0,0,354,383,3,38,19,17,355,356,10,15,0,0,356,357,7,1,0,0,357,383,
  	3,38,19,16,358,359,10,14,0,0,359,360,5,57,0,0,360,383,3,38,19,15,361,
  	362,10,13,0,0,362,363,7,3,0,0,363,383,3,38,19,14,364,365,10,12,0,0,365,
  	366,5,46,0,0,366,383,3,38,19,13,367,368,10,11,0,0,368,369,5,47,0,0,369,
  	383,3,38,19,12,370,371,10,21,0,0,371,372,5,64,0,0,372,373,3,38,19,0,373,
  	374,5,65,0,0,374,383,1,0,0,0,375,376,10,20,0,0,376,377,5,64,0,0,377,378,
  	3,38,19,0,378,379,5,55,0,0,379,380,3,38,19,0,380,381,5,65,0,0,381,383,
  	1,0,0,0,382,345,1,0,0,0,382,352,1,0,0,0,382,355,1,0,0,0,382,358,1,0,0,
  	0,382,361,1,0,0,0,382,364,1,0,0,0,382,367,1,0,0,0,382,370,1,0,0,0,382,
  	375,1,0,0,0,383,386,1,0,0,0,384,382,1,0,0,0,384,385,1,0,0,0,385,39,1,
  	0,0,0,386,384,1,0,0,0,27,43,49,62,81,89,104,106,115,118,148,153,164,185,
  	191,223,245,248,272,279,300,303,313,316,343,348,382,384
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tonParserStaticData = std::move(staticData);
}

}

TonParser::TonParser(TokenStream *input) : TonParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TonParser::TonParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TonParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *tonParserStaticData->atn, tonParserStaticData->decisionToDFA, tonParserStaticData->sharedContextCache, options);
}

TonParser::~TonParser() {
  delete _interpreter;
}

const atn::ATN& TonParser::getATN() const {
  return *tonParserStaticData->atn;
}

std::string TonParser::getGrammarFileName() const {
  return "Ton.g4";
}

const std::vector<std::string>& TonParser::getRuleNames() const {
  return tonParserStaticData->ruleNames;
}

const dfa::Vocabulary& TonParser::getVocabulary() const {
  return tonParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TonParser::getSerializedATN() const {
  return tonParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

TonParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::ProgramContext::EOF() {
  return getToken(TonParser::EOF, 0);
}

std::vector<TonParser::HeaderContext *> TonParser::ProgramContext::header() {
  return getRuleContexts<TonParser::HeaderContext>();
}

TonParser::HeaderContext* TonParser::ProgramContext::header(size_t i) {
  return getRuleContext<TonParser::HeaderContext>(i);
}

std::vector<TonParser::StatementContext *> TonParser::ProgramContext::statement() {
  return getRuleContexts<TonParser::StatementContext>();
}

TonParser::StatementContext* TonParser::ProgramContext::statement(size_t i) {
  return getRuleContext<TonParser::StatementContext>(i);
}


size_t TonParser::ProgramContext::getRuleIndex() const {
  return TonParser::RuleProgram;
}

void TonParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void TonParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


std::any TonParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

TonParser::ProgramContext* TonParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, TonParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TonParser::USE) {
      setState(40);
      header();
      setState(45);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & 4538921438427205) != 0)) {
      setState(46);
      statement();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(52);
    match(TonParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- HeaderContext ------------------------------------------------------------------

TonParser::HeaderContext::HeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::HeaderContext::USE() {
  return getToken(TonParser::USE, 0);
}

tree::TerminalNode* TonParser::HeaderContext::ID() {
  return getToken(TonParser::ID, 0);
}

tree::TerminalNode* TonParser::HeaderContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}


size_t TonParser::HeaderContext::getRuleIndex() const {
  return TonParser::RuleHeader;
}

void TonParser::HeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterHeader(this);
}

void TonParser::HeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitHeader(this);
}


std::any TonParser::HeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitHeader(this);
  else
    return visitor->visitChildren(this);
}

TonParser::HeaderContext* TonParser::header() {
  HeaderContext *_localctx = _tracker.createInstance<HeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, TonParser::RuleHeader);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(TonParser::USE);
    setState(55);
    match(TonParser::ID);
    setState(56);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

TonParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::BlockContext::L_BRACE() {
  return getToken(TonParser::L_BRACE, 0);
}

tree::TerminalNode* TonParser::BlockContext::R_BRACE() {
  return getToken(TonParser::R_BRACE, 0);
}

std::vector<TonParser::StatementContext *> TonParser::BlockContext::statement() {
  return getRuleContexts<TonParser::StatementContext>();
}

TonParser::StatementContext* TonParser::BlockContext::statement(size_t i) {
  return getRuleContext<TonParser::StatementContext>(i);
}


size_t TonParser::BlockContext::getRuleIndex() const {
  return TonParser::RuleBlock;
}

void TonParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void TonParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any TonParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

TonParser::BlockContext* TonParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 4, TonParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58);
    match(TonParser::L_BRACE);
    setState(62);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & 4538921438427205) != 0)) {
      setState(59);
      statement();
      setState(64);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(65);
    match(TonParser::R_BRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

TonParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TonParser::VarDeclContext* TonParser::StatementContext::varDecl() {
  return getRuleContext<TonParser::VarDeclContext>(0);
}

TonParser::TrackDeclContext* TonParser::StatementContext::trackDecl() {
  return getRuleContext<TonParser::TrackDeclContext>(0);
}

TonParser::AssignmentContext* TonParser::StatementContext::assignment() {
  return getRuleContext<TonParser::AssignmentContext>(0);
}

TonParser::IfStatContext* TonParser::StatementContext::ifStat() {
  return getRuleContext<TonParser::IfStatContext>(0);
}

TonParser::LoopStatContext* TonParser::StatementContext::loopStat() {
  return getRuleContext<TonParser::LoopStatContext>(0);
}

TonParser::UntilStatContext* TonParser::StatementContext::untilStat() {
  return getRuleContext<TonParser::UntilStatContext>(0);
}

TonParser::ShoutStatContext* TonParser::StatementContext::shoutStat() {
  return getRuleContext<TonParser::ShoutStatContext>(0);
}

TonParser::FuncDefContext* TonParser::StatementContext::funcDef() {
  return getRuleContext<TonParser::FuncDefContext>(0);
}

TonParser::AudioOpStatContext* TonParser::StatementContext::audioOpStat() {
  return getRuleContext<TonParser::AudioOpStatContext>(0);
}

TonParser::SaveStatContext* TonParser::StatementContext::saveStat() {
  return getRuleContext<TonParser::SaveStatContext>(0);
}

TonParser::PlayStatContext* TonParser::StatementContext::playStat() {
  return getRuleContext<TonParser::PlayStatContext>(0);
}

TonParser::ReturnStatContext* TonParser::StatementContext::returnStat() {
  return getRuleContext<TonParser::ReturnStatContext>(0);
}

TonParser::CallStatContext* TonParser::StatementContext::callStat() {
  return getRuleContext<TonParser::CallStatContext>(0);
}

TonParser::BlockContext* TonParser::StatementContext::block() {
  return getRuleContext<TonParser::BlockContext>(0);
}


size_t TonParser::StatementContext::getRuleIndex() const {
  return TonParser::RuleStatement;
}

void TonParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void TonParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any TonParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

TonParser::StatementContext* TonParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 6, TonParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(81);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      trackDecl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(69);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(70);
      ifStat();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(71);
      loopStat();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(72);
      untilStat();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(73);
      shoutStat();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(74);
      funcDef();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(75);
      audioOpStat();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(76);
      saveStat();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(77);
      playStat();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(78);
      returnStat();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(79);
      callStat();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(80);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

TonParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::VarDeclContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::VarDeclContext::MAKE() {
  return getToken(TonParser::MAKE, 0);
}

TonParser::TypeContext* TonParser::VarDeclContext::type() {
  return getRuleContext<TonParser::TypeContext>(0);
}

tree::TerminalNode* TonParser::VarDeclContext::ID() {
  return getToken(TonParser::ID, 0);
}

tree::TerminalNode* TonParser::VarDeclContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

tree::TerminalNode* TonParser::VarDeclContext::ASSIGN() {
  return getToken(TonParser::ASSIGN, 0);
}

TonParser::ExprContext* TonParser::VarDeclContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}


size_t TonParser::VarDeclContext::getRuleIndex() const {
  return TonParser::RuleVarDecl;
}

void TonParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void TonParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}


std::any TonParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

TonParser::VarDeclContext* TonParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, TonParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(83);
    match(TonParser::EXCLAM_MARK);
    setState(84);
    match(TonParser::MAKE);
    setState(85);
    type();
    setState(86);
    match(TonParser::ID);
    setState(89);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TonParser::ASSIGN) {
      setState(87);
      match(TonParser::ASSIGN);
      setState(88);
      expr(0);
    }
    setState(91);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TrackDeclContext ------------------------------------------------------------------

TonParser::TrackDeclContext::TrackDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TonParser::TrackDeclContext::ID() {
  return getTokens(TonParser::ID);
}

tree::TerminalNode* TonParser::TrackDeclContext::ID(size_t i) {
  return getToken(TonParser::ID, i);
}

tree::TerminalNode* TonParser::TrackDeclContext::NEW() {
  return getToken(TonParser::NEW, 0);
}

tree::TerminalNode* TonParser::TrackDeclContext::TRACK() {
  return getToken(TonParser::TRACK, 0);
}

tree::TerminalNode* TonParser::TrackDeclContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}


size_t TonParser::TrackDeclContext::getRuleIndex() const {
  return TonParser::RuleTrackDecl;
}

void TonParser::TrackDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrackDecl(this);
}

void TonParser::TrackDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrackDecl(this);
}


std::any TonParser::TrackDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitTrackDecl(this);
  else
    return visitor->visitChildren(this);
}

TonParser::TrackDeclContext* TonParser::trackDecl() {
  TrackDeclContext *_localctx = _tracker.createInstance<TrackDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, TonParser::RuleTrackDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(TonParser::ID);
    setState(94);
    match(TonParser::NEW);
    setState(95);
    match(TonParser::TRACK);
    setState(96);
    match(TonParser::ID);
    setState(97);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetContext ------------------------------------------------------------------

TonParser::TargetContext::TargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TonParser::TargetContext::ID() {
  return getTokens(TonParser::ID);
}

tree::TerminalNode* TonParser::TargetContext::ID(size_t i) {
  return getToken(TonParser::ID, i);
}

std::vector<tree::TerminalNode *> TonParser::TargetContext::DOT() {
  return getTokens(TonParser::DOT);
}

tree::TerminalNode* TonParser::TargetContext::DOT(size_t i) {
  return getToken(TonParser::DOT, i);
}

tree::TerminalNode* TonParser::TargetContext::STRING_VAL() {
  return getToken(TonParser::STRING_VAL, 0);
}


size_t TonParser::TargetContext::getRuleIndex() const {
  return TonParser::RuleTarget;
}

void TonParser::TargetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTarget(this);
}

void TonParser::TargetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTarget(this);
}


std::any TonParser::TargetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitTarget(this);
  else
    return visitor->visitChildren(this);
}

TonParser::TargetContext* TonParser::target() {
  TargetContext *_localctx = _tracker.createInstance<TargetContext>(_ctx, getState());
  enterRule(_localctx, 12, TonParser::RuleTarget);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    match(TonParser::ID);
    setState(106);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(100);
      match(TonParser::DOT);
      setState(101);
      match(TonParser::ID);
      setState(104);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(102);
        match(TonParser::DOT);
        setState(103);
        match(TonParser::STRING_VAL);
        break;
      }

      default:
        break;
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallStatContext ------------------------------------------------------------------

TonParser::CallStatContext::CallStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::CallStatContext::ID() {
  return getToken(TonParser::ID, 0);
}

tree::TerminalNode* TonParser::CallStatContext::L_PAREN() {
  return getToken(TonParser::L_PAREN, 0);
}

tree::TerminalNode* TonParser::CallStatContext::R_PAREN() {
  return getToken(TonParser::R_PAREN, 0);
}

tree::TerminalNode* TonParser::CallStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

std::vector<TonParser::ExprContext *> TonParser::CallStatContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::CallStatContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> TonParser::CallStatContext::COMMA() {
  return getTokens(TonParser::COMMA);
}

tree::TerminalNode* TonParser::CallStatContext::COMMA(size_t i) {
  return getToken(TonParser::COMMA, i);
}


size_t TonParser::CallStatContext::getRuleIndex() const {
  return TonParser::RuleCallStat;
}

void TonParser::CallStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallStat(this);
}

void TonParser::CallStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallStat(this);
}


std::any TonParser::CallStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitCallStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::CallStatContext* TonParser::callStat() {
  CallStatContext *_localctx = _tracker.createInstance<CallStatContext>(_ctx, getState());
  enterRule(_localctx, 14, TonParser::RuleCallStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    match(TonParser::ID);
    setState(109);
    match(TonParser::L_PAREN);
    setState(118);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & 558723718711299) != 0)) {
      setState(110);
      expr(0);
      setState(115);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TonParser::COMMA) {
        setState(111);
        match(TonParser::COMMA);
        setState(112);
        expr(0);
        setState(117);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(120);
    match(TonParser::R_PAREN);
    setState(121);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

TonParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TonParser::TargetContext* TonParser::AssignmentContext::target() {
  return getRuleContext<TonParser::TargetContext>(0);
}

tree::TerminalNode* TonParser::AssignmentContext::ASSIGN() {
  return getToken(TonParser::ASSIGN, 0);
}

TonParser::ExprContext* TonParser::AssignmentContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::AssignmentContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

tree::TerminalNode* TonParser::AssignmentContext::ADD_ASSIGN() {
  return getToken(TonParser::ADD_ASSIGN, 0);
}

tree::TerminalNode* TonParser::AssignmentContext::SUB_ASSIGN() {
  return getToken(TonParser::SUB_ASSIGN, 0);
}

tree::TerminalNode* TonParser::AssignmentContext::MULT_ASSIGN() {
  return getToken(TonParser::MULT_ASSIGN, 0);
}

tree::TerminalNode* TonParser::AssignmentContext::DIV_ASSIGN() {
  return getToken(TonParser::DIV_ASSIGN, 0);
}


size_t TonParser::AssignmentContext::getRuleIndex() const {
  return TonParser::RuleAssignment;
}

void TonParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void TonParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any TonParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

TonParser::AssignmentContext* TonParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 16, TonParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(148);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(123);
      target();
      setState(124);
      match(TonParser::ASSIGN);
      setState(125);
      expr(0);
      setState(126);
      match(TonParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(128);
      target();
      setState(129);
      match(TonParser::ADD_ASSIGN);
      setState(130);
      expr(0);
      setState(131);
      match(TonParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(133);
      target();
      setState(134);
      match(TonParser::SUB_ASSIGN);
      setState(135);
      expr(0);
      setState(136);
      match(TonParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(138);
      target();
      setState(139);
      match(TonParser::MULT_ASSIGN);
      setState(140);
      expr(0);
      setState(141);
      match(TonParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(143);
      target();
      setState(144);
      match(TonParser::DIV_ASSIGN);
      setState(145);
      expr(0);
      setState(146);
      match(TonParser::SEMI);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStatContext ------------------------------------------------------------------

TonParser::ReturnStatContext::ReturnStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::ReturnStatContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::ReturnStatContext::OUT() {
  return getToken(TonParser::OUT, 0);
}

tree::TerminalNode* TonParser::ReturnStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

TonParser::ExprContext* TonParser::ReturnStatContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}


size_t TonParser::ReturnStatContext::getRuleIndex() const {
  return TonParser::RuleReturnStat;
}

void TonParser::ReturnStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStat(this);
}

void TonParser::ReturnStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStat(this);
}


std::any TonParser::ReturnStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitReturnStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::ReturnStatContext* TonParser::returnStat() {
  ReturnStatContext *_localctx = _tracker.createInstance<ReturnStatContext>(_ctx, getState());
  enterRule(_localctx, 18, TonParser::RuleReturnStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    match(TonParser::EXCLAM_MARK);
    setState(151);
    match(TonParser::OUT);
    setState(153);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & 558723718711299) != 0)) {
      setState(152);
      expr(0);
    }
    setState(155);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShoutStatContext ------------------------------------------------------------------

TonParser::ShoutStatContext::ShoutStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::ShoutStatContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::ShoutStatContext::SHOUT() {
  return getToken(TonParser::SHOUT, 0);
}

std::vector<TonParser::ExprContext *> TonParser::ShoutStatContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::ShoutStatContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::ShoutStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

std::vector<tree::TerminalNode *> TonParser::ShoutStatContext::COMMA() {
  return getTokens(TonParser::COMMA);
}

tree::TerminalNode* TonParser::ShoutStatContext::COMMA(size_t i) {
  return getToken(TonParser::COMMA, i);
}


size_t TonParser::ShoutStatContext::getRuleIndex() const {
  return TonParser::RuleShoutStat;
}

void TonParser::ShoutStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShoutStat(this);
}

void TonParser::ShoutStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShoutStat(this);
}


std::any TonParser::ShoutStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitShoutStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::ShoutStatContext* TonParser::shoutStat() {
  ShoutStatContext *_localctx = _tracker.createInstance<ShoutStatContext>(_ctx, getState());
  enterRule(_localctx, 20, TonParser::RuleShoutStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(TonParser::EXCLAM_MARK);
    setState(158);
    match(TonParser::SHOUT);
    setState(159);
    expr(0);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TonParser::COMMA) {
      setState(160);
      match(TonParser::COMMA);
      setState(161);
      expr(0);
      setState(166);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(167);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatContext ------------------------------------------------------------------

TonParser::IfStatContext::IfStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> TonParser::IfStatContext::EXCLAM_MARK() {
  return getTokens(TonParser::EXCLAM_MARK);
}

tree::TerminalNode* TonParser::IfStatContext::EXCLAM_MARK(size_t i) {
  return getToken(TonParser::EXCLAM_MARK, i);
}

std::vector<tree::TerminalNode *> TonParser::IfStatContext::IF() {
  return getTokens(TonParser::IF);
}

tree::TerminalNode* TonParser::IfStatContext::IF(size_t i) {
  return getToken(TonParser::IF, i);
}

std::vector<tree::TerminalNode *> TonParser::IfStatContext::L_ANGLE() {
  return getTokens(TonParser::L_ANGLE);
}

tree::TerminalNode* TonParser::IfStatContext::L_ANGLE(size_t i) {
  return getToken(TonParser::L_ANGLE, i);
}

std::vector<TonParser::ExprContext *> TonParser::IfStatContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::IfStatContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> TonParser::IfStatContext::R_ANGLE() {
  return getTokens(TonParser::R_ANGLE);
}

tree::TerminalNode* TonParser::IfStatContext::R_ANGLE(size_t i) {
  return getToken(TonParser::R_ANGLE, i);
}

std::vector<TonParser::BlockContext *> TonParser::IfStatContext::block() {
  return getRuleContexts<TonParser::BlockContext>();
}

TonParser::BlockContext* TonParser::IfStatContext::block(size_t i) {
  return getRuleContext<TonParser::BlockContext>(i);
}

std::vector<tree::TerminalNode *> TonParser::IfStatContext::OTHERWISE() {
  return getTokens(TonParser::OTHERWISE);
}

tree::TerminalNode* TonParser::IfStatContext::OTHERWISE(size_t i) {
  return getToken(TonParser::OTHERWISE, i);
}


size_t TonParser::IfStatContext::getRuleIndex() const {
  return TonParser::RuleIfStat;
}

void TonParser::IfStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStat(this);
}

void TonParser::IfStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStat(this);
}


std::any TonParser::IfStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIfStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::IfStatContext* TonParser::ifStat() {
  IfStatContext *_localctx = _tracker.createInstance<IfStatContext>(_ctx, getState());
  enterRule(_localctx, 22, TonParser::RuleIfStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(TonParser::EXCLAM_MARK);
    setState(170);
    match(TonParser::IF);
    setState(171);
    match(TonParser::L_ANGLE);
    setState(172);
    expr(0);
    setState(173);
    match(TonParser::R_ANGLE);
    setState(174);
    block();
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(175);
        match(TonParser::EXCLAM_MARK);
        setState(176);
        match(TonParser::OTHERWISE);
        setState(177);
        match(TonParser::IF);
        setState(178);
        match(TonParser::L_ANGLE);
        setState(179);
        expr(0);
        setState(180);
        match(TonParser::R_ANGLE);
        setState(181);
        block(); 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
    setState(191);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(188);
      match(TonParser::EXCLAM_MARK);
      setState(189);
      match(TonParser::OTHERWISE);
      setState(190);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStatContext ------------------------------------------------------------------

TonParser::LoopStatContext::LoopStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::LoopStatContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::LoopStatContext::LOOP() {
  return getToken(TonParser::LOOP, 0);
}

tree::TerminalNode* TonParser::LoopStatContext::L_ANGLE() {
  return getToken(TonParser::L_ANGLE, 0);
}

std::vector<TonParser::ExprContext *> TonParser::LoopStatContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::LoopStatContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::LoopStatContext::TIMES() {
  return getToken(TonParser::TIMES, 0);
}

tree::TerminalNode* TonParser::LoopStatContext::R_ANGLE() {
  return getToken(TonParser::R_ANGLE, 0);
}

TonParser::BlockContext* TonParser::LoopStatContext::block() {
  return getRuleContext<TonParser::BlockContext>(0);
}

TonParser::TypeContext* TonParser::LoopStatContext::type() {
  return getRuleContext<TonParser::TypeContext>(0);
}

tree::TerminalNode* TonParser::LoopStatContext::ID() {
  return getToken(TonParser::ID, 0);
}

tree::TerminalNode* TonParser::LoopStatContext::FROM() {
  return getToken(TonParser::FROM, 0);
}

tree::TerminalNode* TonParser::LoopStatContext::TO() {
  return getToken(TonParser::TO, 0);
}

tree::TerminalNode* TonParser::LoopStatContext::ASSIGN() {
  return getToken(TonParser::ASSIGN, 0);
}


size_t TonParser::LoopStatContext::getRuleIndex() const {
  return TonParser::RuleLoopStat;
}

void TonParser::LoopStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopStat(this);
}

void TonParser::LoopStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopStat(this);
}


std::any TonParser::LoopStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitLoopStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::LoopStatContext* TonParser::loopStat() {
  LoopStatContext *_localctx = _tracker.createInstance<LoopStatContext>(_ctx, getState());
  enterRule(_localctx, 24, TonParser::RuleLoopStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(223);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      match(TonParser::EXCLAM_MARK);
      setState(194);
      match(TonParser::LOOP);
      setState(195);
      match(TonParser::L_ANGLE);
      setState(196);
      expr(0);
      setState(197);
      match(TonParser::TIMES);
      setState(198);
      match(TonParser::R_ANGLE);
      setState(199);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(201);
      match(TonParser::EXCLAM_MARK);
      setState(202);
      match(TonParser::LOOP);
      setState(203);
      match(TonParser::L_ANGLE);
      setState(204);
      type();
      setState(205);
      match(TonParser::ID);
      setState(206);
      match(TonParser::FROM);
      setState(207);
      expr(0);
      setState(208);
      match(TonParser::TO);
      setState(209);
      expr(0);
      setState(210);
      match(TonParser::R_ANGLE);
      setState(211);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(213);
      match(TonParser::EXCLAM_MARK);
      setState(214);
      match(TonParser::LOOP);
      setState(215);
      match(TonParser::L_ANGLE);
      setState(216);
      type();
      setState(217);
      match(TonParser::ID);
      setState(218);
      match(TonParser::ASSIGN);
      setState(219);
      expr(0);
      setState(220);
      match(TonParser::R_ANGLE);
      setState(221);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UntilStatContext ------------------------------------------------------------------

TonParser::UntilStatContext::UntilStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::UntilStatContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::UntilStatContext::UNTIL() {
  return getToken(TonParser::UNTIL, 0);
}

tree::TerminalNode* TonParser::UntilStatContext::L_ANGLE() {
  return getToken(TonParser::L_ANGLE, 0);
}

TonParser::ExprContext* TonParser::UntilStatContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::UntilStatContext::R_ANGLE() {
  return getToken(TonParser::R_ANGLE, 0);
}

TonParser::BlockContext* TonParser::UntilStatContext::block() {
  return getRuleContext<TonParser::BlockContext>(0);
}


size_t TonParser::UntilStatContext::getRuleIndex() const {
  return TonParser::RuleUntilStat;
}

void TonParser::UntilStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUntilStat(this);
}

void TonParser::UntilStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUntilStat(this);
}


std::any TonParser::UntilStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitUntilStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::UntilStatContext* TonParser::untilStat() {
  UntilStatContext *_localctx = _tracker.createInstance<UntilStatContext>(_ctx, getState());
  enterRule(_localctx, 26, TonParser::RuleUntilStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(TonParser::EXCLAM_MARK);
    setState(226);
    match(TonParser::UNTIL);
    setState(227);
    match(TonParser::L_ANGLE);
    setState(228);
    expr(0);
    setState(229);
    match(TonParser::R_ANGLE);
    setState(230);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDefContext ------------------------------------------------------------------

TonParser::FuncDefContext::FuncDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::FuncDefContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::FuncDefContext::DEFINE() {
  return getToken(TonParser::DEFINE, 0);
}

std::vector<TonParser::TypeContext *> TonParser::FuncDefContext::type() {
  return getRuleContexts<TonParser::TypeContext>();
}

TonParser::TypeContext* TonParser::FuncDefContext::type(size_t i) {
  return getRuleContext<TonParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> TonParser::FuncDefContext::ID() {
  return getTokens(TonParser::ID);
}

tree::TerminalNode* TonParser::FuncDefContext::ID(size_t i) {
  return getToken(TonParser::ID, i);
}

tree::TerminalNode* TonParser::FuncDefContext::L_ANGLE() {
  return getToken(TonParser::L_ANGLE, 0);
}

tree::TerminalNode* TonParser::FuncDefContext::R_ANGLE() {
  return getToken(TonParser::R_ANGLE, 0);
}

TonParser::BlockContext* TonParser::FuncDefContext::block() {
  return getRuleContext<TonParser::BlockContext>(0);
}

std::vector<tree::TerminalNode *> TonParser::FuncDefContext::COMMA() {
  return getTokens(TonParser::COMMA);
}

tree::TerminalNode* TonParser::FuncDefContext::COMMA(size_t i) {
  return getToken(TonParser::COMMA, i);
}


size_t TonParser::FuncDefContext::getRuleIndex() const {
  return TonParser::RuleFuncDef;
}

void TonParser::FuncDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncDef(this);
}

void TonParser::FuncDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncDef(this);
}


std::any TonParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

TonParser::FuncDefContext* TonParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 28, TonParser::RuleFuncDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    match(TonParser::EXCLAM_MARK);
    setState(233);
    match(TonParser::DEFINE);
    setState(234);
    type();
    setState(235);
    match(TonParser::ID);
    setState(236);
    match(TonParser::L_ANGLE);
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4094) != 0)) {
      setState(237);
      type();
      setState(238);
      match(TonParser::ID);
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TonParser::COMMA) {
        setState(239);
        match(TonParser::COMMA);
        setState(240);
        type();
        setState(241);
        match(TonParser::ID);
        setState(247);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(250);
    match(TonParser::R_ANGLE);
    setState(251);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AudioOpStatContext ------------------------------------------------------------------

TonParser::AudioOpStatContext::AudioOpStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::AudioOpStatContext::SHIFT() {
  return getToken(TonParser::SHIFT, 0);
}

TonParser::TargetContext* TonParser::AudioOpStatContext::target() {
  return getRuleContext<TonParser::TargetContext>(0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::BY() {
  return getToken(TonParser::BY, 0);
}

TonParser::ExprContext* TonParser::AudioOpStatContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::MOVE() {
  return getToken(TonParser::MOVE, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::TO() {
  return getToken(TonParser::TO, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::MUTE() {
  return getToken(TonParser::MUTE, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::UNMUTE() {
  return getToken(TonParser::UNMUTE, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::ALL() {
  return getToken(TonParser::ALL, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::TRASH() {
  return getToken(TonParser::TRASH, 0);
}


size_t TonParser::AudioOpStatContext::getRuleIndex() const {
  return TonParser::RuleAudioOpStat;
}

void TonParser::AudioOpStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAudioOpStat(this);
}

void TonParser::AudioOpStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAudioOpStat(this);
}


std::any TonParser::AudioOpStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAudioOpStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::AudioOpStatContext* TonParser::audioOpStat() {
  AudioOpStatContext *_localctx = _tracker.createInstance<AudioOpStatContext>(_ctx, getState());
  enterRule(_localctx, 30, TonParser::RuleAudioOpStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(279);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TonParser::SHIFT: {
        enterOuterAlt(_localctx, 1);
        setState(253);
        match(TonParser::SHIFT);
        setState(254);
        target();
        setState(255);
        match(TonParser::BY);
        setState(256);
        expr(0);
        setState(257);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::MOVE: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        match(TonParser::MOVE);
        setState(260);
        target();
        setState(261);
        match(TonParser::TO);
        setState(262);
        expr(0);
        setState(263);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::MUTE: {
        enterOuterAlt(_localctx, 3);
        setState(265);
        match(TonParser::MUTE);
        setState(266);
        target();
        setState(267);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::UNMUTE: {
        enterOuterAlt(_localctx, 4);
        setState(269);
        match(TonParser::UNMUTE);
        setState(272);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TonParser::ID: {
            setState(270);
            target();
            break;
          }

          case TonParser::ALL: {
            setState(271);
            match(TonParser::ALL);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(274);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::TRASH: {
        enterOuterAlt(_localctx, 5);
        setState(275);
        match(TonParser::TRASH);
        setState(276);
        target();
        setState(277);
        match(TonParser::SEMI);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SaveStatContext ------------------------------------------------------------------

TonParser::SaveStatContext::SaveStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::SaveStatContext::EXCLAM_MARK() {
  return getToken(TonParser::EXCLAM_MARK, 0);
}

tree::TerminalNode* TonParser::SaveStatContext::SAVE() {
  return getToken(TonParser::SAVE, 0);
}

TonParser::ExprContext* TonParser::SaveStatContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::SaveStatContext::STRING_VAL() {
  return getToken(TonParser::STRING_VAL, 0);
}

tree::TerminalNode* TonParser::SaveStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}


size_t TonParser::SaveStatContext::getRuleIndex() const {
  return TonParser::RuleSaveStat;
}

void TonParser::SaveStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSaveStat(this);
}

void TonParser::SaveStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSaveStat(this);
}


std::any TonParser::SaveStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitSaveStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::SaveStatContext* TonParser::saveStat() {
  SaveStatContext *_localctx = _tracker.createInstance<SaveStatContext>(_ctx, getState());
  enterRule(_localctx, 32, TonParser::RuleSaveStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(281);
    match(TonParser::EXCLAM_MARK);
    setState(282);
    match(TonParser::SAVE);
    setState(283);
    expr(0);
    setState(284);
    match(TonParser::STRING_VAL);
    setState(285);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PlayStatContext ------------------------------------------------------------------

TonParser::PlayStatContext::PlayStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::PlayStatContext::PLAY() {
  return getToken(TonParser::PLAY, 0);
}

TonParser::TargetContext* TonParser::PlayStatContext::target() {
  return getRuleContext<TonParser::TargetContext>(0);
}

tree::TerminalNode* TonParser::PlayStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}


size_t TonParser::PlayStatContext::getRuleIndex() const {
  return TonParser::RulePlayStat;
}

void TonParser::PlayStatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlayStat(this);
}

void TonParser::PlayStatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlayStat(this);
}


std::any TonParser::PlayStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitPlayStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::PlayStatContext* TonParser::playStat() {
  PlayStatContext *_localctx = _tracker.createInstance<PlayStatContext>(_ctx, getState());
  enterRule(_localctx, 34, TonParser::RulePlayStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(287);
    match(TonParser::PLAY);
    setState(288);
    target();
    setState(289);
    match(TonParser::SEMI);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

TonParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::TypeContext::TYPE_BOOL() {
  return getToken(TonParser::TYPE_BOOL, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_INT() {
  return getToken(TonParser::TYPE_INT, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_NUM() {
  return getToken(TonParser::TYPE_NUM, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_CHAR() {
  return getToken(TonParser::TYPE_CHAR, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_STRING() {
  return getToken(TonParser::TYPE_STRING, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_NOTE() {
  return getToken(TonParser::TYPE_NOTE, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_SOUND() {
  return getToken(TonParser::TYPE_SOUND, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_VOID() {
  return getToken(TonParser::TYPE_VOID, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_ARRAY() {
  return getToken(TonParser::TYPE_ARRAY, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_INSTR() {
  return getToken(TonParser::TYPE_INSTR, 0);
}

tree::TerminalNode* TonParser::TypeContext::TYPE_TIMELINE() {
  return getToken(TonParser::TYPE_TIMELINE, 0);
}


size_t TonParser::TypeContext::getRuleIndex() const {
  return TonParser::RuleType;
}

void TonParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void TonParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any TonParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

TonParser::TypeContext* TonParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 36, TonParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4094) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

TonParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t TonParser::ExprContext::getRuleIndex() const {
  return TonParser::RuleExpr;
}

void TonParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::AndExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::AndExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::AndExprContext::AND_OP() {
  return getToken(TonParser::AND_OP, 0);
}

TonParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void TonParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any TonParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddSubMixExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::AddSubMixExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::AddSubMixExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::AddSubMixExprContext::PLUS() {
  return getToken(TonParser::PLUS, 0);
}

tree::TerminalNode* TonParser::AddSubMixExprContext::MINUS() {
  return getToken(TonParser::MINUS, 0);
}

TonParser::AddSubMixExprContext::AddSubMixExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::AddSubMixExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSubMixExpr(this);
}
void TonParser::AddSubMixExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSubMixExpr(this);
}

std::any TonParser::AddSubMixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAddSubMixExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CreateSoundExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::CreateSoundExprContext::ID() {
  return getToken(TonParser::ID, 0);
}

std::vector<TonParser::ExprContext *> TonParser::CreateSoundExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::CreateSoundExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

TonParser::CreateSoundExprContext::CreateSoundExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::CreateSoundExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCreateSoundExpr(this);
}
void TonParser::CreateSoundExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCreateSoundExpr(this);
}

std::any TonParser::CreateSoundExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitCreateSoundExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::NumValExprContext::NUM_VAL() {
  return getToken(TonParser::NUM_VAL, 0);
}

TonParser::NumValExprContext::NumValExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::NumValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumValExpr(this);
}
void TonParser::NumValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumValExpr(this);
}

std::any TonParser::NumValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitNumValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TargetExprContext ------------------------------------------------------------------

TonParser::TargetContext* TonParser::TargetExprContext::target() {
  return getRuleContext<TonParser::TargetContext>(0);
}

TonParser::TargetExprContext::TargetExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::TargetExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetExpr(this);
}
void TonParser::TargetExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetExpr(this);
}

std::any TonParser::TargetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitTargetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelationalExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::RelationalExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::RelationalExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::RelationalExprContext::EQ() {
  return getToken(TonParser::EQ, 0);
}

tree::TerminalNode* TonParser::RelationalExprContext::NEQ() {
  return getToken(TonParser::NEQ, 0);
}

tree::TerminalNode* TonParser::RelationalExprContext::L_ANGLE() {
  return getToken(TonParser::L_ANGLE, 0);
}

tree::TerminalNode* TonParser::RelationalExprContext::R_ANGLE() {
  return getToken(TonParser::R_ANGLE, 0);
}

tree::TerminalNode* TonParser::RelationalExprContext::L_ANGLE_EQ() {
  return getToken(TonParser::L_ANGLE_EQ, 0);
}

tree::TerminalNode* TonParser::RelationalExprContext::R_ANGLE_EQ() {
  return getToken(TonParser::R_ANGLE_EQ, 0);
}

TonParser::RelationalExprContext::RelationalExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::RelationalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpr(this);
}
void TonParser::RelationalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpr(this);
}

std::any TonParser::RelationalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitRelationalExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IndexExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::IndexExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::IndexExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::IndexExprContext::L_BRACKET() {
  return getToken(TonParser::L_BRACKET, 0);
}

tree::TerminalNode* TonParser::IndexExprContext::R_BRACKET() {
  return getToken(TonParser::R_BRACKET, 0);
}

TonParser::IndexExprContext::IndexExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::IndexExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndexExpr(this);
}
void TonParser::IndexExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndexExpr(this);
}

std::any TonParser::IndexExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIndexExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NoteValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::NoteValExprContext::NOTE_VAL() {
  return getToken(TonParser::NOTE_VAL, 0);
}

TonParser::NoteValExprContext::NoteValExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::NoteValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNoteValExpr(this);
}
void TonParser::NoteValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNoteValExpr(this);
}

std::any TonParser::NoteValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitNoteValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TrackEventExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::TrackEventExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::TrackEventExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::TrackEventExprContext::AT() {
  return getToken(TonParser::AT, 0);
}

tree::TerminalNode* TonParser::TrackEventExprContext::AS() {
  return getToken(TonParser::AS, 0);
}

tree::TerminalNode* TonParser::TrackEventExprContext::STRING_VAL() {
  return getToken(TonParser::STRING_VAL, 0);
}

TonParser::TrackEventExprContext::TrackEventExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::TrackEventExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrackEventExpr(this);
}
void TonParser::TrackEventExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrackEventExpr(this);
}

std::any TonParser::TrackEventExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitTrackEventExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

TonParser::ExprContext* TonParser::NotExprContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::NotExprContext::NOT_KW() {
  return getToken(TonParser::NOT_KW, 0);
}

TonParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void TonParser::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

std::any TonParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IsolateExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::IsolateExprContext::ISOLATE() {
  return getToken(TonParser::ISOLATE, 0);
}

TonParser::TargetContext* TonParser::IsolateExprContext::target() {
  return getRuleContext<TonParser::TargetContext>(0);
}

TonParser::IsolateExprContext::IsolateExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::IsolateExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsolateExpr(this);
}
void TonParser::IsolateExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsolateExpr(this);
}

std::any TonParser::IsolateExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIsolateExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::BoolValExprContext::BOOL_VAL() {
  return getToken(TonParser::BOOL_VAL, 0);
}

TonParser::BoolValExprContext::BoolValExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::BoolValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolValExpr(this);
}
void TonParser::BoolValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolValExpr(this);
}

std::any TonParser::BoolValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitBoolValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::StringValExprContext::STRING_VAL() {
  return getToken(TonParser::STRING_VAL, 0);
}

TonParser::StringValExprContext::StringValExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::StringValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringValExpr(this);
}
void TonParser::StringValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringValExpr(this);
}

std::any TonParser::StringValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitStringValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExprContext ------------------------------------------------------------------

TonParser::ExprContext* TonParser::UnaryExprContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::UnaryExprContext::PLUS() {
  return getToken(TonParser::PLUS, 0);
}

tree::TerminalNode* TonParser::UnaryExprContext::MINUS() {
  return getToken(TonParser::MINUS, 0);
}

TonParser::UnaryExprContext::UnaryExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::UnaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpr(this);
}
void TonParser::UnaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpr(this);
}

std::any TonParser::UnaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitUnaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::OrExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::OrExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::OrExprContext::OR_OP() {
  return getToken(TonParser::OR_OP, 0);
}

TonParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void TonParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any TonParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConcatExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::ConcatExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::ConcatExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::ConcatExprContext::AMPERSAND() {
  return getToken(TonParser::AMPERSAND, 0);
}

TonParser::ConcatExprContext::ConcatExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::ConcatExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConcatExpr(this);
}
void TonParser::ConcatExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConcatExpr(this);
}

std::any TonParser::ConcatExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitConcatExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::ArrayExprContext::L_BRACKET() {
  return getToken(TonParser::L_BRACKET, 0);
}

tree::TerminalNode* TonParser::ArrayExprContext::R_BRACKET() {
  return getToken(TonParser::R_BRACKET, 0);
}

std::vector<TonParser::ExprContext *> TonParser::ArrayExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::ArrayExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> TonParser::ArrayExprContext::COMMA() {
  return getTokens(TonParser::COMMA);
}

tree::TerminalNode* TonParser::ArrayExprContext::COMMA(size_t i) {
  return getToken(TonParser::COMMA, i);
}

TonParser::ArrayExprContext::ArrayExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::ArrayExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayExpr(this);
}
void TonParser::ArrayExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayExpr(this);
}

std::any TonParser::ArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitArrayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::FunctionCallExprContext::ID() {
  return getToken(TonParser::ID, 0);
}

tree::TerminalNode* TonParser::FunctionCallExprContext::L_PAREN() {
  return getToken(TonParser::L_PAREN, 0);
}

tree::TerminalNode* TonParser::FunctionCallExprContext::R_PAREN() {
  return getToken(TonParser::R_PAREN, 0);
}

std::vector<TonParser::ExprContext *> TonParser::FunctionCallExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::FunctionCallExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> TonParser::FunctionCallExprContext::COMMA() {
  return getTokens(TonParser::COMMA);
}

tree::TerminalNode* TonParser::FunctionCallExprContext::COMMA(size_t i) {
  return getToken(TonParser::COMMA, i);
}

TonParser::FunctionCallExprContext::FunctionCallExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::FunctionCallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallExpr(this);
}
void TonParser::FunctionCallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallExpr(this);
}

std::any TonParser::FunctionCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitFunctionCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulDivExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::MulDivExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::MulDivExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::MulDivExprContext::MULT() {
  return getToken(TonParser::MULT, 0);
}

tree::TerminalNode* TonParser::MulDivExprContext::DIV_OP() {
  return getToken(TonParser::DIV_OP, 0);
}

tree::TerminalNode* TonParser::MulDivExprContext::COLON() {
  return getToken(TonParser::COLON, 0);
}

TonParser::MulDivExprContext::MulDivExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::MulDivExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivExpr(this);
}
void TonParser::MulDivExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivExpr(this);
}

std::any TonParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptySoundExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::EmptySoundExprContext::EMPTYSOUND() {
  return getToken(TonParser::EMPTYSOUND, 0);
}

TonParser::EmptySoundExprContext::EmptySoundExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::EmptySoundExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptySoundExpr(this);
}
void TonParser::EmptySoundExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptySoundExpr(this);
}

std::any TonParser::EmptySoundExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitEmptySoundExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::IntValExprContext::INT_VAL() {
  return getToken(TonParser::INT_VAL, 0);
}

TonParser::IntValExprContext::IntValExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::IntValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntValExpr(this);
}
void TonParser::IntValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntValExpr(this);
}

std::any TonParser::IntValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIntValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::CharValExprContext::CHAR_VAL() {
  return getToken(TonParser::CHAR_VAL, 0);
}

TonParser::CharValExprContext::CharValExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::CharValExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharValExpr(this);
}
void TonParser::CharValExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharValExpr(this);
}

std::any TonParser::CharValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitCharValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParensExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::ParensExprContext::L_PAREN() {
  return getToken(TonParser::L_PAREN, 0);
}

TonParser::ExprContext* TonParser::ParensExprContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::ParensExprContext::R_PAREN() {
  return getToken(TonParser::R_PAREN, 0);
}

TonParser::ParensExprContext::ParensExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::ParensExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParensExpr(this);
}
void TonParser::ParensExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParensExpr(this);
}

std::any TonParser::ParensExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitParensExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SliceExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::SliceExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::SliceExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::SliceExprContext::L_BRACKET() {
  return getToken(TonParser::L_BRACKET, 0);
}

tree::TerminalNode* TonParser::SliceExprContext::COLON() {
  return getToken(TonParser::COLON, 0);
}

tree::TerminalNode* TonParser::SliceExprContext::R_BRACKET() {
  return getToken(TonParser::R_BRACKET, 0);
}

TonParser::SliceExprContext::SliceExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::SliceExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSliceExpr(this);
}
void TonParser::SliceExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSliceExpr(this);
}

std::any TonParser::SliceExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitSliceExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LengthOfExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::LengthOfExprContext::LENGTH() {
  return getToken(TonParser::LENGTH, 0);
}

TonParser::TargetContext* TonParser::LengthOfExprContext::target() {
  return getRuleContext<TonParser::TargetContext>(0);
}

TonParser::LengthOfExprContext::LengthOfExprContext(ExprContext *ctx) { copyFrom(ctx); }

void TonParser::LengthOfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLengthOfExpr(this);
}
void TonParser::LengthOfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TonListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLengthOfExpr(this);
}

std::any TonParser::LengthOfExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitLengthOfExpr(this);
  else
    return visitor->visitChildren(this);
}

TonParser::ExprContext* TonParser::expr() {
   return expr(0);
}

TonParser::ExprContext* TonParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  TonParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  TonParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, TonParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(343);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(294);
      match(TonParser::L_BRACKET);
      setState(303);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & 558723718711299) != 0)) {
        setState(295);
        expr(0);
        setState(300);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TonParser::COMMA) {
          setState(296);
          match(TonParser::COMMA);
          setState(297);
          expr(0);
          setState(302);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(305);
      match(TonParser::R_BRACKET);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FunctionCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(306);
      match(TonParser::ID);
      setState(307);
      match(TonParser::L_PAREN);
      setState(316);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & 558723718711299) != 0)) {
        setState(308);
        expr(0);
        setState(313);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TonParser::COMMA) {
          setState(309);
          match(TonParser::COMMA);
          setState(310);
          expr(0);
          setState(315);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(318);
      match(TonParser::R_PAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CreateSoundExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(319);
      match(TonParser::ID);
      setState(320);
      expr(0);
      setState(321);
      expr(23);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(323);
      match(TonParser::L_PAREN);
      setState(324);
      expr(0);
      setState(325);
      match(TonParser::R_PAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(327);
      match(TonParser::NOT_KW);
      setState(328);
      expr(18);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<UnaryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(329);
      _la = _input->LA(1);
      if (!(_la == TonParser::PLUS

      || _la == TonParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(330);
      expr(17);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<NoteValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(331);
      match(TonParser::NOTE_VAL);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<IntValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(332);
      match(TonParser::INT_VAL);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<NumValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(333);
      match(TonParser::NUM_VAL);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<BoolValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(334);
      match(TonParser::BOOL_VAL);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<CharValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(335);
      match(TonParser::CHAR_VAL);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<StringValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(336);
      match(TonParser::STRING_VAL);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<TargetExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(337);
      target();
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<LengthOfExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(338);
      match(TonParser::LENGTH);
      setState(339);
      target();
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<EmptySoundExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(340);
      match(TonParser::EMPTYSOUND);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<IsolateExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(341);
      match(TonParser::ISOLATE);
      setState(342);
      target();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(384);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(382);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<TrackEventExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(345);

          if (!(precpred(_ctx, 22))) throw FailedPredicateException(this, "precpred(_ctx, 22)");
          setState(348);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TonParser::AS) {
            setState(346);
            match(TonParser::AS);
            setState(347);
            match(TonParser::STRING_VAL);
          }
          setState(350);
          match(TonParser::AT);
          setState(351);
          expr(23);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(352);

          if (!(precpred(_ctx, 16))) throw FailedPredicateException(this, "precpred(_ctx, 16)");
          setState(353);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 63050394783186944) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(354);
          expr(17);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddSubMixExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(355);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(356);
          _la = _input->LA(1);
          if (!(_la == TonParser::PLUS

          || _la == TonParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(357);
          expr(16);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ConcatExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(358);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(359);
          match(TonParser::AMPERSAND);
          setState(360);
          expr(15);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(361);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(362);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 4325144492135940096) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(363);
          expr(14);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(364);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(365);
          match(TonParser::AND_OP);
          setState(366);
          expr(13);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(367);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(368);
          match(TonParser::OR_OP);
          setState(369);
          expr(12);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<IndexExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(370);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(371);
          match(TonParser::L_BRACKET);
          setState(372);
          expr(0);
          setState(373);
          match(TonParser::R_BRACKET);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<SliceExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(375);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(376);
          match(TonParser::L_BRACKET);
          setState(377);
          expr(0);
          setState(378);
          match(TonParser::COLON);
          setState(379);
          expr(0);
          setState(380);
          match(TonParser::R_BRACKET);
          break;
        }

        default:
          break;
        } 
      }
      setState(386);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool TonParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 19: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TonParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 22);
    case 1: return precpred(_ctx, 16);
    case 2: return precpred(_ctx, 15);
    case 3: return precpred(_ctx, 14);
    case 4: return precpred(_ctx, 13);
    case 5: return precpred(_ctx, 12);
    case 6: return precpred(_ctx, 11);
    case 7: return precpred(_ctx, 21);
    case 8: return precpred(_ctx, 20);

  default:
    break;
  }
  return true;
}

void TonParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tonParserInitialize();
#else
  ::antlr4::internal::call_once(tonParserOnceFlag, tonParserInitialize);
#endif
}
