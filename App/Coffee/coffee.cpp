#include "coffee.h"
#include <iostream>
#include <fstream>

using namespace std;

void showCoffeeMenuUI(ConsoleUIManager& ui) {
    ifstream file("Core/Source/Files/coffee_menu.txt");
    string line;
    int index = 1;

    ui.clearScreen();
    ui.displayHeader("Coffee Menu");

    if (!file.is_open()) {
        ui.displayError("Could not open coffee menu file.");
        ui.pauseExecution();
        return;
    }

    while (getline(file, line)) {
        cout << index << ". " << line << endl;
        index++;
    }

    file.close();
    ui.pauseExecution();
}
