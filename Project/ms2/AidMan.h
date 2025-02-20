/* Citation and Sources...
Final Project Milestone 2
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/15  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
namespace sdds
{
    class AidMan {
    private:
        char* fileName;
        Menu mainMenu;

    public:
        AidMan(const char* filename);
        ~AidMan();
        void run();
    };
}
#endif // !SDDS_AIDMAN_H