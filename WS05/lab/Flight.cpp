/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
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

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;

namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0.0;
        strcpy(m_title, "EmptyPlane");
    }

    Flight::Flight() {
        emptyPlane();
    }

    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boeing747Capacity && fuel >= 0 && fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }

    std::ostream& Flight::display() const {
        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    Flight::operator bool() const
    {
        if (m_passengers > 0 && m_fuel >= 600 * m_passengers) //The plane needs a minimum of 600 Liters of fuel for each passenger.
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Flight::operator int() const {
        return m_passengers;
    }

    Flight::operator double() const {
        return m_fuel;
    }

    Flight::operator const char* () const {
        return m_title;
    }

    bool Flight::operator ~() const
    {
        if (m_passengers == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int Flight::operator+(const Flight obj)
    {
        if (*this && obj)
        {
            return int(*this) + int(obj);
        }
        else
        {
            return 0;
        }
    }
    void operator+=(int& x, Flight obj)
    {
        x += int(obj);

    }

    void Flight::operator=(Flight& obj)
    {
        m_passengers = obj.m_passengers;
        m_fuel = obj.m_fuel;
        strcpy(m_title, obj.m_title);
        obj.emptyPlane();
    }

    void Flight::operator>>(Flight& obj)
    {
        if (int(obj) + int(*this) <= Boeing747Capacity)
        {
            this->m_passengers = 0;
            obj.m_passengers = int(obj) + int(*this);

        }
        else
        {
            this->m_passengers = this->m_passengers - (Boeing747Capacity - int(obj));
            obj.m_passengers = Boeing747Capacity;
        }
    }

    Flight& Flight::operator+=(double fuel)
    {
        if (double(*this) + fuel <= FuelTankCapacity)
        {
            this->m_fuel += fuel;
        }
        return *this;
    }

    Flight& Flight::operator-=(double fuel)
    {
        if (double(*this) - fuel >= 0)
        {
            this->m_fuel -= fuel;
        }
        return *this;
    }

    Flight& Flight::operator+=(int pass)
    {
        if (int(*this) + pass <= Boeing747Capacity)
        {
            this->m_passengers += pass;
        }
        return *this;
    }

    Flight& Flight::operator-=(int pass)
    {
        if (int(*this) - pass >= 0)
        {
            this->m_passengers -= pass;
        }
        return *this;
    }

    void Flight::operator=(int pass)
    {
        if (pass > 0 && pass <= Boeing747Capacity) {
            this->m_passengers = pass;
        }
    }

    void Flight::operator=(double fuel)
    {
        if (fuel >= 0 && fuel <= FuelTankCapacity) {
            this->m_fuel = fuel;
        }
    }
}