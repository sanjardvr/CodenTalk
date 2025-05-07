#include <iostream>
#include <string>
using namespace std;

#include "../../Core/Source/Core/Core.h"

class Admin : public Module
{
    ConsoleUIManager ui;

public:
    string getName() const override {
        return "Enter as Admin";
    }

    void run() override { 
        bool running = true;
        while (running)
        {
            ui.clearScreen();
            ui.displayHeader("Admin Module");
            string options[] = {"Enter login", "Enter password"};
            ui.displayMenu(options, 2);
            int choice = ui.getInput<int>("Enter choice");

            switch (choice)
            {
            case 1:
                cout << "DONE!" << endl;
                break;
            case 2:
                cout << "DONE!" << endl;
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