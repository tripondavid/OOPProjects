//
// Created by david on 06-May-23.
//

#ifndef A89_CSVFILE_H
#define A89_CSVFILE_H

#endif //A89_CSVFILE_H
#pragma once
#include "FileSaver.h"

class CSVFile : public FileSaver {
protected:
    std::string fileName;
public:
    CSVFile(std::string& fileName);
    CSVFile();
    ~CSVFile();
    void save() override;
    void display() override;

    void addRepo(const Event& event) override;
    void deleteRepo(const long long) override;
    void updateRepo(const Event&, const long long) override;
};