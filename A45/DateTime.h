#pragma once

class DateTime 
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;

public:
	DateTime();
	DateTime(int , int , int , int , int );
	
	int getYear() const;
	int getMonth() const;
	int getDay() const;
	int getHour() const;
	int getMinute() const;
};