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
        antlr4::ANTLRInputStream input(line);
        TonLexer lexer(&input);

        lexer.removeErrorListeners();
        lexer.addErrorListener(&errorListener);

        antlr4::CommonTokenStream tokens(&lexer);
        TonParser parser(&tokens);

        parser.removeErrorListeners();
        parser.addErrorListener(&errorListener);

        auto treeAST = parser.program();

        size_t totalErrors = lexer.getNumberOfSyntaxErrors() + parser.getNumberOfSyntaxErrors();
        if (totalErrors > 0) {
            continue;
        }

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
