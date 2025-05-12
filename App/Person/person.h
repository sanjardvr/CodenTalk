#include <iostream>
#include <string>
#include <fstream>

#include "../../Core/Source/Core/Core.h"
using namespace std;

class Person
{
private:
    string name, status;
protected:
    ConsoleUIManager ui;
    string filePath;
public:
    Person(){}
    Person(string path): filePath(path){}

    //getters & setters
    void setName(string n){name = n;}
    void setStatus(string s){status = s;}

    string getName(){return name;}
    string getStatus(){return status;}


    void displaySelfInfo()
    {
        ui.clearScreen();
        ui.displayHeader("Personal Information");
        cout << "Name : " << getName() << endl;
        cout << "Status : " << getStatus() << endl;
        ui.pauseExecution();
    }

};