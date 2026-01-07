#include <iostream>

int main() {
    int a, b, c, d, sum;
    do {
        std::cout << "\nВведите пин-код: "; std::cin >> a >> b >> c >> d;
        sum = a + b + c + d;
        if (sum != 42) {
             std::cout << "\nВвод некорректный, попробуйте еще раз";
        } else {
             std::cout << "\nВвод корректный";
        }
    } while (sum != 42);
}