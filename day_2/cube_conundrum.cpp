//
// Created by marvin on 05.12.2023.
//

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include "cube_conundrum.h"

std::vector<std::string> cube_conundrum::split(std::string s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

void cube_conundrum::solve() {

    std::vector<game> games;
    
    std::string line;
    std::ifstream input("../day_2/input.txt");
    if (input.is_open()) {
        while (getline(input, line)) {
            game current = {};
            std::vector<std::string> game = split(line, ':');

            // Get id => game is always formatted like 'Game XX' 
            current.id = std::stoi(split(game.at(0), ' ').at(1));

            handle_turns(current, split(game.at(1), ';'));
            
            games.push_back(current);
        }
    }
    
    int sum = 0;
    int power_of_sets = 0;
    for (const auto &game: games){
        static int redThreshold = 12;
        static int greenThreshold = 13;
        static int blueThreshold = 14;

        if (game.meets_threshold(redThreshold, greenThreshold, blueThreshold)){
            sum += game.id;
        }
        
        power_of_sets += game.reds * game.blues * game.greens;
    }

    std::cout << "Day 2 - Part 1 - Cube Conundrum => " << sum << std::endl;
    std::cout << "Day 2 - Part 2 - Cube Conundrum => " << power_of_sets << std::endl;
}

void cube_conundrum::handle_turns(game &current, std::vector<std::string> game_data) {

    for (const auto &item: game_data) {
        std::vector<std::string> turn_data = split(item, ';');

        for (const auto &turn: turn_data) {
            std::vector<std::string> cubes = split(turn, ',');

            for (const auto &cube: cubes) {

                std::vector<std::string> cube_data = split(cube, ' ');

                if (cube_data.at(2) == "green") {
                    current.greens = std::max(current.greens, std::stoi(cube_data.at(1)));
                } else if (cube_data.at(2) == "blue") {
                    current.blues = std::max(current.blues, std::stoi(cube_data.at(1)));
                } else if (cube_data.at(2) == "red") {
                    current.reds = std::max(current.reds, std::stoi(cube_data.at(1)));
                }
            }
        }

    }
}
