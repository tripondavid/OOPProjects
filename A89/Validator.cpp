//
// Created by david on 04-May-23.
//
#include "Validator.h"
#include "Exceptions.h"

bool Validator::leapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

Validator::Validator() {
    std::vector<std::invalid_argument> errors;
    this->errors = errors;
}

Validator::~Validator() {
    this->errors.clear();
}

void Validator::validateTitle(const std::string &title) {
    if(title.size() < 2 || title.size() > 100)
        this->errors.push_back(std::invalid_argument("Invalid title!"));
}

void Validator::validateDescription(const std::string &description) {
    if(description.size() < 2 || description.size() > 100)
        this->errors.push_back(std::invalid_argument("Invalid description!"));
}

void Validator::validateNoPeople(const int no_people) {
    if (no_people < 0)
        this->errors.push_back(std::invalid_argument("Invalid number of people!"));
}

void Validator::validateLink(const std::string &link) {
    if (link.size() < 8)
    {
        this->errors.push_back(std::invalid_argument("Invalid link!"));
    }
    if(link.substr(0, 8) != "https://")
    {
        this->errors.push_back(std::invalid_argument("Invalid link!"));
    }
}

void Validator::validateDateTime(const DateTime &dateTime) {
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool ok;

    if (dateTime.getYear() >= 2000 && dateTime.getYear() <= 2100) {
        if (this->leapYear(dateTime.getYear())) {
            days[2]++;
        }

        if (dateTime.getMonth() >= 1 && dateTime.getMonth() <= 12) {
            if (dateTime.getDay() >= 1 && dateTime.getDay() <= days[dateTime.getMonth()]) {
                if (dateTime.getHour() >= 0 && dateTime.getHour() <= 23 && dateTime.getMinute() >= 0 && dateTime.getMinute() <= 59) {
                    ok = true;
                }
                else {
                    ok = false;
                }
            }
            else {
                ok = false;
            }
        }
        else {
            ok = false;
        }
    }
    else {
        ok = false;
    }

    if (!ok) {
        this->errors.push_back(std::invalid_argument("Invalid date time!"));
    }
}

void Validator::throwErrors() {
    if (this->errors.empty())
        return;
    std::string err;
    for (std::invalid_argument e : this->errors) {
        err += std::string(e.what()) + '\n';
    }
    throw ValidationException(err);
}

void Validator::validateEvent(const Event &event) {
    this->validateTitle(event.getTitle());
    this->validateDescription(event.getDescription());
    this->validateDateTime(event.getDateTime());
    this->validateNoPeople(event.getNoPeople());
    this->validateLink(event.getLink());

    this->throwErrors();
}
