/* Citation and Sources...
Final Project Milestone 51
Module: iProduct
Filename: iProduct.cpp
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
#include <iostream>
#include "iProduct.h"
namespace sdds
{
   std::ostream& operator<<(std::ostream& ostr, iProduct& ip)
   {
      ip.display(ostr);
      return ostr;
   }
   std::istream& operator>>(std::istream& istr, iProduct& ip)
   {
      ip.read(istr);
      return istr;
   }
   iProduct::~iProduct() 
   {

   }
}