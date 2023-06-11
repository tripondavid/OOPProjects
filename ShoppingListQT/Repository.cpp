//
// Created by david on 23-May-23.
//
#include "Repository.h"

Repository::Repository() {}

Repository::~Repository() {}

Repository::Repository(std::vector<Item> &repoVector) {
    this->repoVector = repoVector;
    this->populate();
}

std::vector<Item>& Repository::getAll() {
    return this->repoVector;
}

void Repository::add(Item& new_item) {
    this->repoVector.push_back(new_item);
}

void Repository::remove(long long &index) {
    this->repoVector.erase(this->repoVector.begin() + index);
}

long long Repository::findItem(std::string &category, std::string &name) {
    for (auto i = this->repoVector.begin(); i < this->repoVector.end(); ++i)
    {
        if (i->getCategory() == category && i->getName() == name)
        {
            return i - this->repoVector.begin();
        }
    }
    return -1;
}

void Repository::populate() {
    std::string category, name;
    category = "Drinks";
    name = "Orange juice";
    int quantity = 2;
    Item new_item1 = Item(category, name, quantity);
    name = "Water";
    quantity = 6;
    Item new_item2 = Item(category, name, quantity);
    category = "Dairy";
    name = "Yogurt";
    quantity = 4;
    Item new_item3 = Item(category, name, quantity);
    name = "Milk";
    quantity = 1;
    Item new_item4 = Item(category, name, quantity);
    category = "Sweets";
    name = "Chocolate";
    quantity = 3;
    Item new_item5 = Item(category, name, quantity);
    this->add(new_item1);
    this->add(new_item2);
    this->add(new_item3);
    this->add(new_item4);
    this->add(new_item5);
}