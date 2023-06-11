//
// Created by david on 07-May-23.
//
#include "HTMLFile.h"

HTMLFile::HTMLFile() {}

HTMLFile::~HTMLFile() {}

HTMLFile::HTMLFile(std::string& fileName) {
    this->fileName = fileName;
}

void HTMLFile::save() {
    std::ofstream fout(this->fileName);

    fout << "<!DOCTYPE html>\n";
    fout << "<html>\n";
    fout << "<head>\n";
    fout << "\t<title>My Events</title>\n";
    fout << "</head>\n";
    fout << "<body>\n";
    fout << "<table border=\"1\">\n";

    fout << "\t<tr>\n";
    fout << "\t\t<td>Title</td>\n";
    fout << "\t\t<td>Description</td>\n";
    fout << "\t\t<td>Date and Time</td>\n";
    fout << "\t\t<td>People attending</td>\n";
    fout << "\t\t<td>Link</td>\n";
    fout << "\t</tr>\n";

    for (auto i : this->repoVector)
    {
        fout << "\t<tr>\n";
        fout << "\t\t<td>" << i.getTitle() << "</td>\n";
        fout << "\t\t<td>" << i.getDescription() << "</td>\n";
        fout << "\t\t<td>" << i.getDateTime().toString() << "</td>\n";
        fout << "\t\t<td>" << i.getNoPeople() << "</td>\n";
        fout << "\t\t<td><a href=\"" << i.getLink() << "\">link</a></td>\n";
        fout << "\t</tr>\n";
    }
    fout.close();
}

void HTMLFile::display() {
    std::string file = "file:///C:/Users/david/Desktop/Facultate/Anul%201/Semestrul%202/OOP/A7/cmake-build-debug/";
    file += this->fileName;
    ShellExecuteA(NULL, NULL, "chrome.exe", file.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void HTMLFile::addRepo(const Event& event) {
    Repository::addRepo(event);
    this->save();
}

void HTMLFile::deleteRepo(const long long index) {
    Repository::deleteRepo(index);
    this->save();
}

void HTMLFile::updateRepo(const Event &new_event, const long long index) {
    Repository::updateRepo(new_event, index);
    this->save();
}