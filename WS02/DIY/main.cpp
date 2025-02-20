/***********************************************************************
// OOP244 Workshop #2 DIY (part 2): tester program
//
// File  main.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//
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
#include <iostream>
#include "Population.h"
using namespace sdds;
int main() {
    char code[4]{};
    while (getPostalCode(code)) {
        if (load("PCpopulationsComplete.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}
