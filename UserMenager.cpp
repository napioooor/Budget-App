#include "UserMenager.h"

void UserMenager::registerNewUser() {
    User user = inputNewUserData();

    users.push_back(user);
    userFile.inputNewUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserMenager::inputNewUserData() {
    User user;

    user.setId(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setUserName(SupportMethods::inputLine());
    } while (doesUserNameExist(user.getUserName()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(SupportMethods::inputLine());

    return user;
}

int UserMenager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserMenager::doesUserNameExist(string userName) {
    for(int i = 0; i < users.size(); i++) {
        if(users[i].getUserName() == userName) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserMenager::setLoggedInUserId(int newId){
    loggedInUserId = newId;
}

int UserMenager::getLoggedInUserId(){
    return loggedInUserId;
}

int UserMenager::userLogIn(){
    string userName = "", password = "";

    cout << endl << "Podaj login: ";
    userName = SupportMethods::inputLine();

    for(int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserName() == userName)
        {
            for (int numberOfTries = 3; numberOfTries > 0; numberOfTries--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfTries << ": ";
                password = SupportMethods::inputLine();

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return users[i].getId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UserMenager::changeLoggedInUsersPassword() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = SupportMethods::inputLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == loggedInUserId) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userFile.saveAllUsersToFile(users);
}
