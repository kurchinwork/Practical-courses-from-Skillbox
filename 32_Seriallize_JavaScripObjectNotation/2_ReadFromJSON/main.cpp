//
// Created by kurch on 16.04.2026.
//
#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;

void ReadFromFile (nlohmann::json& jsonContent) {
    ifstream MovieLibr ("Movie.json");

    if (!MovieLibr.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    MovieLibr >> jsonContent;
    MovieLibr.close();
}
void findForDirectorName (const string& name,const nlohmann::json& jsonContent) {
    int i = 1;
    for (auto& [title, info]: jsonContent.items ()) {
        if (info["Director:"] == name) {
            cout <<"\n#"<< i << " " <<  title << " : " << "\nGenre: " << info["Genre:"] << "\nYear production: " << info["Year production:"] << endl;
            i++;
        }
    }
}

int main () {
    nlohmann::json jsonContent;
    ReadFromFile(jsonContent);

    string directorName = " ";
    cout << "Enter name Director for start searching: "; getline(cin, directorName);

    findForDirectorName(directorName, jsonContent);

    return 0;
}