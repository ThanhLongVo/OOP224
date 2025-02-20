/*
Name: THANH LONG VO
Student ID: 171587223
Email: tlvo2@myseneca.ca
Section: ZDD
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include "cStrTools.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;
using namespace sdds;

namespace sdds {
    struct PhoneRecord {
        char name[51];
        char areaCode[4];
        char prefix[4];
        char number[5];
    };

    void customToLower(char* str) {
        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = tolower(str[i]);
        }
    }

    void phoneDir(const char* programTitle, const char* fileName) {
        cout << programTitle << " phone direcotry search" << endl;
        cout << "-------------------------------------------------------" << endl;

        FILE* file = fopen(fileName, "r");

        if (!file) {
            cout << fileName << " file not found!" << endl;
            cout << "Thank you for using " << programTitle << " directory." << endl;
            return;
        }

        char partialName[51];

        do {
            fseek(file, 0, SEEK_SET);

            cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
            cout << "> ";
            cin.getline(partialName, sizeof(partialName));

            if (partialName[0] == '!') {
                cout << "Thank you for using " << programTitle << " directory." << endl;
                break;
            }

            PhoneRecord record;

            while (fscanf(file, "%[^\t]\t%3s\t%3s\t%4s\n", record.name, record.areaCode, record.prefix, record.number) == 4) {
                // Convert both the name and partialName to lowercase for case-insensitive comparison
                char lowercaseName[51];
                strcpy(lowercaseName, record.name);

                // Use customToLower to convert to lowercase
                customToLower(lowercaseName);
                customToLower(partialName);

                if (strstr(lowercaseName, partialName) != nullptr) {
                    cout << record.name << ": (" << record.areaCode << ") " << record.prefix << "-" << record.number << endl;
                }
            }
        } while (true);

        fclose(file);
    }
}
