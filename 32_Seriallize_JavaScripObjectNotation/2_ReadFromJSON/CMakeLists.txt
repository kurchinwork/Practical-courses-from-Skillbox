cmake_minimum_required(VERSION 4.1)
project(2_ReadFromJSON)

set(CMAKE_CXX_STANDARD 20)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(2_ReadFromJSON main.cpp)

target_link_libraries(2_ReadFromJSON PRIVATE nlohmann_json::nlohmann_json)
