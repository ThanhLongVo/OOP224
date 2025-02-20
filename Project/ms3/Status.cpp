/* Citation and Sources...
Final Project Milestone 3
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release

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
#include<iostream>
#include<cstring>
#include"Status.h"
using namespace std;
namespace sdds
{
    Status::Status(const char* desc)
    {
        if (desc != nullptr) {
            delete[] Description;
            Description = new char(strlen(desc) + 1);
            strcpy(Description, desc);
        }
        else {
            Description = nullptr;
        }
        Codigo = 0;
    }

    Status::Status(const Status& S)
    {
        if (S.Description != nullptr) {
            delete[] Description;
            Description = new char[strlen(S.Description) + 1];
            strcpy(Description, S.Description);
            Codigo = S.Codigo;
        }
        else {
            Description = nullptr;
        }
    }

    Status& Status::operator=(const Status& S)
    {
        if (this != &S) {
            delete[] Description;
            Description = nullptr;
            Description = new char[strlen(S.Description) + 1];
            strcpy(Description, S.Description);
            Codigo = S.Codigo;
        }
        return *this;
    }

    Status& Status::operator=(int statusCode)
    {
        Codigo = statusCode;
        return *this;
    }

    Status& Status::operator=(const char* desc)
    {
        if (desc != nullptr) {
            delete[] Description;
            Description = nullptr;
            Description = new char[strlen(desc) + 1];
            strcpy(Description, desc);
        }
        else {
            Description = nullptr;
        }

        return *this;
    }

    Status::~Status()
    {
        delete[] Description;
        Description = nullptr;
    }

    Status::operator int() const
    {
        return Codigo;
    }

    Status::operator const char* () const
    {
        return Description;
    }

    Status::operator bool() const
    {
        return Description == nullptr;
    }

    Status& Status::clear()
    {
        delete[] Description;
        Description = nullptr;
        Codigo = 0;
        return *this;
    }

    ostream& Status::display(ostream& ostr) const
    {
        if (Codigo != 0) {

            ostr << "ERR#" << Codigo << ": " << Description;

        }
        else {

            ostr << Description;

        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Status& S) {
        if (S.operator bool() == false) {
            S.display(ostr);
        }
        return ostr;
    }




}