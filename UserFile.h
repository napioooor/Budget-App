#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "SupportMethods.h"
#include "TextFile.h"
#include "Markup.h"

using namespace std;

class UserFile : public TextFile{
    //string changeUserDataToLineSeparetedWithVerticalLines(User user);
    //User getUserData(string userDataSeparetedWithVerticalLines);

public:
    UserFile(string userFileName) : TextFile(userFileName) {};
    void inputNewUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif
