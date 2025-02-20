/* Citation and Sources...
Final Project Milestone 4
Module: Perishable
Filename: Perishable.h
Version 1.1
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/18  Preliminary release
2023/11/22  Update for milstone 51
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include <iostream>
#include <fstream>
#include "Item.h"
#include "Date.h"
namespace sdds
{
   class Perishable : public Item
   {
      Date m_expiry;
      char* m_instruction{};
   public:
      Perishable();
      Perishable(const Perishable& P);
      Perishable& operator=(const Perishable& P);
      virtual ~Perishable();
      const Date& expiry();
      int readSku(std::istream& istr);
      std::ofstream& save(std::ofstream& ofstr)const;
      std::ifstream& load(std::ifstream& ifstr);
      std::ostream& display(std::ostream& ostr)const;
      std::istream& read(std::istream& istr);
   };
}

#endif