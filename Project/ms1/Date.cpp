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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Date.h"
#include "Utils.h"
using namespace std;
namespace sdds
{

    bool Date::validate()
    {

        bool isvalid = false;

        int cyear;

        ut.getSystemDate(&cyear);

        status.clear();

        if (Year < cyear || Year > MAXIMUM_YEAR_VALUE)
        {

            status = "Invalid year in date";

            status = 1;
        }

        else if (Month < 1 || Month > 12)
        {

            status = "Invalid month in date";

            status = 2;
        }

        else if (Day < 1 || Day > ut.daysOfMon(Month, Year))
        {

            status = "Invalid day in date";

            status = 3;
        }
        else if (Invalid == true)
        {
            status = 0;
            status = "Invalid date value";
        }

        else
        {

            isvalid = true;
        }

        return isvalid;
    }

    const Status &Date::state()
    {
        return status;
    }
    int Date::uniqueDateValue() const
    {
        return Year * 372 + Month * 31 + Day;
    }
    Date::Date()
    {
        Invalid = false;
        Format = true;
        ut.getSystemDate(&Year, &Month, &Day);
        
    }

    Date::operator bool() const
    {
        return status;
    }
    Date::Date(int year, int month, int day)
    {
        Invalid = false;
        Format = true;
        Year = year;
        Month = month;
        Day = day;
        validate();
    }

    Date &Date::formatted(bool slash)
    {
        if (slash == false)
        {
            Format = false;
        }

        return *this;
    }
    bool Date::operator==(const Date &right) const
    {
        return this->uniqueDateValue() == right.uniqueDateValue();
    }
    bool Date::operator!=(const Date &right) const
    {
        return this->uniqueDateValue() != right.uniqueDateValue();
    }
    bool Date::operator>=(const Date &right) const
    {
        return this->uniqueDateValue() >= right.uniqueDateValue();
    }
    bool Date::operator<=(const Date &right) const
    {
        return this->uniqueDateValue() <= right.uniqueDateValue();
    }
    bool Date::operator<(const Date &right) const
    {
        return this->uniqueDateValue() < right.uniqueDateValue();
    }
    bool Date::operator>(const Date &right) const
    {
        return this->uniqueDateValue() > right.uniqueDateValue();
    }
    bool notint(bool chara)
    {
        return chara == true;
    }

    std::istream &Date::read(std::istream &istr)
    {
        int number;
        int day1;
        int day2;
        int month1;
        int month2;
        int year1;
        int year2;
        istr >> number;
        if (istr)
        {
            if (number <= 9999)
            {
                day2 = number % 10;
                day1 = number / 10 % 10;
                month2 = number / 100 % 10;
                month1 = number / 1000 % 10;
                if (month1 == 0)
                {
                    Month = month2;
                }
                else
                {
                    Month = (month1 * 10) + month2;
                }
                if (day1 == 0)
                {
                    Day = day2;
                }
                else
                {
                    Day = (day1 * 10) + day2;
                }
                ut.getSystemDate(&Year);
            }
            else if (number >= 100000 && number <= 999999)
            {
                day2 = number % 10;
                day1 = number / 10 % 10;
                month2 = number / 100 % 10;
                month1 = number / 1000 % 10;
                year2 = number / 10000 % 10;
                year1 = number / 100000 % 10;

                if (year1 == 0)
                {
                    Year = 2000 + year2;
                }
                else
                {
                    Year = 2000 + ((year1 * 10) + year2);
                }
                if (month1 == 0)
                {
                    Month = month2;
                }
                else
                {
                    Month = (month1 * 10) + month2;
                }
                if (day1 == 0)
                {
                    Day = day2;
                }
                else
                {
                    Day = (day1 * 10) + day2;
                }
            }
        }
        else
        {
            Invalid = true;
        }

        if (!validate())
        {

            istr.setstate(ios::badbit);
        }
        return istr;
    }
    std::ostream &Date::print(std::ostream &os) const
    {

        if (Format == true)
        {
            os << Year;
            os << '/';
            os.fill('0');
            os.width(2);
            os << Month;
            os << '/';
            os.width(2);
            os << Day;
            os.fill(' ');
        }
        else if (Format == false)
        {
            int year = Year - 2000;
            os << year;
            os.fill('0');
            os.width(2);
            os << Month;
            os.width(2);
            os << Day;
            os.fill(' ');
        }

        return os;
    }
    std::ostream &operator<<(std::ostream &os, const Date &dat)
    {
        return dat.print(os);
    }
    std::istream &operator>>(std::istream &is, Date &dat)
    {
        return dat.read(is);
    }
}