/* Citation and Sources...
Final Project Milestone 1
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/09  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H
#include <iostream>
#include <cstring>
namespace sdds
{
   // Testing date values for application testing and debugging
   // these values must not change at submission time.
   const int sdds_Test_Year = 2023;
   const int sdds_Test_Month = 12;
   const int sdds_Test_Day = 9;
   class Utils
   {
      bool Test_Mode = false;

   public:
      // this function will be used to get the current system date or the test date if m_testMode is true
      void getSystemDate(int *year = nullptr, int *mon = nullptr, int *day = nullptr);
      // this function will return the number of days in a month based on the year
      // 1<=mon<=12  year: four digit number (example: 2021)
      int daysOfMon(int mon, int year) const;
      // Puts the system date in test mode, where getSystemDate() function will return 2023/12/09
      // or whatever the three constant test dates are set to
      void testMode(bool testmode = true);
      void alocpy(char *&destination, const char *source);
      int getint(const char *prompt = nullptr);
      int getint(int min, int max, const char *prompt = nullptr, const char *errMes = nullptr);
   };
   extern Utils ut; // provides global access to the ut instance in the Utils.cpp file
}
#endif