#include "User.h"

void User::setId(int newId){
    if(newId >= 0)
        id = newId;
}

void User::setUserName(string newUserName){
    userName = newUserName;
}

void User::setPassword(string newPassword){
    password = newPassword;
}

int User::getId(){
    return id;
}

string User::getUserName(){
    return userName;
}

string User::getPassword(){
    return password;
}
