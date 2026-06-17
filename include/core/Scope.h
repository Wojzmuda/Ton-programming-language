#pragma once

#include <memory>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>
#include <set>

template <typename T>
class Scope {
public:
    std::shared_ptr<Scope<T>> parent;
    std::map<std::string, T> values; // listener uses it as a line count
    std::map<std::string, std::string> types;
    std::map<std::string, bool> initialized; 

    Scope(std::shared_ptr<Scope<T>> parentScope = nullptr) : parent(parentScope) {}

    // Pobieranie wartości (rekurencyjne)
    T& get(std::string name) {
        if (values.count(name)) {
            if (!initialized.at(name)) {
                throw std::runtime_error("[Error] Variable '" + name + "' is declared but uninitialized.");
            }
            return values[name];
        }
        if (parent) return parent->get(name);
        throw std::runtime_error("[Error] Variable '" + name + "' is not defined");
    }

    T& getRaw(std::string name) {
        if (values.count(name)) return values[name];
        if (parent) return parent->getRaw(name);
        throw std::runtime_error("[Error] Variable '" + name + "' is not defined");
    }

    // Aktualizacja istniejącej zmiennej (rekurencyjne)
    void set(std::string name, T value) {
        if (values.count(name)) {
            values[name] = value;
            initialized[name] = true; 
            return;
        }
        if (parent) { 
            parent->set(name, value);
            return;
        } 
        throw std::runtime_error("[Error] Cannot assign to undefined variable: " + name);
    }

    // Deklaracja nowej zmiennej (zawsze lokalnie)
    void define(std::string name, std::string type, T value, bool isInitialized = true) {
        values[name] = value;
        types[name] = type;
        initialized[name] = isInitialized;
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

    std::vector<std::string> getAllVisibleNames() const {
        std::set<std::string> uniqueNames;
        
        const Scope<T>* current = this;
        while (current != nullptr) {
            for (const auto& pair : current->values) {
                uniqueNames.insert(pair.first);
            }
            current = current->parent.get();
        }
        return std::vector<std::string>(uniqueNames.begin(), uniqueNames.end());
    }
};