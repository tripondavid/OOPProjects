#include "service_user.h"
#include <iostream>
#include <string>

ServiceUser::ServiceUser()
{
}

ServiceUser::ServiceUser(Repository* wholeRepo, Repository* userRepo)
{
	this->wholeRepo = wholeRepo;
	this->userRepo = userRepo;
}

void ServiceUser::seeEventsForMonthService(Event list_corresponding_events[], const int year, const int month, int& sizeUi)
{
	Event* list_of_events = this->wholeRepo->getAllRepo();
	int size_corresponding = 0;
	int size = this->wholeRepo->getSizeRepo();
	for (int i = 0; i < size; i++)
	{
		Event& curr_event = list_of_events[i];
		if (curr_event.getMonth() == month && curr_event.getYear() == year)
		{
			list_corresponding_events[size_corresponding] = curr_event;
			size_corresponding++;
		}
	}
	Event aux;
	for (int i = 0; i < size_corresponding - 1; i++)
		for (int j = i + 1; j < size_corresponding; j++)
		{
			if (list_corresponding_events[i].getMonth() > list_corresponding_events[j].getMonth())
			{
				aux = list_corresponding_events[i];
				list_corresponding_events[i] = list_corresponding_events[j];
				list_corresponding_events[j] = aux;
			}
		}
	sizeUi = size_corresponding;
	//return list_corresponding_events;
}

void ServiceUser::addEventService(Event& event)
{
	this->userRepo->addRepo(event);
	increaseNumberPeopleService(event);
}

void ServiceUser::increaseNumberPeopleService(Event& event)
{
	std::string title = event.getTitle();
	std::string description = event.getDescription();
	DateTime date_time = event.getDateTime();
	int no_people = event.getNumberOfPeople();
	std::string link = event.getLink();
	Event new_event = Event(title, description, date_time, no_people + 1, link);
	int userIndex = this->userRepo->findIndexByTitle(title);
	this->userRepo->updateRepo(new_event, userIndex);
	int wholeIndex = this->wholeRepo->findIndexByTitle(title);
	this->wholeRepo->updateRepo(new_event, wholeIndex);
}

void ServiceUser::decreaseNumberPeopleService(Event& event)
{
	std::string title = event.getTitle();
	std::string description = event.getDescription();
	DateTime date_time = event.getDateTime();
	int no_people = event.getNumberOfPeople();
	std::string link = event.getLink();
	Event new_event = Event(title, description, date_time, no_people - 1, link);
	int userIndex = this->userRepo->findIndexByTitle(title);
	this->userRepo->updateRepo(new_event, userIndex);
	int wholeIndex = this->wholeRepo->findIndexByTitle(title);
	this->wholeRepo->updateRepo(new_event, wholeIndex);
}

void ServiceUser::deleteEventService(const std::string title)
{
	int index = this->userRepo->findIndexByTitle(title);
	if (index != -1)
	{
		Event& this_event = this->userRepo->getAllRepo()[index];
		this->decreaseNumberPeopleService(this_event);
		this->userRepo->deleteRepo(index);
	}
}

Event* ServiceUser::seeEventsUserParticipatesService(int &userSize)
{
	userSize = this->userRepo->getSizeRepo();
	return this->userRepo->getAllRepo();
}