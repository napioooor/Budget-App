#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>

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
};

#endif
