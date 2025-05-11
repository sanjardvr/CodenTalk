// #include <iostream>
// #include <fstream>
// #include <string>

// #include "../../Core/Source/Core/Core.h"
// using namespace std;

// class Coffee {
// 	ConsoleUIManager ui;
// public:
//     void clientMenu(const char* username);
//     void listCoffee();
//     void orderCoffee(const char* username);
//     void showPersonalInfo(const char* username);
// 		void adminMenu(const char* username);

// };

// void Coffee::clientMenu(const char* username) {
//     int choice;

// 		ui.clearScreen();
//  		ui.displayHeader("MENU");

//     do {
//         cout << "\n--- CLIENT MENU (" << username << ") ---\n";
//         cout << "1. See Coffee Menu\n";
//         cout << "2. Order Coffee\n";
//         cout << "3. Logout\n";
//         cout << "Enter choice: ";
//         cin >> choice;
//         cin.ignore();

//         switch (choice) {
//             case 1:
//                 showCoffeeMenu(); 
//                 break;
//             case 2:
//                 orderCoffee(username); 
//                 break;
//             case 3:
//                 cout << "Logging out...\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Try again.\n";
//         }
//     } while (choice != 4);
// }

// void Coffee::listCoffee() {
//     cout << "\n--- Coffee Menu ---\n";
//     cout << "1. Espresso - $2.50\n";
//     cout << "2. Cappuccino - $3.00\n";
//     cout << "3. Latte - $3.50\n";
//     cout << "4. Mocha - $4.00\n";
// }

// void Coffee::orderCoffee(const char* username) {
//     int coffeeChoice;
//     listCoffee();
//     cout << "Enter the number of the coffee you want to order: ";
//     cin >> coffeeChoice;

//     string coffeeName;
//     switch (coffeeChoice) {
//         case 1: coffeeName = "Espresso"; break;
//         case 2: coffeeName = "Cappuccino"; break;
//         case 3: coffeeName = "Latte"; break;
//         case 4: coffeeName = "Mocha"; break;
//         default: 
//             cout << "Invalid choice.\n";
//             return;
//     }

//     cout << "Order placed: " << coffeeName << " for " << username << ".\n";
// }


#ifndef COFFEE_H
#define COFFEE_H

#include <string>
#include "../../Core/Source/Core/Core.h" // for ConsoleUIManager

void showCoffeeMenuUI(ConsoleUIManager& ui);

// more cofe related funcs here e.g:    orderCoffee(const std::string& username);

#endif