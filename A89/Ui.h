//
// Created by david on 19-Apr-23.
//

#ifndef A89_UI_H
#define A89_UI_H

#endif //A89_UI_H
#pragma once
#include "ServiceAdmin.h"
#include "ServiceUser.h"
#include <iostream>
#include "Exceptions.h"

class Ui {
private:
    ServiceAdmin serviceAdmin;
    ServiceUser serviceUser;
public:
    Ui();
    Ui(ServiceAdmin&, ServiceUser&);
    ~Ui();
    void principalMenu();
    void adminMenu();
    void adminMode();
    void userMenu();
    void userMode();
    void start();
};