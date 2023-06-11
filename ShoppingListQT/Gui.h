//
// Created by david on 23-May-23.
//

#ifndef PROBATESTLAB13TURA2_GUI_H
#define PROBATESTLAB13TURA2_GUI_H

#endif //PPROBATESTLAB13TURA2_GUI_H
#pragma once
#include "Service.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QFormLayout>
#include <QListWidget>
#include <QTextBrowser>

class Gui : public QWidget {
private:
    Service service;

    QLabel* titleLabel;

    QPushButton* showButton;
    QPushButton* removeButton;
    QPushButton* searchButton;

    QPushButton* removeSectionButton;

    QWidget* displayWidget;

    QLineEdit* categoryLineEdit;
    QLineEdit* nameLineEdit;

    QLineEdit* searchLineEdit;

    QListWidget* qListWidget;


    void searchItem();
    void updateTextBrowser();
    void initGui();
    void connectSignalsAndSlots();
    void showItems();
    void removeItem();
    void removeSectionItem();
public:
    Gui();
    ~Gui() override;
    Gui(Service& service);
};