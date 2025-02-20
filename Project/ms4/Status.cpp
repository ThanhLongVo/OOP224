/* Citation and Sources...
Final Project Milestone 4
Module: Status
Filename: Status.cpp
Version 1.1
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release
2023/11/18  Update for Milestone 4
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
#include <string>
#include <ctime>
#include "Status.h"
using namespace std;
namespace sdds
{
    Status::Status(char* str, int code)
    {
        Codigo = code;

        if (str != NULL)
        {
            Description = new char[strlen(str) + 1];
            strcpy(Description, str);
        }
        else
        {
            Description = NULL;
        }
    }

    Status::Status(const Status& status)
    {
        Codigo = status.Codigo;

        if (!status)
        {
            Description = new char[strlen(status.Description) + 1];
            strcpy(Description, status.Description);
        }
        else
        {
            Description = NULL;
        }
    }

    Status& Status::operator=(const Status& status)
    {

        delete[] Description;
        Description = nullptr;

        Codigo = status.Codigo;

        if (status)
        {
            Description = new char[strlen(status.Description) + 1];
            strcpy(Description, status.Description);
        }
        else
        {
            Description = NULL;
        }

        return *this;
    }

    Status::~Status()
    {
        delete[] Description;
        Description = nullptr;
    }

    Status& Status::operator=(const char* str)
    {
        delete[] Description;
        Description = nullptr;
        if (str == nullptr) return *this;
        Description = new char[strlen(str) + 1];
        strcpy(Description, str);
        return *this;
    }

    Status& Status::operator=(const int code)
    {
        Codigo = code;
        return *this;
    }

    Status::operator bool() const
    {
        if (Description != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Status::operator int() const
    {
        return Codigo;
    }

    Status::operator char* () const
    {
        return Description;
    }

    ostream& operator<<(ostream& os, const Status& status)
    {
        if (!status)
        {
            if (status.Codigo != 0)
                os << "ERR#" << status.Codigo << ": ";
            os << status.Description;
        }
        return os;
    }

    Status& Status::clear()
    {
        delete[] Description;
        Description = nullptr;
        Codigo = 0;
        return *this;
    }
}

