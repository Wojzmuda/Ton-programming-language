#pragma once

#include <memory>
#include <map>
#include <string>
#include <stdexcept>

template <typename T>
class Scope {
public:
    std::shared_ptr<Scope<T>> parent;
    std::map<std::string, T> values; // listener uses it as a line count
    std::map<std::string, std::string> types;

    Scope(std::shared_ptr<Scope<T>> parentScope = nullptr) : parent(parentScope) {}

    // Pobieranie wartości (rekurencyjne)
    T& get(std::string name) {
        if (values.count(name)) return values[name];
        if (parent) return parent->get(name);
        throw std::runtime_error("[Error] Variable '" + name + "' is not defined");
    }

    // Aktualizacja istniejącej zmiennej (rekurencyjne)
    void set(std::string name, T value) {
        if (values.count(name)) {
            values[name] = value;
            return;
        }
        if (parent) {
            parent->set(name, value);
            return;
        }
        throw std::runtime_error("[Error] Cannot assign to undefined variable: " + name);
    }

    // Deklaracja nowej zmiennej (zawsze lokalnie)
    void define(std::string name, std::string type, T value) {
        values[name] = value;
        types[name] = type;
    }

    // Sprawdzenie czy istnieje w obecnym bloku
    bool existsLocally(std::string name) {
        return values.count(name) == 1;
    }

    // Pobieranie typu (rekurencyjne)
    std::string resolveType(std::string name) {
        if (types.count(name)) return types[name];
        if (parent) return parent->resolveType(name);
        throw std::runtime_error("[Error] Variable '" + name + "' is not defined");
    }

    // Sprawdzenie czy istnieje gdziekolwiek 
    bool exists(std::string name) {
        if (values.count(name)) return true;
        if (parent) return parent->exists(name);
        return false;
    }
};