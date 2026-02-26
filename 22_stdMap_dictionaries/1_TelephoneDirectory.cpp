//
// Created by kurch on 25.02.2026.
//
#include <iostream>
#include <string>
#include <map>
using namespace std;
void findForNum (map <string, string>& phoneDirectory, string& phoneNum) {
    bool found = false;
    for (const auto& pair : phoneDirectory) {
        if (pair.second == phoneNum) {
            cout << "Phone " << phoneNum << " belongs to: " << pair.first << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Phone number not found!" << endl;
    }
}
void findForUserName(map <string, string>& phoneDirectory, string& userName) {
    bool found = false;
    for (const auto& pair : phoneDirectory) {
        if (pair.first == userName) {
            cout << userName << " owner num: " << pair.second << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Phone number not found!" << endl;
    }
}
void allOut (map <string, string>& phoneDirectory) {
    for(auto iter{phoneDirectory.cbegin()}; iter != phoneDirectory.cend(); iter++)
        std::cout << iter->first << "\t" << iter->second << std::endl;
}
void dict (map <string, string>& phoneDirectory) {
    string command = "";
    cout << "\nEnter command: "
            "\n~num~ for find phone user;"
            "\n~user~ for find user phone;"
            "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "\n~all~ for out all list num;"
            "\n~exit~ for exit"
            "\nEnter: "; cin >> command; cin.ignore();

    if (command == "num") {
        string phoneNum = "";
        cout << "\nEnter phone number: "; getline(cin, phoneNum);
        findForNum (phoneDirectory, phoneNum);
    } else if (command == "user") {
        string _userName = "";
        cout << "\nEnter phone number: "; getline(cin, _userName);
        findForUserName (phoneDirectory, _userName);
    } else if (command == "all") {
        allOut(phoneDirectory);
    } else if (command == "exit") {
        exit(0);
    } else {
        cout << "\nUnknown command! Please try again." << endl;
    }
}
int main() {
    map <string, string> phoneDirectory;
    string phone = "",
           userName = "";
    int countNum = 0;
    cout << "How many num you want add?:"; cin >> countNum; cin.ignore();
    for (int i = 0; i < countNum; i++) {
        cout << "Enter the phone num: ";
        getline(cin, phone);
        cout << "Enter the phone User name: ";
        getline(cin, userName);
        phoneDirectory[userName] = phone;
    }

    do {
        dict(phoneDirectory);
    } while (true);
}