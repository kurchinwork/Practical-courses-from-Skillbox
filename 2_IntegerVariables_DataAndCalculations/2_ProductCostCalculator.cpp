//Задание 2. Калькулятор стоимости товара

#include <iostream>

int main() {
    int cost = 120;
    int delivery = 45;
    int sale = 10;
    int price = cost + delivery;
    int price_with_sale = price - ((price * sale) / 100);
    std::cout << price_with_sale;

}