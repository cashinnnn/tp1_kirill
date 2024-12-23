#ifndef KEEPER_H
#define KEEPER_Hgit remote add origin https://github.com/cashinnnn/tp1_kirill.git

#include "Base.h"
#include <vector>
#include <fstream>
#include <stdexcept>

class Keeper {
private:
    std::vector<Base*> objects;

public:
    ~Keeper();

    void addObject(Base* obj);
    void removeObject(int index);
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
    void outputAll() const;
    void editObject(int index);
};

#endif
