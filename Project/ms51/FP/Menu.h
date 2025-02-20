/* Citation and Sources...
Final Project Milestone 51
Module: Menu
Filename: Menu.h
Version 1.1
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/15  Preliminary release
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds {
   class Menu {
      char* m_options{};
      unsigned int m_numOptions;
   public:
      Menu();
      Menu(unsigned int numOptions, const char* options);
      Menu(const Menu& M) = delete;
      Menu& operator=(const Menu& M) = delete;
      Menu& set(unsigned int numOptions, const char* options);
      virtual ~Menu();
      unsigned int run() const;
   };
}

#endif