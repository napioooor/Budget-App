#ifndef SUPPORTMETHODS_H
#define SUPPORTMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <string>
#include <time.h>
#include <stdio.h>

using namespace std;

class SupportMethods{
public:
    static string inputLine();
    static string convertIntToString(int number);
    static char inputChar();
    static string changeFirstLetterIntoUppercaseRestLowercase(string text);
    static bool isFileEmpty(fstream &textFile);
    static int convertStringToInt(string number);
    static int getInt();
    static string convertCommaToPoint(string text);
    static double convertStringToDouble(string number);
};

#endif
