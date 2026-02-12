#include <iostream>

int main() {
    double n, k, i = 1 ;
    std::cout << "Введите число n, затем степень k"; std::cin >> n >> k; std::cout << "\n";
    while (i < k) {
        n *= n;
        i += 1;
    }
    std::cout << "n в степени k = " << n;

}