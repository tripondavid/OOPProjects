//
// Created by david on 18-Apr-23.
//

#ifndef A89_DATETIME_H
#define A89_DATETIME_H

#endif //A89_DATETIME_H
#pragma once
#include <string>

class DateTime {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
public:
    DateTime();
    DateTime(const int&, const int&, const int&, const int&, const int&);
    ~DateTime();
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;
    std::string toString();
};