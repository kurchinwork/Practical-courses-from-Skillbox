#include <iostream>
#include <string>

using namespace std;

// Класс которым мы будем управлять
class Toy {
    string name;
public:
    // Конструктор создает игрушку с заданным именем
    Toy(string _name) : name(_name) {}

    // Деструктор выводит сообщение при удалении объекта из памяти
    ~Toy() {
        cout << "Toy " << name << " deleted" << endl;
    }

    // Геттер для получения имени
    string getName() { return name; }
};

// Класс умный указатель для объектов Toy
class shared_ptr_toy {
private:
    Toy* obj = nullptr;        // Указатель на сам объект Toy в куче
    int* ref_count = nullptr;  // Указатель на счетчик ссылок в куче (общий для всех копий)

    // Внутренний метод для уменьшения счетчика и очистки ресурсов
    void release() {
        if (ref_count) {             // Если указатель на счетчик существует
            (*ref_count)--;          // Уменьшаем количество владельцев на 1
            if (*ref_count == 0) {   // Если владельцев больше нет
                delete obj;          // Удаляем объект Toy
                delete ref_count;    // Удаляем счетчик из памяти
                cout << "Memory freed" << endl;
            }
        }
        // Зануляем указатели текущего экземпляра, чтобы он считался "пустым"
        obj = nullptr;
        ref_count = nullptr;
    }

public:
    // 1. Конструктор по умолчанию: создает пустой указатель
    shared_ptr_toy() : obj(nullptr), ref_count(nullptr) {}

    // 2. Конструктор по имени: создает новую Toy и новый счетчик со значением 1
    shared_ptr_toy(string name) {
        obj = new Toy(name);
        ref_count = new int(1);
    }

    // 3. Конструктор копирования: вызывается при создании копии (например, ptr2(ptr1))
    shared_ptr_toy(const shared_ptr_toy& other) {
        obj = other.obj;             // Копируем адрес объекта
        ref_count = other.ref_count; // Копируем адрес общего счетчика
        if (ref_count) {
            (*ref_count)++;          // Увеличиваем счетчик, так как появился новый владелец
        }
    }

    // 4. Оператор присваивания (ptr1 = ptr2)
    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        // Если пытаемся присвоить указатель на тот же самый объект — ничего не делаем
        if (this->obj == other.obj) return *this;

        // "Отпускаем" старый объект перед тем, как взять новый
        release();

        // Копируем данные из другого указателя
        obj = other.obj;
        ref_count = other.ref_count;
        if (ref_count) {
            (*ref_count)++;          // Увеличиваем счетчик нового объекта
        }
        return *this;
    }

    // 5. Деструктор: вызывается при выходе указателя из области видимости
    ~shared_ptr_toy() {
        release(); // Пытаемся освободить память
    }


    // Сброс указателя: делает его пустым
    void reset() {
        release();
    }

    // Возвращает чистый указатель на объект Toy
    Toy* get() const {
        return obj;
    }

    // Возвращает текущее количество владельцев объекта
    int use_count() const {
        return (ref_count) ? *ref_count : 0;
    }

    // Возвращает имя игрушки или "Nothing", если указатель пустой
    string getToyName() const {
        return (obj) ? obj->getName() : "Nothing";
    }
};

// Сервисная функция для создания умного указателя через конструктор по имени
shared_ptr_toy make_shared_toy(string name) {
    return shared_ptr_toy(name);
}

int main() {
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");
    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_02 = toy_03;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    toy_01.reset();
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;
    std::cout << "=================================================" << std::endl;
    return 0;
}