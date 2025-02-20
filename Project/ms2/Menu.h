

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