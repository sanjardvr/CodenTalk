#ifndef CLIENT
#define CLIENT
#include <iostream>
#include <string>
using namespace std;

#include "../Person/person.h"
#include "../../Core/Source/Core/Core.h"

class Client : public Module, public Person
{
    ConsoleUIManager ui;

public:
    string getName() const override
    {
        return "Enter as Client";
    }

    void showAllClients();
    void deleteClient();
    void addPersonalInfo();
    void run() override;
};

#endif //This gives compiler ability to skip compilation of this file for several times
