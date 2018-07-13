//
// Created by micha on 7/13/2018.
//

#include <fstream>
#include <iostream>
#include "login.h"

void Login::loadUserData() {
    std::fstream data_stream;
    data_stream.open(kUserDataFilePath);

    std::string test;
    data_stream >> test;

    std::cout << test;
}

