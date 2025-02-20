/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To be completed by students
// Revision History
// -----------------------------------------------------------
// Name        Date            Reason
//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop2_DIY
//==============================================
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Population.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

namespace sdds {
    std::vector<Population> populations; // Use a vector instead of an array

    bool startsWith(const char* cString, const char* subString) {
        return std::strstr(cString, subString) == cString;
    }

    bool getPostalCode(char* postal_code_prefix) {
        std::cout << "Population Report\n-----------------\nEnter postal code:\n> ";
        std::cin.getline(postal_code_prefix, 4);
        return strcmp(postal_code_prefix, "!") != 0;
    }

    bool load(const char* filename, const char* partial_postal_code_prefix) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error: Cannot open file " << filename << std::endl;
            return false;
        }

        populations.clear(); // Clear the vector

        while (file.good()) {
            std::string line;
            std::getline(file, line);
            if (line.empty()) {
                continue;
            }

            char postalCode[4];
            int population;
            if (line.size() >= 5 && line[3] == ',' && std::isdigit(line[4])) {
                if (sscanf(line.c_str(), "%3[^,],%d", postalCode, &population) == 2) {
                    if (strcmp(partial_postal_code_prefix, "all") == 0 || startsWith(postalCode, partial_postal_code_prefix)) {
                        // Construct a Population object and then push it into the vector:
                        Population tempPopulation;
                        strcpy(tempPopulation.postalCode, postalCode);
                        tempPopulation.population = population;
                        populations.push_back(tempPopulation);
                    }
                }
            }
        }

        return true;
    }

    void display() {
        std::cout << "Postal Code: population\n-------------------------" << std::endl;

        // Sort populations by population count in ascending order and then by postal code alphabetically
        std::sort(populations.begin(), populations.end(), [](const Population& a, const Population& b) {
            if (a.population == b.population) {
                return strcmp(a.postalCode, b.postalCode) < 0;
            }
            return a.population < b.population;
            });

        for (size_t i = 0; i < populations.size(); i++) {
            std::cout << i + 1 << "- " << populations[i].postalCode << ":  " << populations[i].population << std::endl;
        }

        int totalPopulation = 0;
        for (const Population& p : populations) {
            totalPopulation += p.population;
        }

        std::cout << "-------------------------" << std::endl;
        std::cout << "Population of the listed areas: " << totalPopulation << std::endl;

        // Add a blank line after the report
        std::cout << std::endl;
    }


    void deallocateMemory() {
        populations.clear(); // Clear the vector to deallocate memory
    }
}


