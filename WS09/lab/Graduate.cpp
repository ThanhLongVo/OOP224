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
#include "Graduate.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
namespace sdds {
    Graduate::Graduate() : Student(), m_supervisor(nullptr), m_thesisTitle(nullptr) {}

    Graduate::Graduate(const char* name, int age, const char* thesisTitle, const char* supervisor)
        : Student(name, age) {
        m_thesisTitle = new char[strlen(thesisTitle) + 1];
        strcpy(m_thesisTitle, thesisTitle);
        m_supervisor = new char[strlen(supervisor) + 1];
        strcpy(m_supervisor, supervisor);
    }

    Graduate::Graduate(const Graduate& other) : Student(other) {
        m_thesisTitle = new char[strlen(other.m_thesisTitle) + 1];
        strcpy(m_thesisTitle, other.m_thesisTitle);
        m_supervisor = new char[strlen(other.m_supervisor) + 1];
        strcpy(m_supervisor, other.m_supervisor);
    }

    Graduate& Graduate::operator=(const Graduate& other) {
        if (this != &other) {
            Student::operator=(other);
            delete[] m_thesisTitle;
            delete[] m_supervisor;
            m_thesisTitle = new char[strlen(other.m_thesisTitle) + 1];
            strcpy(m_thesisTitle, other.m_thesisTitle);
            m_supervisor = new char[strlen(other.m_supervisor) + 1];
            strcpy(m_supervisor, other.m_supervisor);
        }
        return *this;
    }

    Graduate::~Graduate() {
        delete[] m_thesisTitle;
        delete[] m_supervisor;
    }


    void Graduate::display() const {
        Student::display();
        if (m_thesisTitle != nullptr) {
            cout << "Thesis Title: " << m_thesisTitle << endl;
        }
        if (m_supervisor != nullptr) {
            cout << "Supervisor: " << m_supervisor << endl;
        }
        cout << "---------------------------------------------" << endl;
    }
}
