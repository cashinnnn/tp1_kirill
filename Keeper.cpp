#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"
#include <fstream>
#include <iostream>
#include <typeinfo>

Keeper::~Keeper() {
    for (auto obj : objects) {
        delete obj;
    }
}

void Keeper::addObject(Base* obj) {
    objects.push_back(obj);
}

void Keeper::removeObject(int index) {
    if (index >= 0 && index < objects.size()) {
        delete objects[index];
        objects.erase(objects.begin() + index);
    } else {
        std::cout << "Объект с таким индексом не существует.\n";
    }
}

void Keeper::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка открытия файла для сохранения.");
    }

    file << objects.size() << '\n';
    for (auto obj : objects) {
        obj->saveToFile(file);
    }

    file.close();
    std::cout << "Данные успешно сохранены в файл.\n";
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Ошибка открытия файла для загрузки.");
    }

    size_t size;
    file >> size;
    file.ignore();

    for (size_t i = 0; i < size; ++i) {
        std::string type;
        std::getline(file, type);

        Base* obj = nullptr;
        if (type == "Car") {
            obj = new Car();
        } else if (type == "Motorcycle") {
            obj = new Motorcycle();
        } else if (type == "Bus") {
            obj = new Bus();
        }

        if (obj) {
            obj->loadFromFile(file);
            objects.push_back(obj);
        }
    }

    file.close();
    std::cout << "Данные успешно загружены из файла.\n";
}

void Keeper::outputAll() const {
    if (objects.empty()) {
        std::cout << "Список пуст.\n";
    } else {
        for (size_t i = 0; i < objects.size(); ++i) {
            std::cout << "Индекс: " << i << std::endl;
            objects[i]->output();
        }
    }
}

void Keeper::editObject(int index) {
    if (index >= 0 && index < objects.size()) {
        objects[index]->edit();
    } else {
        std::cout << "Объект с таким индексом не существует.\n";
    }
}
