//#define _CTR_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int c;
    char new_c;
    FILE* myFile;
    FILE* encryptedFile;
    const char* path = "Text.txt";
    const char* path2 = "Encrypted.txt";
    if (fopen_s(&myFile, path, "r") != NULL)
        cout << "The file cannot be opened!";
    else {
        if (fopen_s(&encryptedFile, path2, "w") != NULL)
            cout << "This file could not be created!";
        else {
            while (!feof(myFile)) {
                c = fgetc(myFile);
                if (c >= 221 && c <= 223)
                    new_c = 191 + (c + 3 - 223);
                else if (c >= 253 && c <= 255)
                    new_c = 223 + (c + 3 - 255);
                else if ((c >= 192 && c <= 220) || (c >= 224 && c <= 252))
                    new_c = c + 3;
                else
                    new_c = c;
                fprintf(encryptedFile, "%c", new_c);
            }
        }
    }

    if (fclose(myFile) == EOF)
        cout << "\nThis file could not be closed!";
    else
        cout << "\nThis file is closed!";
    return 0;
}
