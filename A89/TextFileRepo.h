//
// Created by david on 04-May-23.
//

#ifndef A89_TEXTFILEREPO_H
#define A89_TEXTFILEREPO_H

#endif //A89_TEXTFILEREPO_H
#pragma once
#include "Repository.h"
#include <fstream>

class TextFileRepo : public Repository {
private:
    std::string fileName;
    void loadFile();
    void saveFile();
public:
    TextFileRepo();
    TextFileRepo(std::string& fileName);
    ~TextFileRepo();

    void addRepo(const Event&) override;
    void deleteRepo(const long long) override;
    void updateRepo(const Event&, const long long) override;
};