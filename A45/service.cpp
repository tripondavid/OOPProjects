#include "service.h"
#include "Event.h"

Service::Service(Repository* repo)
{
	this->repo = repo;
}

int Service::addEventService(const std::string title, const std::string description, const DateTime date_time, const int no_people, const std::string link)
{
	Event new_event = Event(title, description, date_time, no_people, link);
	Event* list_of_events = this->repo->getAllRepo();
	int size_of_list = this->repo->getSizeRepo();
	if (size_of_list == 0)
	{
		this->repo->addRepo(new_event);
	}
	else
	{
		for (int i = 0; i < size_of_list; i++)
		{
			if (list_of_events[i].getTitle() == title)
			{
				return 0;
			}
		}
		this->repo->addRepo(new_event);
		return 1;
	}
	return 0;
}

int Service::removeEventService(const std::string title)
{
	int index = this->repo->findIndexByTitle(title);
	
	if (index != -1)
	{
		this->repo->deleteRepo(index);
		return 1;
	}
	return 0;
}

int Service::updateEventService(const std::string title, const std::string description, const DateTime date_time, const int no_people, const std::string link)
{
	int index = this->repo->findIndexByTitle(title);

	if (index != -1)
	{
		Event new_event = Event(title, description, date_time, no_people, link);
		this->repo->updateRepo(new_event, index);
		return 1;
	}
	return 0;
}

Event* Service::getAllEventsService()
{
	return this->repo->getAllRepo();
}

int Service::getSizeService()
{
	return this->repo->getSizeRepo();
}

void Service::addRandomEvents()
{
	DateTime new_dateTime = DateTime(2022, 12, 24, 12, 30);
	Event new_event = Event("Targ de craciun", "Globuri, vin, pom de Craciun", new_dateTime, 500, "https://cluj.com/targul-de-craciun-cluj/");
	this->repo->addRepo(new_event);
	DateTime new_dateTime2 = DateTime(2023, 1, 25, 12, 45);
	Event new_event2 = Event("Targ de vechituri", "Vechituri antice", new_dateTime2, 1000, "https://magazinuldeantichitati.ro/lista-cu-targuri-de-vechituri-din-romania/");
	this->repo->addRepo(new_event2);
}