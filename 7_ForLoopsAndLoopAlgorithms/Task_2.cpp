/*Ваш космический корабль потерпел крушение на пустынной планете. 
Еда здесь не растёт, но вы спасли из-под обломков 100-килограммовый мешок гречки. 
Из прошлого опыта вы знаете, что если будете экономно питаться, 
то у вас будет уходить по четыре килограмма гречки в месяц. 
Чтобы прикинуть гречневый бюджет, вы решили написать программу, 
которая выведет информацию о том, сколько килограммов гречки у вас 
должно быть в запасе через месяц, два и так далее, пока она не закончится.*/

#include <iostream>

int main () {
    int count_milk, count_water;
    std::string password = "StartAdmin";
    std::string checkPassword;

    while (true) {
        
        std::cout << "\n***Запущен сервисный режим***";
        std::cout << "\nСколько мл воды в аппарате?: "; std::cin >> count_water;
        std::cout << "\nСколько мл молока в аппарате?: "; std::cin >> count_milk;
         std::cout << "\nЧтобы ввести машину в работу необходимо ввести пароль.";
        
        for (int attempt = 0; attempt < 3; attempt++) {
                    std::cout << "\nВведите пароль (попытка " << (attempt + 1) << " из 3): "; 
                    std::cin >> checkPassword;
                    
                    if (password == checkPassword) {
                        bool logic = count_milk > 0 && count_water > 0;
                        int m, countAmericano = 0, countLatte = 0;
                        
                        while (logic) {
                            std::string nameUser;
                            std::cout << "\nЗдравствуйте, Вас приветствует аппарат для кофе, как Вас зовут? "; 
                            std::cin >> nameUser;
                            
                            std::cout << "\n" << nameUser << " мы можем Вам предложить два вида напитка:";
                            std::cout << "\n1. Американо\n2. Латте\nВыберите 1 или 2: "; 
                            std::cin >> m;

                            if (m == 1) {
                                if (count_water >= 300) {
                                    std::cout << "\nАмерикано для клиента по имени " << nameUser << " готовится, ожидайте 3 минуты.";
                                    count_water -= 300;
                                    countAmericano += 1;
                                } else {
                                    std::cout << "\nИзвините, недостаточно воды для приготовления Американо.";
                                }
                            } else if (m == 2) {
                                if (count_water >= 30 && count_milk >= 270) {
                                    std::cout << "\nЛатте для клиента по имени " << nameUser << " готовится, ожидайте 4 минуты.";
                                    count_water -= 30;
                                    count_milk -= 270;
                                    countLatte += 1;
                                } else {
                                    std::cout << "\nИзвините, недостаточно ингредиентов для приготовления Латте.";
                                }
                            } else {
                                std::cout << "\nНеверный выбор!";
                            }
                            
                            std::cout << "\nИнгредиентов осталось:";
                            std::cout << "\n          Вода: " << count_water << " мл";
                            std::cout << "\n          Молоко: " << count_milk << " мл";
                            std::cout << "\n****************      **********************\n";

                            
                            if (!(count_water >= 300 || (count_water >= 30 && count_milk >= 270))) {
                                logic = false;
                            }
                        }
                        
                        
                        while (true) {
                            int k;
                            std::cout << "\nРабота остановлена, дождитесь возобновления работы аппарата.";
                            std::cout << "\nКружек американо приготовлено:" << countAmericano;
                            std::cout << "\nКружек латте приготовлено:" << countLatte; std::cin >> k;
                        }

                    }

                    if (attempt == 0) {
                        std::string go;
                        std::cout << "\nПароль неверный. Повторить попытку? (Y/n): ";
                        std::cin >> go;
                        if (!(go == "Y" || go == "y")) {
                            break;
                        }
                    }
                }

                std::cout << "\nДоступ запрещен. Завершение работы.";
                break;
    }
}