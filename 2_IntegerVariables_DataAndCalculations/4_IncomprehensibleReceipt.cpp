//Задание 4. Непонятная квитанция

#include <iostream>

int main() {
    int sum = 4000000;
    int numEnter = 10;
    int numApart = 40;
    std::cout << "Введите сумму, указанную в квитанции: " << sum <<"\n";
    std::cout << "Сколько подъездов в вашем доме? " << numEnter <<"\n";
    std::cout << "Сколько квартир в вашем доме? " << numApart <<"\n";
    std::cout << "----Считаем-----\n";
    std::cout << "Каждая квартира должна платить по " << sum / (numEnter * numApart) << " руб.";
   
}