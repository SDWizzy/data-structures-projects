cmake_minimum_required(VERSION 3.14)
project(data_structures_projects)

set(CMAKE_CXX_STANDARD 14)

include_directories(".")

add_executable(data_structures_projects
        "circularlinkedlist.hpp"
        "hat.hpp"
        "hat_helpers.hpp"
        "hat.cpp"
        "hat_helpers.cpp"
        "main.cpp"
)
