#pragma once
#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <vector>
#include <iostream>
#include <algorithm>
#include "Product.h"
#include "Tobacco.h"
#include "LotteryTickets.h"
using namespace std;

class InventoryManager {
private:
    vector<Product*> products;

public:
    ~InventoryManager() {
        for (auto p : products) {
            delete p;
        }
        products.clear();
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void sellProduct(const string& id) {
        auto it = find_if(products.begin(), products.end(),
            [&id](const Product* p) { return p->ID == id; });
        if (it == products.end()) {
            cout << "Product not found.\n";
        }
        else {
            cout << "Selling Product: " << (*it)->Name << " - Price: $" << (*it)->computePrice() << endl;
            delete* it;
            products.erase(it);
        }
    }

    void searchProduct(const string& name) {
        auto it = find_if(products.begin(), products.end(),
            [&name](const Product* p) { return p->Name == name; });
        if (it != products.end()) {
            cout << "Product Found: " << (*it)->Name << " - Price: $" << (*it)->computePrice() << endl;
        }
        else {
            cout << "Product not found.\n";
        }
    }
};

#endif 
