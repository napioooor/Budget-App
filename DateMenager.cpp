#include "DateMenager.h"

bool DateMenager::isDateCorrect(string date){
    string year, month, day, temp;
    int Y, M, D;
    DateMenager obj;

    if(date.length() != 10)
        return false;

    temp = date;

    year = temp.erase(4, 6);
    Y = SupportMethods::convertStringToInt(year);

    temp = date;
    temp.erase(0, 5);

    month = temp.erase(2, 4);
    M = SupportMethods::convertStringToInt(month);

    temp = date;
    day = temp.erase(0, 8);
    D = SupportMethods::convertStringToInt(day);

    if(Y < 2000 || M < 1 || M > 13 || D < 1 || D > obj.howLongIsMonth(M, Y))
        return false;
    else
        return true;
}

bool DateMenager::isThisLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

int DateMenager::howLongIsMonth(int month, int year){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(isThisLeapYear(year) == true)
        return 29;
    else
        return 28;
}

int DateMenager::convertDateFromStringToInt(string date){
    date.erase(4, 1);
    date.erase(6, 1);

    return SupportMethods::convertStringToInt(date);
}

string DateMenager::currentDateTime() {
    time_t now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

string DateMenager::properCurrentDate(){
    DateMenager obj;

    string time = obj.currentDateTime();

    time.erase(10,9);

    return time;
}

string DateMenager::convertIntDateToString(int date){
    string dateS;

    dateS = SupportMethods::convertIntToString(date);

    dateS.insert(4, "-");
    dateS.insert(7, "-");

    return dateS;
}
