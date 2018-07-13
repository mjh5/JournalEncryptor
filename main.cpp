//
// Created by micha on 7/13/2018.
//

#include <iostream>

int main() {

    bool login_flag = true;
    std::string username;
    std::string password;

    while (login_flag) {
        std::cout
                << "Welcome to Journal Encryptor! Keep your private journal entries encrypted and safe from prying eyes.\n"
                << "Please enter your username: ";
        std::cin >> username;
        std::cout << "Please enter your password: ";
        std::cin >> password;

        login_flag = false;
    }
};

