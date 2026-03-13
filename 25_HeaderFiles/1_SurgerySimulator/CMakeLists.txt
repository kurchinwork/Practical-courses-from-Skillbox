cmake_minimum_required(VERSION 4.1)
project("SurgerySim" VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_executable(SurgerySim main.cpp strctSrgrSmltr.cpp allFuncSrgrSmltr.cpp srgrSmltr.h)

target_include_directories(SurgerySim PUBLIC include)
