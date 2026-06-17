#ifndef TONREPL_H
#define TONREPL_H

#pragma once

#include "interpreter/TonInterpreter.h"
#include "listener/TonDeclarationListener.h"

namespace antlr4 {
class ANTLRInputStream;
class CommonTokenStream;
}
class TonLexer;
class TonParser;

class TonRepl {
private:
    TonDeclarationListener listener;
    TonInterpreter interpreter;
    std::vector<std::unique_ptr<antlr4::ANTLRInputStream>> inputStreams;
    std::vector<std::unique_ptr<TonLexer>> lexers;
    std::vector<std::unique_ptr<antlr4::CommonTokenStream>> tokenStreams;
    std::vector<std::unique_ptr<TonParser>> parsers;

public:
    void start();
};
#endif // TONREPL_H
