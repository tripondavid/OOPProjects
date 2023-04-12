#pragma once
#include "DateTime.h"
#include "repository.h"
#include <string>

class Service {
private:
	Repository* repo;

public:
	Service();
	Service(Repository*);
	Service(const Service&);
	~Service();
	int addEventService(const std::string title, const std::string description, const DateTime date_time, const int no_people, const std::string link);
	int removeEventService(const std::string title);
	int updateEventService(const std::string title, const std::string description, const DateTime date_time, const int no_people, const std::string link);
	Event* getAllEventsService();
	int getSizeService();
	void addRandomEvents();
};