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
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include <cstring>
namespace sdds
{
    class Status
    {
        char *Description{};
        int Codigo; // Spanish word for code is codigo
    public:
        Status(const char *description = nullptr);
        Status(const Status &stat);
        Status &operator=(const char *description);
        Status &operator=(int code);
        operator int() const;
        operator const char *() const;
        operator bool() const;
        Status &clear();
        std::ostream &print(std::ostream &ostr) const;
        ~Status();
    };
    std::ostream &operator<<(std::ostream &os, const Status &stat);

}
#endif