#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
public:
    string ID;
    string Category;
    string Name;
    string ExpDate;  // string for this example
    float Price;

    Product(string id, string category, string name, string expDate, float price)
        : ID(id), Category(category), Name(name), ExpDate(expDate), Price(price) {}

    virtual float computePrice() const {
        return Price;  // Base price 
    }

    virtual ~Product() {}
};

#endif 
