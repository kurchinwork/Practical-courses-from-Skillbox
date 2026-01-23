//
// Created by kurch on 22.01.2026.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void outInitList (vector<int>& list) {
    for (int i : list) {
        cout << i << " ";
    }
}
void sortByBubbleMethodWithAbs (vector<int>& list) {
    int  limitList = list.size() - 1;

    for (int i = 0; i < limitList; i++) {
        for (int j = 0; j < limitList - i; j++) {
            if (abs(list[j]) > abs(list[j + 1])) {
                swap(list[j], list[j + 1]);
            }
        }
    }
}

int main () {
    vector<int> initList;
    while (true) {
        int elementsVector;
        cout << "\nPlease enter elements vector: ";
        cin >> elementsVector;

        if (elementsVector == -1) {
            cout << "\nYour entered vector: ";
            outInitList(initList);

            //Перезаписываю чтобы не потерять массив для предыдущего вывода
            vector<int> sortedList = initList;

            cout << "\nVector with sort by bubble method: ";
            sortByBubbleMethodWithAbs (sortedList); outInitList(sortedList);

            if (sortedList.size() > 4) {
                cout << "\nThe fifth element of a vector: " << sortedList[4];
            } else {
                cout << "\nThe fifth element is empty\n";
            }
        }
        else if (elementsVector == -2) {
            cout << "\nStop program.";
            return 0;
        } else {
            initList.push_back(elementsVector);
        }
    }
}