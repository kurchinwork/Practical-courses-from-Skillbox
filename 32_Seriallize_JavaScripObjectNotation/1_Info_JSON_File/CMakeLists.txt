cmake_minimum_required(VERSION 4.1)
project(1_Info_JSON_File)

set(CMAKE_CXX_STANDARD 20)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(1_Info_JSON_File 1_RecordToJSON.cpp)
target_link_libraries(1_Info_JSON_File PRIVATE nlohmann_json::nlohmann_json)