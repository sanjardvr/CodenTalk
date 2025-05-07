#include <iostream>
#include <string>
using namespace std;

#include "../../Core/Source/Core/Core.h"

class Client : public Module
{
    ConsoleUIManager ui;
    void enterNumber()
    {
        ui.displaySuccess("Entered with Number");
    }

    void enterAccount()
    {
        ui.displaySuccess("Entered with Account");
    }

public:
    string getName() const override
    {
        return "Enter as Client";
    }

    void run() override
    {
        bool running = true;
        while (running)
        {
            ui.clearScreen();
            ui.displayHeader("Client Module");
            string options[] = {"Enter number", "Enter account"};
            ui.displayMenu(options, 2);
            int choice = ui.getInput<int>("Enter choice");

            switch (choice)
            {
            case 1:
                enterNumber();
                break;
            case 2:
                enterAccount();
                break;
            case 0:
                return;
            default:
                ui.displayError("Invalid choice");
                break;
            }
        }
    }
};
