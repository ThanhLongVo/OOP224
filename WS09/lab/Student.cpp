//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop9_LAB
// Date:           22 Nov 2023
// Reason:         Primary release
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
    Student::Student() : m_name(nullptr), m_age(0) {}

    Student::Student(const char* name, int age) : m_age(age) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    Student::Student(const Student& other) : m_age(other.m_age) {
        m_name = new char[strlen(other.m_name) + 1];
        strcpy(m_name, other.m_name);
    }

    Student& Student::operator=(const Student& other) {
        if (this != &other) {
            delete[] m_name;
            m_age = other.m_age;
            m_name = new char[strlen(other.m_name) + 1];
            strcpy(m_name, other.m_name);
        }
        return *this;
    }

    Student::~Student() {
        delete[] m_name;
    }

    void Student::display() const {
        if (m_name != nullptr) {
            cout << "Name: " << m_name << endl;
        }
        cout << "Age: " << m_age << endl;
    }
}
