#pragma once
#ifndef TOBACCO_H
#define TOBACCO_H

#include "Product.h"

class Tobacco : public Product {
public:
    float SpecialTax;

    Tobacco(string id, string name, string expDate, float price, float specialTax)
        : Product(id, "Tobacco", name, expDate, price), SpecialTax(specialTax) {}

    float computePrice() const override {
        return Price + SpecialTax;
    }
};

#endif 
