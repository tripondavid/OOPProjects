#pragma once
#include "repository.h"
#include "Event.h"

class ServiceUser {
private:
	Repository* wholeRepo;
	Repository* userRepo;

public:
	ServiceUser();
	ServiceUser(Repository* wholeRepo, Repository* userRepo);
	~ServiceUser();

	void seeEventsForMonthService(Event*, const int, const int, int&);
	void increaseNumberPeopleService(Event&);
	void decreaseNumberPeopleService(Event&);
	void addEventService(Event&);
	void deleteEventService(const std::string);
	Event* seeEventsUserParticipatesService(int&);

};