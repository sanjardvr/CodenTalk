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
    void signup(string fileTitle)
    {
        ofstream activeFile;
        string email, password;
        ui.clearScreen();
        ui.displayHeader("SignUp Process");
        ui.getStringInput("Enter your email", email);
        ui.getStringInput("Enter your password", password);

        activeFile.open(filePath, ios::app);
        if (activeFile.is_open())
        {
            // here we move to the end of the file to check is it empty or not, to append or create new file
            activeFile.seekp(0, ios::end);
            if (activeFile.tellp() == 0)
            {
                activeFile << "--------"<<fileTitle<<"--------" << endl;
                activeFile << "                                        " << endl;
            }
            activeFile << email << "\t\t" << password << endl;
            cout << "You have successfully registered!" << endl;
            ui.pauseExecution();
        }
        else
        {
            // stop the program to handle exception
            throw runtime_error("Failed to open file for writing.");
        }
        activeFile.close();
    }

    bool login()
    {
        int attempts = 3;
        while (attempts > 0)
        {
            ifstream activeFile(filePath);
            string email, password, eInput, pInput;

            bool isFound = false;
            ui.clearScreen();
            ui.displayHeader("LogIn Process");

            ui.getStringInput("Enter your email", eInput);
            ui.getStringInput("Enter your password", pInput);

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
                cout << "Login successful. Welcome back, " << eInput << "!" << endl;
                // break;
                return true;
            }
            else
            {
                cout << "Login failed. Email or password is incorrect.Try again" << endl;
                ui.pauseExecution();
                ui.clearScreen();
            }
            attempts--;
        }
        return false;
    }

    void logOut()
    {
        ifstream inFile(filePath);
        ofstream outFile("Core/Source/Files/temp.txt");
        string email, password, eInput, pInput;
        bool found = false;

        ui.clearScreen();
        ui.displayHeader("Account Deletion Process");
        ui.getStringInput("Enter your email", eInput);
        ui.getStringInput("Enter your password", pInput);

        if (!inFile || !outFile)
        {
            cout << "Failed to open file." << endl;
            return;
        }

        string line;
        getline(inFile, line);
        outFile << line << endl;
        getline(inFile, line);
        outFile << line << endl;

        while (inFile >> email >> password)
        {
            if (email == eInput && password == pInput)
            {
                found = true;
                continue;
            }
            outFile << email << "\t\t" << password << endl;
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
            if (rename("Core/Source/Files/temp.txt", filePath.c_str()) != 0)
            {
                cout << "Failed to rename the temp file." << endl;
                return;
            }
            cout << "Account successfully deleted." << endl;
        }
        else
        {
            remove("Core/Source/Files/temp.txt");
            cout << "Account not found or incorrect credentials." << endl;
        }

        ui.pauseExecution();
    }
};