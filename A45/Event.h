#pragma once
#include <string>
#include "DateTime.h"

class Event
{
private:
	std::string title;
	std::string description;
	DateTime date_time;
	int no_people;
	std::string link;

public:
	Event();
	Event(const std::string&, const std::string&, const DateTime&, const int&, const std::string&);
	Event(const Event&);
	~Event();
	std::string getTitle() const;
	std::string getDescription() const;
	DateTime getDateTime() const;
	int getNumberOfPeople() const;
	std::string getLink() const;
	std::string toString() const;
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
};