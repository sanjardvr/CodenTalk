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
            reg.signup("Clients Database Records");
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

void Client::showAllClients()
{
    ui.clearScreen();
    ui.displayHeader("List of all Clients");
    string line;

    ifstream in("Core/Source/Files/clients_db.txt");
    if (in.is_open())
    {
        getline(in, line);
        getline(in, line);
        while (getline(in, line))
        {
            cout << line << std::endl;
        }
    }
    in.close();
    ui.pauseExecution();
}

void Client::deleteClient()
{   
    filePath = "Core/Source/Files/clients_db.txt";
    ifstream inFile(filePath);
    ofstream outFile("Core/Source/Files/clients_db_temp.txt");
    string name, nInput, status;
    bool found = false;
    string line;
    ui.clearScreen();
    ui.displayHeader("Delete Client Proccess");
    ui.getStringInput("Enter Client Name", nInput);

    if (!inFile || !outFile)
    {
        cout << "Failed to open file." << endl;
        return;
    }

    getline(inFile, line);
    outFile << line << endl;
    getline(inFile, line);
    outFile << line << endl;
    while (inFile >> name >> status)
    {
        if (name == nInput)
        {
            found = true;
            continue;
        }
        outFile << name << "\t\t" << status << endl;
    }

    inFile.close();
    outFile.close();

    if (found)
    {
        ui.pauseExecution();
        if (remove(filePath.c_str()) != 0)
        {
            cout << "Failed to delete the original file." << endl;
            return;
        }
        if (rename("Core/Source/Files/clients_db_temp.txt", filePath.c_str()) != 0)
        {
            cout << "Failed to rename the temp file." << endl;
            return;
        }
        cout << "Client successfully deleted." << endl;
    }
    else
    {
        remove("Core/Source/Files/clients_db_temp.txt");
        cout << "Client not found or incorrect name." << endl;
    }

    ui.pauseExecution();
}