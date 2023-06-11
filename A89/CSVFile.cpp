//
// Created by david on 06-May-23.
//
#include "CSVFile.h"
#include <fstream>

CSVFile::CSVFile(std::string &fileName) {
    this->fileName = fileName;
}

CSVFile::CSVFile() {}

CSVFile::~CSVFile() {}

void CSVFile::save() {
    std::ofstream fout(this->fileName);

    for (auto i : this->repoVector)
    {
        fout << i;
    }

    fout.close();
}

void CSVFile::display() {
    ShellExecuteA(NULL, NULL, "notepad.exe", this->fileName.c_str(), NULL, SW_SHOWMAXIMIZED);
}

void CSVFile::addRepo(const Event& event) {
        Repository::addRepo(event);
        this->save();
}

void CSVFile::deleteRepo(const long long index) {
    Repository::deleteRepo(index);
    this->save();
}

void CSVFile::updateRepo(const Event &new_event, const long long index) {
    Repository::updateRepo(new_event, index);
    this->save();
}