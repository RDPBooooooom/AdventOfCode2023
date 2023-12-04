cmake_minimum_required(VERSION 3.26)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode main.cpp
        i_puzzle.h
        puzzle_factory.h
        day_1/trebuchet.cpp
        day_1/trebuchet.h)
