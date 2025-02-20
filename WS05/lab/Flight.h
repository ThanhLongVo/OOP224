/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
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
// Workshop:       Workshop5-LAB
// Date:           12 Oct 2023
//==============================================

#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boeing747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {
        int m_passengers = 0;
        double m_fuel = 0.0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display() const;

        operator bool() const;
        explicit operator int() const;
        explicit operator double() const;
        operator const char* () const;
        
        bool operator~() const;
        int operator+(const Flight obj);
        friend void operator+=(int&, Flight);

        void operator=(Flight& obj);
        void operator>>(Flight& obj);
        Flight& operator+=(double);
        Flight& operator-=(double);
        Flight& operator+=(int);
        Flight& operator-=(int);

        void operator=(int);
        void operator=(double);
              
    };

}

#endif // SDDS_FLIGHT_H
