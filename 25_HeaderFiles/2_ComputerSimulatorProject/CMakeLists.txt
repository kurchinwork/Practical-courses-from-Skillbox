cmake_minimum_required(VERSION 3.20)
project(compSim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable(compSim main.cpp
        src/cpu.cpp
        src/ram.cpp
        src/disk.cpp
        src/gpu.cpp
        src/kbd.cpp
        src/commands.cpp)

# Указываем папку с заголовками для этой цели
target_include_directories(compSim PRIVATE ${PROJECT_SOURCE_DIR}/include)