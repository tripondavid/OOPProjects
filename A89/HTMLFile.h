//
// Created by david on 07-May-23.
//

#ifndef A89_HTMLFILE_H
#define A89_HTMLFILE_H

#endif //A89_HTMLFILE_H
#pragma once
#include "FileSaver.h"

class HTMLFile : public FileSaver {
protected:
    std::string fileName;
public:
    HTMLFile();
    ~HTMLFile();
    HTMLFile(std::string&);
    void save() override;
    void display() override;

    void addRepo(const Event&) override;
    void deleteRepo(const long long) override;
    void updateRepo(const Event&, const long long) override;
};