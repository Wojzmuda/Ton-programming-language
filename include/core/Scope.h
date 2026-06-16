#pragma once

#include <memory>
#include <map>
#include <string>
#include <stdexcept>
#include <vector>

template <typename T>
class Scope {
public:
    std::shared_ptr<Scope<T>> parent;
    std::map<std::string, T> values; 
    std::map<std::string, std::string> types;
    std::map<std::string, bool> initialized; 

    Scope(std::shared_ptr<Scope<T>> parentScope = nullptr) : parent(parentScope) {}

    T& get(std::string name) {
        if (values.count(name)) {
            if (!initialized[name]) {
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

    void define(std::string name, std::string type, T value, bool isInitialized = true) {
        values[name] = value;
        types[name] = type;
        initialized[name] = isInitialized;
    }

    bool existsLocally(std::string name) {
        return values.count(name) == 1;
    }

    std::string resolveType(std::string name) {
        if (types.count(name)) return types[name];
        if (parent) return parent->resolveType(name);
        throw std::runtime_error("[Error] Variable '" + name + "' is not defined");
    }

    bool exists(std::string name) {
        if (values.count(name)) return true;
        if (parent) return parent->exists(name);
        return false;
    }

    std::vector<std::string> getAllVisibleNames() const {
        std::vector<std::string> names;
        for (const auto& pair : values) {
            names.push_back(pair.first);
        }
        if (parent != nullptr) {
            auto parentNames = parent->getAllVisibleNames();
            names.insert(names.end(), parentNames.begin(), parentNames.end());
        }
        return names;
    }
};