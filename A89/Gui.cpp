//
// Created by david on 18-May-23.
//
#include "Gui.h"
#include <iostream>

Gui::Gui() {}

Gui::~Gui() = default;

Gui::Gui(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser) {
    this->serviceAdmin = serviceAdmin;
    this->serviceUser = serviceUser;

    this->titleLabel = new QLabel(this);

    this->adminButton = new QPushButton(this);
    this->userButton = new QPushButton(this);
    this->exitButton = new QPushButton(this);

    this->initGui();
    this->connectSignalSlot();
}

void Gui::initGui() {
    auto* layout = new QVBoxLayout(this);
    this->titleLabel->setText("<p style='text-align:center'>Main Menu</p>");
    layout->addWidget(this->titleLabel);
    this->adminButton->setText("Admin Menu");
    this->userButton->setText("User Menu");
    this->exitButton->setText("Exit");
    layout->addWidget(adminButton);
    layout->addWidget(userButton);
    layout->addWidget(exitButton);
    this->setLayout(layout);
}

void Gui::connectSignalSlot() {
    QObject::connect(this->adminButton, &QPushButton::clicked, this, &Gui::showAdmin);
    QObject::connect(this->userButton, &QPushButton::clicked, this, &Gui::showUser);
    QObject::connect(this->exitButton, &QPushButton::clicked, this, &Gui::exit);
}

void Gui::exit() {
    this->close();
}

void Gui::showAdmin() {
    auto* adminGui = new AdminGui(this->serviceAdmin, this->serviceUser);
    adminGui->show();
}

void Gui::showUser() {
    auto* userGui = new UserGui(this->serviceAdmin, this->serviceUser);
    userGui->show();
}

AdminGui::AdminGui() {}

AdminGui::~AdminGui() {}

AdminGui::AdminGui(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser) {
    this->serviceAdmin = serviceAdmin;
    this->serviceUser = serviceUser;

    this->titleLabel = new QLabel(this);

    this->exitButton = new QPushButton(this);
    this->addButton = new QPushButton(this);
    this->deleteButton = new QPushButton(this);
    this->updateButton = new QPushButton(this);
    this->displayButton = new QPushButton(this);

    this->titleLineEdit = new QLineEdit{};
    this->descriptionLineEdit = new QLineEdit{};
    this->dateTimeLineEdit = new QLineEdit{};
    this->noPeopleLineEdit = new QLineEdit{};
    this->linkLineEdit = new QLineEdit{};

    this->initAdminGui();
    this->connectSignalSlot();
}

void AdminGui::initAdminGui() {
    auto* layout = new QVBoxLayout(this);
    this->titleLabel->setText("<p style='text-align:center'>Admin Menu</p>");
    this->addButton->setText("Add");
    this->deleteButton->setText("Delete");
    this->updateButton->setText("Update");
    this->displayButton->setText("Display events");
    this->exitButton->setText("Exit");

    layout->addWidget(this->titleLabel);

    auto* eventLayout = new QFormLayout{};
    eventLayout->addRow("Title", this->titleLineEdit);
    eventLayout->addRow("Description", this->descriptionLineEdit);
    eventLayout->addRow("Date Time", this->dateTimeLineEdit);
    eventLayout->addRow("Number of people", this->noPeopleLineEdit);
    eventLayout->addRow("Link", this->linkLineEdit);
    layout->addLayout(eventLayout);

    auto* buttonLayout = new QGridLayout();
    buttonLayout->addWidget(this->addButton);
    buttonLayout->addWidget(this->deleteButton);
    buttonLayout->addWidget(this->updateButton);
    buttonLayout->addWidget(this->displayButton);
    buttonLayout->addWidget(this->exitButton);
    layout->addLayout(buttonLayout);

    this->setLayout(layout);
}

void AdminGui::exit() {
    this->close();
}

void AdminGui::connectSignalSlot() {
    QObject::connect(this->exitButton, &QPushButton::clicked, this, &AdminGui::exit);
    QObject::connect(this->addButton, &QPushButton::clicked, this, &AdminGui::addEvent);
    QObject::connect(this->deleteButton, &QPushButton::clicked, this, &AdminGui::deleteEvent);
    QObject::connect(this->updateButton, &QPushButton::clicked, this, &AdminGui::updateEvent);
    QObject::connect(this->displayButton, &QPushButton::clicked, this, &AdminGui::displayEvents);
}

void AdminGui::addEvent() {
    std::string title = this->titleLineEdit->text().toStdString();
    std::string description = this->descriptionLineEdit->text().toStdString();
    std::string dateTimeString = this->dateTimeLineEdit->text().toStdString();
    std::string noPeopleString = this->noPeopleLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();

    int noPeople = std::stoi(noPeopleString);

    char* dateTimeChar = new char[101];
    strcpy(dateTimeChar, dateTimeString.c_str());
    char* p = std::strtok(dateTimeChar, ".");
    int year = std::stoi(p);
    p = std::strtok(NULL,".");
    int month = std::stoi(p);
    p = std::strtok(NULL, " ");
    int day = std::stoi(p);
    p = std::strtok(NULL, ":");
    int hour = std::stoi(p);
    p = std::strtok(NULL, ":");
    int minute = std::stoi(p);
    DateTime dateTime = DateTime(year, month, day, hour, minute);
    this->serviceAdmin.addEvent(title, description, dateTime, noPeople, link);
}

void AdminGui::deleteEvent() {
    std::string title = this->titleLineEdit->text().toStdString();

    this->serviceAdmin.deleteEvent(title);
}

void AdminGui::updateEvent() {
    std::string title = this->titleLineEdit->text().toStdString();
    std::string description = this->descriptionLineEdit->text().toStdString();
    std::string dateTimeString = this->dateTimeLineEdit->text().toStdString();
    std::string noPeopleString = this->noPeopleLineEdit->text().toStdString();
    std::string link = this->linkLineEdit->text().toStdString();

    int noPeople = std::stoi(noPeopleString);

    char* dateTimeChar = new char[101];
    strcpy(dateTimeChar, dateTimeString.c_str());
    char* p = std::strtok(dateTimeChar, ".");
    int year = std::stoi(p);
    p = std::strtok(NULL,".");
    int month = std::stoi(p);
    p = std::strtok(NULL, " ");
    int day = std::stoi(p);
    p = std::strtok(NULL, ":");
    int hour = std::stoi(p);
    p = std::strtok(NULL, ":");
    int minute = std::stoi(p);
    DateTime dateTime = DateTime(year, month, day, hour, minute);

    this->serviceAdmin.updateEvent(title, description, dateTime, noPeople, link);
}

void AdminGui::displayEvents() {
    this->displayWidget = new QWidget{};
    auto* textBrowser = new QTextBrowser();
    auto* layout = new QVBoxLayout(this->displayWidget);
    QStringList list;

    for (auto &i: this->serviceAdmin.getAll())
    {
        list.append(QString::fromStdString(i.toString()));
    }

    layout->addWidget(textBrowser);
    for(auto &i : list)
    {
        textBrowser->append(i);
        //textBrowser->append("\n");
    }
    this->displayWidget->setLayout(layout);
    this->displayWidget->show();
}

UserGui::UserGui() {}

UserGui::~UserGui() {}

UserGui::UserGui(ServiceAdmin &serviceAdmin, ServiceUser &serviceUser) {
    this->serviceAdmin = serviceAdmin;
    this->serviceUser = serviceUser;

    this->titleLabel = new QLabel(this);

    this->showButton = new QPushButton();
    this->exitButton = new QPushButton();
    this->addButton = new QPushButton();
    this->allEventsButton = new QPushButton();

    this->yearLineEdit = new QLineEdit{};
    this->monthLineEdit = new QLineEdit{};

    this->indexLineEdit = new QLineEdit{};

    this->initUserGui();
    this->connectSignalSlot();
}

void UserGui::connectSignalSlot() {
    QObject::connect(this->exitButton, &QPushButton::clicked, this, &UserGui::exit);
    QObject::connect(this->showButton, &QPushButton::clicked, this, &UserGui::displayEventsForMonth);
    QObject::connect(this->addButton, &QPushButton::clicked, this, &UserGui::addEvent);
    QObject::connect(this->allEventsButton, &QPushButton::clicked, this, &UserGui::displayUserEvents);
}

void UserGui::initUserGui() {
    auto* layout = new QVBoxLayout();
    this->titleLabel->setText("<p style='text-align:center'>User Menu</p>");
    this->showButton->setText("Show events from selected year and month");
    this->addButton->setText("Add");
    this->exitButton->setText("Exit");
    this->allEventsButton->setText("Show my events");

    auto* eventLayout = new QFormLayout{};
    eventLayout->addRow("Year", this->yearLineEdit);
    eventLayout->addRow("Month", this->monthLineEdit);

    layout->addWidget(this->titleLabel);

    auto* buttonLayout = new QGridLayout();
    buttonLayout->addWidget(this->showButton);
    buttonLayout->addWidget(this->allEventsButton);
    buttonLayout->addWidget(this->exitButton);

    layout->addLayout(eventLayout);
    layout->addLayout(buttonLayout);
    this->setLayout(layout);
}

void UserGui::displayEventsForMonth() {
    this->displayWidget = new QWidget{};
    auto* textBrowser = new QTextBrowser();
    auto* layout = new QVBoxLayout(this->displayWidget);
    layout->addWidget(textBrowser);

    std::string monthString = this->monthLineEdit->text().toStdString();
    std::string yearString = this->yearLineEdit->text().toStdString();

    int month = std::stoi(monthString);
    int year = std::stoi(yearString);

    this->list_of_events = this->serviceUser.seeEventsForMonth(year, month);

    layout->addWidget(textBrowser);
    for(auto &i : this->list_of_events)
    {
        textBrowser->append(QString::fromStdString(i.toString()));
    }


    auto* eventLayout = new QFormLayout{};

    auto* buttonLayout = new QGridLayout();
    buttonLayout->addWidget(this->addButton);

    eventLayout->addRow("Insert the index:", this->indexLineEdit);

    layout->addLayout(eventLayout);
    layout->addLayout(buttonLayout);

    this->displayWidget->setLayout(layout);

    this->displayWidget->show();

}

void UserGui::displayUserEvents() {
    this->serviceUser.seeEventsUser();
}

void UserGui::addEvent() {
    std::string indexString = this->indexLineEdit->text().toStdString();
    long long index = std::stoi(indexString);
    this->serviceUser.addEvent(list_of_events[index]);
}

void UserGui::exit() {
    this->close();
}

FileGui::FileGui() {}

FileGui::FileGui(FileSaver* fileSaver) {
    this->HTMLButton = new QPushButton();
    this->CSVButton = new QPushButton();
    this->titleLabel = new QLabel(this);
    this->fileSaver = fileSaver;

    this->initFileGui();
    this->connectSignalSlot();
}

FileGui::~FileGui() {}

void FileGui::initFileGui() {
    auto* layout = new QVBoxLayout(this);
    this->titleLabel->setText("<p style='text-align:center'>Choose the file format!</p>");
    layout->addWidget(this->titleLabel);

    auto* buttonLayout = new QGridLayout();
    this->HTMLButton->setText("HTML");
    this->CSVButton->setText("CSV");
    buttonLayout->addWidget(HTMLButton);
    buttonLayout->addWidget(CSVButton);

    layout->addLayout(buttonLayout);
    this->setLayout(layout);
}

void FileGui::connectSignalSlot() {
    QObject::connect(this->HTMLButton, &QPushButton::clicked, this, &FileGui::optionHTML);
    QObject::connect(this->CSVButton, &QPushButton::clicked, this, &FileGui::optionCSV);
}

void FileGui::optionHTML() {
    std::string file = "events.html";
    this->fileSaver = new HTMLFile(file);
    this->close();
}

void FileGui::optionCSV() {
    std::string file = "events.csv";
    this->fileSaver = new CSVFile(file);
    this->close();
}