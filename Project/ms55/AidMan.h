/* Citation and Sources...
Final Project Milestone 54
Module: AidMan
Filename: AidMan.h
Version 1.4
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/15  Preliminary release
2023/11/22  Update for milestone 51
2023/11/24  Update for milestone 52
2023/11/26  Update for milestone 53
2023/11/28  Update for milestone 54
2023/11/29  Update for milestone 55 (add sortItem())
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/

#ifndef SDDS_AidMan_H
#define SDDS_AidMan_H
#include "Menu.h"
#include "iProduct.h"
namespace sdds
{
   const int sdds_max_num_items = 100;
   class AidMan
   {
      char* m_fileName;
      Menu m_mainMenu;
      unsigned int menu() const;
      iProduct* m_iproduct[sdds_max_num_items]{};
      int m_numOfIproduct;
      void listItem();
      void addItem();
      void removeItem();
      void updateItem();
      void sortItem();
      void itemDesc(char* input);
   public:
      AidMan();
      AidMan(const AidMan& a) = delete;
      AidMan& operator=(const AidMan& A) = delete;
      virtual ~AidMan();
      void run();
      void save();
      void deallocate();
      void load();
      void remove(int index);
      int list(const char* sub_desc = nullptr);
      int search(int sku) const;
   };
}
#endif