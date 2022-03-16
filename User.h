#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
    int id;
    string username, password, name, surname;

public:
    void setId(int newId);
    void setUsername(string newUsername);
    void setPassword(string newPassword);
    void setName(string newName);
    void setSurname(string newSurname);

    int getId();
    string getUsername();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
