//
// Created by david on 17-May-23.
//

#ifndef A89_GUI_H
#define A89_GUI_H

#endif //A89_GUI_H
#pragma once
#include <QWidget>
#include <QLabel>
#include "HTMLFile.h"
#include "CSVFile.h"
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QStringList>
#include <QTextBrowser>
#include <QRadioButton>
#include <QVBoxLayout>
#include "ServiceAdmin.h"
#include "ServiceUser.h"
#include "TextFileRepo.h"

class FileGui : public QWidget {
private:
    QPushButton* HTMLButton;
    QPushButton* CSVButton;
    QLabel* titleLabel;
    FileSaver* fileSaver;
    void initFileGui();
    void connectSignalSlot();
    void optionHTML();
    void optionCSV();
public:
    FileGui();
    explicit FileGui(FileSaver* fileSaver);
    ~FileGui() override;
};

class Gui : public QWidget {
private:
    ServiceAdmin serviceAdmin;
    ServiceUser serviceUser;
    QLabel* titleLabel;
    QPushButton* adminButton;
    QPushButton* userButton;
    QPushButton* exitButton;
    void initGui();
    void connectSignalSlot();
    void exit();
    void showAdmin();
    void showUser();
public:
    Gui();
    ~Gui() override;
    Gui(ServiceAdmin& serviceAdmin, ServiceUser& serviceUser);
};

class AdminGui : public QWidget {
private:
    ServiceAdmin serviceAdmin;
    ServiceUser serviceUser;

    QLabel* titleLabel;

    QPushButton* exitButton;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* displayButton;

    QLineEdit* titleLineEdit;
    QLineEdit* descriptionLineEdit;
    QLineEdit* dateTimeLineEdit;
    QLineEdit* noPeopleLineEdit;
    QLineEdit* linkLineEdit;

    QWidget* displayWidget;

    void initAdminGui();
    void connectSignalSlot();
    void addEvent();
    void deleteEvent();
    void updateEvent();
    void exit();
    void displayEvents();
public:
    AdminGui();
    ~AdminGui() override;
    AdminGui(ServiceAdmin& serviceAdmin, ServiceUser& serviceUser);

};

class UserGui : public QWidget {
private:
    ServiceAdmin serviceAdmin;
    ServiceUser serviceUser;

    QLabel* titleLabel;

    QPushButton* exitButton;
    QPushButton* showButton;
    QPushButton* allEventsButton;

    QLineEdit* yearLineEdit;
    QLineEdit* monthLineEdit;

    QWidget* displayWidget;


    QLineEdit* indexLineEdit;
    QPushButton* addButton;

    std::vector<Event> list_of_events;

    void initUserGui();
    void connectSignalSlot();
    void addEvent();
    void displayEventsForMonth();
    void displayUserEvents();
    void exit();
public:
    UserGui();
    ~UserGui() override;
    UserGui(ServiceAdmin& serviceAdmin, ServiceUser& serviceUser);
};