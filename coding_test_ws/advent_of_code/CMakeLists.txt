cmake_minimum_required(VERSION 3.10)

project(advent_of_code)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(day01_p01 src/solutions/day01_part01.cpp)
add_executable(day01_p02 src/solutions/day01_part02.cpp)
add_executable(day02_p01 src/solutions/day02_part01.cpp)
add_executable(day02_p02 src/solutions/day02_part02.cpp)
add_executable(day03 src/solutions/day03_part01_part02.cpp)