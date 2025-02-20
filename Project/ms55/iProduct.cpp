
#include <iostream>
#include "iProduct.h"
namespace sdds
{
   std::ostream& operator<<(std::ostream& ostr, iProduct& ip)
   {
      ip.display(ostr);
      return ostr;
   }
   std::istream& operator>>(std::istream& istr, iProduct& ip)
   {
      ip.read(istr);
      return istr;
   }
   iProduct::~iProduct() 
   {

   }
}