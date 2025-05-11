#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "../../Core/Source/Core/Core.h"
#include "coffee.h"

void Coffee::displayAllCoffee()
{
    ui.clearScreen();
    ui.displayHeader("List of all Coffee");
    string line;
 
    ifstream in(filePath);
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << std::endl;
        }
    }
    in.close();  
    ui.pauseExecution(); 
}

void Coffee::createCoffee()
{   

    ofstream activeFile;
    string name;
    string price;
    ConsoleUIManager ui;
    ui.clearScreen();
    ui.displayHeader("New Coffee");
    ui.getStringInput("Enter Coffee Name", name);
    ui.getStringInput("Enter Coffee Price", price);

    setName(name);
    setPrice(price);
    activeFile.open(filePath, ios::app);
    if (activeFile.is_open())
    {
        // here we move to the end of the file to check is it empty or not, to append or create new file
        activeFile.seekp(0, ios::end);
        if (activeFile.tellp() == 0)
        {
            activeFile << "--------Coffee Database Records--------" << endl;
            activeFile << "                                        " << endl;
        }
        activeFile << getName() << " " << getPrice() << endl;
    }
    else
    {
        // stop the program to handle exception
        throw runtime_error("Failed to open file for writing.");
    }
    activeFile.close();
    cout << "\nNew Coffee has been added" << endl;
    ui.pauseExecution();
}

void Coffee::deleteCoffee()
{
    ifstream inFile(filePath);
    ofstream outFile("Core/Source/Files/coffee_temp.txt");
    string name, nInput , price;
    bool found = false;

    ui.clearScreen();
    ui.displayHeader("Delete Coffee Proccess");
    ui.getStringInput("Enter Coffee name", nInput);

    if (!inFile || !outFile)
    {
        cout << "Failed to open file." << endl;
        return;
    }

    while (inFile >> name >> price)
    {
        if (name == nInput)
        {
            found = true;
            continue;
        }
        outFile << name << " " << price << endl;
    }

    inFile.close();
    outFile.close();

    if (found)
    {
        if (remove(filePath.c_str()) != 0)
        {
            cout << "Failed to delete the original file." << endl;
            return;
        }
        if (rename("Core/Source/Files/coffee_temp.txt", filePath.c_str()) != 0)
        {
            cout << "Failed to rename the temp file." << endl;
            return;
        }
        cout << "Coffee successfully deleted." << endl;
    }
    else
    {
        remove("Core/Source/Files/coffee_temp.txt");
        cout << "Coffee not found or incorrect name." << endl;
    }

    ui.pauseExecution();
}