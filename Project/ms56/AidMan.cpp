/* Citation and Sources...
Final Project Milestone 56
Module: AidMan
Filename: AidMan.cpp
Version 1.5
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
2023/11/01  Update for milestone 56
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
#include "AidMan.h"
#include "Date.h"
#include "Utils.h"
#include "Perishable.h"
using namespace std;
namespace sdds
{
   unsigned int AidMan::menu() const
   {
      cout << "Aid Management System" << endl <<
         "Date: 2023/12/09" << endl <<
         "Data file: " << (m_fileName == nullptr ? "No file" : m_fileName) << endl <<
         "---------------------------------\n";
      return m_mainMenu.run();
   }

   AidMan::AidMan()
   {
      m_mainMenu.set(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");
      m_fileName = nullptr;
      m_numOfIproduct = 0;
   }

   AidMan::~AidMan()
   {
      delete[] m_fileName;
      deallocate();
   }

   void AidMan::run()
   {
      int val = 999;
      do
      {
         val = menu();
         if (val != 0 && val != 7 && m_fileName == nullptr) val = 7;
         switch (val)
         {
         case 0:
            cout << "Exiting Program!" << endl;
            save();
            break;
         case 1:
            cout << endl << "****List Items****\n";
            listItem();
            break;
         case 2:
            cout << endl << "****Add Item****\n";
            addItem();
            break;
         case 3:
            cout << endl << "****Remove Item****\n";
            removeItem();
            break;
         case 4:
            cout << endl << "****Update Quantity****\n";
            updateItem();
            break;
         case 5:
            cout << endl << "****Sort****\n";
            sortItem();
            break;
         case 6:
            cout << endl << "****Ship Items****\n";
            shipItem();
            break;
         case 7:
            cout << endl << "****New/Open Aid Database****\n";
            load();
            break;
         }
      } while (val);
   }

   void AidMan::save()
   {
      if (m_fileName)
      {
         ofstream ofstr(m_fileName);
         for (int i = 0; m_iproduct[i] != 0; i++)
         {
            m_iproduct[i]->save(ofstr);
            ofstr << "\n";
         }

      }
   }

   void AidMan::deallocate()
   {
      for (int i = 0; i < sdds_max_num_items; i++)
      {
         delete m_iproduct[i];
      }
      m_numOfIproduct = 0;
   }

   void AidMan::load()
   {
      char input, fileName[100];
      unsigned int i = 0;
      bool valid;
      save();
      deallocate();
      cout << "Enter file name: ";
      cin >> fileName;
      ut.alocpy(m_fileName, fileName);
      ifstream ifstr(m_fileName);
      if (ifstr.is_open())
      {
         while (ifstr)
         {
            input = ifstr.peek();
            for (i = 0, valid = false; !valid; i++)
            {
               if (input >= '1' && input <= '3')
               {
                  if (m_iproduct[i] == 0)
                  {
                     m_iproduct[i] = new Perishable;
                     valid = true;
                  }
               }
               else if (input > '3' && input <= '9')
               {
                  if (m_iproduct[i] == 0)
                  {
                     m_iproduct[i] = new Item;
                     valid = true;
                  }
               }
               else
               {
                  ifstr.setstate(ios::badbit);
                  valid = true;
               }
            }
            if (m_iproduct[m_numOfIproduct])
            {
               m_iproduct[m_numOfIproduct]->load(ifstr);
               if (m_iproduct[m_numOfIproduct]->operator bool())
               {
                  m_numOfIproduct++;
               }
               else
               {
                  ut.dealoSingle(m_iproduct[m_numOfIproduct]);
               }
            }
         }
      }
      else
      {
         cout << "Failed to open " << m_fileName << " for reading!\n" <<
            "Would you like to create a new data file?\n" <<
            "1- Yes!\n" <<
            "0 - Exit" << endl << "> ";
         cin >> i;
         if (i)
            ofstream ofstr(m_fileName);
      }
      cout << m_numOfIproduct << " records loaded!\n" << endl;
   }

   void AidMan::listItem()
   {
      int numList;
      int input;
      numList = list();
      if (numList)
      {
         cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";
         cin.clear();
         cin.get();
         if (cin.peek() != '\n')
         {
            input = ut.getint(1, numList);
            m_iproduct[input - 1]->linear(false);
            m_iproduct[input - 1]->display(cout);
            cout << endl;
         }
      }
      cout << endl;
   }

   void AidMan::addItem()
   {
      if (m_numOfIproduct >= sdds_max_num_items)
         cout << "Database full!";
      else
      {
         cout << "1- Perishable" << endl <<
            "2- Non-Perishable" << endl <<
            "-----------------" << endl <<
            "0- Exit" << endl <<
            "> ";
         switch (ut.getint(0, 2))
         {
         case 1:
            m_iproduct[m_numOfIproduct] = new Perishable;
            addInfoToItem();
            break;
         case 2:
            m_iproduct[m_numOfIproduct] = new Item;
            addInfoToItem();
            break;
         default:
            cout << "Aborted\n";
         }
         cout << endl;
      }
   }

   void AidMan::removeItem()
   {
      char input[1000];
      int index;
      itemDesc(input);
      if (list(input))
      {
         index = search(ut.getint(10000, 99999, "Enter SKU: "));
         if (index == -1)
         {
            cout << "SKU not found!" << endl;
         }
         else
         {
            cout << "Following item will be removed: " << endl;
            m_iproduct[index]->linear(false);
            m_iproduct[index]->display(cout);
            cout << endl << "Are you sure?" << endl <<
               "1- Yes!" << endl <<
               "0- Exit" << endl <<
               "> ";
            switch (ut.getint(0, 1))
            {
            case 1:
               remove(index);
               cout << "Item removed!" << endl;
               break;
            default:
               cout << "Aborted!" << endl;
            }
         }
      }
      cout << endl;
   }

   void AidMan::updateItem()
   {
      char input[1000];
      int index, val;
      itemDesc(input);
      if (list(input))
      {
         index = search(ut.getint(10000, 99999, "Enter SKU: "));
         if (index == -1)
         {
            cout << "SKU not found!" << endl;
         }
         else
         {
            cout << "1- Add" << endl <<
               "2- Reduce" << endl <<
               "0- Exit" << endl <<
               "> ";
            switch (ut.getint(0, 2))
            {
            case 1:
               if (m_iproduct[index]->qtyNeeded() == m_iproduct[index]->qty())
                  cout << "Quantity Needed already fulfilled!\n";
               else
               {
                  val = ut.getint(1, m_iproduct[index]->qtyNeeded() - m_iproduct[index]->qty(), "Quantity to add: ");
                  *m_iproduct[index] += val;
                  cout << val << " items added!" << endl;
               }
               break;
            case 2:
               if (!m_iproduct[index]->qty())
                  cout << "Quantity on hand is zero\n";
               else
               {
                  val = ut.getint(1, m_iproduct[index]->qty(), "Quantity to reduce: ");
                  *m_iproduct[index] -= val;
                  cout << val << " items removed!" << endl;
               }
               break;
            default:
               cout << "Aborted!" << endl;
            }
         }
      }
      cout << endl;
   }

   void AidMan::sortItem()
   {
      iProduct* ip;
      int qtyDiff_A, qtyDiff_B;
      for (int i = 0; m_iproduct[i] != 0; i++)
      {
         for (int j = 0; m_iproduct[j + 1] != 0; j++)
         {
            qtyDiff_A = m_iproduct[j]->qtyNeeded() - m_iproduct[j]->qty();
            qtyDiff_B = m_iproduct[j + 1]->qtyNeeded() - m_iproduct[j + 1]->qty();
            if (qtyDiff_A < qtyDiff_B)
            {
               ip = m_iproduct[j];
               m_iproduct[j] = m_iproduct[j + 1];
               m_iproduct[j + 1] = ip;
            }
         }
      }
      cout << "Sort completed!\n\n";
   }

   void AidMan::shipItem()
   {
      int count = 0;
      ofstream ofstr("shippingOrder.txt");
      ofstr << "Shipping Order, Date: 2023/12/09" << endl;
      displayTableTitle(ofstr);
      for (int i = 0; m_iproduct[i] != 0; i++)
      {
         if (m_iproduct[i]->qtyNeeded() == m_iproduct[i]->qty())
         {
            displayIproductLinear(i, ofstr, count, true);
            remove(i);
            count++;
         }
      }
      displayTableBorder(ofstr);
      cout << "Shipping Order for " << count << " times saved!\n\n";
   }

   std::ostream& AidMan::displayTableTitle(std::ostream& ostr)
   {
      ostr << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
      displayTableBorder(ostr);
      return ostr;
   }

   std::ostream& AidMan::displayTableBorder(std::ostream& ostr)
   {
      ostr << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
      return ostr;
   }

   std::ostream& AidMan::displayIproductLinear(int index, std::ostream& ostr, int count , bool shipItem)
   {
      if (shipItem)
      {
         ostr << "   " << count + 1;
         ostr << " | ";
         m_iproduct[index]->linear(true);
         ostr << *m_iproduct[index] << endl;
      }
      else
      {
         ostr << "   " << index + 1;
         ostr << " | ";
         m_iproduct[index]->linear(true);
         ostr << *m_iproduct[index] << endl;
      }
      return ostr;
   }

   void AidMan::itemDesc(char* input)
   {
      cout << "Item description: ";
      cin.clear();
      cin.get();
      cin.getline(input, 1000, '\n');
   }

   void AidMan::addInfoToItem()
   {
      int input;
      input = m_iproduct[m_numOfIproduct]->readSku(cin);
      if (search(input) == -1)
      {
         m_iproduct[m_numOfIproduct]->read(cin);
         if (m_iproduct[m_numOfIproduct]->operator bool())
         {
            m_numOfIproduct++;
         }
         else
         {
            m_iproduct[m_numOfIproduct]->display(cout);
            ut.dealoSingle(m_iproduct[m_numOfIproduct]);
         }
      }
      else
      {
         ut.dealoSingle(m_iproduct[m_numOfIproduct]);
         cout << "Sku: " << input << " is already in the system, try updating quantity instead.\n";
      }
   }

   void AidMan::remove(int index)
   {
      ut.dealoSingle(m_iproduct[index]);
      for (int j = index; j < sdds_max_num_items - 1; j++)
         m_iproduct[j] = m_iproduct[j + 1];
      m_numOfIproduct--;
   }

   int AidMan::list(const char* sub_desc)
   {
      unsigned int i = 0;
      displayTableTitle();
      if (!sub_desc)
      {
         for (i = 0; m_iproduct[i] != 0; i++)
            displayIproductLinear(i);
         displayTableBorder();
      }
      else
      {
         for (i = 0; m_iproduct[i] != 0; i++)
         {
            if (*m_iproduct[i] == sub_desc)
               displayIproductLinear(i);
         }
         displayTableBorder();
      }
      if (!i)
         cout << "The list is emtpy!" << endl;
      return i;
   }

   int AidMan::search(int sku) const
   {
      int index = -1;
      for (int i = 0; m_iproduct[i] != 0 && i < sdds_max_num_items && index == -1; i++)
      {
         if (*m_iproduct[i] == sku)
            index = i;
      }
      return index;
   }

}