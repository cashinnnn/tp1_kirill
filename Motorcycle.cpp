#include "Motorcycle.h"

Motorcycle::Motorcycle() {
    std::cout << "Конструктор Motorcycle по умолчанию\n";
}

Motorcycle::Motorcycle(const std::string& brand, const std::string& model, double engineVolume, double enginePower,
                       const std::string& terrainType)
        : brand(brand), model(model), engineVolume(engineVolume), enginePower(enginePower), terrainType(terrainType) {
    std::cout << "Конструктор Motorcycle с параметрами\n";
}

Motorcycle::Motorcycle(const Motorcycle& other)
        : brand(other.brand), model(other.model), engineVolume(other.engineVolume),
          enginePower(other.enginePower), terrainType(other.terrainType) {
    std::cout << "Конструктор копирования Motorcycle\n";
}

void Motorcycle::input() {
    std::cout << "Введите марку мотоцикла: ";
    std::cin >> brand;
    std::cout << "Введите модель мотоцикла: ";
    std::cin >> model;
    std::cout << "Введите объем двигателя: ";
    std::cin >> engineVolume;
    std::cout << "Введите мощность двигателя: ";
    std::cin >> enginePower;
    std::cout << "Введите тип местности: ";
    std::cin >> terrainType;
}

void Motorcycle::output() const {
    std::cout << "Марка: " << brand << ", Модель: " << model << ", Объем двигателя: " << engineVolume
              << ", Мощность двигателя: " << enginePower << ", Местность: " << terrainType << std::endl;
}

void Motorcycle::edit() {
    int choice;
    std::cout << "Что вы хотите изменить?\n1. Марка\n2. Модель\n3. Объем двигателя\n4. Мощность двигателя\n5. Местность\n";
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "Введите новую марку: ";
            std::cin >> brand;
            break;
        case 2:
            std::cout << "Введите новую модель: ";
            std::cin >> model;
            break;
        case 3:
            std::cout << "Введите новый объем двигателя: ";
            std::cin >> engineVolume;
            break;
        case 4:
            std::cout << "Введите новую мощность двигателя: ";
            std::cin >> enginePower;
            break;
        case 5:
            std::cout << "Введите новый тип местности: ";
            std::cin >> terrainType;
            break;
        default:
            std::cout << "Неверный выбор.\n";
    }
}

void Motorcycle::saveToFile(std::ofstream& out) const {
    out << "Motorcycle\n";
    out << brand << '\n'
        << model << '\n'
        << engineVolume << '\n'
        << enginePower << '\n'
        << terrainType << '\n';
}

void Motorcycle::loadFromFile(std::ifstream& in) {
    std::getline(in, brand);
    std::getline(in, model);
    in >> engineVolume >> enginePower;
    in.ignore();
    std::getline(in, terrainType);
}


Motorcycle::~Motorcycle() {
    std::cout << "Деструктор Motorcycle\n";
}
