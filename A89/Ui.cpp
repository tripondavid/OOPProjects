//
// Created by david on 19-Apr-23.
//
#include "Ui.h"

Ui::Ui() {}
Ui::~Ui() {}

Ui::Ui(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser) {
    this->serviceAdmin = serviceAdmin;
    this->serviceUser = serviceUser;
}

void Ui::principalMenu()
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

            try {
                int year = std::stoi(year_string);
                int month = std::stoi(month_string);
                int day = std::stoi(day_string);
                int hour = std::stoi(hour_string);
                int minute = std::stoi(minute_string);
                DateTime date_time = DateTime(year, month, day, hour, minute);

                std::cout << "Insert the number of people: ";
                std::getline(std::cin, no_people_string);
                int no_people = std::stoi(no_people_string);

                std::cout << "Insert the link: ";
                std::getline(std::cin, link);
                this->serviceAdmin.addEvent(title, description, date_time, no_people, link);
            }
            catch (ValidationException& e)
            {
                std::cout << e.what() << "\n";
            }
            catch (RepositoryException& e)
            {
                std::cout << e.what() << "\n";
            }
        }
        else if (option == "2")
        {
            std::string title;
            std::cout << "Insert the title: ";
            std::getline(std::cin, title);
            try {
                this->serviceAdmin.deleteEvent(title);
            }
            catch (RepositoryException& e)
            {
                std::cout << e.what() << "\n";
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
            try {
                DateTime date_time = DateTime(year, month, day, hour, minute);

                std::cout << "Insert the number of people: ";
                std::getline(std::cin, no_people_string);
                int no_people = std::stoi(no_people_string);

                std::cout << "Insert the link: ";
                std::getline(std::cin, link);
                this->serviceAdmin.updateEvent(title, description, date_time, no_people, link);
            }
            catch (RepositoryException& e)
            {
                std::cout << e.what() << "\n";
            }
        }
        else if (option == "4")
        {
            for (auto i = this->serviceAdmin.getAll().begin(); i < this->serviceAdmin.getAll().end(); ++i)
            {
                std::cout<<i->toString();
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

void Ui::userMode() {
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
            std::vector<Event> list_of_events = this->serviceUser.seeEventsForMonth(year, month);
            unsigned long long sizeUi = list_of_events.size();
            if(sizeUi == 0)
            {
                std::cout << "No event in that month. \n";
            }
            else {
                unsigned long long i = 0;
                while (1) {
                    if (i < sizeUi) {
                        std::cout << list_of_events[i].toString();
                        std::string option2;
                        std::cout << "1. Add it to your event list.\n";
                        std::cout << "2. See next event from that month.\n";
                        std::cout << "0. Exit.\n";
                        std::getline(std::cin, option2);
                        if (option2 == "1") {
                            this->serviceUser.addEvent(list_of_events[i]);
                        } else if (option2 == "2") {
                            i++;
                        } else if (option2 == "0") {
                            break;
                        }
                    } else {
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
            this->serviceUser.deleteEvent(title_option_2);
        }
        else if (option == "3")
        {
            std::vector<Event> list_events = this->serviceUser.seeEventsUser();
            for (auto i = list_events.begin(); i< list_events.end(); ++i)
                std::cout<<i->toString();
        }
    }
}

void Ui::start()
{
    while (1)
    {
        principalMenu();
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

