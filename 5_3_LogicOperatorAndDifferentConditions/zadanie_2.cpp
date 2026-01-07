#include <iostream>

int main () {
    int a, b, c;
    std::cout << "\nВведите длину первой палочки"; std::cin >> a;
    std::cout << "\nВведитедлину второй  палочки"; std::cin >> b;
    std::cout << "\nВведите длину третьей  палочки"; std::cin >> c;

    if ( (a + b) <= c || (c + b) <= a || (a + c) <= b) {
                std::cout << "\nТреугольник сложить нельзя!";
    } else {
        std::cout << "\nТреугольник сложить можно!";
    }
    
}