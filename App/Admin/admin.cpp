#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "admin.h"
#include "../../Core/Source/Core/Core.h"
#include "../../Core/Utils/utils.h"


void Admin::clients()
{  
    bool running = true;
    while (running)
    {
        ui.clearScreen();
        ui.displayHeader("Admin Clients View");
        string options[] = {"Show all Clients", "Delete Client"};
        ui.displayMenu(options, 2);
        int choice = ui.getInput<int>("Enter choice");

        switch (choice)
        {
        case 1:
            client.showAllClients();
            break;
        case 2:
            client.deleteClient();
            break;
        case 0:
            return;
        default:
            ui.displayError("Invalid choice");
            break;
        }
    }
}

void Admin::coffeeModule()
{  
    bool running = true;
    while (running)
    {
        ui.clearScreen();
        ui.displayHeader("Admin Coffee View");
        string options[] = {"Show all Coffee", "Add Coffee", "Delete Coffee"};
        ui.displayMenu(options, 3);
        int choice = ui.getInput<int>("Enter choice");
        switch (choice)
        {
        case 1:
            coffObj.displayAllCoffee();
            break;
        case 2:
            coffObj.createCoffee();
            break;
        case 3:
            coffObj.deleteCoffee();
            break;
        case 0:
            return;
        default:
            ui.displayError("Invalid choice");
            break;
        }
    }
}

void Admin::run()
{
    Registration reg("Core/Source/Files/admins.txt");
    bool loggedIn = false;

    while (!loggedIn)
    {
        ui.clearScreen();
        ui.displayHeader("Admin Module");
        string options[] = {"SignUp", "Login"};
        ui.displayMenu(options, 2);
        int choice = ui.getInput<int>("Enter choice");

        switch (choice)
        {
        case 1:
            reg.signup("Admins Database Records");
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
        ui.displayHeader("Admin Dashboard");
        string options[] = {"Clients", "Coffee", "Settings"};
        ui.displayMenu(options, 3);
        int choice = ui.getInput<int>("Enter choice");

        switch (choice)
        {
        case 1:
            clients();
            break;
        case 2:
            coffeeModule();
            break;
        case 3:
            break;
        case 0:
            return;
        default:
            ui.displayError("Invalid choice");
            break;
        }
    }
}
