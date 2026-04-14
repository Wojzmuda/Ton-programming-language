
// Generated from Ton.g4 by ANTLR 4.13.2


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
      "target", "assignment", "shoutStat", "ifStat", "loopStat", "untilStat", 
      "funcDef", "audioOpStat", "saveStat", "playStat", "type", "expr"
    },
    std::vector<std::string>{
      "", "'BOOL'", "'INT'", "'NUMERICAL'", "'CHAR'", "'STRING'", "'NOTE'", 
      "'SOUND'", "'VOID'", "'ARRAY'", "'INSTRUMENT'", "'TIMELINE'", "'!make'", 
      "'!if'", "'if'", "'!otherwise'", "'!until'", "'!loop'", "'!define'", 
      "'!out'", "'!shout'", "'!save'", "'NEW'", "'TRACK'", "'AS'", "'AT'", 
      "'SHIFT'", "'BY'", "'MOVE'", "'ALL'", "'ISOLATE'", "'LENGTH'", "'PLAY'", 
      "'FROM'", "'TO'", "'TIMES'", "'USE'", "'TRASH'", "'MUTE'", "'UNMUTE'", 
      "'DIVIDE'", "'EMPTYSOUND'", "'<-'", "'+<-'", "'-<-'", "'*<-'", "'/<-'", 
      "'AND'", "'OR'", "'NOT'", "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", 
      "':'", "'.'", "'&'", "'<'", "'>'", "'{'", "'}'", "'['", "']'", "'('", 
      "')'", "';'", "','"
    },
    std::vector<std::string>{
      "", "TYPE_BOOL", "TYPE_INT", "TYPE_NUM", "TYPE_CHAR", "TYPE_STRING", 
      "TYPE_NOTE", "TYPE_SOUND", "TYPE_VOID", "TYPE_ARRAY", "TYPE_INSTR", 
      "TYPE_TIMELINE", "MAKE", "IF", "IF_PLAIN", "OTHERWISE", "UNTIL", "LOOP", 
      "DEFINE", "OUT", "SHOUT", "SAVE", "NEW", "TRACK", "AS", "AT", "SHIFT", 
      "BY", "MOVE", "ALL", "ISOLATE", "LENGTH", "PLAY", "FROM", "TO", "TIMES", 
      "USE", "TRASH", "MUTE", "UNMUTE", "DIVIDE", "EMPTYSOUND", "ASSIGN", 
      "ADD_ASSIGN", "SUB_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "AND_OP", 
      "OR_OP", "NOT_KW", "EQ", "NEQ", "PLUS", "MINUS", "MULT", "DIV_OP", 
      "COLON", "DOT", "AMPERSAND", "L_ANGLE", "R_ANGLE", "L_BRACE", "R_BRACE", 
      "L_BRACKET", "R_BRACKET", "L_PAREN", "R_PAREN", "SEMI", "COMMA", "NOTE_VAL", 
      "INT_VAL", "NUM_VAL", "BOOL_VAL", "CHAR_VAL", "STRING_VAL", "ID", 
      "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,77,340,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,1,0,5,0,38,8,0,10,0,12,0,41,9,0,1,0,
  	5,0,44,8,0,10,0,12,0,47,9,0,1,0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,5,2,57,8,
  	2,10,2,12,2,60,9,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,3,3,75,8,3,1,4,1,4,1,4,1,4,1,4,3,4,82,8,4,1,4,1,4,1,5,1,5,1,5,1,5,1,
  	5,1,5,1,6,1,6,1,6,1,6,1,6,3,6,97,8,6,3,6,99,8,6,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,3,7,126,8,7,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,
  	9,1,9,1,9,1,9,5,9,144,8,9,10,9,12,9,147,9,9,1,9,1,9,3,9,151,8,9,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,180,
  	8,10,1,11,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,5,12,198,8,12,10,12,12,12,201,9,12,3,12,203,8,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,1,13,1,13,3,13,227,8,13,1,13,1,13,1,13,1,13,
  	1,13,1,13,1,13,1,13,1,13,3,13,238,8,13,1,14,1,14,1,14,1,14,1,14,1,15,
  	1,15,1,15,1,15,1,16,1,16,1,17,1,17,1,17,1,17,1,17,5,17,256,8,17,10,17,
  	12,17,259,9,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,268,8,17,10,17,
  	12,17,271,9,17,3,17,273,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,
  	1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,
  	296,8,17,1,17,1,17,1,17,3,17,301,8,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,
  	17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,5,17,335,8,
  	17,10,17,12,17,338,9,17,1,17,0,1,34,18,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,0,4,1,0,1,11,1,0,54,56,1,0,52,53,2,0,50,51,59,60,379,
  	0,39,1,0,0,0,2,50,1,0,0,0,4,54,1,0,0,0,6,74,1,0,0,0,8,76,1,0,0,0,10,85,
  	1,0,0,0,12,91,1,0,0,0,14,125,1,0,0,0,16,127,1,0,0,0,18,131,1,0,0,0,20,
  	179,1,0,0,0,22,181,1,0,0,0,24,187,1,0,0,0,26,237,1,0,0,0,28,239,1,0,0,
  	0,30,244,1,0,0,0,32,248,1,0,0,0,34,295,1,0,0,0,36,38,3,2,1,0,37,36,1,
  	0,0,0,38,41,1,0,0,0,39,37,1,0,0,0,39,40,1,0,0,0,40,45,1,0,0,0,41,39,1,
  	0,0,0,42,44,3,6,3,0,43,42,1,0,0,0,44,47,1,0,0,0,45,43,1,0,0,0,45,46,1,
  	0,0,0,46,48,1,0,0,0,47,45,1,0,0,0,48,49,5,0,0,1,49,1,1,0,0,0,50,51,5,
  	36,0,0,51,52,5,75,0,0,52,53,5,67,0,0,53,3,1,0,0,0,54,58,5,61,0,0,55,57,
  	3,6,3,0,56,55,1,0,0,0,57,60,1,0,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,61,
  	1,0,0,0,60,58,1,0,0,0,61,62,5,62,0,0,62,5,1,0,0,0,63,75,3,8,4,0,64,75,
  	3,10,5,0,65,75,3,14,7,0,66,75,3,18,9,0,67,75,3,20,10,0,68,75,3,22,11,
  	0,69,75,3,16,8,0,70,75,3,24,12,0,71,75,3,26,13,0,72,75,3,28,14,0,73,75,
  	3,30,15,0,74,63,1,0,0,0,74,64,1,0,0,0,74,65,1,0,0,0,74,66,1,0,0,0,74,
  	67,1,0,0,0,74,68,1,0,0,0,74,69,1,0,0,0,74,70,1,0,0,0,74,71,1,0,0,0,74,
  	72,1,0,0,0,74,73,1,0,0,0,75,7,1,0,0,0,76,77,5,12,0,0,77,78,3,32,16,0,
  	78,81,5,75,0,0,79,80,5,42,0,0,80,82,3,34,17,0,81,79,1,0,0,0,81,82,1,0,
  	0,0,82,83,1,0,0,0,83,84,5,67,0,0,84,9,1,0,0,0,85,86,5,75,0,0,86,87,5,
  	22,0,0,87,88,5,23,0,0,88,89,5,75,0,0,89,90,5,67,0,0,90,11,1,0,0,0,91,
  	98,5,75,0,0,92,93,5,57,0,0,93,96,5,75,0,0,94,95,5,57,0,0,95,97,5,74,0,
  	0,96,94,1,0,0,0,96,97,1,0,0,0,97,99,1,0,0,0,98,92,1,0,0,0,98,99,1,0,0,
  	0,99,13,1,0,0,0,100,101,3,12,6,0,101,102,5,42,0,0,102,103,3,34,17,0,103,
  	104,5,67,0,0,104,126,1,0,0,0,105,106,3,12,6,0,106,107,5,43,0,0,107,108,
  	3,34,17,0,108,109,5,67,0,0,109,126,1,0,0,0,110,111,3,12,6,0,111,112,5,
  	44,0,0,112,113,3,34,17,0,113,114,5,67,0,0,114,126,1,0,0,0,115,116,3,12,
  	6,0,116,117,5,45,0,0,117,118,3,34,17,0,118,119,5,67,0,0,119,126,1,0,0,
  	0,120,121,3,12,6,0,121,122,5,46,0,0,122,123,3,34,17,0,123,124,5,67,0,
  	0,124,126,1,0,0,0,125,100,1,0,0,0,125,105,1,0,0,0,125,110,1,0,0,0,125,
  	115,1,0,0,0,125,120,1,0,0,0,126,15,1,0,0,0,127,128,5,20,0,0,128,129,3,
  	34,17,0,129,130,5,67,0,0,130,17,1,0,0,0,131,132,5,13,0,0,132,133,5,59,
  	0,0,133,134,3,34,17,0,134,135,5,60,0,0,135,145,3,4,2,0,136,137,5,15,0,
  	0,137,138,5,14,0,0,138,139,5,59,0,0,139,140,3,34,17,0,140,141,5,60,0,
  	0,141,142,3,4,2,0,142,144,1,0,0,0,143,136,1,0,0,0,144,147,1,0,0,0,145,
  	143,1,0,0,0,145,146,1,0,0,0,146,150,1,0,0,0,147,145,1,0,0,0,148,149,5,
  	15,0,0,149,151,3,4,2,0,150,148,1,0,0,0,150,151,1,0,0,0,151,19,1,0,0,0,
  	152,153,5,17,0,0,153,154,5,59,0,0,154,155,3,34,17,0,155,156,5,35,0,0,
  	156,157,5,60,0,0,157,158,3,4,2,0,158,180,1,0,0,0,159,160,5,17,0,0,160,
  	161,5,59,0,0,161,162,3,32,16,0,162,163,5,75,0,0,163,164,5,33,0,0,164,
  	165,3,34,17,0,165,166,5,34,0,0,166,167,3,34,17,0,167,168,5,60,0,0,168,
  	169,3,4,2,0,169,180,1,0,0,0,170,171,5,17,0,0,171,172,5,59,0,0,172,173,
  	3,32,16,0,173,174,5,75,0,0,174,175,5,42,0,0,175,176,3,34,17,0,176,177,
  	5,60,0,0,177,178,3,4,2,0,178,180,1,0,0,0,179,152,1,0,0,0,179,159,1,0,
  	0,0,179,170,1,0,0,0,180,21,1,0,0,0,181,182,5,16,0,0,182,183,5,59,0,0,
  	183,184,3,34,17,0,184,185,5,60,0,0,185,186,3,4,2,0,186,23,1,0,0,0,187,
  	188,5,18,0,0,188,189,3,32,16,0,189,190,5,75,0,0,190,202,5,59,0,0,191,
  	192,3,32,16,0,192,199,5,75,0,0,193,194,5,68,0,0,194,195,3,32,16,0,195,
  	196,5,75,0,0,196,198,1,0,0,0,197,193,1,0,0,0,198,201,1,0,0,0,199,197,
  	1,0,0,0,199,200,1,0,0,0,200,203,1,0,0,0,201,199,1,0,0,0,202,191,1,0,0,
  	0,202,203,1,0,0,0,203,204,1,0,0,0,204,205,5,60,0,0,205,206,3,4,2,0,206,
  	25,1,0,0,0,207,208,5,26,0,0,208,209,3,12,6,0,209,210,5,27,0,0,210,211,
  	3,34,17,0,211,212,5,67,0,0,212,238,1,0,0,0,213,214,5,28,0,0,214,215,3,
  	12,6,0,215,216,5,34,0,0,216,217,3,34,17,0,217,218,5,67,0,0,218,238,1,
  	0,0,0,219,220,5,38,0,0,220,221,3,12,6,0,221,222,5,67,0,0,222,238,1,0,
  	0,0,223,226,5,39,0,0,224,227,3,12,6,0,225,227,5,29,0,0,226,224,1,0,0,
  	0,226,225,1,0,0,0,227,228,1,0,0,0,228,238,5,67,0,0,229,230,5,30,0,0,230,
  	231,3,12,6,0,231,232,5,67,0,0,232,238,1,0,0,0,233,234,5,37,0,0,234,235,
  	3,12,6,0,235,236,5,67,0,0,236,238,1,0,0,0,237,207,1,0,0,0,237,213,1,0,
  	0,0,237,219,1,0,0,0,237,223,1,0,0,0,237,229,1,0,0,0,237,233,1,0,0,0,238,
  	27,1,0,0,0,239,240,5,21,0,0,240,241,3,34,17,0,241,242,5,74,0,0,242,243,
  	5,67,0,0,243,29,1,0,0,0,244,245,5,32,0,0,245,246,3,12,6,0,246,247,5,67,
  	0,0,247,31,1,0,0,0,248,249,7,0,0,0,249,33,1,0,0,0,250,251,6,17,-1,0,251,
  	252,5,63,0,0,252,257,3,34,17,0,253,254,5,68,0,0,254,256,3,34,17,0,255,
  	253,1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,257,258,1,0,0,0,258,260,1,
  	0,0,0,259,257,1,0,0,0,260,261,5,64,0,0,261,296,1,0,0,0,262,263,5,75,0,
  	0,263,272,5,65,0,0,264,269,3,34,17,0,265,266,5,68,0,0,266,268,3,34,17,
  	0,267,265,1,0,0,0,268,271,1,0,0,0,269,267,1,0,0,0,269,270,1,0,0,0,270,
  	273,1,0,0,0,271,269,1,0,0,0,272,264,1,0,0,0,272,273,1,0,0,0,273,274,1,
  	0,0,0,274,296,5,66,0,0,275,276,5,75,0,0,276,277,3,34,17,0,277,278,3,34,
  	17,21,278,296,1,0,0,0,279,280,5,65,0,0,280,281,3,34,17,0,281,282,5,66,
  	0,0,282,296,1,0,0,0,283,284,5,49,0,0,284,296,3,34,17,16,285,296,5,69,
  	0,0,286,296,5,70,0,0,287,296,5,71,0,0,288,296,5,72,0,0,289,296,5,73,0,
  	0,290,296,5,74,0,0,291,296,3,12,6,0,292,293,5,31,0,0,293,296,3,12,6,0,
  	294,296,5,41,0,0,295,250,1,0,0,0,295,262,1,0,0,0,295,275,1,0,0,0,295,
  	279,1,0,0,0,295,283,1,0,0,0,295,285,1,0,0,0,295,286,1,0,0,0,295,287,1,
  	0,0,0,295,288,1,0,0,0,295,289,1,0,0,0,295,290,1,0,0,0,295,291,1,0,0,0,
  	295,292,1,0,0,0,295,294,1,0,0,0,296,336,1,0,0,0,297,300,10,20,0,0,298,
  	299,5,24,0,0,299,301,5,74,0,0,300,298,1,0,0,0,300,301,1,0,0,0,301,302,
  	1,0,0,0,302,303,5,25,0,0,303,335,3,34,17,21,304,305,10,15,0,0,305,306,
  	7,1,0,0,306,335,3,34,17,16,307,308,10,14,0,0,308,309,7,2,0,0,309,335,
  	3,34,17,15,310,311,10,13,0,0,311,312,5,58,0,0,312,335,3,34,17,14,313,
  	314,10,12,0,0,314,315,7,3,0,0,315,335,3,34,17,13,316,317,10,11,0,0,317,
  	318,5,47,0,0,318,335,3,34,17,12,319,320,10,10,0,0,320,321,5,48,0,0,321,
  	335,3,34,17,11,322,323,10,19,0,0,323,324,5,63,0,0,324,325,3,34,17,0,325,
  	326,5,64,0,0,326,335,1,0,0,0,327,328,10,18,0,0,328,329,5,63,0,0,329,330,
  	3,34,17,0,330,331,5,56,0,0,331,332,3,34,17,0,332,333,5,64,0,0,333,335,
  	1,0,0,0,334,297,1,0,0,0,334,304,1,0,0,0,334,307,1,0,0,0,334,310,1,0,0,
  	0,334,313,1,0,0,0,334,316,1,0,0,0,334,319,1,0,0,0,334,322,1,0,0,0,334,
  	327,1,0,0,0,335,338,1,0,0,0,336,334,1,0,0,0,336,337,1,0,0,0,337,35,1,
  	0,0,0,338,336,1,0,0,0,22,39,45,58,74,81,96,98,125,145,150,179,199,202,
  	226,237,257,269,272,295,300,334,336
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
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TonParser::USE) {
      setState(36);
      header();
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(45);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & -9223372036618501261) != 0)) {
      setState(42);
      statement();
      setState(47);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(48);
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
    setState(50);
    match(TonParser::USE);
    setState(51);
    match(TonParser::ID);
    setState(52);
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
    setState(54);
    match(TonParser::L_BRACE);
    setState(58);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 12) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 12)) & -9223372036618501261) != 0)) {
      setState(55);
      statement();
      setState(60);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(61);
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


size_t TonParser::StatementContext::getRuleIndex() const {
  return TonParser::RuleStatement;
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
    setState(74);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(63);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(64);
      trackDecl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(65);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(66);
      ifStat();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(67);
      loopStat();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(68);
      untilStat();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(69);
      shoutStat();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(70);
      funcDef();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(71);
      audioOpStat();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(72);
      saveStat();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(73);
      playStat();
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
    setState(76);
    match(TonParser::MAKE);
    setState(77);
    type();
    setState(78);
    match(TonParser::ID);
    setState(81);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TonParser::ASSIGN) {
      setState(79);
      match(TonParser::ASSIGN);
      setState(80);
      expr(0);
    }
    setState(83);
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
    setState(85);
    match(TonParser::ID);
    setState(86);
    match(TonParser::NEW);
    setState(87);
    match(TonParser::TRACK);
    setState(88);
    match(TonParser::ID);
    setState(89);
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
    setState(91);
    match(TonParser::ID);
    setState(98);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(92);
      match(TonParser::DOT);
      setState(93);
      match(TonParser::ID);
      setState(96);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
      case 1: {
        setState(94);
        match(TonParser::DOT);
        setState(95);
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


std::any TonParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

TonParser::AssignmentContext* TonParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 14, TonParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(100);
      target();
      setState(101);
      match(TonParser::ASSIGN);
      setState(102);
      expr(0);
      setState(103);
      match(TonParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(105);
      target();
      setState(106);
      match(TonParser::ADD_ASSIGN);
      setState(107);
      expr(0);
      setState(108);
      match(TonParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(110);
      target();
      setState(111);
      match(TonParser::SUB_ASSIGN);
      setState(112);
      expr(0);
      setState(113);
      match(TonParser::SEMI);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(115);
      target();
      setState(116);
      match(TonParser::MULT_ASSIGN);
      setState(117);
      expr(0);
      setState(118);
      match(TonParser::SEMI);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(120);
      target();
      setState(121);
      match(TonParser::DIV_ASSIGN);
      setState(122);
      expr(0);
      setState(123);
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

//----------------- ShoutStatContext ------------------------------------------------------------------

TonParser::ShoutStatContext::ShoutStatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TonParser::ShoutStatContext::SHOUT() {
  return getToken(TonParser::SHOUT, 0);
}

TonParser::ExprContext* TonParser::ShoutStatContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::ShoutStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}


size_t TonParser::ShoutStatContext::getRuleIndex() const {
  return TonParser::RuleShoutStat;
}


std::any TonParser::ShoutStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitShoutStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::ShoutStatContext* TonParser::shoutStat() {
  ShoutStatContext *_localctx = _tracker.createInstance<ShoutStatContext>(_ctx, getState());
  enterRule(_localctx, 16, TonParser::RuleShoutStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(TonParser::SHOUT);
    setState(128);
    expr(0);
    setState(129);
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

tree::TerminalNode* TonParser::IfStatContext::IF() {
  return getToken(TonParser::IF, 0);
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

std::vector<tree::TerminalNode *> TonParser::IfStatContext::IF_PLAIN() {
  return getTokens(TonParser::IF_PLAIN);
}

tree::TerminalNode* TonParser::IfStatContext::IF_PLAIN(size_t i) {
  return getToken(TonParser::IF_PLAIN, i);
}


size_t TonParser::IfStatContext::getRuleIndex() const {
  return TonParser::RuleIfStat;
}


std::any TonParser::IfStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIfStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::IfStatContext* TonParser::ifStat() {
  IfStatContext *_localctx = _tracker.createInstance<IfStatContext>(_ctx, getState());
  enterRule(_localctx, 18, TonParser::RuleIfStat);
  size_t _la = 0;

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
    setState(131);
    match(TonParser::IF);
    setState(132);
    match(TonParser::L_ANGLE);
    setState(133);
    expr(0);
    setState(134);
    match(TonParser::R_ANGLE);
    setState(135);
    block();
    setState(145);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(136);
        match(TonParser::OTHERWISE);
        setState(137);
        match(TonParser::IF_PLAIN);
        setState(138);
        match(TonParser::L_ANGLE);
        setState(139);
        expr(0);
        setState(140);
        match(TonParser::R_ANGLE);
        setState(141);
        block(); 
      }
      setState(147);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TonParser::OTHERWISE) {
      setState(148);
      match(TonParser::OTHERWISE);
      setState(149);
      block();
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


std::any TonParser::LoopStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitLoopStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::LoopStatContext* TonParser::loopStat() {
  LoopStatContext *_localctx = _tracker.createInstance<LoopStatContext>(_ctx, getState());
  enterRule(_localctx, 20, TonParser::RuleLoopStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(152);
      match(TonParser::LOOP);
      setState(153);
      match(TonParser::L_ANGLE);
      setState(154);
      expr(0);
      setState(155);
      match(TonParser::TIMES);
      setState(156);
      match(TonParser::R_ANGLE);
      setState(157);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(159);
      match(TonParser::LOOP);
      setState(160);
      match(TonParser::L_ANGLE);
      setState(161);
      type();
      setState(162);
      match(TonParser::ID);
      setState(163);
      match(TonParser::FROM);
      setState(164);
      expr(0);
      setState(165);
      match(TonParser::TO);
      setState(166);
      expr(0);
      setState(167);
      match(TonParser::R_ANGLE);
      setState(168);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(170);
      match(TonParser::LOOP);
      setState(171);
      match(TonParser::L_ANGLE);
      setState(172);
      type();
      setState(173);
      match(TonParser::ID);
      setState(174);
      match(TonParser::ASSIGN);
      setState(175);
      expr(0);
      setState(176);
      match(TonParser::R_ANGLE);
      setState(177);
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


std::any TonParser::UntilStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitUntilStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::UntilStatContext* TonParser::untilStat() {
  UntilStatContext *_localctx = _tracker.createInstance<UntilStatContext>(_ctx, getState());
  enterRule(_localctx, 22, TonParser::RuleUntilStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(181);
    match(TonParser::UNTIL);
    setState(182);
    match(TonParser::L_ANGLE);
    setState(183);
    expr(0);
    setState(184);
    match(TonParser::R_ANGLE);
    setState(185);
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


std::any TonParser::FuncDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitFuncDef(this);
  else
    return visitor->visitChildren(this);
}

TonParser::FuncDefContext* TonParser::funcDef() {
  FuncDefContext *_localctx = _tracker.createInstance<FuncDefContext>(_ctx, getState());
  enterRule(_localctx, 24, TonParser::RuleFuncDef);
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
    setState(187);
    match(TonParser::DEFINE);
    setState(188);
    type();
    setState(189);
    match(TonParser::ID);
    setState(190);
    match(TonParser::L_ANGLE);
    setState(202);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4094) != 0)) {
      setState(191);
      type();
      setState(192);
      match(TonParser::ID);
      setState(199);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TonParser::COMMA) {
        setState(193);
        match(TonParser::COMMA);
        setState(194);
        type();
        setState(195);
        match(TonParser::ID);
        setState(201);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(204);
    match(TonParser::R_ANGLE);
    setState(205);
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

tree::TerminalNode* TonParser::AudioOpStatContext::ISOLATE() {
  return getToken(TonParser::ISOLATE, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::TRASH() {
  return getToken(TonParser::TRASH, 0);
}


size_t TonParser::AudioOpStatContext::getRuleIndex() const {
  return TonParser::RuleAudioOpStat;
}


std::any TonParser::AudioOpStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAudioOpStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::AudioOpStatContext* TonParser::audioOpStat() {
  AudioOpStatContext *_localctx = _tracker.createInstance<AudioOpStatContext>(_ctx, getState());
  enterRule(_localctx, 26, TonParser::RuleAudioOpStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(237);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TonParser::SHIFT: {
        enterOuterAlt(_localctx, 1);
        setState(207);
        match(TonParser::SHIFT);
        setState(208);
        target();
        setState(209);
        match(TonParser::BY);
        setState(210);
        expr(0);
        setState(211);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::MOVE: {
        enterOuterAlt(_localctx, 2);
        setState(213);
        match(TonParser::MOVE);
        setState(214);
        target();
        setState(215);
        match(TonParser::TO);
        setState(216);
        expr(0);
        setState(217);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::MUTE: {
        enterOuterAlt(_localctx, 3);
        setState(219);
        match(TonParser::MUTE);
        setState(220);
        target();
        setState(221);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::UNMUTE: {
        enterOuterAlt(_localctx, 4);
        setState(223);
        match(TonParser::UNMUTE);
        setState(226);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case TonParser::ID: {
            setState(224);
            target();
            break;
          }

          case TonParser::ALL: {
            setState(225);
            match(TonParser::ALL);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        setState(228);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::ISOLATE: {
        enterOuterAlt(_localctx, 5);
        setState(229);
        match(TonParser::ISOLATE);
        setState(230);
        target();
        setState(231);
        match(TonParser::SEMI);
        break;
      }

      case TonParser::TRASH: {
        enterOuterAlt(_localctx, 6);
        setState(233);
        match(TonParser::TRASH);
        setState(234);
        target();
        setState(235);
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


std::any TonParser::SaveStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitSaveStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::SaveStatContext* TonParser::saveStat() {
  SaveStatContext *_localctx = _tracker.createInstance<SaveStatContext>(_ctx, getState());
  enterRule(_localctx, 28, TonParser::RuleSaveStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(TonParser::SAVE);
    setState(240);
    expr(0);
    setState(241);
    match(TonParser::STRING_VAL);
    setState(242);
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


std::any TonParser::PlayStatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitPlayStat(this);
  else
    return visitor->visitChildren(this);
}

TonParser::PlayStatContext* TonParser::playStat() {
  PlayStatContext *_localctx = _tracker.createInstance<PlayStatContext>(_ctx, getState());
  enterRule(_localctx, 30, TonParser::RulePlayStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(TonParser::PLAY);
    setState(245);
    target();
    setState(246);
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


std::any TonParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

TonParser::TypeContext* TonParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 32, TonParser::RuleType);
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
    setState(248);
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


std::any TonParser::AddSubMixExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAddSubMixExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BoolValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::BoolValExprContext::BOOL_VAL() {
  return getToken(TonParser::BOOL_VAL, 0);
}

TonParser::BoolValExprContext::BoolValExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::BoolValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitBoolValExpr(this);
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


std::any TonParser::CreateSoundExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitCreateSoundExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::StringValExprContext::STRING_VAL() {
  return getToken(TonParser::STRING_VAL, 0);
}

TonParser::StringValExprContext::StringValExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::StringValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitStringValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::NumValExprContext::NUM_VAL() {
  return getToken(TonParser::NUM_VAL, 0);
}

TonParser::NumValExprContext::NumValExprContext(ExprContext *ctx) { copyFrom(ctx); }


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

TonParser::RelationalExprContext::RelationalExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::RelationalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitRelationalExpr(this);
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


std::any TonParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
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


std::any TonParser::IndexExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIndexExpr(this);
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

std::vector<TonParser::ExprContext *> TonParser::ArrayExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::ArrayExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::ArrayExprContext::R_BRACKET() {
  return getToken(TonParser::R_BRACKET, 0);
}

std::vector<tree::TerminalNode *> TonParser::ArrayExprContext::COMMA() {
  return getTokens(TonParser::COMMA);
}

tree::TerminalNode* TonParser::ArrayExprContext::COMMA(size_t i) {
  return getToken(TonParser::COMMA, i);
}

TonParser::ArrayExprContext::ArrayExprContext(ExprContext *ctx) { copyFrom(ctx); }


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


std::any TonParser::MulDivExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitMulDivExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NoteValExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::NoteValExprContext::NOTE_VAL() {
  return getToken(TonParser::NOTE_VAL, 0);
}

TonParser::NoteValExprContext::NoteValExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::NoteValExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitNoteValExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EmptySoundExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::EmptySoundExprContext::EMPTYSOUND() {
  return getToken(TonParser::EMPTYSOUND, 0);
}

TonParser::EmptySoundExprContext::EmptySoundExprContext(ExprContext *ctx) { copyFrom(ctx); }


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


std::any TonParser::ParensExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitParensExpr(this);
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


std::any TonParser::TrackEventExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitTrackEventExpr(this);
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


std::any TonParser::SliceExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitSliceExpr(this);
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


std::any TonParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
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
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, TonParser::RuleExpr, precedence);

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
    setState(295);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(251);
      match(TonParser::L_BRACKET);
      setState(252);
      expr(0);
      setState(257);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TonParser::COMMA) {
        setState(253);
        match(TonParser::COMMA);
        setState(254);
        expr(0);
        setState(259);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(260);
      match(TonParser::R_BRACKET);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FunctionCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(262);
      match(TonParser::ID);
      setState(263);
      match(TonParser::L_PAREN);
      setState(272);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 31) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 31)) & 34930969281537) != 0)) {
        setState(264);
        expr(0);
        setState(269);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TonParser::COMMA) {
          setState(265);
          match(TonParser::COMMA);
          setState(266);
          expr(0);
          setState(271);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(274);
      match(TonParser::R_PAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CreateSoundExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(275);
      match(TonParser::ID);
      setState(276);
      expr(0);
      setState(277);
      expr(21);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(279);
      match(TonParser::L_PAREN);
      setState(280);
      expr(0);
      setState(281);
      match(TonParser::R_PAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(283);
      match(TonParser::NOT_KW);
      setState(284);
      expr(16);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NoteValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(285);
      match(TonParser::NOTE_VAL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IntValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(286);
      match(TonParser::INT_VAL);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<NumValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(287);
      match(TonParser::NUM_VAL);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BoolValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(288);
      match(TonParser::BOOL_VAL);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<CharValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(289);
      match(TonParser::CHAR_VAL);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<StringValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(290);
      match(TonParser::STRING_VAL);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<TargetExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(291);
      target();
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<LengthOfExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(292);
      match(TonParser::LENGTH);
      setState(293);
      target();
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<EmptySoundExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(294);
      match(TonParser::EMPTYSOUND);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(336);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(334);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<TrackEventExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(297);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(300);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == TonParser::AS) {
            setState(298);
            match(TonParser::AS);
            setState(299);
            match(TonParser::STRING_VAL);
          }
          setState(302);
          match(TonParser::AT);
          setState(303);
          expr(21);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(304);

          if (!(precpred(_ctx, 15))) throw FailedPredicateException(this, "precpred(_ctx, 15)");
          setState(305);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 126100789566373888) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(306);
          expr(16);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddSubMixExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(307);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(308);
          _la = _input->LA(1);
          if (!(_la == TonParser::PLUS

          || _la == TonParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(309);
          expr(15);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ConcatExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(310);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(311);
          match(TonParser::AMPERSAND);
          setState(312);
          expr(14);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(313);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(314);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1732759956630798336) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(315);
          expr(13);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(316);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(317);
          match(TonParser::AND_OP);
          setState(318);
          expr(12);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(319);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(320);
          match(TonParser::OR_OP);
          setState(321);
          expr(11);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<IndexExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(322);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(323);
          match(TonParser::L_BRACKET);
          setState(324);
          expr(0);
          setState(325);
          match(TonParser::R_BRACKET);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<SliceExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(327);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(328);
          match(TonParser::L_BRACKET);
          setState(329);
          expr(0);
          setState(330);
          match(TonParser::COLON);
          setState(331);
          expr(0);
          setState(332);
          match(TonParser::R_BRACKET);
          break;
        }

        default:
          break;
        } 
      }
      setState(338);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
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
    case 17: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TonParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 20);
    case 1: return precpred(_ctx, 15);
    case 2: return precpred(_ctx, 14);
    case 3: return precpred(_ctx, 13);
    case 4: return precpred(_ctx, 12);
    case 5: return precpred(_ctx, 11);
    case 6: return precpred(_ctx, 10);
    case 7: return precpred(_ctx, 19);
    case 8: return precpred(_ctx, 18);

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
