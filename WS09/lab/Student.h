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
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H
#include <string>
using namespace std;
namespace sdds {
    class Student {
        char* m_name;
        int m_age;

    public:
        Student();
        Student(const char* name, int age);
        Student(const Student& other);
        Student& operator=(const Student& other);
        virtual ~Student();

        void display() const;
    };
}

#endif // SDDS_STUDENT_H
