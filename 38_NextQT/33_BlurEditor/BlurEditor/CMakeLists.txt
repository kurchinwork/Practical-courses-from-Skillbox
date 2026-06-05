cmake_minimum_required(VERSION 4.1)
project(BlurEditor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.5.1/5.5/mingw492_32")

find_package(Qt5 COMPONENTS Widgets Concurrent REQUIRED)

add_executable(BlurEditor
        blureditor.cpp
        blureditor.h
        main.cpp)

target_link_libraries(BlurEditor
        Qt5::Widgets
        Qt5::Concurrent)