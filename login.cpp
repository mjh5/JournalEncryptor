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

    string test;
    data_stream >> test;
    cout << test << std::endl;
    data_stream.close();
}

