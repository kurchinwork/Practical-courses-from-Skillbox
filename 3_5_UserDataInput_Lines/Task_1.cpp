//Задача 1. Симулятор маршрутки

#include <iostream>
//#include <windows.h>

int main() 
{
    //SetConsoleOutputCP(1251); 
    //SetConsoleCP(1251); 
    /*Добавил эти две строки чтобы в консоли Visual studio
    корректно отображался русский язык*/

    int currentNumPasseng = 0;
    int numPassengPassedOut = 0;
    int numPassengPassedEntered = 0;
    int price = 20; //Цена билета
    int moneyDrive;
    int total = 0 ;
    int remainder = 0; 

    std::string busStop_1 = "'Улица Программистов'";
    std::string busStop_2 = "'Улица Вязов'";
    std::string busStop_3 = "'Улица Алгоритмов'";
    std::string busStop_4 = "'Улица Сезам'";

//////////////////////////////////////////////////////////////////////////////////////////////
//......................................Улица 1.............................................//
//////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "-----------Едем---------";
    std::cout << "\nПрибываем на остановку " << busStop_1 << ".";
    
    std::cout << "\nВ салоне пассажиров: " << currentNumPasseng;

   
    std::cout << "\nСколько пассажиров вышло на остановке? (Введите): ";
    std::cin >> numPassengPassedOut;
    std::cout << numPassengPassedOut;
        currentNumPasseng -= numPassengPassedOut;
    std::cout << "\nСколько пассажиров зашло на остановке? (Введите): ";
    std::cin >> numPassengPassedEntered;
    std::cout << numPassengPassedEntered;
        currentNumPasseng += numPassengPassedEntered;

    
    std::cout << "\nОтправляемся с остановки" << busStop_1 << ". В салоне пассажиров: ";
    std::cout << currentNumPasseng;
    moneyDrive = price * currentNumPasseng;
    total += moneyDrive;

//////////////////////////////////////////////////////////////////////////////////////////////
//......................................Улица 2.............................................//
//////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "\n\n-----------Едем---------";
    std::cout << "\nПрибываем на остановку " << busStop_2 << ".";
    
    std::cout << "\nВ салоне пассажиров: " << currentNumPasseng;

   
    std::cout << "\nСколько пассажиров вышло на остановке? (Введите): ";
    std::cin >> numPassengPassedOut;
    std::cout << numPassengPassedOut;
        currentNumPasseng -= numPassengPassedOut;
    std::cout << "\nСколько пассажиров зашло на остановке? (Введите): ";
    std::cin >> numPassengPassedEntered;
    std::cout << numPassengPassedEntered;
        currentNumPasseng += numPassengPassedEntered;

    
    std::cout << "\nОтправляемся с остановки" << busStop_3 << ". В салоне пассажиров: ";
    std::cout << currentNumPasseng;
    moneyDrive = price * currentNumPasseng;
    total += moneyDrive;

//////////////////////////////////////////////////////////////////////////////////////////////
//......................................Улица 3.............................................//
//////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "\n\n-----------Едем---------";
    std::cout << "\nПрибываем на остановку " << busStop_3 << ".";
    
    std::cout << "\nВ салоне пассажиров: " << currentNumPasseng;

   
    std::cout << "\nСколько пассажиров вышло на остановке? (Введите): ";
    std::cin >> numPassengPassedOut;
    std::cout << numPassengPassedOut;
        currentNumPasseng -= numPassengPassedOut;
    std::cout << "\nСколько пассажиров зашло на остановке? (Введите): ";
    std::cin >> numPassengPassedEntered;
    std::cout << numPassengPassedEntered;
        currentNumPasseng += numPassengPassedEntered;

    
    std::cout << "\nОтправляемся с остановки" << busStop_1 << ". В салоне пассажиров: ";
    std::cout << currentNumPasseng;
    moneyDrive = price * currentNumPasseng;
    total += moneyDrive;

//////////////////////////////////////////////////////////////////////////////////////////////
//......................................Улица 4.............................................//
//////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "\n\n-----------Едем---------";
    std::cout << "\nПрибываем на остановку " << busStop_4 << ".";
    
    std::cout << "\nВ салоне пассажиров: " << currentNumPasseng;

   
    std::cout << "\nСколько пассажиров вышло на остановке? (Введите): ";
    std::cin >> numPassengPassedOut;
    std::cout << numPassengPassedOut;
        currentNumPasseng -= numPassengPassedOut;
    std::cout << "\nСколько пассажиров зашло на остановке? (Введите): ";
    std::cin >> numPassengPassedEntered;
    std::cout << numPassengPassedEntered;
        currentNumPasseng += numPassengPassedEntered;

    
    std::cout << "\nОтправляемся с остановки" << busStop_1 << ". В салоне пассажиров: ";
    std::cout << currentNumPasseng;
    moneyDrive = price * currentNumPasseng;
    total += moneyDrive;

//////////////////////////////////////////////////////////////////////////////////////////////
//......................................Расчет..............................................//
//////////////////////////////////////////////////////////////////////////////////////////////

    std::cout << "\n\nВсего заработали: ";
    std::cout << total;
    std::cout << " руб.";

    int driver;
    std::cout << "\nЗарплата водителя: " << (driver = total * 0.25) << " руб.";
        int ost = driver;
        ost = total - ost;
    
    int fuel;
    std::cout << "\nРасходы на топливо: " << (fuel = ost * 0.2) << " руб.";
    remainder +=fuel;

    int taxServ;
    std::cout << "\nНалоги: " << (taxServ = ost * 0.2) << " руб.";
    remainder +=taxServ;

    int repair;
    std::cout << "\nРасходы на ремонт машины: " << (repair = ost * 0.2) << " руб.";
    remainder +=repair;

    //total = total - remainder - driver;
    std::cout << "\nИтого доход: " << (total - remainder - driver) << " руб.";
}