/*Задание 3. Проверка на чётное число
Что нужно сделать
Напишите программу, которая проверяет, чётное ли число ввел пользователь.

Пример: int remainder = x % 2 (вычисляет остаток от деления `x` на 2).*/

#include <iostream>
//#include <windows.h>

int main() {
//    SetConsoleCP(65001);
//    SetConsoleOutputCP(65001);

    int a;

    std::cout << "Введите число: ";
    std::cin >> a;


    if ( a % 2 > 0) {
        std::cout << "Число " << a << " - НЕчетное";
    } else {
        std::cout << "Число " << a << " - четное";
    }
    return 0;
}
