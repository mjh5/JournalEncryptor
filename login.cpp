//
// Created by micha on 7/13/2018.
//

#include <fstream>
#include <iostream>
#include "login.h"

using namespace std;

void Login::loadUserData() {
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
        user_passwords_.insert(pair(username, password));
        user_cypher_keys_.insert(pair(username, cipher_key));
    }
}

