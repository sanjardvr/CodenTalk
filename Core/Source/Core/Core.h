#include <iostream>
#include <string>
using namespace std;

#ifndef CORE
#define CORE

/*
? The Core file is used to define the main application settings, which are not directly related to the project logic itself. Only common functions/classes/definitions that can be used throughout the application.
*/

class Module
{
public:
    // two main function that will be overriden later
    virtual void run() = 0;
    virtual string getName() const = 0;

    // to avoid memory leaks
    virtual ~Module() = default;
};

class ConsoleUIManager
{
    const int CONSOLE_WIDTH = 50;

public:
    void displayHeader(const string &title)
    {
        // using constructor of string library
        string separator(CONSOLE_WIDTH, '-');
        cout << separator << endl;
        cout << "-----" << title << "-----" << endl;
        cout << separator << endl;

        /*
            -----------------------
            ------TITLE------
            -----------------------
        */
    }

    void displayMenu(const string options[], int optionCount)
    {
        for (int i = 0; i < optionCount; i++)
        {
            cout << options[i] << " : " << (i + 1) << endl;
        }
        cout << "Exit Program : 0" << endl;
        /*
        Option1 : 1
        Option2 : 2
        Option3 : 3
        Option4 : 4
        Exit Program : 0
    */
    }

    template <typename T>
    T getInput(const string &prompt)
    {
        T input;
        while (true)
        {
            cout << prompt << " : ";
            cin >> input;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please try again.\n";
            }
            else
            {
                cin.ignore(10000, '\n');
                return input;
            }
        }
    }

    void getStringInput(const string &prompt, string &buffer)
    {
        cout << prompt << " : ";
        cin.ignore();
        getline(cin, buffer);
    }

    void displaySuccess(const string &message)
    {
        cout << "\nSUCCESS: " << message << endl;
        pauseExecution();
        clearScreen();
    }

    void displayError(const string &message)
    {
        cout << "\nERROR: " << message << endl;
        pauseExecution();
        clearScreen();
    }

    void pauseExecution()
    {
        cout << "\nPress Enter to continue...";
        cin.ignore();
    }

    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }
};

class CodenTalk
{
    ConsoleUIManager ui;
    static const int MAX_MODULES = 5;
    Module *modules[MAX_MODULES];
    int moduleCount;

public:
    CodenTalk() : moduleCount(0) {}

    ~CodenTalk()
    {
        for (int i = 0; i < moduleCount; i++)
        {
            delete modules[i];
        }
    }

    void registerModule(Module *module)
    {
        if (moduleCount < MAX_MODULES)
        {
            modules[moduleCount++] = module;
        }
    }

    void run()
    {
        bool running = true;
        while (running)
        {
            ui.clearScreen();
            ui.displayHeader("Welcome to Coffee Shop");
            string moduleOptions[MAX_MODULES];

            for (int i = 0; i < moduleCount; i++)
            {
                moduleOptions[i] = modules[i]->getName();
            }
            ui.displayMenu(moduleOptions, moduleCount);
            int choice = ui.getInput<int>("Enter choice");

            if (choice == 0)
            {
                running = false;
            }
            else if (choice > 0 && choice <= moduleCount)
            {
                modules[choice - 1]->run();
            }
        }
    }
};

#endif // CORE