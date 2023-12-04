//
// Created by marvin on 04.12.2023.
//

#ifndef ADVENTOFCODE_PUZZLE_FACTORY_H
#define ADVENTOFCODE_PUZZLE_FACTORY_H


#include <string>
#include <map>
#include <functional>
#include "i_puzzle.h"

// Macro for registering puzzles
#define REGISTER_PUZZLE(NAME, CLASS) \
    static bool CLASS ## _registered = []() -> bool { \
        puzzle_factory::register_puzzle(NAME, []() -> i_puzzle* { return new CLASS(); }); \
        return true; \
    }();

class puzzle_factory {
private:
    static std::map<std::string, std::function<i_puzzle *()>> &get_map() {
        static std::map<std::string, std::function<i_puzzle *()>> impl;
        return impl;
    }

public:
    static void register_puzzle(const std::string &name, std::function<i_puzzle *()> constructor) {
        get_map()[name] = constructor;
    }

    static i_puzzle *create_instance(const std::string &name) {
        auto it = get_map().find(name);
        if (it != get_map().end()) {
            return it->second();
        }
        return nullptr;
    }
};


#endif //ADVENTOFCODE_PUZZLE_FACTORY_H
