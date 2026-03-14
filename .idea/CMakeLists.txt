cmake_minimum_required(VERSION 4.1)
project(_idea)

set(CMAKE_CXX_STANDARD 14)

add_executable(_idea
        .gitignore
        editor.xml
        modules.xml
        PracticalCourses.iml
        vcs.xml
        ../zadanie_1_15.cpp
        ../zadanie_3_15.cpp
        ../zadanie_3_15.cpp
        ../22_stdMap_dictionaries/3_Annagrams.cpp)
