#ifndef BUS_H
#define BUS_H

#include "Base.h"

class Bus : public Base {
private:
    std::string brand;
    std::string model;
    int seatingCapacity;
    int totalCapacity;
    std::string finalDestination;

public:
    Bus(); // Конструктор по умолчанию
    Bus(const std::string& brand, const std::string& model, int seatingCapacity, int totalCapacity, const std::string& finalDestination);
    Bus(const Bus& other);

    void input() override;
    void output() const override;
    void edit() override;

    void saveToFile(std::ofstream& out) const override; // Добавляем декларацию
    void loadFromFile(std::ifstream& in) override;      // Добавляем декларацию

    ~Bus(); // Деструктор
};

#endif
