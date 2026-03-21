
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
      "program", "header", "block", "statement", "varDecl", "assignment", 
      "shoutStat", "ifStat", "loopStat", "untilStat", "funcDef", "audioOpStat", 
      "saveStat", "type", "expr"
    },
    std::vector<std::string>{
      "", "'BOOL'", "'INT'", "'NUMERICAL'", "'CHAR'", "'STRING'", "'NOTE'", 
      "'SOUND'", "'VOID'", "'ARRAY'", "'INSTRUMENT'", "'!make'", "'!if'", 
      "'if'", "'!otherwise'", "'!until'", "'!loop'", "'!define'", "'!out'", 
      "'!shout'", "'!save'", "'FROM'", "'TO'", "'TIMES'", "'USE'", "'MIXWITH'", 
      "'TRASH'", "'MUTE'", "'DIVIDE'", "'EMPTYSOUND'", "'<-'", "'AND'", 
      "'OR'", "'NOT'", "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", "':'", 
      "'<'", "'>'", "'{'", "'}'", "'['", "']'", "'('", "')'", "';'", "','"
    },
    std::vector<std::string>{
      "", "TYPE_BOOL", "TYPE_INT", "TYPE_NUM", "TYPE_CHAR", "TYPE_STRING", 
      "TYPE_NOTE", "TYPE_SOUND", "TYPE_VOID", "TYPE_ARRAY", "TYPE_INSTR", 
      "MAKE", "IF", "IF_PLAIN", "OTHERWISE", "UNTIL", "LOOP", "DEFINE", 
      "OUT", "SHOUT", "SAVE", "FROM", "TO", "TIMES", "USE", "MIXWITH", "TRASH", 
      "MUTE", "DIVIDE", "EMPTYSOUND", "ASSIGN", "AND_OP", "OR_OP", "NOT_KW", 
      "EQ", "NEQ", "PLUS", "MINUS", "MULT", "DIV_OP", "COLON", "L_ANGLE", 
      "R_ANGLE", "L_BRACE", "R_BRACE", "L_BRACKET", "R_BRACKET", "L_PAREN", 
      "R_PAREN", "SEMI", "COMMA", "NOTE_VAL", "INT_VAL", "NUM_VAL", "BOOL_VAL", 
      "CHAR_VAL", "STRING_VAL", "ID", "WS", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,59,272,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,1,0,5,0,32,8,0,10,0,12,0,35,9,0,1,0,5,0,38,8,0,10,0,12,0,41,9,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,2,1,2,5,2,51,8,2,10,2,12,2,54,9,2,1,2,1,2,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,67,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,5,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,5,7,97,8,7,10,7,12,7,100,9,7,1,7,1,7,3,7,104,8,7,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,
  	8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,133,8,8,1,9,1,9,1,9,1,9,1,9,1,9,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,151,8,10,10,10,
  	12,10,154,9,10,3,10,156,8,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,
  	3,11,180,8,11,1,12,1,12,1,12,1,12,1,12,1,13,1,13,1,14,1,14,1,14,1,14,
  	1,14,5,14,194,8,14,10,14,12,14,197,9,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,5,14,206,8,14,10,14,12,14,209,9,14,3,14,211,8,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,3,14,232,8,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,5,14,267,8,14,10,14,
  	12,14,270,9,14,1,14,0,1,28,15,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	0,4,1,0,1,10,1,0,38,40,1,0,36,37,2,0,34,35,41,42,298,0,33,1,0,0,0,2,44,
  	1,0,0,0,4,48,1,0,0,0,6,66,1,0,0,0,8,68,1,0,0,0,10,75,1,0,0,0,12,80,1,
  	0,0,0,14,84,1,0,0,0,16,132,1,0,0,0,18,134,1,0,0,0,20,140,1,0,0,0,22,179,
  	1,0,0,0,24,181,1,0,0,0,26,186,1,0,0,0,28,231,1,0,0,0,30,32,3,2,1,0,31,
  	30,1,0,0,0,32,35,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,39,1,0,0,0,35,
  	33,1,0,0,0,36,38,3,6,3,0,37,36,1,0,0,0,38,41,1,0,0,0,39,37,1,0,0,0,39,
  	40,1,0,0,0,40,42,1,0,0,0,41,39,1,0,0,0,42,43,5,0,0,1,43,1,1,0,0,0,44,
  	45,5,24,0,0,45,46,5,57,0,0,46,47,5,49,0,0,47,3,1,0,0,0,48,52,5,43,0,0,
  	49,51,3,6,3,0,50,49,1,0,0,0,51,54,1,0,0,0,52,50,1,0,0,0,52,53,1,0,0,0,
  	53,55,1,0,0,0,54,52,1,0,0,0,55,56,5,44,0,0,56,5,1,0,0,0,57,67,3,8,4,0,
  	58,67,3,10,5,0,59,67,3,14,7,0,60,67,3,16,8,0,61,67,3,18,9,0,62,67,3,12,
  	6,0,63,67,3,20,10,0,64,67,3,22,11,0,65,67,3,24,12,0,66,57,1,0,0,0,66,
  	58,1,0,0,0,66,59,1,0,0,0,66,60,1,0,0,0,66,61,1,0,0,0,66,62,1,0,0,0,66,
  	63,1,0,0,0,66,64,1,0,0,0,66,65,1,0,0,0,67,7,1,0,0,0,68,69,5,11,0,0,69,
  	70,3,26,13,0,70,71,5,57,0,0,71,72,5,30,0,0,72,73,3,28,14,0,73,74,5,49,
  	0,0,74,9,1,0,0,0,75,76,5,57,0,0,76,77,5,30,0,0,77,78,3,28,14,0,78,79,
  	5,49,0,0,79,11,1,0,0,0,80,81,5,19,0,0,81,82,3,28,14,0,82,83,5,49,0,0,
  	83,13,1,0,0,0,84,85,5,12,0,0,85,86,5,41,0,0,86,87,3,28,14,0,87,88,5,42,
  	0,0,88,98,3,4,2,0,89,90,5,14,0,0,90,91,5,13,0,0,91,92,5,41,0,0,92,93,
  	3,28,14,0,93,94,5,42,0,0,94,95,3,4,2,0,95,97,1,0,0,0,96,89,1,0,0,0,97,
  	100,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,103,1,0,0,0,100,98,1,0,0,0,
  	101,102,5,14,0,0,102,104,3,4,2,0,103,101,1,0,0,0,103,104,1,0,0,0,104,
  	15,1,0,0,0,105,106,5,16,0,0,106,107,5,41,0,0,107,108,3,28,14,0,108,109,
  	5,23,0,0,109,110,5,42,0,0,110,111,3,4,2,0,111,133,1,0,0,0,112,113,5,16,
  	0,0,113,114,5,41,0,0,114,115,3,26,13,0,115,116,5,57,0,0,116,117,5,21,
  	0,0,117,118,3,28,14,0,118,119,5,22,0,0,119,120,3,28,14,0,120,121,5,42,
  	0,0,121,122,3,4,2,0,122,133,1,0,0,0,123,124,5,16,0,0,124,125,5,41,0,0,
  	125,126,3,26,13,0,126,127,5,57,0,0,127,128,5,30,0,0,128,129,3,28,14,0,
  	129,130,5,42,0,0,130,131,3,4,2,0,131,133,1,0,0,0,132,105,1,0,0,0,132,
  	112,1,0,0,0,132,123,1,0,0,0,133,17,1,0,0,0,134,135,5,15,0,0,135,136,5,
  	41,0,0,136,137,3,28,14,0,137,138,5,42,0,0,138,139,3,4,2,0,139,19,1,0,
  	0,0,140,141,5,17,0,0,141,142,3,26,13,0,142,143,5,57,0,0,143,155,5,41,
  	0,0,144,145,3,26,13,0,145,152,5,57,0,0,146,147,5,50,0,0,147,148,3,26,
  	13,0,148,149,5,57,0,0,149,151,1,0,0,0,150,146,1,0,0,0,151,154,1,0,0,0,
  	152,150,1,0,0,0,152,153,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,155,144,
  	1,0,0,0,155,156,1,0,0,0,156,157,1,0,0,0,157,158,5,42,0,0,158,159,3,4,
  	2,0,159,21,1,0,0,0,160,161,5,57,0,0,161,162,5,26,0,0,162,163,3,28,14,
  	0,163,164,5,40,0,0,164,165,3,28,14,0,165,166,5,49,0,0,166,180,1,0,0,0,
  	167,168,5,57,0,0,168,169,5,27,0,0,169,170,3,28,14,0,170,171,5,40,0,0,
  	171,172,3,28,14,0,172,173,5,49,0,0,173,180,1,0,0,0,174,175,5,57,0,0,175,
  	176,5,28,0,0,176,177,3,28,14,0,177,178,5,49,0,0,178,180,1,0,0,0,179,160,
  	1,0,0,0,179,167,1,0,0,0,179,174,1,0,0,0,180,23,1,0,0,0,181,182,5,20,0,
  	0,182,183,3,28,14,0,183,184,5,56,0,0,184,185,5,49,0,0,185,25,1,0,0,0,
  	186,187,7,0,0,0,187,27,1,0,0,0,188,189,6,14,-1,0,189,190,5,45,0,0,190,
  	195,3,28,14,0,191,192,5,50,0,0,192,194,3,28,14,0,193,191,1,0,0,0,194,
  	197,1,0,0,0,195,193,1,0,0,0,195,196,1,0,0,0,196,198,1,0,0,0,197,195,1,
  	0,0,0,198,199,5,46,0,0,199,232,1,0,0,0,200,201,5,57,0,0,201,210,5,47,
  	0,0,202,207,3,28,14,0,203,204,5,50,0,0,204,206,3,28,14,0,205,203,1,0,
  	0,0,206,209,1,0,0,0,207,205,1,0,0,0,207,208,1,0,0,0,208,211,1,0,0,0,209,
  	207,1,0,0,0,210,202,1,0,0,0,210,211,1,0,0,0,211,212,1,0,0,0,212,232,5,
  	48,0,0,213,214,5,57,0,0,214,215,3,28,14,0,215,216,3,28,14,19,216,232,
  	1,0,0,0,217,218,5,47,0,0,218,219,3,28,14,0,219,220,5,48,0,0,220,232,1,
  	0,0,0,221,222,5,33,0,0,222,232,3,28,14,15,223,232,5,51,0,0,224,232,5,
  	52,0,0,225,232,5,53,0,0,226,232,5,54,0,0,227,232,5,55,0,0,228,232,5,56,
  	0,0,229,232,5,57,0,0,230,232,5,29,0,0,231,188,1,0,0,0,231,200,1,0,0,0,
  	231,213,1,0,0,0,231,217,1,0,0,0,231,221,1,0,0,0,231,223,1,0,0,0,231,224,
  	1,0,0,0,231,225,1,0,0,0,231,226,1,0,0,0,231,227,1,0,0,0,231,228,1,0,0,
  	0,231,229,1,0,0,0,231,230,1,0,0,0,232,268,1,0,0,0,233,234,10,14,0,0,234,
  	235,7,1,0,0,235,267,3,28,14,15,236,237,10,13,0,0,237,238,7,2,0,0,238,
  	267,3,28,14,14,239,240,10,12,0,0,240,241,5,25,0,0,241,242,3,28,14,0,242,
  	243,5,21,0,0,243,244,3,28,14,13,244,267,1,0,0,0,245,246,10,11,0,0,246,
  	247,7,3,0,0,247,267,3,28,14,12,248,249,10,10,0,0,249,250,5,31,0,0,250,
  	267,3,28,14,11,251,252,10,9,0,0,252,253,5,32,0,0,253,267,3,28,14,10,254,
  	255,10,18,0,0,255,256,5,45,0,0,256,257,3,28,14,0,257,258,5,46,0,0,258,
  	267,1,0,0,0,259,260,10,17,0,0,260,261,5,45,0,0,261,262,3,28,14,0,262,
  	263,5,40,0,0,263,264,3,28,14,0,264,265,5,46,0,0,265,267,1,0,0,0,266,233,
  	1,0,0,0,266,236,1,0,0,0,266,239,1,0,0,0,266,245,1,0,0,0,266,248,1,0,0,
  	0,266,251,1,0,0,0,266,254,1,0,0,0,266,259,1,0,0,0,267,270,1,0,0,0,268,
  	266,1,0,0,0,268,269,1,0,0,0,269,29,1,0,0,0,270,268,1,0,0,0,16,33,39,52,
  	66,98,103,132,152,155,179,195,207,210,231,266,268
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
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TonParser::USE) {
      setState(30);
      header();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(39);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115188077664256) != 0)) {
      setState(36);
      statement();
      setState(41);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(42);
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
    setState(44);
    match(TonParser::USE);
    setState(45);
    match(TonParser::ID);
    setState(46);
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
    setState(48);
    match(TonParser::L_BRACE);
    setState(52);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 144115188077664256) != 0)) {
      setState(49);
      statement();
      setState(54);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(55);
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
    setState(66);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(57);
      varDecl();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(58);
      assignment();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(59);
      ifStat();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(60);
      loopStat();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(61);
      untilStat();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(62);
      shoutStat();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(63);
      funcDef();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(64);
      audioOpStat();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(65);
      saveStat();
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

tree::TerminalNode* TonParser::VarDeclContext::ASSIGN() {
  return getToken(TonParser::ASSIGN, 0);
}

TonParser::ExprContext* TonParser::VarDeclContext::expr() {
  return getRuleContext<TonParser::ExprContext>(0);
}

tree::TerminalNode* TonParser::VarDeclContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
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

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(68);
    match(TonParser::MAKE);
    setState(69);
    type();
    setState(70);
    match(TonParser::ID);
    setState(71);
    match(TonParser::ASSIGN);
    setState(72);
    expr(0);
    setState(73);
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

tree::TerminalNode* TonParser::AssignmentContext::ID() {
  return getToken(TonParser::ID, 0);
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
  enterRule(_localctx, 10, TonParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(75);
    match(TonParser::ID);
    setState(76);
    match(TonParser::ASSIGN);
    setState(77);
    expr(0);
    setState(78);
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
  enterRule(_localctx, 12, TonParser::RuleShoutStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(80);
    match(TonParser::SHOUT);
    setState(81);
    expr(0);
    setState(82);
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
  enterRule(_localctx, 14, TonParser::RuleIfStat);
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
    setState(84);
    match(TonParser::IF);
    setState(85);
    match(TonParser::L_ANGLE);
    setState(86);
    expr(0);
    setState(87);
    match(TonParser::R_ANGLE);
    setState(88);
    block();
    setState(98);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(89);
        match(TonParser::OTHERWISE);
        setState(90);
        match(TonParser::IF_PLAIN);
        setState(91);
        match(TonParser::L_ANGLE);
        setState(92);
        expr(0);
        setState(93);
        match(TonParser::R_ANGLE);
        setState(94);
        block(); 
      }
      setState(100);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(103);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == TonParser::OTHERWISE) {
      setState(101);
      match(TonParser::OTHERWISE);
      setState(102);
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
  enterRule(_localctx, 16, TonParser::RuleLoopStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(105);
      match(TonParser::LOOP);
      setState(106);
      match(TonParser::L_ANGLE);
      setState(107);
      expr(0);
      setState(108);
      match(TonParser::TIMES);
      setState(109);
      match(TonParser::R_ANGLE);
      setState(110);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      match(TonParser::LOOP);
      setState(113);
      match(TonParser::L_ANGLE);
      setState(114);
      type();
      setState(115);
      match(TonParser::ID);
      setState(116);
      match(TonParser::FROM);
      setState(117);
      expr(0);
      setState(118);
      match(TonParser::TO);
      setState(119);
      expr(0);
      setState(120);
      match(TonParser::R_ANGLE);
      setState(121);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(123);
      match(TonParser::LOOP);
      setState(124);
      match(TonParser::L_ANGLE);
      setState(125);
      type();
      setState(126);
      match(TonParser::ID);
      setState(127);
      match(TonParser::ASSIGN);
      setState(128);
      expr(0);
      setState(129);
      match(TonParser::R_ANGLE);
      setState(130);
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
  enterRule(_localctx, 18, TonParser::RuleUntilStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    match(TonParser::UNTIL);
    setState(135);
    match(TonParser::L_ANGLE);
    setState(136);
    expr(0);
    setState(137);
    match(TonParser::R_ANGLE);
    setState(138);
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
  enterRule(_localctx, 20, TonParser::RuleFuncDef);
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
    setState(140);
    match(TonParser::DEFINE);
    setState(141);
    type();
    setState(142);
    match(TonParser::ID);
    setState(143);
    match(TonParser::L_ANGLE);
    setState(155);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2046) != 0)) {
      setState(144);
      type();
      setState(145);
      match(TonParser::ID);
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TonParser::COMMA) {
        setState(146);
        match(TonParser::COMMA);
        setState(147);
        type();
        setState(148);
        match(TonParser::ID);
        setState(154);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(157);
    match(TonParser::R_ANGLE);
    setState(158);
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

tree::TerminalNode* TonParser::AudioOpStatContext::ID() {
  return getToken(TonParser::ID, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::TRASH() {
  return getToken(TonParser::TRASH, 0);
}

std::vector<TonParser::ExprContext *> TonParser::AudioOpStatContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::AudioOpStatContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::AudioOpStatContext::COLON() {
  return getToken(TonParser::COLON, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::SEMI() {
  return getToken(TonParser::SEMI, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::MUTE() {
  return getToken(TonParser::MUTE, 0);
}

tree::TerminalNode* TonParser::AudioOpStatContext::DIVIDE() {
  return getToken(TonParser::DIVIDE, 0);
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
  enterRule(_localctx, 22, TonParser::RuleAudioOpStat);

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
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      match(TonParser::ID);
      setState(161);
      match(TonParser::TRASH);
      setState(162);
      expr(0);
      setState(163);
      match(TonParser::COLON);
      setState(164);
      expr(0);
      setState(165);
      match(TonParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(167);
      match(TonParser::ID);
      setState(168);
      match(TonParser::MUTE);
      setState(169);
      expr(0);
      setState(170);
      match(TonParser::COLON);
      setState(171);
      expr(0);
      setState(172);
      match(TonParser::SEMI);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(174);
      match(TonParser::ID);
      setState(175);
      match(TonParser::DIVIDE);
      setState(176);
      expr(0);
      setState(177);
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
  enterRule(_localctx, 24, TonParser::RuleSaveStat);

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
    match(TonParser::SAVE);
    setState(182);
    expr(0);
    setState(183);
    match(TonParser::STRING_VAL);
    setState(184);
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
  enterRule(_localctx, 26, TonParser::RuleType);
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
    setState(186);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2046) != 0))) {
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
//----------------- IdExprContext ------------------------------------------------------------------

tree::TerminalNode* TonParser::IdExprContext::ID() {
  return getToken(TonParser::ID, 0);
}

TonParser::IdExprContext::IdExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::IdExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitIdExpr(this);
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
//----------------- MixWithExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::MixWithExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::MixWithExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::MixWithExprContext::MIXWITH() {
  return getToken(TonParser::MIXWITH, 0);
}

tree::TerminalNode* TonParser::MixWithExprContext::FROM() {
  return getToken(TonParser::FROM, 0);
}

TonParser::MixWithExprContext::MixWithExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::MixWithExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitMixWithExpr(this);
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
//----------------- AddSubExprContext ------------------------------------------------------------------

std::vector<TonParser::ExprContext *> TonParser::AddSubExprContext::expr() {
  return getRuleContexts<TonParser::ExprContext>();
}

TonParser::ExprContext* TonParser::AddSubExprContext::expr(size_t i) {
  return getRuleContext<TonParser::ExprContext>(i);
}

tree::TerminalNode* TonParser::AddSubExprContext::PLUS() {
  return getToken(TonParser::PLUS, 0);
}

tree::TerminalNode* TonParser::AddSubExprContext::MINUS() {
  return getToken(TonParser::MINUS, 0);
}

TonParser::AddSubExprContext::AddSubExprContext(ExprContext *ctx) { copyFrom(ctx); }


std::any TonParser::AddSubExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TonVisitor*>(visitor))
    return parserVisitor->visitAddSubExpr(this);
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
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, TonParser::RuleExpr, precedence);

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
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ArrayExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(189);
      match(TonParser::L_BRACKET);
      setState(190);
      expr(0);
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TonParser::COMMA) {
        setState(191);
        match(TonParser::COMMA);
        setState(192);
        expr(0);
        setState(197);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(198);
      match(TonParser::R_BRACKET);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<FunctionCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(200);
      match(TonParser::ID);
      setState(201);
      match(TonParser::L_PAREN);
      setState(210);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 286154507325276160) != 0)) {
        setState(202);
        expr(0);
        setState(207);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == TonParser::COMMA) {
          setState(203);
          match(TonParser::COMMA);
          setState(204);
          expr(0);
          setState(209);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(212);
      match(TonParser::R_PAREN);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CreateSoundExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(213);
      match(TonParser::ID);
      setState(214);
      expr(0);
      setState(215);
      expr(19);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ParensExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(217);
      match(TonParser::L_PAREN);
      setState(218);
      expr(0);
      setState(219);
      match(TonParser::R_PAREN);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(221);
      match(TonParser::NOT_KW);
      setState(222);
      expr(15);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NoteValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(223);
      match(TonParser::NOTE_VAL);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IntValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(224);
      match(TonParser::INT_VAL);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<NumValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(225);
      match(TonParser::NUM_VAL);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<BoolValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(226);
      match(TonParser::BOOL_VAL);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<CharValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(227);
      match(TonParser::CHAR_VAL);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<StringValExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(228);
      match(TonParser::STRING_VAL);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<IdExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(229);
      match(TonParser::ID);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<EmptySoundExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(230);
      match(TonParser::EMPTYSOUND);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(268);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(266);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(233);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(234);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1924145348608) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(235);
          expr(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(236);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(237);
          _la = _input->LA(1);
          if (!(_la == TonParser::PLUS

          || _la == TonParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(238);
          expr(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<MixWithExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(239);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(240);
          match(TonParser::MIXWITH);
          setState(241);
          expr(0);
          setState(242);
          match(TonParser::FROM);
          setState(243);
          expr(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<RelationalExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(245);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(246);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 6648609374208) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(247);
          expr(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(248);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(249);
          match(TonParser::AND_OP);
          setState(250);
          expr(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(251);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(252);
          match(TonParser::OR_OP);
          setState(253);
          expr(10);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<IndexExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(254);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(255);
          match(TonParser::L_BRACKET);
          setState(256);
          expr(0);
          setState(257);
          match(TonParser::R_BRACKET);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<SliceExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(259);

          if (!(precpred(_ctx, 17))) throw FailedPredicateException(this, "precpred(_ctx, 17)");
          setState(260);
          match(TonParser::L_BRACKET);
          setState(261);
          expr(0);
          setState(262);
          match(TonParser::COLON);
          setState(263);
          expr(0);
          setState(264);
          match(TonParser::R_BRACKET);
          break;
        }

        default:
          break;
        } 
      }
      setState(270);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
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
    case 14: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool TonParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 18);
    case 7: return precpred(_ctx, 17);

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
