#include "Bus.h"

Bus::Bus() {
    std::cout << "Конструктор Bus по умолчанию\n";
}

Bus::Bus(const std::string& brand, const std::string& model, int seatingCapacity, int totalCapacity, const std::string& finalDestination)
        : brand(brand), model(model), seatingCapacity(seatingCapacity), totalCapacity(totalCapacity), finalDestination(finalDestination) {
    std::cout << "Конструктор Bus с параметрами\n";
}

Bus::Bus(const Bus& other)
        : brand(other.brand), model(other.model), seatingCapacity(other.seatingCapacity),
          totalCapacity(other.totalCapacity), finalDestination(other.finalDestination) {
    std::cout << "Конструктор копирования Bus\n";
}

void Bus::input() {
    std::cout << "Введите марку автобуса: ";
    std::cin >> brand;
    std::cout << "Введите модель автобуса: ";
    std::cin >> model;
    std::cout << "Введите количество сидячих мест: ";
    std::cin >> seatingCapacity;
    std::cout << "Введите общее количество пассажирских мест: ";
    std::cin >> totalCapacity;
    std::cout << "Введите конечный пункт маршрута: ";
    std::cin >> finalDestination;
}

void Bus::output() const {
    std::cout << "Марка: " << brand << ", Модель: " << model << ", Сидячих мест: " << seatingCapacity
              << ", Общее количество мест: " << totalCapacity << ", Конечный пункт: " << finalDestination << std::endl;
}

void Bus::edit() {
    int choice;
    std::cout << "Что вы хотите изменить?\n1. Марка\n2. Модель\n3. Сидячие места\n4. Общее количество мест\n5. Конечный пункт\n";
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
            std::cout << "Введите новое количество сидячих мест: ";
            std::cin >> seatingCapacity;
            break;
        case 4:
            std::cout << "Введите новое общее количество мест: ";
            std::cin >> totalCapacity;
            break;
        case 5:
            std::cout << "Введите новый конечный пункт маршрута: ";
            std::cin >> finalDestination;
            break;
        default:
            std::cout << "Неверный выбор.\n";
    }
}

void Bus::saveToFile(std::ofstream& out) const {
    out << "Bus\n";
    out << brand << '\n'
        << model << '\n'
        << seatingCapacity << '\n'
        << totalCapacity << '\n'
        << finalDestination << '\n';
}

void Bus::loadFromFile(std::ifstream& in) {
    std::getline(in, brand);
    std::getline(in, model);
    in >> seatingCapacity >> totalCapacity;
    in.ignore();
    std::getline(in, finalDestination);
}


Bus::~Bus() {
    std::cout << "Деструктор Bus\n";
}

