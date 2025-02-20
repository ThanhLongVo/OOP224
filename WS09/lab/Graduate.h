//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop9_LAB
// Date:           22 Nov 2023
// Reason:         Primary release
//==============================================
#pragma once
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"
using namespace std;
namespace sdds {
    class Graduate : public Student {
        char* m_supervisor;
        char* m_thesisTitle;

    public:
        Graduate();
        Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor);
        Graduate(const Graduate& other);
        Graduate& operator=(const Graduate& other);
        ~Graduate();

        void display() const;
    };
}

#endif // SDDS_GRADUATE_H
