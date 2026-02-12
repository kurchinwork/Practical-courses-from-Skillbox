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
    vector<int> initList = {-100, -50, -5, 1, 10, 15};
    cout << "Original vector: ";
    outInitList(initList);
    cout << "\nRunning sort with use ABS...\n";
    sortByBubbleMethodWithAbs(initList);
    cout << "Sorted by ABS is complited!\nVector: ";
    outInitList(initList);
}