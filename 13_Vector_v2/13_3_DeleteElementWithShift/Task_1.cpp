//
// Created by kurch on 22.12.2025.
//
#include <iostream>
#include <vector>

using namespace std;

bool makeDecisionAbout (const string& question) {
    char choice;
    cout << question << "Y/N"; cin >> choice;
    return choice == 'y' || choice == 'Y';
}
int sellRobot (vector<int>& serialNumbRobo, int& countRobo, int indexForBuy) {
    int vectorIndex = indexForBuy - 1;
    int boughtSerialNumber = serialNumbRobo[vectorIndex];
    serialNumbRobo.erase(serialNumbRobo.begin() + vectorIndex);
    --countRobo;

    return boughtSerialNumber;
}
void addNewRobot (vector<int>& serialNumbRobo, int& countRobo) {
    int countNewRobo = 0;
    bool logicNewElementApprove = false;

    while (!logicNewElementApprove) {
        cout << "\nHow many robots you want added?";
        cin >> countNewRobo;

        if (countNewRobo == 0) {
            cout << "\nAre you serious? This is zero?";
        } else if (countNewRobo < 0) {
            cout << "\nI think you're kidding me. Why is it less than zero?";
        }
        if (countNewRobo > 0)
            logicNewElementApprove = true;

    }

    int oldSizeCountRobo = countRobo;
    countRobo += countNewRobo;

    serialNumbRobo.resize(countRobo);
    for (int i = oldSizeCountRobo; i < countRobo; i++) {
        cout << "\nInput number robo: #" << i + 1 << ":";
        cin >> serialNumbRobo[i];
    }
    cout << "Successfully added " << countNewRobo << " new robots!" << endl;
}
void outPutRobot (const vector<int>& serialNumbRobo,const int& countRobo) {
    for (int i = 0; i < countRobo; i++)
        cout << serialNumbRobo[i] << " ";
}

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

    int indexForBuy = 0;
    bool logicApprove = true;

    while (logicApprove) {
        cout << "\nInput number robot for buy: #";
        cin >> indexForBuy; cout << endl;

        if (indexForBuy < 0 || indexForBuy > countRobo) {
            cout << "\nThis index is not supported!";
            logicApprove = makeDecisionAbout("\nDo you wanna try again?");
            if (!logicApprove)
                break;
            continue;
        }

        int boughtSerialNumber = sellRobot(serialNumbRobo, countRobo, indexForBuy);
        cout << "\nYou bought robot #" << indexForBuy << " with serial number: " << boughtSerialNumber << endl;

        if (countRobo == 0) {
            cout << "\nAll robots are sold! Showcase is empty." << endl;
            break;
        }

        cout << "\nRemaining robots: ";
        outPutRobot (serialNumbRobo, countRobo);
    }

    if (countRobo == 1) {
        cout << "\nYou have last robots with index: " << serialNumbRobo[0];
        bool logicalAdd = makeDecisionAbout("\nDo you want to list new robots for sale?");

        if (logicalAdd == true) {
            addNewRobot(serialNumbRobo, countRobo);
            cout << "\nOn showcase demonstrate "<< countRobo <<" robots with numbers: ";
            outPutRobot (serialNumbRobo, countRobo);
        }
    }
}