cmake_minimum_required(VERSION 3.14)
project(TonLanguage)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(ANTLR_BUILD_CPP_TESTS OFF CACHE INTERNAL "")
add_subdirectory(runtime)

set(SOURCES
    main.cpp                                       
    TonInterpreter.cpp
    antlr4_generated/TonLexer.cpp
    antlr4_generated/TonParser.cpp
    antlr4_generated/TonBaseVisitor.cpp
    antlr4_generated/TonVisitor.cpp
    TonSyntaxErrorListener.cpp
    TonDeclarationListener.cpp
)

add_executable(ton_app ${SOURCES})

target_include_directories( ton_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/runtime/src    
    ${CMAKE_CURRENT_SOURCE_DIR}/antlr4_generated       
    ${CMAKE_CURRENT_SOURCE_DIR}                        
)

target_link_libraries(ton_app PRIVATE antlr4_static)