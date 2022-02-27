#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <sstream>
#include <windows.h>

#include "UserMenager.h"
//#include "AdresatMenedzer.h"

using namespace std;

class Menu{
    char pickOptionFromUserMenu();
    char pickOptionFromMainMenu();

public:
    void runMenu(UserMenager userMenager);
};

#endif
