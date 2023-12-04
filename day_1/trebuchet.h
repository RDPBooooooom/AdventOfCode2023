﻿//
// Created by marvin on 04.12.2023.
//

#ifndef ADVENTOFCODE_TREBUCHET_H
#define ADVENTOFCODE_TREBUCHET_H


#include "../i_puzzle.h"

struct calibration_value {
    std::string first_digit;
    std::string last_digit;

    int get_number() const {
        return std::stoi(first_digit + last_digit);
    }
};

class trebuchet : public i_puzzle {
public:
    void solve() override;
};


#endif //ADVENTOFCODE_TREBUCHET_H
