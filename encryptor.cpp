//
// Created by micha on 7/17/2018.
//

#include <iostream>
#include <regex>
#include "encryptor.h"

//Referenced https://www.geeksforgeeks.org/caesar-cipher/ when writing encrypt and decrypt

bool Encryptor::encrypt(string file_path, int cipher_key) {
    in_steam.open(file_path);
    if (!in_steam) {
        cout << "Unable to open file " << file_path << endl;
        return false;
    }

    string encrypted_text;
    string line;
    while (getline(in_steam, line)) {
        string encrypted_line;
        for (int i = 0; i < line.length(); ++i) {
            if (isupper(line[i])) {
                encrypted_line += char(int(line[i]+cipher_key-65)%26 +65);
            } else if (islower(line[i])) {
                encrypted_line += char(int(line[i]+cipher_key-97)%26 +97);
            } else if (isdigit(line[i])) {
                encrypted_line += char(int(line[i]+cipher_key-48)%10 +48);
            }
        }
        encrypted_text += encrypted_line + "\n";
    }
}
