//
// Created by kurch on 03.02.2026.
//
#include <iostream>
#include <vector>
using namespace std;

void swapvec (vector <int> &v, vector <int> &w) {
    for (int i = 0; i < v.size(); i++) {
        int temp = v[i];
        v[i] = w[i];
        w[i] = temp;
    }
}
void outVec (vector <int> &v, vector <int> &w) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << w[i] << " ";
    }
}
int main () {
    vector<int> a = {1,2,3,4},
                b = {2,4,6,8};
    swapvec(a,b);
    outVec(a,b);

    return 0;
}


