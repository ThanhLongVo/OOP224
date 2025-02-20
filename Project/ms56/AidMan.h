
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
      void shipItem();
      std::ostream& displayTableTitle(std::ostream& ostr = std::cout);
      std::ostream& displayTableBorder(std::ostream& ostr = std::cout);
      std::ostream& displayIproductLinear(int index, std::ostream& ostr = std::cout, int count = 0, bool shipItem = false);
      void itemDesc(char* input);
      void addInfoToItem();
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