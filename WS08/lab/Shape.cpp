/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/
#include "Shape.h"

namespace sdds {
    std::ostream& operator<<(std::ostream& ostr, const Shape& shape) {
        shape.draw(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Shape& shape) {
        shape.getSpecs(istr);
        return istr;
    }
}
