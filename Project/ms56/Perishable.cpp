/* Citation and Sources...
Final Project Milestone 56
Module: Perishable
Filename: Perishable.cpp
Version 1.1
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/18  Preliminary release
2023/11/22  Update for milestone 51 
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
#include <fstream>
#include "Perishable.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
   Perishable::Perishable() : Item()
   {

   }

   Perishable::Perishable(const Perishable& P)
   {
      operator=(P);
   }

   Perishable& Perishable::operator=(const Perishable& P)
   {
      if (this != &P)
      {
         Item:: operator=(P);
         m_expiry = P.m_expiry;
         ut.alocpy(m_instruction, P.m_instruction);
         if (m_instruction == nullptr)
         {
            m_state = "Empty";
         }
      }
      return *this;
   }

   Perishable::~Perishable()
   {
      delete[] m_instruction;
   }

   const Date& Perishable::expiry()
   {
      return m_expiry;
   }

   int Perishable::readSku(std::istream& istr)
   {
      return ut.getint(10000, 39999, "SKU: ");
   }

   std::ofstream& Perishable::save(std::ofstream& ofstr) const
   {
      Date D;
      if (*this)
      {
         //it will call the save of the Base class.
         Item::save(ofstr);
         ofstr << "\t";
         // check and write m_instruction if any.
         if (m_instruction && m_instruction[0] != '\0') {
             ofstr << m_instruction; // Write m_instruction if any.
             ofstr << "\t";
         }
         else {
             ofstr << "\t";
         }
         
         // write m_expiry if any, then insert 1 tab. if there is no m_expiry, end the line.
         D = m_expiry;
         if (m_expiry) {
            
             D.formatted(false);
             ofstr << D;
         }
         // If there are no m_instruction and m_expiry, end the line.
         if (!(m_instruction && m_instruction[0] != '\0') && !m_expiry) {
             
         }
         
      }
      return ofstr;
   }
   
   std::ifstream& Perishable::load(std::ifstream& ifstr)
   {
      char temp[1000];
      Item::load(ifstr);
      ifstr.getline(temp, 1000, '\t');
      ut.alocpy(m_instruction, temp);
      m_expiry.Date::read(ifstr);
      ifstr.clear();
      ifstr.ignore(1000, '\n');
      if (ifstr.fail() || !m_state)
      {
         m_state = "Input file stream read (perishable) failed!";
         ifstr.setstate(ios::badbit);
      }
      return ifstr;
   }
   std::ostream& Perishable::display(std::ostream& ostr) const
   {
      if (!*this)
         ostr << m_state;
      else if (linear())
      {
         Item::display(ostr);
         if (m_instruction && m_instruction[0] != '\0')
            ostr << "*";
         else
            ostr << " ";
         ostr << m_expiry;
      }
      else if (!linear())
      {
         ostr << "Perishable ";
         Item::display(ostr);
         ostr << "Expiry date: ";
         ostr << m_expiry;
         if (m_instruction && m_instruction[0] != '\0')
         {
            ostr << endl << "Handling Instructions: ";
            ostr << m_instruction;
         }
         ostr << "\n";
      }
      return ostr;
   }
   std::istream& Perishable::read(std::istream& istr)
   {
      char temp[1000];
      istr.clear();
      Item::read(istr);
      delete[] m_instruction;
      m_instruction = nullptr;
      cout << "Expiry date (YYMMDD): ";
      m_expiry.Date::read(istr);
      istr.ignore(1000, '\n');
      cout << "Handling Instructions, ENTER to skip: ";
      if (istr.peek() != '\n')
      {
         istr.getline(temp, 1000, '\n');
         ut.alocpy(m_instruction, temp);
      }
      if (!istr)
      {
         m_state = "Perishable console date entry failed!";
      }
      return istr;
   }
}