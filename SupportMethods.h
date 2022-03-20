#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;

class SupportMethods{
    string currentDateTime();
public:
    static string inputLine();
    static string convertIntToString(int number);
    static char inputChar();
    static string changeFirstLetterIntoUppercaseRestLowercase(string text);
    static bool isFileEmpty(fstream &textFile);
    static int convertStringToInt(string number);
    static int getInt();
    static bool isDateCorrect(string date);
    static int howLongIsMonth(int month, int year);
    static bool isThisLeapYear(int year);
    static int convertDateFromStringToInt(string date);
    static string convertCommaToPoint(string text);
    static double convertStringToDouble(string number);
    static string properCurrentDate();
};

#endif
