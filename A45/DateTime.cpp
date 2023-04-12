#include "DateTime.h"

DateTime::DateTime() :year{ 2023 }, month{ 1 }, day{ 1 }, hour{ 0 }, minute{ 01 }
{

}

DateTime::DateTime(int year, int month, int day, int hour, int minute)
{
	this->year = year;
	this->month = month;
	this->day = day;
	this->hour = hour;
	this->minute = minute;
}

int DateTime::getYear() const
{
	return this->year;
}

int DateTime::getMonth() const
{
	return this->month;
}

int DateTime::getDay() const
{
	return this->day;
}

int DateTime::getHour() const
{
	return this->hour;
}

int DateTime::getMinute() const
{
	return minute;
}