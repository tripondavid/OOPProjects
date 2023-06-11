//
// Created by david on 18-Apr-23.
//

#ifndef A89_REPOSITORY_H
#define A89_REPOSITORY_H

#endif //A89_REPOSITORY_H
#pragma once
#include <vector>
#include <iterator>
#include "Event.h"

class Repository {
protected:
    std::vector<Event> repoVector;
public:
    Repository();
    Repository(std::vector<Event>&);
    ~Repository();
    std::vector<Event>& getAllRepo();
    unsigned long long getSizeRepo();
    unsigned long long getCapacityRepo();
    virtual void addRepo(const Event&);
    virtual void deleteRepo(const long long);
    virtual void updateRepo(const Event&, const long long);
    long long searchEvent(std::string&);
};