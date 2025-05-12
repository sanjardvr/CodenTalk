#include <iostream>
#include <string>
using namespace std;

#include "../Person/person.h"
#include "../Client/client.h"
#include "../Coffee/coffee.h"
#include "../../Core/Source/Core/Core.h"

class Admin : public Module , Person
{   
    Client client;
    Coffee coffObj;
    ConsoleUIManager ui;

public:
    Admin() : coffObj("Core/Source/Files/coffee.txt") {}
    string getName() const override
    {
        return "Enter as Admin";
    }
    void clients();
    void coffeeModule();
    void settings();
    void run() override;
};