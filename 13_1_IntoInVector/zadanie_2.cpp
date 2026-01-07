//
// Created by kurch on 19.12.2025.
//

#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n = 0;

    cout << "Enter the number of elements in the vector: "; cin >> n; cout << endl;
    cout << "Enter the vector elements: ";
    vector<float> len(n);
    for (int i = 0; i < n; i++) {
        cin >> len[i];
    }
    cout << "Reverse the vector: ";
    for (int i = n - 1; i >= 0; i--) {
        cout << len[i] << " ";
    }
}