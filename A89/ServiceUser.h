//
// Created by david on 20-Apr-23.
//

#ifndef A89_SERVICEUSER_H
#define A89_SERVICEUSER_H

#endif //A6PROBA2_SERVICEUSER_H
#pragma once
#include "Repository.h"
#include "FileSaver.h"


class ServiceUser {
protected:
    Repository* userRepository;
    Repository* wholeRepository;
    FileSaver* userFileRepo;

public:
    ServiceUser();
    ServiceUser(Repository*, Repository*, FileSaver*);
    ~ServiceUser();
    void addEvent(Event&);
    void deleteEvent(std::string&);
    void increaseNumberPerson(Event&);
    void decreaseNumberPerson(Event&);
    std::vector<Event> seeEventsForMonth(const int&, const int&);
    std::vector<Event>& seeEventsUser();
};