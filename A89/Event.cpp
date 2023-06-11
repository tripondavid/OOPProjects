//
// Created by david on 18-Apr-23.
//
#include "Event.h"
#include <iostream>
Event::Event() {}
Event::~Event() {}
Event::Event(const std::string &title, const std::string &description, const DateTime& date_time, const int& no_people, const std::string& link) {
    this->title = title;
    this->description = description;
    this->date_time = date_time;
    this->no_people = no_people;
    this->link = link;
}

std::string Event::getTitle() const {
    return this->title;
}

std::string Event::getDescription() const {
    return this->description;
}

DateTime Event::getDateTime() const {
    return this->date_time;
}

int Event::getNoPeople() const {
    return this->no_people;
}

std::string Event::getLink() const {
    return this->link;
}

int Event::getYear() const {
    return this->date_time.getYear();
}

int Event::getMonth() const {
    return this->date_time.getMonth();
}

int Event::getDay() const {
    return this->date_time.getDay();
}

int Event::getHour() const {
    return this->date_time.getHour();
}

int Event::getMinute() const {
    return this->date_time.getMinute();
}

std::string Event::toString() const {
    auto year = std::to_string(this->date_time.getYear());
    auto month = std::to_string(this->date_time.getMonth());
    auto day = std::to_string(this->date_time.getDay());
    auto hour = std::to_string(this->date_time.getHour());
    auto minute = std::to_string(this->date_time.getMinute());
    auto num_people = std::to_string(this->no_people);

    return "Title:" + this->title + "\nDescription: " + this->description + "\nDate and time(year, month, day, hour, minute): " + year + "." + month + "." + day + " " + hour + ":" + minute + "\nNumber of people : " + num_people + "\nLink : " + link +"\n\n";
}

std::ifstream& operator>>(std::ifstream &fin, Event &event) {
    char str[1001], s[1001];
    fin.getline(str, 1000);

    char data[5][1001];
    int datanum = 0;
    char* p = std::strtok(str, "|");
    while (p != NULL)
    {
        std::strcpy(data[datanum], p);
        datanum++;
        p = std::strtok(NULL, "|");
    }

    char title[1001], description[1001], link[1001];
    std::strcpy(title, data[0]);
    std::strcpy(description, data[1]);
    std::strcpy(link, data[4]);
    int no_people = std::stoi(data[3]);

    p = std::strtok(data[2], " ");
    char date[1001] = "\0", time[1001] = "\0";

    while (p != NULL)
    {
        std::strcpy(s, p);
        if (std::strlen(date) == 0)
        {
            std::strcpy(date, s);
        }
        else
        {
            strcpy(time, s);
        }
        p = std::strtok(NULL, " ");
    }
    p = std::strtok(date, ".");
    int year = std::stoi(p);
    p = std::strtok(NULL, ".");
    int month = std::stoi(p);
    p = std::strtok(NULL, ".");
    int day = std::stoi(p);
    p = std::strtok(time, ":");
    int hour = std::stoi(p);
    p = std::strtok(NULL, ":");
    int miunte = std::stoi(p);
    DateTime date_time = DateTime(year, month, day, hour, miunte);
    event = Event(title, description, date_time, no_people, link);
    return fin;
}

std::ofstream& operator<<(std::ofstream &fout, Event &event) {
    fout << event.getTitle() <<"|" << event.getDescription() << "|" << event.date_time.getYear() <<
    "." << event.date_time.getMonth() << "." << event.date_time.getDay() << " " << event.date_time.getHour()
    << ":" << event.date_time.getMinute() << "|" << event.getNoPeople() << "|" << event.getLink() << "\n";
    return fout;
}
