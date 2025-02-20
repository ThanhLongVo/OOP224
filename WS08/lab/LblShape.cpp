/***********************************************************************
// OOP244 Workshop #8 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <cstring>

namespace sdds {
    LblShape::LblShape() : m_label(nullptr) {}

    LblShape::LblShape(const char* label) {
        if (label) {
            m_label = new char[std::strlen(label) + 1];
            std::strcpy(m_label, label);
        }
    }

    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    void LblShape::getSpecs(std::istream& is) {
        char buffer[1000];
        is.getline(buffer, 1000, ',');
        delete[] m_label;
        m_label = new char[std::strlen(buffer) + 1];
        std::strcpy(m_label, buffer);
    }
}
