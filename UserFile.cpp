#include "UserFile.h"

void UserFile::inputNewUserToFile(User user) {
    CMarkup file;
    bool fileExists = file.Load(getFileName());

    if (!fileExists) {
        file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        file.AddElem("Users");
    }

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

    file.Save(getFileName());
}

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

    return users;
}

void UserFile::saveAllUsersToFile(vector <User> &users) {
    CMarkup file;

    file.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
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

    file.Save(getFileName());
}

