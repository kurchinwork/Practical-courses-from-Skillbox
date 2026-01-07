//Задача 3. Злостные вредители

#include <iostream>
//#include <windows.h>

int main()
{
    //SetConsoleOutputCP(1251); 
    //SetConsoleCP(1251); 
    /*Добавил эти две строки чтобы в консоли Visual studio
    корректно отображался русский язык*/

    int startHeight;
    int grewUp;
    int destroyed;
    int height;

    std::cout << "Введите начальный рост в сантиметрах: ";
    std::cin >> startHeight;
    std::cout << "Введите прирост в день (в сантиметрах): ";
    std::cin >> grewUp;
    std::cout << "Введите сколько уничтожается за ночь вредителями (в сантиметрах): ";
    std::cin >> destroyed;

    std::cout << "Бамбук в середине третьего дня будет равен: " << (height = startHeight + (grewUp - destroyed) * 2 + grewUp * 0.5) << " см.";

}
