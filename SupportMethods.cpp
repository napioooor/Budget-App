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
