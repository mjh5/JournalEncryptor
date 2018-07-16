//
// Created by micha on 7/13/2018.
//

#include <iostream>

#include "login.h"

using namespace std;

int main() {

    bool login_flag = true;
    string username;
    string password;

    auto userLogin = new Login();
    userLogin->loadUserData();

    cout << "Welcome to Journal Encryptor! Keep your private journal entries encrypted and safe from prying eyes.\n";
    while (login_flag) {
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;

        if (userLogin->validPassword(username, password)) {
            login_flag = false;
        }
    }
};

