#include "test.h"
#include "Event.h"
#include "repository.h"
#include "service.h"
#include <assert.h>

void testAdmin()
{
	auto* dvTest1 = new DynamicVector<Event>(10);
	auto* testRepo = new Repository(dvTest1);
	auto* testService = new Service(testRepo);
	DateTime new_dateTime = DateTime(2022, 12, 24, 12, 30);
	const std::string title = "Targ de craciun";
	const std::string description = "Globuri, vin, pom de Craciun";
	const std::string link = "https://cluj.com/targul-de-craciun-cluj/";
	const int no_people = 500;
	testService->addEventService(title, description, new_dateTime, no_people, link);
	assert(testService->addEventService(title, description, new_dateTime, no_people, link) == 0);
	assert(testService->addEventService(title, description, new_dateTime, 500, link) == 0);
	assert(testService->removeEventService(title) == 1);
	assert(testService->removeEventService(title) == 0);
	testService->addEventService(title, description, new_dateTime, no_people, link);
	DateTime new_dateTime2 = DateTime(2022, 12, 25, 12, 30);
	std::string title2 = "Targuri de craciun";
	assert(testService->updateEventService(title, description, new_dateTime2, 600, link) == 1);
	assert(testService->updateEventService(title2 , description, new_dateTime2, 600, link) == 0);
}