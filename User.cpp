#include "User.h"

void User::setId(int newId){
    if(newId >= 0)
        id = newId;
}

void User::setUsername(string newUsername){
    username = newUsername;
}

void User::setPassword(string newPassword){
    password = newPassword;
}

void User::setName(string newName){
    name = newName;
}

void User::setSurname(string newSurname){
    surname = newSurname;
}

int User::getId(){
    return id;
}

string User::getUsername(){
    return username;
}

string User::getPassword(){
    return password;
}

string User::getName(){
    return name;
}

string User::getSurname(){
    return surname;
}
