#include <iostream>

int main() 
{
    std::string login;
    std::string password;
    std::cout << "Введите логин:";
    std::cin >> login;
    std::cout << "\nВведите пароль:\n";
    std::cin >> password;
    std::cout << login;
    std::cout << ", вы успешно зашли!";
}