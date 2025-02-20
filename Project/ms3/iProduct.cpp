/* Citation and Sources...
Final Project Milestone 3
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#include <iostream>  
#include "iProduct.h"
namespace sdds {
    int iProduct::readSku(std::istream& istr)
    {
        int flag;
        istr >> flag;
        return flag;
    }

    int iProduct::operator-=(int qty)
    {
        return qty;
    }

    iProduct::operator double() const
    {
        return 0.0;
    }

    iProduct::operator bool() const
    {
        return false;
    }

    int iProduct::qtyNeeded() const
    {
        return 0;
    }

    int iProduct::qty() const
    {
        return 0;
    }

    void iProduct::linear(bool isLinear)
    {
        std::cout << isLinear;
    }

    std::ofstream& iProduct::save(std::ofstream& ofstr) const
    {
        return ofstr;
    }

    std::ifstream& iProduct::load(std::ifstream& ifstr)
    {
        return ifstr;
    }

    std::ostream& iProduct::display(std::ostream& ostr) const
    {
        return ostr;
    }

    std::istream& iProduct::read(std::istream& istr)
    {
        return istr;
    }

    bool iProduct::operator==(int sku) const
    {
        return false;
    }

    bool iProduct::operator==(const char* description) const
    {
        return false;
    }

    int iProduct::operator+=(int qty)
    {
        return qty;
    }

    std::ostream& operator<<(std::ostream& ostr, const iProduct& I)
    {
        return I.display(ostr);
    }

    std::istream& operator>>(std::istream& istr, iProduct& I)
    {
        return I.read(istr);
    }


}