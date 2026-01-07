#include <iostream>

int main () {
    float distance, temp, sum;
    std::string Name;

    std::cout << "Здравствуйте, введите свое имя: "; std::cin >> Name; std::cout << std::endl;
    std::cout << Name << " приступим к подсчету, сколько километров Вы пробежали?:= "; std::cin >> distance; std::cout << std::endl;

    for (int i = 0; i < distance; ++i) {
        std::cout << "Какой темп был у Вас на " << i + 1 << " километре?:= "; std::cin >> temp; std::cout << std::endl;
        sum += temp;
    }

    sum = (sum / distance);

    std::cout << "Ваш средний темп за тренировку: " << (int) sum / 60 << " минут " << (int) sum % 60 << " секунд."; std::cout << std::endl;
}