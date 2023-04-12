#pragma once
#include "dynamicVector.h"

class Repository {
private:
	DynamicVector<Event>* repoArray;

public:
	Repository();
	Repository(DynamicVector<Event>* repoArray);
	~Repository();
	Event* getAllRepo();
	int getSizeRepo();
	int getCapacityRepo();
	int findIndexByTitle(const std::string);
	void addRepo(const Event&);
	void deleteRepo(const int);
	void updateRepo(const Event&, const int);

};