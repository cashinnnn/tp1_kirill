#ifndef CAR_H
#define CAR_H

#include "Base.h"

class Car : public Base {
private:
    std::string brand;
    std::string model;
    double engineVolume;
    std::string color;
    std::string transmissionType;

public:
    Car(); // Конструктор по умолчанию
    Car(const std::string& brand, const std::string& model, double engineVolume,
        const std::string& color, const std::string& transmissionType); // Конструктор с параметрами
    Car(const Car& other); // Конструктор копирования

    void input() override;
    void output() const override;
    void edit() override;
    void saveToFile(std::ofstream& out) const override; // Добавляем декларацию
    void loadFromFile(std::ifstream& in) override;      // Добавляем декларацию

    ~Car(); // Деструктор
};

#endif
