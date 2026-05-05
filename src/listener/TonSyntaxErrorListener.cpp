#include "TonSyntaxErrorListener.h"
#include <iostream>

void TonSyntaxErrorListener::syntaxError(antlr4::Recognizer *recognizer, 
                                         antlr4::Token *offendingSymbol, 
                                         size_t line, 
                                         size_t charPositionInLine, 
                                         const std::string &msg, 
                                         std::exception_ptr e) {
std::string tokenText = (offendingSymbol != nullptr) ? offendingSymbol->getText() : "Unrecognized sign";
std::string message;

std::string expected = "";

if (e != nullptr) {
    try {
        std::rethrow_exception(e);
    } catch (const antlr4::RecognitionException &re) {
if (re.getOffendingState() != (size_t)-1) {
            const antlr4::dfa::Vocabulary &vocab = recognizer->getVocabulary(); 
            expected = re.getExpectedTokens().toString(vocab);
        } else {
            expected = "Could not determine expected tokens (Invalid State)";
        }
    } catch (...) {

    }
}

if (msg.find("mismatched input") != std::string::npos){
    message = "Unexpected sign or word.";
    if (!expected.empty()) {
        message += "\n    Expected one of: " + expected;
    }
}
else if (msg.find("no viable alternative") != std::string::npos){
    message = "A message or sign doesn't fit Ton language rules";
    if (!expected.empty()) {
        message +=  "\n    Expected one of: " + expected;
    }
}
else if (msg.find("missing") != std::string::npos){
    message = "A missing sign";
    if (!expected.empty()) {
        message += "\n    Try adding: " + expected;
    }
}
else if (msg.find("extraneous input") != std::string::npos){
    message = "Unnecessary additional signs.";
}
else if (msg.find("token recognition error") != std::string::npos){
    message = "Used sign is not a part of Ton grammar";
}
else{
    message = msg;
}


std::cerr << "\n>>> [SYNTAX ERROR] Line " << line << ", Column " << charPositionInLine << ":\n"
              << "    Problem with: '" << tokenText << "'\n"
              << "    " << message << "\n";
}



                                            
                                         