#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> db(20);
    int pos = 0;

    while (true) {
        int val;
        cout << "input number: ";
        cin >> val;

        if (val == -1) break;

        db[pos % 20] = val;
        pos++;
    }

    cout << "output: ";
    int start = (pos >= 20) ? pos % 20 : 0;
    int count = min(pos, 20);

    for (int i = 0; i < count; i++) {
        cout << db[(start + i) % 20] << " ";
    }
    cout << endl;
}