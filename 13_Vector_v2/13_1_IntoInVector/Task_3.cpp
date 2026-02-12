//
// Created by kurch on 19.12.2025.
//

#include <iostream>
#include <vector>

using namespace std;

int main () {
    float max = 0.0f, maxTwo = 0.0f;
    vector<float> len{1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    for (int i = 0; i < len.size(); i++) {
        cout << len[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < len.size(); i++) {
        if (len[i] > max) {
            maxTwo = max;
            max = len[i];
        }
        else if (len[i] > maxTwo && len[i] < max)
            maxTwo = len[i];
        }
    cout << max << "\n" <<maxTwo << endl;
}