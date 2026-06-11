cmake_minimum_required(VERSION 3.15)
project(HTML_Editor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/Qt5.5.1/5.5/mingw492_32")

#WebKitWidgets
find_package(Qt5 COMPONENTS Core Gui Widgets WebKitWidgets REQUIRED)

add_executable(HTML_Editor
        main.cpp
        masknum.cpp
        masknum.h
        masknum.ui
)