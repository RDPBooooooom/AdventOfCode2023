//
// Created by marvin on 04.12.2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <regex>
#include "trebuchet.h"

void trebuchet::solve() {

    std::vector<calibration_value> values_part_one;
    std::vector<calibration_value> values_part_two;

    std::string line;
    std::ifstream input("../day_1/input.txt");
    if (input.is_open()) {
        while (getline(input, line)) {
            calibration_value value = {};
            calibration_value value_two = {};
            
            for (size_t i = 0; i < line.length(); ++i) {
                check_digit(line[i], value);
                check_digit(line[i], value_two);
                check_digit(get_number(line.substr(i, line.length())), value_two);
            }

            values_part_one.push_back(value);
            values_part_two.push_back(value_two);
        }
        input.close();
    }

    int sum = 0;
    for (const auto &item: values_part_one) {
        sum += item.get_number();
    }
    std::cout << "Day 1 - Part 1 - Trebuchet => " << sum << std::endl;
    
    sum = 0;
    for (const auto &item: values_part_two) {
        sum += item.get_number();
    }
    std::cout << "Day 1 - Part 2 - Trebuchet => " << sum << std::endl;
}

void trebuchet::check_digit(const char &digit, calibration_value &value) {
    if (isdigit(digit)) {

        if (value.first) {
            value.first = false;
            value.first_digit = digit;
        }
        value.last_digit = digit;
    }
}

char trebuchet::get_number(const std::string &str) {
    const std::unordered_map<std::string, std::string> numberWords{
            {"one",   "1"},
            {"two",   "2"},
            {"three", "3"},
            {"four",  "4"},
            {"five",  "5"},
            {"six",   "6"},
            {"seven", "7"},
            {"eight", "8"},
            {"nine",  "9"}
    };

    for (const auto &pair: numberWords) {
        size_t pos = 0;
        if (str.length() < pair.first.length()) continue;

        if (str.substr(0, pair.first.length()) == pair.first) {
            return *pair.second.c_str();
        }
    }

    return *"";
}