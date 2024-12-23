#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>
#include <fstream>

class Base {
public:
    virtual void input() = 0;   // Ввод данных
    virtual void output() const = 0;   // Вывод данных
    virtual void edit() = 0;    // Редактирование данных

    virtual void saveToFile(std::ofstream& out) const = 0; // Сохранение в файл
    virtual void loadFromFile(std::ifstream& in) = 0;      // Загрузка из файла

    virtual ~Base() {} // Виртуальный деструктор
};

#endif
