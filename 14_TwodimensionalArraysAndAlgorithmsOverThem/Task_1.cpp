//
// Created by kurch on 14.01.2026.
//

#include <iostream>
using namespace std;

void outArray (int array[2][12], int cols, int rows) {
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << array [i][j] << "\t";
        }
        cout << endl;
    }
}

int main () {
    int cutlery [2][12] {
        {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3},
        {4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3}
    };
    int plates [2][12] {
        {3, 2,  2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
        {3, 2,  2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
    };
    int chairs[2][12]{
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    cout << "A woman with children came in fifth place\n"
            "Taken this into account, the numbers chairs will be increased.\n";
    chairs [0][4] += 1;
    outArray(chairs, 2, 12);

    cout << "\nAttention, spoon stolen!\n";
    cutlery[1][2] -= 1;
    outArray(cutlery, 2, 12);

    cout << "\nVIP person give spoon another person.\n";
    cutlery[0][0] -= 1;
    outArray(cutlery, 2, 12);

    cout << "\nThe waiter took the dessert plate away.\n";
    plates [0][0] -= 1;
    outArray(plates, 2, 12);
}