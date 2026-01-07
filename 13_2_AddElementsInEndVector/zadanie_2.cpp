//
// Created by kurch on 22.12.2025.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> add(vector<int> len_1, int val){
    vector<int> len_2(len_1.size() + 1);
    for (int i = 0; i <len_1.size(); ++i)
        len_2[i] = len_1[i];
    len_2 [len_1.size()] = val;

    return len_2;
}
int main() {
    vector<int> len_1;
    int num = 0, sum = 0;
    cout << "Enter patient number:\n";
    while (num != -1) {
        cin >> num;
        if (num == -1) {
            break;
        }
        len_1 = add(len_1, num);
    }
    cout << "\nAll patients with numbers:\n";
    for (int i = 0; i < len_1.size(); ++i) {
        cout << len_1[i] << " ";
        sum += len_1[i];
    }
    cout << "\nAverage age of patients:" << sum / len_1.size() << "\nTotal patients:" << len_1.size();
}