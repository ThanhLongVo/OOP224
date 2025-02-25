/* Citation and Sources...
Final Project Milestone 51
Module: iProduct
Filename: iProduct.h
Version 1.2
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release
2023/11/18  Updated for Milestone 4
2023/11/22  Updated for Milestone 51
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_IPRODUCT_H
#define SDDS_IPRODUCT_H
#include <iostream>
namespace sdds
{
   class iProduct
   {
   public:
      virtual int readSku(std::istream& istr) = 0;
      // to reduce the quantity on hand
      virtual int operator-=(int qty) = 0;
      // to increase the quantity on hand
      virtual int operator+=(int qty) = 0;
      // returns the price of the produce
      virtual operator double()const = 0;
      // returns if the iProduct is in a good state
      virtual operator bool()const = 0;
      // returns the number of products needed
      virtual int qtyNeeded()const = 0;
      // retuns the quantity on hand
      virtual int qty()const = 0;
      // determines if the iProduct is displayed in a linear format or 
      // descriptive format
      virtual void linear(bool islinear) = 0;
      // saves the iProduct into a file
      virtual std::ofstream& save(std::ofstream& ofstr)const = 0;
      // loads an iProduct from a file
      virtual std::ifstream& load(std::ifstream& ifstr) = 0;
      // displays the iProduct on the screen
      virtual std::ostream& display(std::ostream& ostr)const = 0;
      // reads the iProduct from the console
      virtual std::istream& read(std::istream& istr) = 0;
      // return true if the sku is a match to the iProduct's sku
      virtual bool operator==(int sku)const = 0;
      // rtrns true if the description is found in the iPorduct's description
      virtual bool operator==(const char* description)const = 0;
      virtual ~iProduct();

   };
   std::ostream& operator<<(std::ostream& ostr, iProduct& ip);
   std::istream& operator>>(std::istream& istr, iProduct& ip);
}
#endif