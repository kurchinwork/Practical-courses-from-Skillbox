//
// Created by kurch on 22.01.2026.
// Максимальная сумма подотрезка

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void outInitList (vector<int>& list) {
    for (int i : list) {
        cout << i << " ";
    }
}
void maxSum (vector<int> mainVector) {
    /*    Вывод только сумму элементов
     *    int currentMax = mainVector[0], maxSoFar = mainVector[0];

        //Старт итерации со второго элемента
        for (int i = 1; i < mainVector.size(); i++) {
            currentMax = max(mainVector[i], currentMax+mainVector[i]);
            maxSoFar = max(maxSoFar, currentMax);
        }
        cout << "\nMax sum under the segment:" << maxSoFar << endl << "Elements index:" << mainVector;
    }
    */

    int currentMax = 0,
        maxSoFar = 0,
        startIndex = 0,
        endIndex = 0,
        tempIndex = 0;

    for (int i = 1; i < mainVector.size(); i++) {
        if (mainVector[i] > currentMax + mainVector[i]) {
            currentMax = mainVector[i];
            tempIndex = i;
        } else {
            currentMax += mainVector[i];
        }
        if (currentMax > maxSoFar) {
            maxSoFar = currentMax;
            startIndex = tempIndex;
            endIndex = i;
        }
    }
    cout << "\nMax sum under the segment:" << maxSoFar << endl << "Elements index:" <<startIndex << "," << endIndex << endl;
}


int main() {
    vector <int> listInitData = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Original vector:\n";
    outInitList(listInitData);
    maxSum(listInitData);
}