#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"

namespace sdds {
    

    // Private Methods
    bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const {
        return (name && name[0] != '\0' && number > 999999999 && number < 9999999999 &&
            strlen(vCode) == 2 && strlen(sNumber) == 9);
    }

    void HealthCard::setEmpty() {
        m_name = nullptr;
    }

    void HealthCard::allocateAndCopy(const char* name) {
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
    }

    void HealthCard::extractChar(std::istream& istr, char ch) const {
        char next = istr.peek();
        if (next == ch) {
            istr.ignore();
        }
        else {
            istr.ignore(1000, ch);
            istr.setstate(std::ios::failbit);
        }
    }

    std::ostream& HealthCard::printIDInfo(std::ostream& ostr) const {
        ostr << m_number << '-' << m_vCode << ", " << m_sNumber;
        return ostr;
    }

    void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[]) {
        if (validID(name, number, vCode, sNumber)) {
            allocateAndCopy(name);
            m_number = number;
            strcpy(m_vCode, vCode);
            strcpy(m_sNumber, sNumber);
        }
        else {
            setEmpty();
        }
    }

    // Constructors
    HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[]) {
        set(name, number, vCode, sNumber);
    }

    HealthCard::HealthCard() {
        m_name = nullptr;
    }

    // Rule of Three
    HealthCard::HealthCard(const HealthCard& hc) {
        m_name = nullptr;
        *this = hc;
    }

    HealthCard& HealthCard::operator=(const HealthCard& hc) {
        if (this != &hc) {
            delete[] m_name;
            m_name = nullptr;
            if (hc.m_name) {
                allocateAndCopy(hc.m_name);
            }
            m_number = hc.m_number;
            strcpy(m_vCode, hc.m_vCode);
            strcpy(m_sNumber, hc.m_sNumber);
        }
        return *this;
    }

    HealthCard::~HealthCard() {
        delete[] m_name;
    }

    HealthCard::operator bool() const {
        return m_name != nullptr;
    }

    std::ostream& HealthCard::print(std::ostream& ostr, bool toFile) const {
        if (!m_name) {
            ostr << "Invalid Health Card Record";
        }
        else {
            ostr.setf(std::ios::left);
            ostr.width(MaxNameLength);
            ostr.fill('.');
            ostr << m_name;
            ostr.unsetf(std::ios::left);
            if (toFile) {
                ostr << m_number << '-' << m_vCode << ", " << m_sNumber;
            }
            else {
                ostr << ' ';
                ostr << ' ' << m_number << '-' << m_vCode << ", " << m_sNumber;
            }
        }
        return ostr;
    }

    std::istream& HealthCard::read(std::istream& istr) {
        char name[MaxNameLength + 1] = {};  // Khởi tạo mảng name bằng toàn bộ giá trị rỗng (0).
        long long number = 0;
        char vCode[3] = {};
        char sNumber[10] = {};

        if (istr.getline(name, MaxNameLength + 1, ',') &&  // Đảm bảo đọc không quá độ dài tối đa cho tên.
            istr >> number && istr.ignore(1, ',') &&  // Đọc dấu ',' sau number và bỏ qua nó.
            istr.get(vCode, 3, '-') && istr.ignore(1, '-') &&  // Đọc dấu '-' sau vCode và bỏ qua nó.
            istr.get(sNumber, 10)) {
            // Kiểm tra xem tất cả dữ liệu đã được đọc thành công.
            if (name[0] != '\0' && validID(name, number, vCode, sNumber)) {
                set(name, number, vCode, sNumber);
            }
            else {
                setEmpty();
            }
        }
        else {
            setEmpty();
        }

        return istr;
    }



    std::ostream& operator<<(std::ostream& ostr, const HealthCard& hc) {
        return hc.print(ostr, false);
    }

    std::istream& operator>>(std::istream& istr, HealthCard& hc) {
        return hc.read(istr);
    }
}
