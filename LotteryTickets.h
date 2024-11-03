#pragma once
#ifndef LOTTERYTICKETS_H
#define LOTTERYTICKETS_H

#include "Product.h"

class LotteryTickets : public Product {
public:
    float CityTax;
    float CountyTax;

    LotteryTickets(string id, string name, string expDate, float price, float cityTax, float countyTax)
        : Product(id, "LotteryTickets", name, expDate, price), CityTax(cityTax), CountyTax(countyTax) {}

    float computePrice() const override {
        return Price + CityTax + CountyTax;
    }
};

#endif 
