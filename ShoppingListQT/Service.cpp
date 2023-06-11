//
// Created by david on 23-May-23.
//
#include "Service.h"

Service::Service() {}

Service::~Service() {}

Service::Service(Repository *repo) {
    this->repo = repo;
}

void Service::add(std::string &category, std::string &name, int &quantity) {
    if (this->repo->findItem(category, name) == -1) {
        Item new_item = Item(category, name, quantity);
        this->repo->add(new_item);
    }
}

void Service::remove(std::string &category, std::string &name) {
    long long index = this->repo->findItem(category, name);
    if(index != -1)
    {
        this->repo->remove(index);
    }
}

std::vector<Item>& Service::getAll() {
    return this->repo->getAll();
}