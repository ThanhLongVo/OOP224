/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"

namespace sdds {
    class Line : public LblShape {
        int m_length;
    public:
        Line();
        Line(const char* label, int length);
        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}
#endif // SDDS_LINE_H
