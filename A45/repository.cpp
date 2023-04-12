#include "repository.h"
#include "dynamicVector.h"
#include "Event.h"

Repository::Repository()
{
}

Repository::Repository(DynamicVector<Event>* repoArray)
{
	this->repoArray = repoArray;
}

Repository::~Repository()
{
}

Event* Repository::getAllRepo()
{
	return (Event*)this->repoArray->getAll();
}

int Repository::getSizeRepo()
{
	return (int)this->repoArray->getSize();
}

int Repository::getCapacityRepo()
{
	return (int)this->repoArray->getCapacity();
}

int Repository::findIndexByTitle(const std::string title)
{
	Event* list_of_events = this->repoArray->getAll();
	for (int i = 0; i < this->repoArray->getSize(); i++)
	{
		Event& curr_event = list_of_events[i];
		std::string compareTitle = curr_event.getTitle();
		if (title == compareTitle)
		{
			return i;
		}
	}
	return -1;
}

void Repository::addRepo(const Event& event)
{
	this->repoArray->addItem(event);
}

void Repository::deleteRepo(const int index)
{
	this->repoArray->removeItem(index);
}

void Repository::updateRepo(const Event& event, const int index)
{
	this->repoArray->updateItem(event, index);
}
