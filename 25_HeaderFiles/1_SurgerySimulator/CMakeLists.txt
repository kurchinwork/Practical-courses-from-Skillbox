cmake_minimum_required(VERSION 3.26)
project(SurgerySim)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(SurgerySim
        src/main.cpp
        src/allFuncSim.cpp
        src/allFuncSim.cpp
)
