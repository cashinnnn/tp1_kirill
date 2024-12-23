#include <iostream>
#include "Keeper.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Bus.h"

int main() {
    Keeper keeper;
    int choice;

    while (true) {
        std::cout << "1) Добавить машину\n";
        std::cout << "2) Добавить мотоцикл\n";
        std::cout << "3) Добавить автобус\n";
        std::cout << "4) Вывести весь транспорт\n";
        std::cout << "5) Сохранить в файл\n";
        std::cout << "6) Загрузить из файла\n";
        std::cout << "7) Убрать из списка транспорт\n";
        std::cout << "8) Редактировать определенное значение\n";
        std::cout << "9) Выход\n";
        std::cout << "Выберите опцию: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Car* car = new Car();
                car->input();
                keeper.addObject(car);
                break;
            }
            case 2: {
                Motorcycle* motorcycle = new Motorcycle();
                motorcycle->input();
                keeper.addObject(motorcycle);
                break;
            }
            case 3: {
                Bus* bus = new Bus();
                bus->input();
                keeper.addObject(bus);
                break;
            }
            case 4: {
                keeper.outputAll();
                break;
            }
            case 5: {
                keeper.saveToFile("transport.dat");
                break;
            }
            case 6: {
                keeper.loadFromFile("transport.dat");
                break;
            }
            case 7: {
                int index;
                std::cout << "Введите индекс объекта для удаления: ";
                std::cin >> index;
                keeper.removeObject(index);
                break;
            }
            case 8: {
                int index;
                std::cout << "Введите индекс объекта для редактирования: ";
                std::cin >> index;
                keeper.editObject(index);
                break;
            }
            case 9:
                return 0;
            default:
                std::cout << "Неверный выбор.\n";
        }
    }

    return 0;
}
