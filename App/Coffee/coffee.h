#include <iostream>
#include <fstream>
#include <string>

#include "../../Core/Source/Core/Core.h"
using namespace std;


class Coffee
{
private:
    ConsoleUIManager ui;
    string name, price;

protected:
    string filePath;

public:
    Coffee() {}
    Coffee(string filePath) { this->filePath = filePath; }

    void displayAllCoffee();
    void createCoffee();
    void deleteCoffee();

    // getter setter
    void setName(string n) { name = n; }
    void setPrice(string p) { price = p; }

    string getName() { return name; }
    string getPrice() { return price; }
};