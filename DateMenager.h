#ifndef DATEMENAGER_H
#define DATEMENAGER_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>

#include "SupportMethods.h"

using namespace std;

class DateMenager{
    string currentDateTime();
    bool isThisLeapYear(int year);
    int howLongIsMonth(int month, int year);
public:
    static bool isDateCorrect(string date);
    static int convertDateFromStringToInt(string date);
    static string properCurrentDate();
    static string convertIntDateToString(int date);
};

#endif
