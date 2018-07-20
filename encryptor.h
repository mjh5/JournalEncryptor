//
// Created by micha on 7/17/2018.
//

#ifndef JOURNALENCRYPTOR_ENCRYPTOR_H
#define JOURNALENCRYPTOR_ENCRYPTOR_H

#include <fstream>

using namespace std;

class Encryptor {

private:
    ifstream in_steam;
    ofstream out_stream;

public:
    bool encrypt(string file_path, int cipher_key);

    bool decrypt(string file_path, int cipher_key);

    bool readFile(string file_path);

    bool openOutStream(string file_path);

};

#endif //JOURNALENCRYPTOR_ENCRYPTOR_H
