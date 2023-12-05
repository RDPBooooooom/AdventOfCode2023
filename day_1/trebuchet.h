//
// Created by marvin on 04.12.2023.
//

#ifndef ADVENTOFCODE_TREBUCHET_H
#define ADVENTOFCODE_TREBUCHET_H


#include "../i_puzzle.h"

struct calibration_value {
    bool first = true;
    
    std::string first_digit;
    std::string last_digit;

    int get_number() const {
        return std::stoi(first_digit + last_digit);
    }
};

class trebuchet : public i_puzzle {
public:
    void solve() override;

    void check_digit(const char& digit, calibration_value &value);

    char get_number(const std::string &to_cleanup);
};


#endif //ADVENTOFCODE_TREBUCHET_H
