#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "client.h"
#include "../../Core/Source/Core/Core.h"
#include "../../Core/Utils/utils.h"
#include "../Coffee/coffee.h"

void orderCoffee()
{
    Coffee coffee("Core/Source/Files/coffee.txt");
    ConsoleUIManager ui;

    string coffee_name;
    ui.clearScreen();
    ui.displayHeader("Order Coffee Process");
    coffee.displayAllCoffee();
    coffee.findCoffee();
}


void Client::addPersonalInfo()
{
    string filePath = "Core/Source/Files/clients_db.txt";
    ofstream activeFile;
    string nInp;
    string age;
    ConsoleUIManager ui;
    ui.clearScreen();
    ui.displayHeader("Personal Information");
    ui.getStringInput("Enter your Name", nInp);
    ui.getStringInput("Enter your Age", age);

    this->setName(nInp);
    this->setStatus("Active");
    activeFile.open(filePath, ios::app);
    if (activeFile.is_open())
    {
        // here we move to the end of the file to check is it empty or not, to append or create new file
        activeFile.seekp(0, ios::end);
        if (activeFile.tellp() == 0)
        {
            activeFile << "--------Clients Database Records--------" << endl;
            activeFile << "                                        " << endl;
        }
        activeFile << nInp << "\t\t" << this->getStatus() << endl;
    }
    else
    {
        // stop the program to handle exception
        throw runtime_error("Failed to open file for writing.");
    }
    activeFile.close();
    cout << "\nYour details have been saved" << endl;
    ui.pauseExecution();
}

void Client::run()
{   
    Registration reg("Core/Source/Files/clients.txt");
    bool loggedIn = false;

    while (!loggedIn)
    {
        ui.clearScreen();
        ui.displayHeader("Client Module");
        string options[] = {"SignUp", "Login"};
        ui.displayMenu(options, 2);
        int choice = ui.getInput<int>("Enter choice");

        switch (choice)
        {
        case 1:
            reg.signup();
            this->addPersonalInfo();
            break;
        case 2:
            if (reg.login())
            {
                loggedIn = true;
            }
            break;
        case 0:
            return;
        default:
            ui.displayError("Invalid choice");
            break;
        }
    }

    bool running = true;
    while (running)
    {
        ui.clearScreen();
        ui.displayHeader("Client Dashboard");
        string options[] = {"Show Personal Info", "Order Coffee", "LogOut"};
        ui.displayMenu(options, 3);
        int choice = ui.getInput<int>("Enter choice");

        switch (choice)
        {
        case 1:
            displaySelfInfo();
            break;
        case 2:
            orderCoffee();
            break;
        case 3:
            reg.logOut();
            loggedIn = false;
            running = false;
            break;
        case 0:
            return;
        default:
            ui.displayError("Invalid choice");
            break;
        }
    }
}
