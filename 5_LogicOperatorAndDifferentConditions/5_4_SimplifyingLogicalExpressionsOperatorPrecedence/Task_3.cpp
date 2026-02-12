#include <iostream>

int main () {
    int a, b, c, sum = 0;
    std::cout << "\nВведите число а"; std::cin >> a;
    std::cout << "\nВведите число b"; std::cin >> b;
    std::cout << "\nВведите число c"; std::cin >> c;

    if (a == b || a ==c || b == a || b == c) {
            sum += 2;
    } if (a == b && b == c) {
            sum += 1;
    } 
        std::cout << "\nСовпадает " << sum << " числа.";
}