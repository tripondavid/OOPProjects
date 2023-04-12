#include "ui.h"
#include "service.h"
#include "repository.h"
#include "dynamicVector.h"
#include "test.h"

int main()
{
	auto* dv = new DynamicVector<Event>(10);
	auto* dvUser = new DynamicVector<Event>(10);
	auto* repo = new Repository(dv);
	auto* userRepo = new Repository(dvUser);
	auto* service = new Service(repo);
	auto* userService = new ServiceUser(repo, userRepo);
	auto* ui = new Ui(service, userService);

	testAdmin();
	service->addRandomEvents();
	ui->start();
}