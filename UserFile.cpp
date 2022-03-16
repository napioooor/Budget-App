#include "UserFile.h"

void UserFile::inputNewUserToFile(User user) {
    CMarkup file;

    if(file.Load(getFileName()) == true){
        file.FindElem();
        file.IntoElem();
        file.AddElem("User");
        file.IntoElem();
        file.AddElem("ID", user.getId());
        file.AddElem("Username", user.getUsername());
        file.AddElem("Password", user.getPassword());
        file.AddElem("Name", user.getName());
        file.AddElem("Surname", user.getSurname());
        file.OutOfElem();
    }
    else {
        file.AddElem("Users");
        file.IntoElem();
        file.AddElem("User");
        file.IntoElem();
        file.AddElem("ID", user.getId());
        file.AddElem("Username", user.getUsername());
        file.AddElem("Password", user.getPassword());
        file.AddElem("Name", user.getName());
        file.AddElem("Surname", user.getSurname());
        file.OutOfElem();
    }

    file.Save("users.xml");
    /*string userDataLine = "";
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
    textFile.close();*/
}

/*string UserFile::changeUserDataToLineSeparetedWithVerticalLines(User user) {
    string userDataLine = "";

    userDataLine += SupportMethods::convertIntToString(user.getId())+ '|';
    userDataLine += user.getUserName() + '|';
    userDataLine += user.getPassword() + '|';
    return userDataLine;
}*/

vector <User> UserFile::loadUsersFromFile() {
    vector <User> users;
    User user;
    CMarkup file;

    file.Load(getFileName());
    file.FindElem();
    file.IntoElem();
    while(file.FindElem("User")) {
        file.IntoElem();
        file.FindElem("ID");
        user.setId(atoi( MCD_2PCSZ(file.GetData())));
        file.FindElem("Username");
        user.setUsername(file.GetData());
        file.FindElem("Password");
        user.setPassword(file.GetData());
        file.FindElem("Name");
        user.setName(file.GetData());
        file.FindElem("Surname");
        user.setSurname(file.GetData());
        file.OutOfElem();
        users.push_back(user);
    }

    /*string userDataSeparetedWithVerticalLines = "";
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, userDataSeparetedWithVerticalLines)) {
            user = getUserData(userDataSeparetedWithVerticalLines);
            users.push_back(user);
        }
    }
    textFile.close();*/

    return users;
}

/*User UserFile::getUserData(string userDataSeparetedWithVerticalLines) {
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
}*/

void UserFile::saveAllUsersToFile(vector <User> &users) {
    CMarkup file;

    file.AddElem("Users");
    file.IntoElem();

    for (int number = 0; number < users.size(); number++) {
        file.AddElem("User");
        file.IntoElem();
        file.AddElem("ID", users[number].getId());
        file.AddElem("Username", users[number].getUsername());
        file.AddElem("Password", users[number].getPassword());
        file.AddElem("Name", users[number].getName());
        file.AddElem("Surname", users[number].getSurname());
        file.OutOfElem();
    }

    file.Save("users.xml");
    /*fstream textFile;
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
    textFile.close();*/
}

