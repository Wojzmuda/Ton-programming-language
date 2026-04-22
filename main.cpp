#include "antlr4-runtime.h"
#include "antlr4_generated/TonLexer.h"
#include "antlr4_generated/TonParser.h"
#include "TonInterpreter.h"
#include "TonSyntaxErrorListener.h"
#include "TonDeclarationListener.h"

#include <iostream>
#include <fstream>


int main(int argc, const char* argv[]){
    if(argc < 2){
        std::cerr << "Use command: \t "<<argv[0]<< "\t <Ton_program.txt>"<<std::endl;
        return 1;
    }

    std::ifstream stream(argv[1]);

    if(!stream.is_open()){
        std::cerr << "Cannot open file: "<< argv[1]<<std::endl;
        return 1;
    }

    std::map<std::string, std::string> declaredTypes;
    std::map<std::string, std::any> memory;
    std::map<std::string, int> declarationLines;

    TonSyntaxErrorListener myErrorListener;

    antlr4::ANTLRInputStream input(stream);
    TonLexer lexer(&input);

    lexer.removeErrorListeners();
    lexer.addErrorListener(&myErrorListener);

    antlr4::CommonTokenStream tokens(&lexer);
    TonParser parser(&tokens);

    parser.removeErrorListeners();
    parser.addErrorListener(&myErrorListener);
    

    auto treeAST = parser.program();
    
  size_t totalErrors = lexer.getNumberOfSyntaxErrors() + parser.getNumberOfSyntaxErrors();

if (totalErrors > 0) {
    std::cerr <<std::endl << "Found " << totalErrors << " syntax errors, fix your code." << std::endl;
    return 1;
}
    TonDeclarationListener listener(declaredTypes, declarationLines);
    TonInterpreter interpreter(declaredTypes, memory);

    try {
        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, treeAST);
        interpreter.visit(treeAST);
        std::cout << "\n Provided program executed successfully!" << std::endl;
    } 
    catch (const std::bad_any_cast& e) {
        std::cerr << "\n>>> [RUNTIME ERROR - TYPE MISMATCH]: Incorrect data type! (" << e.what() << ")" << std::endl;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "\n>>> [RUNTIME ERROR]: " << e.what() << std::endl;
        return 1;
    } 
    catch (...) {
        std::cerr << "\n>>> [FATAL ERROR]: Critical memory error!" << std::endl;
        return 1;
    }

    return 0;

}