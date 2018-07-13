//
// Created by micha on 7/13/2018.
//

#ifndef JOURNALENCRYPTOR_LOGIN_H
#define JOURNALENCRYPTOR_LOGIN_H

#include <map>

using namespace std;

class Login {

private:
    const string kUserDataFilePath = "JournalEncryptor/user_data.txt";

    map<string, string> user_passwords_;
    map<string, int> user_cypher_keys_;

public:
    void loadUserData();

    bool validPassword(std::string username);

    int getCypherKey(std::string username);
};

#endif //JOURNALENCRYPTOR_LOGIN_H
