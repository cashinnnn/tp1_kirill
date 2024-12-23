#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Base.h"

class Motorcycle : public Base {
private:
    std::string brand;
    std::string model;
    double engineVolume;
    double enginePower;
    std::string terrainType;

public:
    Motorcycle(); // Конструктор по умолчанию
    Motorcycle(const std::string& brand, const std::string& model, double engineVolume, double enginePower,
               const std::string& terrainType); // Конструктор с параметрами
    Motorcycle(const Motorcycle& other); // Конструктор копирования

    void input() override;
    void output() const override;
    void edit() override;
    void saveToFile(std::ofstream& out) const override; // Добавляем декларацию
    void loadFromFile(std::ifstream& in) override;      // Добавляем декларацию

    ~Motorcycle(); // Деструктор
};

#endif
