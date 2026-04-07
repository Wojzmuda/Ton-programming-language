#include "antlr4-runtime.h"
#include "antlr4_generated/TonLexer.h"
#include "antlr4_generated/TonParser.h"
#include "TonInterpreter.h"

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
    }

    antlr4::ANTLRInputStream input(stream);
    TonLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    TonParser parser(&tokens);

    auto treeAST = parser.program();
    if (parser.getNumberOfSyntaxErrors() > 0){
        std::cerr << "Found " << parser.getNumberOfSyntaxErrors() << " syntax errors, fix your code."<< std::endl;
        return 1;
    }


    TonInterpreter interpreter;
    try {
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