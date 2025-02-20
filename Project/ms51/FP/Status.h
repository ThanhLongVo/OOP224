/* Citation and Sources...
Final Project Milestone 4
Module: Status
Filename: Status.h
Version 1.2
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release
2023/11/20  Update for Milestone 4
2023/11/21  Update for Milestone 5
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
namespace sdds
{
   class Status
   {
      char* m_errDesc{};
      int m_errCode;
   public:
      Status(const char* c = nullptr);
      Status(const Status& s);
      Status& operator=(const Status& s);
      ~Status();
      Status& operator=(int num);
      Status& operator=(const char* str);
      operator int()const;
      operator const char* ()const;
      operator bool()const;
      Status& clear();
   };
   std::ostream& operator<< (std::ostream& ostr, const Status& s);
}
#endif // SDDS_STATUS_H