#include "repl/TonRepl.h"
#include "antlr4-runtime.h"
#include "TonLexer.h"
#include "TonParser.h"
#include "listener/TonSyntaxErrorListener.h"

#include <iostream>
#include <string>

void TonRepl::start() {
    std::cout << "======================================================\n";
    std::cout << ">>> Welcome to Tøn Interactive\n";
    std::cout << ">>> Type 'exit' or 'quit' to close.\n";
    std::cout << "======================================================\n";

    std::string line;
    while (true) {
        std::cout << "ton> ";

        // breaks on ctrl+D / EOF
        if (!std::getline(std::cin, line)) {
            break;
        }

        // breaks on exit and quit
        if (line == "exit" || line == "quit") {
            break;
        }

        // ignoring empty inputs
        if (line.empty()) {
            continue;
        }

        // kinda copy of main.cpp, but single line conf:
        TonSyntaxErrorListener errorListener;
        auto input = std::make_unique<antlr4::ANTLRInputStream>(line);
        auto lexer = std::make_unique<TonLexer>(input.get());

        lexer->removeErrorListeners();
        lexer->addErrorListener(&errorListener);

        auto tokens = std::make_unique<antlr4::CommonTokenStream>(lexer.get());
        auto parser = std::make_unique<TonParser>(tokens.get());

        parser->removeErrorListeners();
        parser->addErrorListener(&errorListener);

        auto treeAST = parser->program();

        size_t totalErrors = lexer->getNumberOfSyntaxErrors() + parser->getNumberOfSyntaxErrors();
        if (totalErrors > 0) {
            continue;
        }

        // move this to shared class memory
        inputStreams.push_back(std::move(input));
        lexers.push_back(std::move(lexer));
        tokenStreams.push_back(std::move(tokens));
        parsers.push_back(std::move(parser));

        // Run TypeChecker and Interpreter
        try {
            antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, treeAST);
            // printing in REPL wihtout !shout expr
            std::any possibleOutput = interpreter.visit(treeAST);
            if (possibleOutput.has_value()) {
                interpreter.printValue(possibleOutput);
                std::cout << "\n";
            }
        }
        catch (const std::bad_any_cast& e) {
            std::cerr << ">>> [RUNTIME ERROR - TYPE MISMATCH]: Incorrect data type! (" << e.what() << ")\n";
        }
        catch (const std::exception& e) {
            std::cerr << ">>> [RUNTIME ERROR]: " << e.what() << "\n";
        }
        catch (...) {
            std::cerr << ">>> [FATAL ERROR]: Critical memory error!\n";
        }
    }
}
