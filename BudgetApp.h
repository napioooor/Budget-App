#ifndef BUDGETAPP_H
#define BUDGETAPP_H

#include <iostream>

#include "UserMenager.h"
#include "Menu.h"

using namespace std;

class BudgetApp {
    UserMenager userMenager;
    Menu menu;

public:
    BudgetApp(string userFileName) : userMenager(userFileName, 0){
        menu.runMenu(userMenager);
    };
};

#endif
