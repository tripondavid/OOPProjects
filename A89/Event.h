//
// Created by david on 18-Apr-23.
//

#ifndef A89_EVENT_H
#define A89_EVENT_H

#endif //A89_EVENT_H
#pragma once
#include <string>
#include "DateTime.h"
#include <fstream>
#include <cstring>

class Event {
private:
    std::string title;
    std::string description;
    DateTime date_time;
    int no_people;
    std::string link;
    friend std::ifstream& operator>>(std::ifstream&, Event&);
    friend std::ofstream& operator<<(std::ofstream&, Event&);
public:
    Event();
    Event(const std::string&, const std::string&, const DateTime&, const int&, const std::string&);
    ~Event();
    std::string getTitle() const;
    std::string getDescription() const;
    DateTime getDateTime() const;
    int getNoPeople() const;
    std::string getLink() const;
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    std::string toString() const;
};

std::ifstream& operator>>(std::ifstream&, Event&);

std::ofstream& operator<<(std::ofstream&, Event&);