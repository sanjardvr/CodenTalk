#include <iostream>
#include <fstream>
#include <string>

#include "../Source/Core/Core.h"
using namespace std;

// class for all Registration processes
class Registration
{
    // using composition to generate ui
    ConsoleUIManager ui;
    string filePath;

public:
    Registration() {}
    Registration(string filePath)
    {
        this->filePath = filePath;
    }

    // sign up methods should first check for an existing file (meaning there were record already), or create new one and then work with it further
    void signup()
    {
        ofstream activeFile;
        string email, password;
        ui.clearScreen();
        ui.displayHeader("SignUp Process");
        ui.getStringInput("Enter your email 📩", email);
        ui.getStringInput("Enter your password 🔑", password);

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
            activeFile << email << "\t\t" << password << endl;
            cout << "✅ You have successfully registered!" << endl;
        }
        else
        {
            // stop the program to handle exception
            throw runtime_error("Failed to open file for writing.");
        }
        activeFile.close();
    }

    void login()
    {   
        int attempts = 3;
        while (attempts > 0)
        {
            ifstream activeFile(filePath);
            string email, password, eInput, pInput;

            bool isFound = false;
            ui.clearScreen();
            ui.displayHeader("LogIn Process");

            ui.getStringInput("Enter your email 📩", eInput);
            ui.getStringInput("Enter your password 🔑", pInput);

            if (!activeFile.is_open())
            {
                throw runtime_error("Failed to open file for writing.");
            }
            string line;
            getline(activeFile, line); // this is how we skip header in the txt file
            getline(activeFile, line);
            while (activeFile >> email >> password)
            {
                if (email == eInput && password == pInput)
                {
                    isFound = true;
                    break;
                }
            }

            activeFile.close();

            if (isFound)
            {
                cout << "✅ Login successful. Welcome back, " << eInput << "!" << endl;
                break;
            }
            else
            {
                cout << "❌ Login failed. Email or password is incorrect.Try again" << endl;
                ui.pauseExecution();
                ui.clearScreen();
            }
            attempts--;
        }
    }
};