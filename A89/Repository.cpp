//
// Created by david on 18-Apr-23.
//
#include "Repository.h"

Repository::Repository() {}
Repository::~Repository() {}

Repository::Repository(std::vector<Event> &repoVector) {
    this->repoVector = repoVector;
}

std::vector<Event>& Repository::getAllRepo() {
    return this->repoVector;
}

unsigned long long Repository::getSizeRepo() {
    return this->repoVector.size();
}

unsigned long long Repository::getCapacityRepo() {
    return this->repoVector.capacity();
}

void Repository::addRepo(const Event &event) {
    this->repoVector.push_back(event);
}

void Repository::deleteRepo(const long long index) {
    this->repoVector.erase(this->repoVector.begin() + index);
}

void Repository::updateRepo(const Event &new_event, const long long index) {
    this->repoVector[index] = new_event;
}

long long Repository::searchEvent(std::string &title) {
    for (auto i = this->repoVector.begin(); i < this->repoVector.end(); ++i)
        if (i->getTitle() == title)
            return i - this->repoVector.begin();
    return -1;
}
