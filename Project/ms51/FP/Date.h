/* Citation and Sources...
Final Project Milestone 51
Module: Date
Filename: Date.h
Version 1.2
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/09  Preliminary release
2023/11/18  Edit for Milestone 4
2023/11/23  Edit for Milestone 51
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
namespace sdds
{
   class Date
   {
      const int m_maxyear = 2030;
      int m_year;
      int m_month;
      int m_day;
      Status m_state;
      bool m_format = true;
      bool validate();
      int uniqueDateVal();
   public:
      Date(const int year = 0, const int month = 0, const int date = 0);
      Date& operator=(const Date& d);
      bool operator==(Date& d);
      bool operator!=(Date& d);
      bool operator<(Date& d);
      bool operator>(Date& d);
      bool operator<=(Date& d);
      bool operator>=(Date& d);
      const Status& state()const;
      Date& formatted(bool set);
      operator bool()const;
      std::ostream& write(std::ostream& ostr) const;
      std::istream& read(std::istream& istr);
   };
   std::ostream& operator<<(std::ostream& ostr, const Date& d);
   std::istream& operator>>(std::istream& istr, Date& d);

}
#endif // SDDS_DATE_H