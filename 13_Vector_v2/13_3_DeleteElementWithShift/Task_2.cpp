//
// Created by kurch on 22.12.2025.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int countRobo;
    cout << "Input count Robots: "; cin >> countRobo; cout << endl;
    vector<int> serialNumbRobo(countRobo);

    for (int i = 0; i < countRobo; i++) {
        int j = i;
        cout << "Serial number for robot: #" << j + 1 << ":";
        cin >> serialNumbRobo[i];
    }

    cout << "On showcase demonstrate "<< countRobo <<" robots with numbers: ";
    for (int i = 0; i < countRobo; i++)
        cout << serialNumbRobo[i] << " ";

    int indexForBuy;
    bool logicApprove = true;

    while (logicApprove) {
        cout << "\nInput number robot for buy: #";
        cin >> indexForBuy; cout << endl;
        if (indexForBuy < 0 || indexForBuy > countRobo) {
            cout << "\nThis index is not supported!" << endl;
            cout << "\nInput Y/y for reboot sell, else input any symbol.\n"
                    "Do you wanna reboot?: ";
            char choice; cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                continue;
            } else {
                logicApprove = false;
                break;
            }
        }

        int vectorIndex = indexForBuy - 1;
        int boughtSerialNumber = serialNumbRobo[vectorIndex];

        serialNumbRobo.erase(serialNumbRobo.begin() + vectorIndex);
        --countRobo;

        cout << "You bought robot #" << indexForBuy << " with serial number: " << boughtSerialNumber << endl;

        if (countRobo == 0) {
            cout << "\nAll robots are sold! Showcase is empty." << endl;
            logicApprove = false;
            break;
        }

        cout << "\nRemaining robots: ";
        for (int i = 0; i < countRobo; i++) {
            cout << serialNumbRobo[i] << " ";
        }
    }

}