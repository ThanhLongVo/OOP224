

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