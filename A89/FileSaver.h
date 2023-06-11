//
// Created by david on 06-May-23.
//

#ifndef A89_FILESAVER_H
#define A89_FILESAVER_H

#endif //A89_FILESAVER_H
#pragma once
#include <string>
#include "Repository.h"
#include <windows.h>

class FileSaver : public Repository {
protected:
    std::string fileName;
public:
    FileSaver();
    virtual ~FileSaver();
    FileSaver(std::string& fileName);

    virtual void save();
    virtual void display();
};