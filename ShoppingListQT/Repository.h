//
// Created by david on 23-May-23.
//

#ifndef PROBATESTLAB13TURA2_REPOSITORY_H
#define PROBATESTLAB13TURA2_REPOSITORY_H

#endif //PROBATESTLAB13TURA2_REPOSITORY_H
#pragma once
#include <vector>
#include <iterator>
#include "Item.h"

class Repository {
private:
    std::vector<Item> repoVector;
public:
    Repository();
    ~Repository();
    Repository(std::vector<Item>& repoVector);
    std::vector<Item>& getAll();
    void add(Item& new_item);
    void remove(long long& index);
    long long findItem(std::string& category, std::string& name);
    void populate();
};