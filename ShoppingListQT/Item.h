//
// Created by david on 23-May-23.
//

#ifndef PROBATESTLAB13TURA2_ITEM_H
#define PROBATESTLAB13TURA2_ITEM_H

#endif //PROBATESTLAB13TURA2_ITEM_H
#pragma once
#include <string>

class Item {
private:
    std::string category;
    std::string name;
    int quantity;

public:
    Item();
    ~Item();
    Item(std::string& category, std::string& name, int& quantity);
    std::string getCategory();
    std::string getName();
    int getQuantity();
    std::string toString();
};