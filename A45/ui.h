#pragma once
#include "service.h"
#include "service_user.h"

class Ui {
private:
	Service* service;
	ServiceUser* userService;

public:
	Ui();
	Ui(Service*, ServiceUser*);
	~Ui();

	void printPrincipalMenu();
	void adminMenu();
	void userMenu();
	void start();
	void adminMode();
	void userMode();
};