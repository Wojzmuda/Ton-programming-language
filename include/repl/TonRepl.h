#ifndef TONREPL_H
#define TONREPL_H

#pragma once

#include "interpreter/TonInterpreter.h"
#include "listener/TonDeclarationListener.h"

class TonRepl {
private:
    // Te obiekty żyją tak długo, jak długo kręci się REPL.
    // To one zapewniają nam "pamięć" między kolejnymi komendami!
    TonDeclarationListener listener;
    TonInterpreter interpreter;

public:
    void start();
};
#endif // TONREPL_H
