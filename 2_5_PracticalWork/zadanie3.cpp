//Задание 3. Время, время!

#include <iostream>

int main() {
    int order = 2;
    int collectOrder = 4;
    int shiftDuration = 480;
    std::cout << "Эта программа рассчитает, сколько клиентов успеет обслужить кассир за смену.\n";
    std::cout << "Введите длительность смены в минутах: " << shiftDuration << "\n";
    std::cout << "Сколько минут клиент делает заказ? " << order << "\n";
    std::cout << "Сколько минут кассир собирает заказ? " << collectOrder << "\n";
    std::cout << "-----Считаем-----\n";
    std::cout << "За смену длиной " << shiftDuration << " минут кассир успеет собрать " << shiftDuration / (collectOrder + order) << " клиентов.";

}
