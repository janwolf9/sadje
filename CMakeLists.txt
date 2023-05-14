cmake_minimum_required(VERSION 3.17)
project(sadje)

set(CMAKE_CXX_STANDARD 14)

add_executable(sadje main.cpp brute_force.cpp)
add_executable(brute_force brute_force.cpp)


