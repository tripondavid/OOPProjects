#include "Event.h"

using namespace std;

Event::Event()
{
	title = "";
	description = "";
	date_time = DateTime();
	no_people = 0;
	link = "";
}

Event::Event(const std::string& title, const std::string& description, const DateTime& date_time, const int& no_people, const std::string& link):
	title{ title }, description{ description }, date_time{ date_time }, no_people{ no_people }, link{ link }
{
}

Event::~Event()
{
}

string Event::getTitle() const
{
	return this->title;
}

string Event::getDescription() const
{
	return this->description;
}

DateTime Event::getDateTime() const
{
	return this->date_time;
}

int Event::getNumberOfPeople() const
{
	return this->no_people;
}

string Event::getLink() const
{
	return this->link;
}

string Event::toString() const
{
	auto year = to_string(this->date_time.getYear());
	auto month = to_string(this->date_time.getMonth());
	auto day = to_string(this->date_time.getDay());
	auto hour = to_string(this->date_time.getHour());
	auto minute = to_string(this->date_time.getMinute());
	auto no_people = to_string(this->no_people);

	return "Title:" + this->title + "\nDescription: " + this->description + "\nDate and time(year, month, day, hour, minute): " + year + "." + month + "." + day + " " + hour + ":" + minute + "\nNumber of people : " + no_people + "\nLink : " + link +"\n\n";
}

int Event::getYear() const
{
	return this->date_time.getYear();
}

int Event::getMonth() const
{
	return this->date_time.getMonth();
}

int Event::getDay() const
{
	return this->date_time.getDay();
}

int Event::getHour() const
{
	return this->date_time.getHour();
}

int Event::getMinute() const
{
	return this->date_time.getMinute();
}