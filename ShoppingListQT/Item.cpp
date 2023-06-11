//
// Created by david on 23-May-23.
//
#include "Item.h"

Item::Item() {}

Item::~Item() {}

Item::Item(std::string &category, std::string &name, int &quantity) {
    this->category = category;
    this->name = name;
    this->quantity = quantity;
}

std::string Item::getCategory() {
    return this->category;
}

std::string Item::getName() {
    return this->name;
}

int Item::getQuantity() {
    return this->quantity;
}

std::string Item::toString() {
    return "Category: " + this->category + "\n" +
    "Name: " + this->name + "\n" +
    "Quantity: " + std::to_string(this->quantity) + "\n";
}