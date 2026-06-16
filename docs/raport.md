# Kompleksowa Dokumentacja Projektu: Język Ton

## Spis Treści
1. [Podręcznik Użytkownika (User Manual)](#1-podręcznik-użytkownika-user-manual)
   - 1.1. Wymagania i uruchomienie
   - 1.2. Struktura języka i przykłady
2. [Raport z Implementacji (Technical Report)](#2-raport-z-implementacji-technical-report)
   - 2.1. Architektura Systemu
   - 2.2. Struktura Projektu
   - 2.3. Fazy Przetwarzania (Hoisting i Typechecking)
   - 2.4. Zaawansowana Obsługa Błędów

---

## 1. Podręcznik Użytkownika (User Manual)

Język **Ton** to autorski język skryptowy stworzony z myślą o elastyczności, bezpieczeństwie typów oraz wbudowanym wsparciu dla operacji matematycznych i muzycznych.

### 1.1. Wymagania i uruchomienie
Interpreter został napisany w C++ (standard C++17) i korzysta z biblioteki ANTLR4. 
Aby uruchomić skrypt napisany w języku Ton, należy z poziomu konsoli wywołać skompilowany plik wykonywalny, podając ścieżkę do pliku tekstowego z kodem jako pierwszy argument.

**Składnia polecenia:**
`./ton_interpreter <Ton_program.txt>`

**Obsługa błędów wejścia:**
* Jeśli zapomnisz podać pliku, program poinstruuje Cię: `Use command: ./ton_interpreter <Ton_program.txt>`
* Jeśli plik nie istnieje, otrzymasz błąd: `Cannot open file: <nazwa_pliku>`

### 1.2. Struktura języka i przykłady
Język Ton jest silnie typowany i obsługuje instrukcje sterujące, zmienne oraz dedykowane komendy domenowe.

**Deklaracja zmiennych:**
Język obsługuje podstawowe typy danych.

```ton
int x = 10;
float pi = 3.14;
string greeting = "Hello World";
bool isReady = true;
```

**Instrukcje warunkowe i pętle:**
Klasyczne podejście znane z języków rodziny C.

```ton
if (x > 5) {
    x = x - 1;
} else {
    x = x + 1;
}

while (x > 0) {
    x = x - 1;
}
```

**Moduł Muzyczny (Music Examples):**
Język Ton posiada wbudowane instrukcje do generowania/obsługi dźwięku.

```ton
tempo(120);
play(C4);
rest(0.5);
```

---

## 2. Raport z Implementacji (Technical Report)

Projekt interpretera został zrealizowany w języku C++ z wykorzystaniem generatora parserów **ANTLR4**. Architektura systemu została zaprojektowana modułowo, oddzielając fazę parsowania, analizę statyczną oraz właściwą ewaluację kodu.

### 2.1. Architektura Systemu i Cykl Życia Programu

Plik `main.cpp` definiuje ścisły, wielofazowy potok (pipeline) wykonania:

1. **Analiza leksykalna i składniowa:** `TonLexer` rozbija strumień wejściowy na tokeny, a `TonParser` buduje Drzewo Składni Abstrakcyjnej (AST).
2. **Walidacja Składni:** Przed uruchomieniem jakiejkolwiek logiki program sprawdza, czy wystąpiły błędy na etapie budowy drzewa (`totalErrors > 0`). Jeśli tak, natychmiast przerywa działanie.
3. **Faza Deklaracji (Hoisting):** Narzędzie typu Listener (`TonDeclarationListener`) przemierza drzewo za pomocą `ParseTreeWalker::DEFAULT.walk()`. Rejestruje zmienne i funkcje w przestrzeni nazw przed ich wykonaniem.
4. **Analiza Statyczna (Typechecker):** System sprawdza poprawność operacji na typach (zabezpieczając przed błędami w runtime).
5. **Egzekucja (Visitor):** Główny silnik (`TonInterpreter`) wykorzystuje wzorzec Visitor (`interpreter.visit(treeAST)`) do właściwego wykonania kodu.

### 2.2. Struktura Projektu

Zastosowano podział katalogów zgodny z najlepszymi praktykami C++:

```text
├── docs/                 # Dokumentacja projektu
├── examples/             # Skrypty testowe języka Ton
│   ├── error_examples/         # Testowanie łapania błędów
│   ├── math_examples/          # Testy operacji matematycznych
│   ├── Music_examples/         # Skrypty domenowe audio
│   └── type_checker_examples/  # Walidacja systemu typów
├── external/             # Zewnętrzne zależności (ANTLR4 runtime)
├── include/              # Pliki nagłówkowe (.h)
│   ├── core/
│   ├── interpreter/
│   ├── listener/
│   └── typechecker/
└── src/                  # Pliki źródłowe (.cpp)
    ├── interpreter/
    ├── listener/
    └── typechecker/
```

### 2.3. Zarządzanie Pamięcią i Zabezpieczenia Runtime

Ponieważ framework ANTLR4 dla C++ opiera przekazywanie danych w drzewie Visitora na typie `std::any`, implementacja jest wysoce narażona na wycieki pamięci lub naruszenia segmentacji przy rzutowaniu błędnych typów.
W głównym punkcie wejściowym interpretera zaimplementowano twarde zabezpieczenia w bloku `try-catch`:
* `std::bad_any_cast` został zmapowany na czytelny błąd `[RUNTIME ERROR - TYPE MISMATCH]`.
* Standardowe wyjątki C++ (`std::exception`) są łapane jako ogólne błędy wykonania.

### 2.4. Zaawansowana Obsługa Błędów (TonSyntaxErrorListener)

Kluczowym osiągnięciem w UX projektu jest całkowite nadpisanie domyślnego mechanizmu błędów ANTLR. Standardowe, kryptograficzne komunikaty zostały zastąpione przez czytelne podpowiedzi w klasie `TonSyntaxErrorListener`.

**Mechanizm Tłumaczenia Błędów:**
Klasa przechwytuje ciąg znaków błędu (np. *mismatched input*, *no viable alternative*) i za pomocą `std::string::find` konwertuje je na instrukcje dla użytkownika:
* **Mismatched input** -> `"Unexpected sign or word."`
* **No viable alternative** -> `"A message or sign doesn't fit Ton language rules"`
* **Missing** -> `"A missing sign"`
* **Extraneous input** -> `"Unnecessary additional signs."`
* **Token recognition error** -> `"Used sign is not a part of Ton grammar"`

**Ekstrakcja Oczekiwanych Znaków:**
Gdy to możliwe, Listener odpytuje słownik gramatyki (`recognizer->getVocabulary()`) o to, jakiego tokenu brakowało w danym stanie:

```cpp
expected = re.getExpectedTokens().toString(vocab);
```

Dzięki temu, w konsoli zamiast zrzutu błędu parsera, użytkownik widzi sformatowany, dokładny komunikat, np.:

```text
>>> [SYNTAX ERROR] Line 12, Column 5:
    Problem with: 'x'
    A missing sign
    Try adding: {';'}
```

Ten mechanizm chroni użytkownika końcowego przed zawiłościami wewnętrznymi parsera i drastycznie ułatwia pisanie skryptów w języku Ton.