//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop4_LAB
// Date:           01 Oct 2023
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "CarInventory.h"

namespace sdds {
    CarInventory::CarInventory() {
        resetInfo();
    }

    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        resetInfo();
        setInfo(type, brand, model, year, code, price);
    }

    CarInventory::~CarInventory() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0.0;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;

        m_type = new char[strlen(type) + 1];
        strcpy_s(m_type, strlen(type) + 1, type);

        m_brand = new char[strlen(brand) + 1];
        strcpy_s(m_brand, strlen(brand) + 1, brand);

        m_model = new char[strlen(model) + 1];
        strcpy_s(m_model, strlen(model) + 1, model);

        m_year = (year >= 1990) ? year : 2022;
        m_code = (code >= 100 && code <= 999) ? code : 100;
        m_price = (price > 0) ? price : 1.0;

        return *this;
    }

    void CarInventory::printInfo() const {
        std::cout << "| " << std::left << std::setw(10) << m_type << " | " << std::setw(16) << m_brand << " | "
            << std::setw(16) << m_model << " | " << std::setw(4) << m_year << " | " << std::setw(3) << m_code
            << " | " << std::fixed << std::setprecision(2) << std::setw(9) << m_price << " |" << std::endl;
    }

    bool CarInventory::isValid() const {
        return (m_type && m_brand && m_model && m_year >= 1990 && m_code >= 100 && m_code <= 999 && m_price > 0);
    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        if (!m_type || !m_brand || !m_model || !car.m_type || !car.m_brand || !car.m_model)
            return false;

        return (strcmp(m_type, car.m_type) == 0 && strcmp(m_brand, car.m_brand) == 0 &&
            strcmp(m_model, car.m_model) == 0 && m_year == car.m_year);
    }
}

namespace sdds {
    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i; // Return the index of the first similar entry
                }
            }
        }
        return -1; // No similar entries found
    }
}


