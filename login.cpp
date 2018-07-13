//
// Created by micha on 7/13/2018.
//

#include <fstream>
#include <iostream>
#include "login.h"

using namespace std;

void Login::loadUserData() {
    ifstream data_stream;
    data_stream.open("JournalEncryptor/user_data.txt");

    if (data_stream.is_open()) {
        string test;
        data_stream >> test;

        cout << test << std::endl;
    } else {
        cout << "stream not open" << std::endl;
    }

    data_stream.close();
}

