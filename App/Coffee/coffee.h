#include <iostream>
#include <fstream>
#include <string>

#include "../../Core/Source/Core/Core.h"

class Coffee {
	ConsoleUIManager ui;
public:
    void clientMenu(const char* username);
    void showCoffeeMenu();
    void orderCoffee(const char* username);
    void showPersonalInfo(const char* username);
};

void Coffee::clientMenu(const char* username) {
    int choice;

		ui.clearScreen();
 		ui.displayHeader("MENU");

    do {
        std::cout << "\n--- CLIENT MENU (" << username << ") ---\n";
        std::cout << "1. See Coffee Menu\n";
        std::cout << "2. Order Coffee\n";
        std::cout << "3. See Personal Info\n";
        std::cout << "4. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                showCoffeeMenu(); 
                break;
            case 2:
                orderCoffee(username); 
                break;
            case 3:
                showPersonalInfo(username);
                break;
            case 4:
                std::cout << "Logging out...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

void Coffee::showCoffeeMenu() {
    std::cout << "\n--- Coffee Menu ---\n";
    std::cout << "1. Espresso - $2.50\n";
    std::cout << "2. Cappuccino - $3.00\n";
    std::cout << "3. Latte - $3.50\n";
    std::cout << "4. Mocha - $4.00\n";
}

void Coffee::orderCoffee(const char* username) {
    int coffeeChoice;
    showCoffeeMenu();
    std::cout << "Enter the number of the coffee you want to order: ";
    std::cin >> coffeeChoice;

    std::string coffeeName;
    switch (coffeeChoice) {
        case 1: coffeeName = "Espresso"; break;
        case 2: coffeeName = "Cappuccino"; break;
        case 3: coffeeName = "Latte"; break;
        case 4: coffeeName = "Mocha"; break;
        default: 
            std::cout << "Invalid choice.\n";
            return;
    }

    std::cout << "Order placed: " << coffeeName << " for " << username << ".\n";
}

void Coffee::showPersonalInfo(const char* username) {
    std::ifstream file("clients.txt");
    std::string line;

    while (getline(file, line)) {
        if (line.find(username) != std::string::npos) {
            std::cout << "Personal Info: " << line << "\n";
            return;
        }
    }

    std::cout << "No personal info found.\n";
}
