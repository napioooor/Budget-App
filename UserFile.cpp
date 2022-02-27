#include "UserFile.h"

void UserFile::inputNewUserToFile(User user) {
    string userDataLine = "";
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good() == true) {
        userDataLine = changeUserDataToLineSeparetedWithVerticalLines(user);

        if (SupportMethods::isFileEmpty(textFile) == true) {
            textFile << userDataLine;
        } else {
            textFile << endl << userDataLine ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;
    textFile.close();
}

string UserFile::changeUserDataToLineSeparetedWithVerticalLines(User user) {
    string userDataLine = "";

    userDataLine += SupportMethods::convertIntToString(user.getId())+ '|';
    userDataLine += user.getUserName() + '|';
    userDataLine += user.getPassword() + '|';
    return userDataLine;
}

vector <User> UserFile::loadUsersFromFile() {
    User user;
    vector <User> users;
    string userDataSeparetedWithVerticalLines = "";
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, userDataSeparetedWithVerticalLines)) {
            user = getUserData(userDataSeparetedWithVerticalLines);
            users.push_back(user);
        }
    }
    textFile.close();

    return users;
}

User UserFile::getUserData(string userDataSeparetedWithVerticalLines) {
    User user;
    string singleUserData = "";
    int singleUserDataNumber = 1;

    for (int charPosition = 0; charPosition < userDataSeparetedWithVerticalLines.length(); charPosition++) {
        if (userDataSeparetedWithVerticalLines[charPosition] != '|') {
            singleUserData += userDataSeparetedWithVerticalLines[charPosition];
        } else {
            switch(singleUserDataNumber) {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setUserName(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            singleUserDataNumber++;
        }
    }
    return user;
}

void UserFile::saveAllUsersToFile(vector <User> &users) {
    fstream textFile;
    string userDataLine = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(getFileName().c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            userDataLine = changeUserDataToLineSeparetedWithVerticalLines(*itr);

            if (itr == itrEnd) {
                textFile << userDataLine;
            } else {
                textFile << userDataLine << endl;
            }
            userDataLine = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << getFileName() << endl;
    }
    textFile.close();
}

