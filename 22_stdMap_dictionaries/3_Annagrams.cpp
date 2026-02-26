//
// Created by kurch on 26.02.2026.
//
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

bool checkOnAnnagram(string word_1, string word_2) {
    if (word_1.length() != word_2.length()) {
        return false;
    }
    sort(word_1.begin(), word_1.end());
    sort(word_2.begin(), word_2.end());

    if (word_1 == word_2) {
        return true;
    } else {
        return false;
    }


}

int main() {
    map <string, string> listAnnagrams;
    map <string, string> listNonAnnagrams;

    do {
        string firstWord,
           secondWord;
        cout << "Enter two words* (only words) for check on sign annagram\n"
                "First word: "; cin >> firstWord;
        cout << "First second: "; cin >> secondWord;

        if (checkOnAnnagram(firstWord, secondWord)) {
            listAnnagrams.insert(pair <string, string> (firstWord, secondWord));
        } else {
            listNonAnnagrams.insert(pair(firstWord, secondWord));
        }
        string commands = "";
        cout << "\nEnter commands:"
                "\n~ann~ for out list with annagrams word;"
                "\n~nonAnn~ for out list with non-annagrams word;"
                "\n~exit~ for exit"
                "\nEnter:"; cin >> commands;

        if (commands == "ann") {
            for(const auto& pair : listAnnagrams) {
                cout << pair.first << "\t" << pair.second << endl;
            }
        } else if (commands == "nonAnn") {
            for(const auto& pair : listNonAnnagrams) {
                cout << pair.first << "\t" << pair.second << endl;
            }
        } else if (commands == "exit") {
            return 0;
        }
    } while (true);

}
