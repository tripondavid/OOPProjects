//
// Created by david on 20-Apr-23.
//
#include "ServiceUser.h"
#include <iostream>

ServiceUser::ServiceUser() {}
ServiceUser::~ServiceUser() {}

ServiceUser::ServiceUser(Repository *userRepository, Repository *wholeRepository, FileSaver* userFileRepo) {
    this->userRepository = userRepository;
    this->wholeRepository = wholeRepository;
    this->userFileRepo = userFileRepo;
}

void ServiceUser::addEvent(Event &new_event) {
    this->userRepository->addRepo(new_event);
    this->userFileRepo->addRepo(new_event);
    this->increaseNumberPerson(new_event);
}

void ServiceUser::deleteEvent(std::string &title) {
    long long index = this->userRepository->searchEvent(title);
    if (index != -1)
    {
        this->userRepository->deleteRepo(index);
        this->userFileRepo->deleteRepo(index);
    }
}

void ServiceUser::increaseNumberPerson(Event &event) {
    std::string title = event.getTitle();
    std::string description = event.getDescription();
    DateTime date_time = event.getDateTime();
    int no_people = event.getNoPeople();
    std::string link = event.getLink();
    Event new_event = Event(title, description, date_time, no_people + 1, link);
    long long userIndex = this->userRepository->searchEvent(title);
    this->userRepository->updateRepo(new_event, userIndex);
    this->userFileRepo->updateRepo(new_event, userIndex);
    long long wholeIndex = this->userRepository->searchEvent(title);
    this->wholeRepository->updateRepo(new_event, wholeIndex);
}

void ServiceUser::decreaseNumberPerson(Event &event) {
    std::string title = event.getTitle();
    std::string description = event.getDescription();
    DateTime date_time = event.getDateTime();
    int no_people = event.getNoPeople();
    std::string link = event.getLink();
    Event new_event = Event(title, description, date_time, no_people - 1, link);
    long long userIndex = this->userRepository->searchEvent(title);
    this->userRepository->updateRepo(new_event, userIndex);
    this->userFileRepo->updateRepo(new_event, userIndex);
    long long wholeIndex = this->userRepository->searchEvent(title);
    this->wholeRepository->updateRepo(new_event, wholeIndex);
}

std::vector<Event>& ServiceUser::seeEventsUser() {
    this->userFileRepo->display();
    return this->userRepository->getAllRepo();
}

std::vector<Event> ServiceUser::seeEventsForMonth(const int &year, const int &month) {
    std::vector<Event> list_of_corresponding_events;
    for (auto i = this->wholeRepository->getAllRepo().begin(); i < this->wholeRepository->getAllRepo().end(); ++i) {
        if (i->getYear() == year && i->getMonth() == month) {
            list_of_corresponding_events.push_back(*i);
        }
    }

    return list_of_corresponding_events;
}