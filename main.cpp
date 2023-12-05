#include <iostream>
#include <memory>
#include <regex>
#include "day_1/trebuchet.h"
#include "puzzle_factory.h"
#include "day_2/cube_conundrum.h"

REGISTER_PUZZLE("day_1", trebuchet)
REGISTER_PUZZLE("day_2", cube_conundrum)

int main() {
    
    std::vector<std::unique_ptr<i_puzzle>> puzzles;

    // Manually add puzzles to the list
    puzzles.emplace_back(puzzle_factory::create_instance("day_1"));
    puzzles.emplace_back(puzzle_factory::create_instance("day_2"));

    // Iterate over puzzles and solve them
    for (auto& puzzle : puzzles) {
        puzzle->solve();
    }
}
