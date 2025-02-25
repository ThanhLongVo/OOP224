/* Citation and Sources...
Final Project Milestone 1
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
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include <cstring>
#include <sstream>
#include "Status.h"
namespace sdds
{

    const int MAXIMUM_YEAR_VALUE = 2030;

    class Date
    {
        Status status;
        int Year;
        int Month;
        int Day;
        bool Format;
        bool Invalid;
        bool validate();
        int uniqueDateValue() const;

    public:
        Date();
        bool notint(bool chara = false);

        Date(int year, int month, int day);
        operator bool() const;
        const Status &state();
        Date &formatted(bool slash);
        bool operator==(const Date &right) const;
        bool operator!=(const Date &right) const;
        bool operator>=(const Date &right) const;
        bool operator<=(const Date &right) const;
        bool operator<(const Date &right) const;
        bool operator>(const Date &right) const;
        std::ostream &print(std::ostream &os) const;
        std::istream &read(std::istream &istr);
    };
    std::ostream &operator<<(std::ostream &os, const Date &dat);
    std::istream &operator>>(std::istream &is, Date &dat);
}
#endif