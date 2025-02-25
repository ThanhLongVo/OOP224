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
#ifndef SDDS_IPRODUCT_H_
#define SDDS_IPRODUCT_H_
namespace sdds {
    class iProduct {
    public:
        //
        virtual int readSku(std::istream& istr);
        // to reduce the quantity on hand
        virtual int operator-=(int qty);
        // to increase the quantity on hand
        virtual int operator+=(int qty);
        // returns the price of the produce
        virtual operator double()const;
        // returns if the iProduct is in a good state
        virtual operator bool()const;
        // returns the number of products needed
        virtual int qtyNeeded()const;
        // retuns the quantity on hand
        virtual int qty()const;
        // determines if the iProduct is displayed in a linear format or  descriptive format
        virtual void linear(bool isLinear);
        // saves the iProduct into a file
        virtual std::ofstream& save(std::ofstream& ofstr)const;
        // loads an iProduct from a file
        virtual std::ifstream& load(std::ifstream& ifstr);
        // displays the iProduct on the screen
        virtual std::ostream& display(std::ostream& ostr)const;
        // reads the iProduct from the console
        virtual std::istream& read(std::istream& istr);
        // return true if the sku is a match to the iProduct's sku
        virtual bool operator==(int sku)const;
        // rtrns true if the description is found in the iProduct's description
        virtual bool operator==(const char* description)const;
        virtual ~iProduct() {};
    };
    std::ostream& operator<<(std::ostream& ostr, const iProduct& I);
    std::istream& operator>>(std::istream& istr, iProduct& I);
}

#endif // !SDDS_IPRODUCT_H_virtual 