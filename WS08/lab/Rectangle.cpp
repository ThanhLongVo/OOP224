/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
#include <cstring>
#include <iostream>
#include <iomanip>

namespace sdds {
    Rectangle::Rectangle() : LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
        if (height >= 3 && width >= static_cast<int>(std::strlen(label)) + 2) {
            m_width = width;
            m_height = height;
        }
        else {
            m_width = 0;
            m_height = 0;
        }
    }

    void Rectangle::draw(std::ostream& os) const {
        if (m_width > 0 && m_height > 0) {
            os << "+" << std::string(m_width - 2, '-') << "+" << std::endl;
            os << "|" << std::left << std::setw(m_width - 2) << label() << "|" << std::endl;
            for (int i = 0; i < m_height - 3; ++i) {
                os << "|" << std::string(m_width - 2, ' ') << "|" << std::endl;
            }
            os << "+" << std::string(m_width - 2, '-') << "+";
        }
    }

    void Rectangle::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_width;
        is.ignore();
        is >> m_height;
        is.ignore(1000, '\n');
        if (m_height < 3 || m_width < static_cast<int>(std::strlen(label())) + 2) {
            m_width = 0;
            m_height = 0;
        }
    }
}
