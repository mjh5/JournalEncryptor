//
// Created by micha on 7/13/2018.
//

#include <fstream>
#include <iostream>
#include "user_data.h"

using namespace std;

void UserData::loadUserData() {
    ifstream data_stream(kUserDataFilePath);
    if (data_stream.fail()) {
        cout << "Unable to load user login data." << std::endl;
        exit(1);
    }

    string username;
    string password;
    int cipher_key;
    while (!data_stream.eof()) {
        data_stream >> username >> password >> cipher_key;
        user_passwords_.insert(pair<string, string>(username, password));
        user_cypher_keys_.insert(pair<string, int>(username, cipher_key));
    }

    data_stream.close();
    data_stream.clear();
}

bool UserData::validPassword(string username, string password) {
    if (user_passwords_.find(username) == user_passwords_.end()) { return false; }
    string saved_password = user_passwords_.at(username);
    return saved_password == password;
}

int UserData::getCypherKey(string username) {
    if (user_cypher_keys_.find(username) == user_cypher_keys_.end()) {
        cout << "Error: No cipher key found for user " << username << endl;
        return -1;
    }
    return user_cypher_keys_.at(username);
}

