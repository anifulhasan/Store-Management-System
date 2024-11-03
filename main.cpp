#include <iostream>
#include "InventoryManager.h"
#include "Tobacco.h"
#include "LotteryTickets.h"
using namespace std;


void displayMenu() {
    cout << "\033[31m";
    cout << "1. Search Inventory\n";
    cout << "2. Sell Products\n";
    cout << "3. Add New Inventory\n";
    cout << "4. Remove Inventory\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cout << "\033[0m";
}

int main() {
    InventoryManager manager;
    int choice;
    string id, name, expDate;
    float price, tax1, tax2;

    //  data
    manager.addProduct(new Tobacco("1", "Mild Cigars", "2024-12", 5.0, 2.0));
    manager.addProduct(new LotteryTickets("2", "MegaMillions", "N/A", 2.0, 0.5, 3.0));

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product name to search: ";
            cin >> name;
            manager.searchProduct(name);
            break;
        case 2:
            cout << "Enter product ID to sell: ";
            cin >> id;
            manager.sellProduct(id);
            break;
        case 3:
            cout << "Add Product (Tobacco/Lottery)\n";
            cin >> name;  // types of ch
            cout << "Enter ID, Name, ExpDate, Price, Tax1, [Tax2]: ";
            cin >> id >> name >> expDate >> price >> tax1;
            if (name == "Tobacco") {
                manager.addProduct(new Tobacco(id, name, expDate, price, tax1));
            }
            else {
                cin >> tax2;
                manager.addProduct(new LotteryTickets(id, name, expDate, price, tax1, tax2));
            }
            break;
        case 4:
            cout << "Enter product ID to remove: ";
            cin >> id;
            manager.sellProduct(id);  // removal selling
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
