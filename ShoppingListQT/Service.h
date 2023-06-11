//
// Created by david on 23-May-23.
//

#ifndef PROBATESTLAB13TURA2_SERVICE_H
#define PROBATESTLAB13TURA2_SERVICE_H

#endif //PROBATESTLAB13TURA2_SERVICE_H
#pragma once
#include "Repository.h"

class Service {
private:
    Repository* repo;
public:
    Service();
    ~Service();
    Service(Repository* repo);
    void add(std::string& category, std::string& name, int& quantity);
    void remove(std::string& category, std::string& name);
    std::vector<Item>& getAll();
};