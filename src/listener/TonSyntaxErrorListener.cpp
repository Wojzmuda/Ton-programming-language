#include "listener/TonSyntaxErrorListener.h"
#include <iostream>
#include <string>

void TonSyntaxErrorListener::syntaxError(antlr4::Recognizer *recognizer, 
                                         antlr4::Token *offendingSymbol, 
                                         size_t line, 
                                         size_t charPositionInLine, 
                                         const std::string &msg, 
                                         std::exception_ptr e) {
    
  
    std::string tokenText = (offendingSymbol != nullptr) ? offendingSymbol->getText() : "Unrecognized sign";
    if (tokenText == "<EOF>") {
        tokenText = "End of File";
    }

    std::string message;
    std::string expected = "";

  
    if (e != nullptr) {
        try {
            std::rethrow_exception(e);
        } catch (const antlr4::RecognitionException &re) {
            if (re.getOffendingState() != (size_t)-1) {
                const antlr4::dfa::Vocabulary &vocab = recognizer->getVocabulary(); 
                expected = re.getExpectedTokens().toString(vocab);
            }
        } catch (...) {
            
        }
    }


    if (msg.find("missing") != std::string::npos) {
        if (expected.find("';'") != std::string::npos) {
            message = "Missing semicolon. You likely forgot a ';' at the end of the previous statement.";
        } else if (expected.find("'<-'") != std::string::npos) {
            message = "Missing assignment operator '<-'.";
        } else {
            message = "Syntax is incomplete. Something is missing here.";
            if (!expected.empty()) {
                message += "\n    Try adding one of: " + expected;
            }
        }
    }
    else if (msg.find("mismatched input") != std::string::npos) {
        if (tokenText == "=" && expected.find("'<-'") != std::string::npos) {
            message = "Invalid assignment. In Ton language, you must use '<-' instead of '='.";
        } else {
            message = "Unexpected token found.";
            if (!expected.empty()) {
                message += "\n    Expected one of: " + expected;
            }
        }
    }
    else if (msg.find("no viable alternative") != std::string::npos) {
        message = "This statement doesn't fit any known Ton language rules.";
        if (!expected.empty()) {
            message += "\n    Expected one of: " + expected;
        }
    }
    else if (msg.find("extraneous input") != std::string::npos) {
        message = "This token is out of place and shouldn't be here.";
        if (!expected.empty()) {
            message += "\n    Expected instead: " + expected;
        }
    }
    else if (msg.find("token recognition error") != std::string::npos) {
        message = "Illegal character. This sign is not part of the Ton grammar.";
    }
    else {
        message = msg; 
    }


    std::string errorLineText = "";
    std::string indicator = "";

  
    antlr4::IntStream *inputStream = recognizer->getInputStream();
    std::string fullText = "";
    
    if (auto *charStream = dynamic_cast<antlr4::CharStream*>(inputStream)) {
        fullText = charStream->toString();
    } else if (auto *tokenStream = dynamic_cast<antlr4::TokenStream*>(inputStream)) {
        if (tokenStream->getTokenSource() && tokenStream->getTokenSource()->getInputStream()) {
            fullText = tokenStream->getTokenSource()->getInputStream()->toString(); // Błąd Parsera
        }
    }

    if (!fullText.empty()) {
        size_t currentLine = 1;
        size_t startPos = 0;
        
        while (currentLine < line && startPos < fullText.length()) {
            size_t nlPos = fullText.find('\n', startPos);
            if (nlPos == std::string::npos) break;
            startPos = nlPos + 1;
            currentLine++;
        }
        
        size_t endPos = fullText.find('\n', startPos);
        if (endPos == std::string::npos) endPos = fullText.length();
        
        errorLineText = fullText.substr(startPos, endPos - startPos);
        

        if (!errorLineText.empty() && errorLineText.back() == '\r') {
            errorLineText.pop_back();
        }

        
        for (size_t i = 0; i < charPositionInLine; i++) {

            if (i < errorLineText.length() && errorLineText[i] == '\t') {
                indicator += "\t";
            } else {
                indicator += " ";
            }
        }
        
        size_t tokenLength = (offendingSymbol != nullptr) ? offendingSymbol->getText().length() : 1;
        if (tokenLength == 0 || tokenText == "End of File") tokenLength = 1;
        for (size_t i = 0; i < tokenLength; i++) {
            indicator += "^";
        }
    }

    // error render
    std::cerr << "\n>>> [SYNTAX ERROR] Line " << line << ", Column " << charPositionInLine << ":\n";
    
    if (!errorLineText.empty()) {
        std::cerr << "  |\n"
                  << line << " | " << errorLineText << "\n"
                  << "  | " << indicator << "\n"
                  << "  |\n";
    }
    
    std::cerr << "    Problem with: '" << tokenText << "'\n"
              << "    " << message << "\n";
}