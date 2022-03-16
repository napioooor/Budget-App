#ifndef USERMENAGER_H
#define USERMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserMenager{
    int loggedInUserId;
    UserFile userFile;

    vector <User> users;

    User inputNewUserData();
    int getNewUserId();
    bool doesUsernameExist(string userName);

public:
    UserMenager(string userFileName, int id) : userFile(userFileName) {
    loggedInUserId = id;
    users = userFile.loadUsersFromFile();
    };
    void registerNewUser();
    int userLogIn();
    void changeLoggedInUsersPassword();

    int getLoggedInUserId();
    void setLoggedInUserId(int newId);
};

#endif
