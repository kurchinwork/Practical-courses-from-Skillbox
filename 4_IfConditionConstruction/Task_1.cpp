/*Задание 1. Минимум из двух чисел
Что нужно сделать
Напишите программу, которая ищет минимальное значение из двух чисел.*/

#include <iostream>

int main() {

    int a,b;
    std::cout << "Введите первое число: "; std::cin >> a; std::cout << std::endl;
    std::cout << "Введите второе число: "; std::cin >> b; std::cout << std::endl;
    std::cout << "-----Проверяем-----\n";

    if (a < b) {
        std::cout << "Наименьшее число: " << a << std::endl;
    } else {
        std::cout << "Наименьшее число: " << b << std::endl;
    }

    return 0;
}