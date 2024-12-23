#include "Car.h"

Car::Car() {
    std::cout << "Конструктор Car по умолчанию\n";
}

Car::Car(const std::string& brand, const std::string& model, double engineVolume,
         const std::string& color, const std::string& transmissionType)
        : brand(brand), model(model), engineVolume(engineVolume), color(color), transmissionType(transmissionType) {
    std::cout << "Конструктор Car с параметрами\n";
}

Car::Car(const Car& other)
        : brand(other.brand), model(other.model), engineVolume(other.engineVolume),
          color(other.color), transmissionType(other.transmissionType) {
    std::cout << "Конструктор копирования Car\n";
}

void Car::saveToFile(std::ofstream& out) const {
    out << "Car\n";
    out << brand << '\n'
        << model << '\n'
        << engineVolume << '\n'
        << color << '\n'
        << transmissionType << '\n';
}

void Car::loadFromFile(std::ifstream& in) {
    std::getline(in, brand);
    std::getline(in, model);
    in >> engineVolume;
    in.ignore();
    std::getline(in, color);
    std::getline(in, transmissionType);
}

void Car::input() {
    std::cout << "Введите марку автомобиля: ";
    std::cin >> brand;
    std::cout << "Введите модель автомобиля: ";
    std::cin >> model;
    std::cout << "Введите объем двигателя: ";
    std::cin >> engineVolume;
    std::cout << "Введите цвет автомобиля: ";
    std::cin >> color;
    std::cout << "Введите тип КПП: ";
    std::cin >> transmissionType;
}

void Car::output() const {
    std::cout << "Марка: " << brand << ", Модель: " << model << ", Объем двигателя: " << engineVolume
              << ", Цвет: " << color << ", Тип КПП: " << transmissionType << std::endl;
}

void Car::edit() {
    int choice;
    std::cout << "Что вы хотите изменить?\n1. Марка\n2. Модель\n3. Объем двигателя\n4. Цвет\n5. Тип КПП\n";
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
            std::cout << "Введите новый цвет: ";
            std::cin >> color;
            break;
        case 5:
            std::cout << "Введите новый тип КПП: ";
            std::cin >> transmissionType;
            break;
        default:
            std::cout << "Неверный выбор.\n";
    }
}

Car::~Car() {
    std::cout << "Деструктор Car\n";
}

#include "Car.h"



