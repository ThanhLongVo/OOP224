/* Citation and Sources...
Final Project Milestone 2
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/09  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <string.h>
#include "Utils.h"
using namespace std;
namespace sdds {
    Utils ut;
    void Utils::testMode(bool testmode) {
        Test_Mode = testmode;
    }
    void Utils::getSystemDate(int* year, int* mon, int* day) {
        if (Test_Mode) {
            if (day) *day = sdds_Test_Day;
            if (mon) *mon = sdds_Test_Month;
            if (year) *year = sdds_Test_Year;
        }
        else {
            time_t t = std::time(NULL);
            tm lt = *localtime(&t);
            if (day) *day = lt.tm_mday;
            if (mon) *mon = lt.tm_mon + 1;
            if (year) *year = lt.tm_year + 1900;
        }
    }
    int Utils::daysOfMon(int month, int year)const {
        int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
        int mon = (month >= 1 && month <= 12 ? month : 13) - 1;
        return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
    }
    void Utils::alocpy(char*& destination, const char* source)
    {
        if (destination != nullptr)
        {
            delete[] destination;
            destination = nullptr;
        }

        if (source != NULL && strcmp(source, "") != 0)
        {
            destination = new char[strlen(source) + 1];
            strcpy(destination, source);
        }
    }
    int Utils::getint(const char* prompt)
    {
        int n;
        if (prompt != NULL && strcmp(prompt, "") != 0)
            cout << prompt;

        while (true)
        {
            cin >> n;
            if (cin.fail())
            {
                cout << "Invalid Integer, retry: ";
                cin.clear();
            }
            else
                return n;
        }
    }
    int Utils::getint(int min, int max, const char* prompt, const char* errMes)
    {
        int n = getint(prompt);
        while (true)
        {
            if (n >= min && n <= max)
                return n;
            else
            {
                if (errMes != NULL && strcmp(errMes, "") != 0)
                    cout << errMes << ", retry: ";
                else
                    cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
            }
        }
    }
}