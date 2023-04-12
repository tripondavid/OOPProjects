#include "ui.h"
#include <iostream>
#include <string>

Ui::Ui(Service* service, ServiceUser* userService)
{
	this->service = service;
	this->userService = userService;
}

void Ui::printPrincipalMenu()
{
	std::cout << "1. Administrator mode.\n";
	std::cout << "2. User mode.\n";
	std::cout << "0. Exit.\n";
	std::cout << "Choose the desired mode: \n";
}

void Ui::adminMenu()
{
	std::cout << "1. Add new event.\n";
	std::cout << "2. Delete an event.\n";
	std::cout << "3. Update an event.\n";
	std::cout << "4. See all events.\n";
	std::cout << "0. Exit.\n";
}

void Ui::adminMode()
{
	while (1)
	{
		adminMenu();

		std::string option;
		std::getline(std::cin, option);
		if (option == "1")
		{
			std::string title, description, link;
			std::string no_people_string;
			std::string year_string;
			std::string month_string;
			std::string day_string;
			std::string hour_string;
			std::string minute_string;

			std::cout << "Insert the title: ";
			std::getline(std::cin, title);

			std::cout << "Insert the description: ";
			std::getline(std::cin, description);

			std::cout << "Insert the year: ";
			std::getline(std::cin, year_string);
			std::cout << "Insert the month(1-12): ";
			std::getline(std::cin, month_string);
			std::cout << "Insert the day: ";
			std::getline(std::cin, day_string);
			std::cout << "Insert the hour(0-23): ";
			std::getline(std::cin, hour_string);
			std::cout << "Insert the minute(0-59): ";
			std::getline(std::cin, minute_string);

			int year = std::stoi(year_string);
			int month = std::stoi(month_string);
			int day = std::stoi(day_string);
			int hour = std::stoi(hour_string);
			int minute = std::stoi(minute_string);
			if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
			{
				DateTime date_time = DateTime(year, month, day, hour, minute);

				std::cout << "Insert the number of people: ";
				std::getline(std::cin, no_people_string);
				int no_people = std::stoi(no_people_string);

				std::cout << "Insert the link: ";
				std::getline(std::cin, link);
				int result = this->service->addEventService(title, description, date_time, no_people, link);
				if (result == 0)
				{
					std::cout << "Event already added.\n";
				}
				else
				{
					std::cout << "Event added successfully.\n";
				}
			}
			else
			{
				std::cout << "Invalid date time!\n";
			}
		}
		else if (option == "2")
		{
			std::string title;
			std::cout << "Insert the title: ";
			std::getline(std::cin, title);
			int result = this->service->removeEventService(title);
			if (result == 0)
			{
				std::cout << "Event doesn't exist.\n";
			}
			else
			{
				std::cout << "Event deleted successfully.\n";
			}
		}
		else if (option == "3")
		{
			std::string title, description, link;
			std::string no_people_string;
			std::string year_string;
			std::string month_string;
			std::string day_string;
			std::string hour_string;
			std::string minute_string;

			std::cout << "Insert the title: ";
			std::getline(std::cin, title);

			std::cout << "Insert the description: ";
			std::getline(std::cin, description);

			std::cout << "Insert the year: ";
			std::getline(std::cin, year_string);
			std::cout << "Insert the month(1-12): ";
			std::getline(std::cin, month_string);
			std::cout << "Insert the day: ";
			std::getline(std::cin, day_string);
			std::cout << "Insert the hour(0-23): ";
			std::getline(std::cin, hour_string);
			std::cout << "Insert the minute(0-59): ";
			std::getline(std::cin, minute_string);

			int year = std::stoi(year_string);
			int month = std::stoi(month_string);
			int day = std::stoi(day_string);
			int hour = std::stoi(hour_string);
			int minute = std::stoi(minute_string);
			if (year > 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31 && hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59)
			{
				DateTime date_time = DateTime(year, month, day, hour, minute);

				std::cout << "Insert the number of people: ";
				std::getline(std::cin, no_people_string);
				int no_people = std::stoi(no_people_string);

				std::cout << "Insert the link: ";
				std::getline(std::cin, link);
				int result = this->service->updateEventService(title, description, date_time, no_people, link);
				if (result == 0)
				{
					std::cout << "Event not found.\n";
				}
				else
				{
					std::cout << "Event updated successfully.\n";
				}
			}
			else
			{
				std::cout << "Invalid date time!\n";
			}
		}
		else if (option == "4")
		{
			int size = this->service->getSizeService();
			if (size == 0)
				std::cout << "No event coming up.\n";
			else
			{
				Event* list_of_events = this->service->getAllEventsService();
				for (int i = 0; i < size; i++)
				{
					std::cout << list_of_events[i].toString();
				}
			}
		}
		else if (option == "0")
		{
			break;
		}
	}
}

void Ui::userMenu()
{
	std::cout << "1. See the events in the database for a given month and choose if you want to participate.\n";
	std::cout << "2. Delete an event from your list.\n";
	std::cout << "3. See your list of events.\n";
	std::cout << "0. Exit.\n";
}

void Ui::userMode()
{
	while (1)
	{
		userMenu();
		std::string option;
		std::getline(std::cin, option);
		if (option == "0")
		{
			break;
		}
		else if (option == "1")
		{
			std::string monthString;
			std::string yearString;
			std::cout << "Insert the year:\n";
			std::getline(std::cin, yearString);
			int year = std::stoi(yearString);
			std::cout << "Insert the month:\n";
			std::getline(std::cin, monthString);
			int month = std::stoi(monthString);
			int sizeUi = 0;
			Event list_of_events[101];
			this->userService->seeEventsForMonthService(list_of_events, year, month, sizeUi);
			if (sizeUi == 0)
			{
				std::cout << "No event in that month. \n";
			}
			else
			{
				int i = 0;
				while (1)
				{
					if (i < sizeUi)
					{
						std::cout << list_of_events[i].toString();
						std::string option2;
						std::cout << "1. Add it to your event list.\n";
						std::cout << "2. See next event from that month.\n";
						std::cout << "0. Exit.\n";
						std::getline(std::cin, option2);
						if (option2 == "1")
						{
							this->userService->addEventService(list_of_events[i]);
						}
						else if (option2 == "2")
						{
							i++;
						}
						else if (option2 == "0")
						{
							break;
						}
					}
					else
					{
						i = 0;
					}
				}
			}
		}
		else if (option == "2")
		{
			std::cout << "Insert the title of the event. \n";
			std::string title_option_2;
			std::getline(std::cin, title_option_2);
			this->userService->deleteEventService(title_option_2);
		}
		else if (option == "3")
		{
			int size_of_list;
			Event* list_user_events = this->userService->seeEventsUserParticipatesService(size_of_list);
			for (int i = 0; i < size_of_list; i++)
			{
				std::cout << list_user_events[i].toString() << "\n";
			}

		}
	}
}

void Ui::start()
{
	while (1)
	{
		printPrincipalMenu();
		std::string option;
		std::getline(std::cin, option);
		if (option == "0")
		{
			break;
		}
		else if (option == "1")
		{
			adminMode();
		}
		else if (option == "2")
		{
			userMode();
		}
	}
}