#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 1. Структура для хранения пары Ключ-Значение
template <typename K, typename V>
struct Entry {
    K key;
    V value;
};

// 2. Класс Реестра
template <typename K, typename V>
class Registry {
private:
    std::vector<Entry<K, V>> items;

public:
    // Добавление элемента
    void add(K key, V value) {
        items.push_back({key, value});
    }

    // Удаление всех элементов с заданным ключом
    void remove(K key) {
        for (auto it = items.begin(); it != items.end(); ) {
            if (it->key == key) {
                it = items.erase(it);
            } else {
                ++it;
            }
        }
    }

    // Вывод всех элементов
    void print() {
        if (items.empty()) {
            std::cout << "Registry is empty." << std::endl;
            return;
        }
        for (const auto& item : items) {
            std::cout << "[" << item.key << "]: " << item.value << std::endl;
        }
    }

    // Поиск элементов по ключу
    void find(K key) {
        bool found = false;
        for (const auto& item : items) {
            if (item.key == key) {
                std::cout << "Found: " << item.value << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No items found for this key." << std::endl;
        }
    }
};


template <typename K, typename V>
void runRegistry() {
    Registry<K, V> reg;
    std::string command;
    
    std::cout << "Commands: add, remove, print, find, exit" << std::endl;

    while (true) {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "add") {
            K key;
            V value;
            std::cout << "Enter key: "; std::cin >> key;
            std::cout << "Enter value: "; std::cin >> value;
            reg.add(key, value);
        } else if (command == "remove") {
            K key;
            std::cout << "Enter key to remove: "; std::cin >> key;
            reg.remove(key);
        } else if (command == "print") {
            reg.print();
        } else if (command == "find") {
            K key;
            std::cout << "Enter key to find: "; std::cin >> key;
            reg.find(key);
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Unknown command!" << std::endl;
        }
    }
}

int main() {
    std::cout << "Starting registry (Key: string, Value: int)" << std::endl;
    runRegistry<std::string, int>();
    
    return 0;
}
