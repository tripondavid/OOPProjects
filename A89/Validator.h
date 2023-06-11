//
// Created by david on 04-May-23.
//

#ifndef A89_VALIDATOR_H
#define A89_VALIDATOR_H

#endif //A89_VALIDATOR_H
#pragma once
#include "Event.h"
#include <vector>

class Validator {
private:
    std::vector<std::invalid_argument> errors;
    bool leapYear(int year);
    void validateTitle(const std::string& title);
    void validateDescription(const std::string& description);
    void validateDateTime(const DateTime& date_time);
    void validateNoPeople(const int no_people);
    void validateLink(const std::string& link);

    void throwErrors();
public:
    Validator();
    ~Validator();

    void validateEvent(const Event& event);
};