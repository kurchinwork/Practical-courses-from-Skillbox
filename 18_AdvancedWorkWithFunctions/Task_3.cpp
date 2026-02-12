//
// Created by kurch on 03.02.2026.
//
#include <iostream>
using namespace std;

void superLongDigit (long long digit, int &countHonest) {
    if (digit == 0) {
        return;
    }

    int lastDigit = digit / 10;
    if (lastDigit % 2 == 0)
        countHonest++;
    long long tempDigit = digit / 10;
    superLongDigit(tempDigit, countHonest);
}

int main() {
    long long longDigit = 9223372036854775806;
    int ans = 0;
    superLongDigit(longDigit, ans);
    cout << ans << endl;
}