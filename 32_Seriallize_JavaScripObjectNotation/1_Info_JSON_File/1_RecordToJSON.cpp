//
// Created by kurch on 16.04.2026.
//
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;

int main () {

    nlohmann::json jsonContent;

    ifstream MovieLibr ("movies.json");

    if (!MovieLibr.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    MovieLibr >> jsonContent;

    MovieLibr.close();

    cout << "--- All Movies ---" << endl;
    for (auto& [title, info] : jsonContent.items()) {
        cout << "Title: " << title << endl;
        cout << "  Director: " << info["Director:"] << endl;
        cout << "  Year: " << info["Year production:"] << endl;
    }

    return 0;
}