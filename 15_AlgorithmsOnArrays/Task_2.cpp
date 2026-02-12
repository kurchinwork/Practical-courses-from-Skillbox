//
// Created by kurch on 23.01.2026.
//

#include <iostream>
#include <vector>

using namespace std;

void outInitList (vector<int>& list) {
    for (int i : list) {
        cout << i << " ";
    }
}
void searchElement (vector<int> mainVector,int elementForSearch) {
    int currentSum = 0,
        startIndex = 0,
        endIndex = 0,
        tempIndex = 0;
    for (int i = 0; i < mainVector.size() - 1; i++) {
        currentSum = mainVector[i] + mainVector[i + 1];
        tempIndex = i;
        if (currentSum == elementForSearch) {
            startIndex = tempIndex;
            endIndex = i + 1;
        }
    }
    cout << "Position find index " << startIndex << "," << endIndex << " for element " << elementForSearch << endl;
}


int main() {
    vector <int> listInitData = {2, 7, 11, 15};
    cout << "\nInitial vector:"; outInitList(listInitData);

    int findElement;
    cout << "\nEnter the element you are looking for: "; cin >> findElement;
    searchElement(listInitData, findElement);
}