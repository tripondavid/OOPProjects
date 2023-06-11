//
// Created by david on 18-Apr-23.
//
#include "DateTime.h"

DateTime::DateTime() {}
DateTime::~DateTime() {}
DateTime::DateTime(const int &year, const int &month, const int &day, const int &hour, const int &minute) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->hour = hour;
    this->minute = minute;
}

int DateTime::getYear() const {
    return this->year;
}

int DateTime::getMonth() const {
    return this->month;
}

int DateTime::getDay() const {
    return this->day;
}

int DateTime::getHour() const {
    return this->hour;
}

int DateTime::getMinute() const {
    return this->minute;
}

std::string DateTime::toString() {
    std::string date_time = std::to_string(this->year) + "." + std::to_string(this->month) + "." + std::to_string(this->day) + " " +
            std::to_string(this->hour) + ":" + std::to_string(this->minute);
    return date_time;
}