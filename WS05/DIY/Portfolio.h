/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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
#ifndef SDDS_PORTFOLIO_H
#define SDDS_PORTFOLIO_H
using namespace std;
namespace sdds {
    class Portfolio {
        double m_value;
        char m_stock[16];
        char m_type;

    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);

        // Member function declarations
        void dispPortfolio() const;
        ostream& display() const;

        operator double() const;
        operator const char* () const;
        operator char() const;
        operator bool() const;

        Portfolio& operator+=(double value);
        Portfolio& operator-=(double value);
        bool operator~() const;
        Portfolio& operator<<(Portfolio& other);
        Portfolio& operator>>(Portfolio& other);

        friend double operator+(const Portfolio& left, const Portfolio& right);
        friend Portfolio& operator+=(double& left, const Portfolio& right);

    private:
        void emptyPortfolio();
    };
}

#endif // SDDS_PORTFOLIO_H


