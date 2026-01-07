//
// Created by kurch on 19.12.2025.
//


#include <iostream>
#include <vector>

using namespace std;

int main () {
    int n, sum = 0;
    cout << "Enter the number of elements in the vector: N =  "; cin >> n; cout << endl;

    vector<int> len(n);
    cout << "Now enter the elements of the vector sequentially into a row:\n"
            "It should be remembered that the number of vector elements is no more than " << n << endl;

    for (int i = 0; i < n; i++) {
        cin >> len[i];
        sum += len[i];
    }
    cout << "Arithmetic mean of a vector: " << sum / n << endl;
}
