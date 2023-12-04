#include <iostream>
#include <memory>
#include "day_1/trebuchet.h"
#include "puzzle_factory.h"

REGISTER_PUZZLE("day_1_trebuchet", trebuchet)

int main() {
    
    std::vector<std::unique_ptr<i_puzzle>> puzzles;

    // Manually add puzzles to the list
    puzzles.emplace_back(puzzle_factory::create_instance("day_1_trebuchet"));

    // Iterate over puzzles and solve them
    for (auto& puzzle : puzzles) {
        puzzle->solve();
    }
}
