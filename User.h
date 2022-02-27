#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
    int id;
    string userName, password;

public:
    void setId(int newId);
    void setUserName(string newUserName);
    void setPassword(string newPassword);

    int getId();
    string getUserName();
    string getPassword();
};

#endif
