//
// Created by micha on 7/17/2018.
//

#include <iostream>
#include <regex>
#include "encryptor.h"

//Referenced https://www.geeksforgeeks.org/caesar-cipher/ when writing encrypt and decrypt

bool Encryptor::encrypt(string file_path, int cipher_key) {
    if (!openInStream(file_path)) {
        return false;
    }

    string encrypted_text;
    string line;
    while (getline(in_stream, line)) {
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
    closeInStream();

    openOutStream(file_path);
    out_stream << encrypted_text << endl;
    closeOutStream();
    return true;
}

bool Encryptor::decrypt(string file_path, int cipher_key) {
    if (!openInStream(file_path)) {
        return false;
    }

    string decrypted_text;
    string line;
    while (getline(in_stream, line)) {
        string encrypted_line;
        for (int i = 0; i < line.length(); ++i) {
            if (isupper(line[i])) {
                encrypted_line += char(int(line[i]-cipher_key-65)%26 +65);
            } else if (islower(line[i])) {
                encrypted_line += char(int(line[i]-cipher_key-97)%26 +97);
            } else if (isdigit(line[i])) {
                encrypted_line += char(int(line[i]-cipher_key-48)%10 +48);
            }
        }
        decrypted_text += encrypted_line + "\n";
    }
    closeInStream();

    openOutStream(file_path);
    out_stream << decrypted_text << endl;
    closeOutStream();
    return true;
}

bool Encryptor::openInStream(string file_path) {
    //Add path to current directory, then user path
    in_stream.open("../JournalEncryptor/" + file_path);
    if (!in_stream) {
        cout << "Unable to open file " << file_path << endl;
        return false;
    }
    return true;
}

bool Encryptor::openOutStream(string file_path) {
    //Add path to current directory, then user path
    out_stream.open("../JournalEncryptor/" + file_path);
    if (!out_stream) {
        cout << "Unable to open file " << file_path << endl;
        return false;
    }
    return true;
}

bool Encryptor::closeInStream() {
    in_stream.close();
    in_stream.clear();
}

bool Encryptor::closeOutStream() {
    out_stream.close();
    out_stream.clear();
}