//
// Created by david on 19-Apr-23.
//

#ifndef A89_SERVICE_H
#define A89_SERVICE_H

#endif //A89_SERVICE_H
#pragma once
#include "Repository.h"
#include "Exceptions.h"
#include "Validator.h"

class ServiceAdmin {
private:
    Repository* repository;
public:
    ServiceAdmin();
    ServiceAdmin(Repository*);
    ~ServiceAdmin();
    void addEvent(std::string&, std::string&, DateTime&, int&, std::string&);
    void deleteEvent(std::string&);
    void updateEvent(std::string&, std::string&, DateTime&, int&, std::string&);
    std::vector<Event>& getAll();
    void loadFromFile(std::string&);
    void writeToFile(std::string&, std::string&, DateTime&, int&, std::string&);
};