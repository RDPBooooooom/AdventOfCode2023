//
// Created by marvin on 05.12.2023.
//

#ifndef ADVENTOFCODE_CUBE_CONUNDRUM_H
#define ADVENTOFCODE_CUBE_CONUNDRUM_H


#include "../i_puzzle.h"

struct game {
    int id = 0;

    int reds = 0;
    int blues = 0;
    int greens = 0;

    bool meets_threshold(int redThreshold, int greenThreshold, int blueThreshold) const {
        return reds <= redThreshold && greens <= greenThreshold && blues <= blueThreshold;
    }
};

class cube_conundrum : public i_puzzle {

public:
    std::vector<std::string> split(std::string s, char delimiter);

    void solve() override;

    void handle_turns(game &current, std::vector<std::string> game_data);
};


#endif //ADVENTOFCODE_CUBE_CONUNDRUM_H
