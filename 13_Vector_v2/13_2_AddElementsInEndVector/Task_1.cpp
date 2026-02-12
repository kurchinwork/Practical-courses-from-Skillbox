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
    int num = 0;

    cout << "Input your number:";
    while (num != -1) {

        cin >> num;
        len_1 = add(len_1, num);

    }
    for (int i = 0; i <len_1.size(); ++i)
        cout << len_1[i] << " ";

}