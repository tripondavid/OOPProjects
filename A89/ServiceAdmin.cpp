//
// Created by david on 19-Apr-23.
//
#include "ServiceAdmin.h"

ServiceAdmin::ServiceAdmin() {}
ServiceAdmin::~ServiceAdmin() {}

ServiceAdmin::ServiceAdmin(Repository* repository) {
    this->repository = repository;
}

void ServiceAdmin::addEvent(std::string &title, std::string &description, DateTime &date_time, int &no_people, std::string &link) {
    Event new_event = Event(title, description, date_time, no_people, link);
    Validator validator;
    validator.validateEvent(new_event);
    long long index = this->repository->searchEvent(title);
    if (index != -1)
    {
        throw RepositoryException("Event already exists!");
    }
    this->repository->addRepo(new_event);
}

void ServiceAdmin::deleteEvent(std::string &title) {
    long long index = this->repository->searchEvent(title);
    if (index == -1)
    {
        throw RepositoryException("No event with the given title exists!");
    }
    this->repository->deleteRepo(index);
}

void ServiceAdmin::updateEvent(std::string &title, std::string &description, DateTime &date_time, int &no_people, std::string &link) {
    long long index = this->repository->searchEvent(title);
    if (index == -1)
    {
        throw RepositoryException("No event with the given title exists!");
    }
    Event new_event = Event(title, description, date_time, no_people, link);
    Validator validator;
    validator.validateEvent(new_event);
    this->repository->updateRepo(new_event, index);
}

std::vector<Event>& ServiceAdmin::getAll() {
    return this->repository->getAllRepo();
}
