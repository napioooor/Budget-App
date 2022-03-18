#include "SupportMethods.h"

string SupportMethods::inputLine() {
    string entry = "";
    getline(cin, entry);
    return entry;
}

string SupportMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

char SupportMethods::inputChar() {
    string entry = "";
    char character  = {0};

    while (true) {
        getline(cin, entry);

        if (entry.length() == 1) {
            character = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string SupportMethods::changeFirstLetterIntoUppercaseRestLowercase(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

bool SupportMethods::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

int SupportMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

int SupportMethods::getInt() {
    string entry = "";
    int number = 0;

    while (true) {
        getline(cin, entry);

        stringstream myStream(entry);
        if (myStream >> number)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return number;
}

bool SupportMethods::isDateCorrect(string date){
    string year, month, day, temp;
    int Y, M, D;

    if(date.length() != 10)
        return false;

    temp = date;

    year = temp.erase(4, 6);
    Y = convertStringToInt(year);

    temp = date;
    temp.erase(0, 5);

    month = temp.erase(2, 4);
    M = convertStringToInt(month);

    temp = date;
    day = temp.erase(0, 8);
    D = convertStringToInt(day);

    if(Y < 2000 || M < 1 || M > 13 || D < 1 || D > howLongIsMonth(M, Y))
        return false;
    else
        return true;
}

bool SupportMethods::isThisLeapYear(int year){
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

int SupportMethods::howLongIsMonth(int month, int year){
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if(month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else if(isThisLeapYear(year) == true)
        return 29;
    else
        return 28;
}

int SupportMethods::convertDateFromStringToInt(string date){
    date.erase(4, 1);
    date.erase(6, 1);

    return convertStringToInt(date);
}

string SupportMethods::convertCommaToPoint(string text){
    for(long long unsigned int i = 0; i < text.length(); i++){
        if(text[i] == 44)
            text[i] = 46;
    }

    return text;
}

double SupportMethods::convertStringToDouble(string number){
    double amount = stod(number);

    return amount;
}

string SupportMethods::currentDateTime() {
    time_t now = time(0);
    struct tm  tstruct;
    char buf[80];
    tstruct = *localtime(&now);

    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

string SupportMethods::properCurrentDate(){
    SupportMethods obj;

    string time = obj.currentDateTime();

    time.erase(10,9);

    return time;
}

