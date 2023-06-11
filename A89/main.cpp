#include "Gui.h"
#include <iostream>
#include <string.h>
#include "FileSaver.h"
#include "TextFileRepo.h"
#include "HTMLFile.h"
#include "CSVFile.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    std::vector<Event> userVector;
    std::string fileName = "C:\\Users\\david\\Desktop\\Facultate\\Anul 1\\Semestrul 2\\OOP\\A89\\cmake-build-debug\\events.txt";
    std::cout << "Choose how you want to get the info: HTML or CSV \n";
    std::string option;
    std::getline(std::cin, option);
    FileSaver* fileSaver = nullptr;
    if(option == "HTML")
    {
        std::string file = "events.html";
        fileSaver = new HTMLFile(file);
    }
    else if (option == "CSV")
    {
        std::string file = "events.csv";
        fileSaver = new CSVFile(file);
    }
    else
    {
        return 0;
    }
    //FileSaver* fileSaver = nullptr;
    //FileGui fileGui = FileGui(fileSaver);
    //fileGui.show();

    auto* adminRepository = new TextFileRepo(fileName);
    auto* userRepository = new Repository(userVector);

    ServiceAdmin serviceAdmin = ServiceAdmin(adminRepository);
    ServiceUser serviceUser = ServiceUser(userRepository, adminRepository, fileSaver);

    Gui gui = Gui(serviceAdmin, serviceUser);
    gui.show();
    return a.exec();
}
