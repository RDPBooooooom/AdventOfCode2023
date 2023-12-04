//
// Created by marvin on 04.12.2023.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "trebuchet.h"

void trebuchet::solve() {

    std::vector<calibration_value> values;

    std::string line;
    std::ifstream input("../day_1/input.txt");
    if (input.is_open()) {
        while (getline(input, line)) {
            bool first = true;
            calibration_value value = {};
            for (const auto &item: line) {
                if (!isdigit(item)) continue;
                
                if (first) {
                    value.first_digit = item;
                    first = false;
                }
                
                value.last_digit = item;
            }
            values.push_back(value);
        }
        input.close();
    }

    int sum = 0;
    for (const auto &item: values){
        sum += item.get_number();
    }
    std::cout << "Day 1 - Trebuchet => " << sum << std::endl;
}
