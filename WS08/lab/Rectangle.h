/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"

namespace sdds {
    class Rectangle : public LblShape {
        int m_width;
        int m_height;
    public:
        Rectangle();
        Rectangle(const char* label, int width, int height);
        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}
#endif // SDDS_RECTANGLE_H
