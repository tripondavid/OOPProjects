//
// Created by david on 04-May-23.
//
#include "TextFileRepo.h"
#include <iostream>

TextFileRepo::TextFileRepo(std::string &fileName) {
    this->fileName = fileName;
    loadFile();
}

void TextFileRepo::loadFile() {
    std::ifstream fin(this->fileName);
    if(fin.peek() != std::ifstream::traits_type::eof())
    {
        this->repoVector.clear();
        Event fileEvent;
        while (!fin.eof()) {
            fin >> fileEvent;
            this->repoVector.push_back(fileEvent);
        }
    }
    fin.close();
}

void TextFileRepo::saveFile() {
    std::ofstream fout(this->fileName);
    for (auto i : this->repoVector)
    {
        fout << i;
    }
    fout.close();
}

void TextFileRepo::addRepo(const Event &new_event) {
    Repository::addRepo(new_event);
    this->saveFile();
}

void TextFileRepo::deleteRepo(const long long index) {
    Repository::deleteRepo(index);
    this->saveFile();
}

void TextFileRepo::updateRepo(const Event &updated_event, const long long index) {
    Repository::updateRepo(updated_event, index);
    this->saveFile();
}