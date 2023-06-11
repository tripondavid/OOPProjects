//
// Created by david on 23-May-23.
//
#include "Gui.h"

Gui::Gui() {}

Gui::~Gui() {}

Gui::Gui(Service &service) {
    this->service = service;

    this->titleLabel = new QLabel(this);

    this->showButton = new QPushButton("Show all items");
    this->removeSectionButton = new QPushButton("Delete Menu");
    this->removeButton = new QPushButton("Delete Item");
    this->searchButton = new QPushButton("Search certain items");

    this->categoryLineEdit = new QLineEdit{};
    this->nameLineEdit = new QLineEdit{};
    this->searchLineEdit = new QLineEdit{};

    this->qListWidget = new QListWidget{};

    this->initGui();
    this->connectSignalsAndSlots();
}

void Gui::initGui() {
    auto* layout = new QVBoxLayout();

    this->titleLabel->setText("<p style='text-align:center'>Main Menu</p>");
    layout->addWidget(this->titleLabel);

    auto* buttonLayout = new QGridLayout{};
    buttonLayout->addWidget(this->showButton);
    buttonLayout->addWidget(this->removeSectionButton);
    buttonLayout->addWidget(this->searchButton);
    layout->addLayout(buttonLayout);

    this->setLayout(layout);
}

void Gui::connectSignalsAndSlots() {
    QObject::connect(this->showButton, &QPushButton::clicked, this, &Gui::showItems);
    QObject::connect(this->removeSectionButton, &QPushButton::clicked, this, &Gui::removeSectionItem);
    QObject::connect(this->removeButton, &QPushButton::clicked, this, &Gui::removeItem);
    QObject::connect(this->searchButton, &QPushButton::clicked, this, &Gui::searchItem);
    QObject::connect(this->searchLineEdit, &QLineEdit::textChanged, this, &Gui::updateTextBrowser);
}

void Gui::showItems() {
    this->displayWidget = new QWidget{};
    auto* layout = new QVBoxLayout(this->displayWidget);
    auto* list = new QListWidget{};

    for (auto &item: this->service.getAll())
    {
        list->addItem(QString::fromStdString(item.toString()));
    }

    layout->addWidget(list);
    this->displayWidget->setLayout(layout);
    this->displayWidget->show();
}

void Gui::removeSectionItem() {
    this->displayWidget = new QWidget{};
    auto* layout = new QVBoxLayout(this->displayWidget);

    auto* eventLayout = new QFormLayout{};
    eventLayout->addRow("Category", this->categoryLineEdit);
    eventLayout->addRow("Name", this->nameLineEdit);

    auto* buttonLayout = new QGridLayout{};
    buttonLayout->addWidget(this->removeButton);

    layout->addLayout(eventLayout);
    layout->addLayout(buttonLayout);

    this->displayWidget->setLayout(layout);
    this->displayWidget->show();
}

void Gui::removeItem() {
    std::string category = this->categoryLineEdit->text().toStdString();
    std::string name = this->nameLineEdit->text().toStdString();
    this->service.remove(category, name);
}

void Gui::searchItem() {
    this->displayWidget = new QWidget{};
    auto* layout = new QVBoxLayout(this->displayWidget);

    auto* eventLayout = new QFormLayout{};

    eventLayout->addRow("Search", this->searchLineEdit);

    layout->addLayout(eventLayout);
    layout->addWidget(this->qListWidget);

    this->displayWidget->setLayout(layout);
    this->displayWidget->show();
}

void Gui::updateTextBrowser() {
    std::string searchString = this->searchLineEdit->text().toStdString();
    this->qListWidget->clear();
    for (auto &i: this->service.getAll())
    {
        if(i.getName().find(searchString) != std::string::npos  || i.getCategory().find(searchString) != std::string::npos)
        {
            this->qListWidget->addItem(QString::fromStdString(i.toString()));
        }
    }
}