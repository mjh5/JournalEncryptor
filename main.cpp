//
// Created by micha on 7/13/2018.
//

#include <iostream>

#include "user_data.h"
#include "encryptor.h"

using namespace std;

int main() {

    bool login_flag = true;
    string username;
    string password;

    auto userLogin = new UserData();
    userLogin->loadUserData();

    cout << "Welcome to Journal Encryptor! Keep your private journal entries encrypted and safe from prying eyes.\n";
    while (login_flag) {
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;

        if (userLogin->validPassword(username, password)) {
            login_flag = false;
        } else {
            cout << "Invalid username and password. Please try again." << endl;
        }
    }

    auto encryptor = new Encryptor();

    cout << "Welcome " << username << "!";
    int user_input;
    do {
        cout << "\nPlease select a command."
             << "\n1. Encrypt"
             << "\n2. Decrypt"
             << "\n3. Exit" << endl;
        cin >> user_input;

        switch (user_input) {
            string file_path;
            case 1:
                //Encryption prompt
                cout << "Please enter the file to encrypt: ";
                cin >> file_path;
                encryptor->encrypt(file_path, userLogin->getCypherKey(username));
                break;
            case 2:
                //Decryption prompt
                break;
            case 3:
                cout << "Thank you for using Journal Encryptor! Have a nice day!";
                break;
            default:
                cout << "Invalid command. Please try again." << endl;
        }
    } while (user_input != 3);
};

