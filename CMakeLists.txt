cmake_minimum_required(VERSION 3.14)
project(TonLanguage)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(ANTLR_BUILD_CPP_TESTS OFF CACHE INTERNAL "")
add_subdirectory(runtime)

set(SOURCES
    src/main.cpp
    src/interpreter/TonInterpreter.cpp
    src/listener/TonDeclarationListener.cpp
    src/listener/TonSyntaxErrorListener.cpp
    antlr4_generated/TonLexer.cpp
    antlr4_generated/TonParser.cpp
    antlr4_generated/TonBaseVisitor.cpp
    antlr4_generated/TonVisitor.cpp
)

set(HEADERS
    include/interpreter/TonInterpreter.h
    include/listener/TonDeclarationListener.h
    include/listener/TonSyntaxErrorListener.h
    include/core/MusicBase.h
    include/core/Scope.h
    include/core/Timeline.h
)

add_executable(ton_app ${SOURCES} ${HEADERS})

target_include_directories( ton_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include            
    ${CMAKE_CURRENT_SOURCE_DIR}/antlr4_generated   
    ${CMAKE_CURRENT_SOURCE_DIR}/external           
    ${CMAKE_CURRENT_SOURCE_DIR}/runtime/runtime/src                    
)

target_link_libraries(ton_app PRIVATE antlr4_static)
