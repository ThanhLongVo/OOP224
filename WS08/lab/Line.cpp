
/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/#include "Line.h"
#include <cstring>
#include <iostream>

namespace sdds {
    Line::Line() : LblShape(), m_length(0) {}

    Line::Line(const char* label, int length) : LblShape(label), m_length(length) {}

    void Line::draw(std::ostream& os) const {
        if (m_length > 0 && label() && label()[0] != '\0') {
            os << label() << std::endl;
            os << std::string(m_length, '=');
        }
    }

    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;
        is.ignore(1000, '\n');
    }
}
