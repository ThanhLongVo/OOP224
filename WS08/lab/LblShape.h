/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"

namespace sdds {
    class LblShape : public Shape {
        char* m_label;
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        ~LblShape();
        void getSpecs(std::istream& is) override;
    };
}
#endif // SDDS_LBLSHAPE_H
