/**/

#include <iostream>

int main () {
    
    int barber, men, countInMonths, countBarbers, requiredBarbers ;
    
    std::cout << "\nВведите количество мужчин:"; std::cin >> men;
    std::cout << "\nВведите количество барберов:"; std::cin >> barber;
    std::cout << "\n_______Выполняем подсчет_______";
    std::cout << "\nОдин барбер работает 8 часов в день, на одного клиента тратит 1 час.";
    std::cout << "\nСоответственно 8 человек обслуживает 1 барбер в день.";
  
    countInMonths = 8 * 22;

    std::cout << "\nСоответственно "<< countInMonths << " человек обслуживает 1 барбер в месяц.\n";

    countInMonths *= barber;
    std::cout << barber << " барберов обслужат " << countInMonths << " мужчин за месяц.";
    
    requiredBarbers = (men + countInMonths - 1) / countInMonths;
if (barber >= requiredBarbers) {
    std::cout << "\nСледовательно, барберов хватает.";
} else {
    std::cout << "\nСледовательно, барберов НЕ хватает.";
}

     std::cout << " чтобы обслужить " << men << " мужчин за месяц.";
}