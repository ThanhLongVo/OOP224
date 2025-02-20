/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop2_DIY
//==============================================
***********************************************************************/

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#include "File.h"

namespace sdds {
    struct Population {
        char postalCode[4];
        int population;
    };

    // Returns true if the cstring starts with subString
    bool startsWith(const char* cString, const char* subString);

    // Function to get postal code prefix from the user
    bool getPostalCode(char* postal_code_prefix);

    // Function to load data from the file based on postal code prefix
    bool load(const char* filename, const char* partial_postal_code_prefix = nullptr);

    // Function to display the population report
    void display();
    void display(const char* partial_postal_code_prefix);

    // Function to deallocate dynamic memory
    void deallocateMemory();
}

#endif // SDDS_POPULATION_H_

