/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/
//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop5-DIY
// Date:           14 Oct 2023
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Portfolio.h"

using namespace std;
namespace sdds {
    
    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }

    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio(); 
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }

    ostream& Portfolio::display() const {
        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();
        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return std::cout;
    }

    Portfolio::operator double() const {
        return m_value;
    }

    Portfolio::operator const char* () const {
        return m_stock;
    }

    Portfolio::operator char() const {
        return m_type;
    }

    Portfolio::operator bool() const {
        return (m_type == 'V' || m_type == 'G' || m_type == 'I');
    }

    Portfolio& Portfolio::operator+=(double value) {
        if (*this && value >= 0) {
            m_value += value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator-=(double value) {
        if (*this && value >= 0) {
            m_value -= value;
            if (m_value < 0) {
                m_value = 0;
            }
        }
        return *this;
    }

    bool Portfolio::operator~() const {
        return (m_value < 0);
    }

    Portfolio& Portfolio::operator<<(Portfolio& other) {
        if (this != &other && *this && other) {
            m_value += other.m_value;
            other.emptyPortfolio();
        }
        return *this;
    }

    Portfolio& Portfolio::operator>>(Portfolio& other) {
        if (this != &other && *this && other) {
            other.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    double operator+(const Portfolio& left, const Portfolio& right) {
        if (left && right) {
            return left.m_value + right.m_value;
        }
        return 0;
    }

    Portfolio& operator+=(double& left, const Portfolio& right) {
        if (right) {
            left += right.m_value;
        }
        return const_cast<Portfolio&>(right);
    }    
}
