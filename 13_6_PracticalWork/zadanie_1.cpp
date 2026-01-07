//
// Created by kurchin ilya on 07.01.2026.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int countDigit;
    cout << "\nEnter a size vector: ";
    cin >> countDigit;
    vector<int> vectr(countDigit);

    for (int i = 0; i < vectr.size(); i++) {
        cout << "Input digit #" << i + 1 << ": ";  cin >> vectr[i];
        cout << endl;
    }

    for (int i = 0; i < vectr.size(); i++) {
        cout << vectr[i] << " ";
    }

    int digitForDel;
    cout << "\nInput number for delete: ";
    cin >> digitForDel;

    int countCopyDigit = 0;
    for (int i = 0; i < vectr.size(); i++) {
        if (vectr[i] == digitForDel) {
            countCopyDigit++;
        }
    }
    int approveCountElement = 0;
    while (approveCountElement != countCopyDigit) {
        for (int i = 0; i < vectr.size(); i++) {
            if (vectr[i] == digitForDel) {
                vectr.erase(vectr.begin() + i);
            }
        }
        approveCountElement++;
    }

    cout << "\nResult:\n";
    for (int i : vectr) {
        cout << i << " ";
    }
}