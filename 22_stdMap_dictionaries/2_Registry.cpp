//
// Created by kurch on 26.02.2026.
//
#include <iostream>
#include <map>
using namespace std;

void outListPacient (map <string, int>& allPacientList) {
    if (allPacientList.empty()) {
        cout  << "\nEmpty list, enter data!";
        return;
    } else {
        cout << "\nPatient list:" << endl;
        for(const auto& pair : allPacientList) {
            cout << pair.first << "\t" << pair.second << endl;
        }
    }
}

int main () {

    map <string, int> _registry;

    string namePacient;
    int numDocPacient;

    cout << "\nEnter patient data sequentially:"
            "\n~(or enter 'next' in name pacient for out list)"
            "\n~(or enter 'exit' in name pacient for exit)";

    do {
        cout << "\nEnter name pacient:"; getline(cin, namePacient);
        if (namePacient == "next") {
            outListPacient(_registry);
            continue;
        } else if (namePacient == "exit") {
            cout << "\nProgram terminate";
            return 0;
        }
        cout << "\nEnter num doc pacient:"; cin >> numDocPacient; cin.ignore();
        _registry[namePacient] = numDocPacient;
    } while (true);
}