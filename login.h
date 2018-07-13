//
// Created by micha on 7/13/2018.
//

#ifndef JOURNALENCRYPTOR_LOGIN_H
#define JOURNALENCRYPTOR_LOGIN_H

#include <map>

class Login {

private:
    const std::string kUserDataFilePath = "user_data";

    std::map <std::string, std::string> user_passwords_;
    std::map<std::string, int> user_cypher_keys_;

public:
    void loadUserData();

    bool validPassword(std::string username);

    int getCypherKey(std::string username);
};

#endif //JOURNALENCRYPTOR_LOGIN_H
