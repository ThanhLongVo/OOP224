/* Citation and Sources...
Final Project Milestone 2
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/15  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Menu.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
    AidMan::AidMan(const char* filename) : fileName(nullptr), mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
        if (filename != nullptr) {
            fileName = new char[strlen(filename) + 1];
            strcpy(fileName, filename);
        }
    }

    AidMan::~AidMan() {
        delete[] fileName;
    }

    void AidMan::run() {
        while (true) {
            std::cout << "Aid Management System" << std::endl;
            std::cout << "Date: 2023/12/09" << std::endl;
            std::cout << "Data file: " << (fileName ? fileName : "No file") << std::endl;
            //std::cout << "\nSelect an option:" << std::endl;
            std::cout << "\n1- List Items" << std::endl;
            std::cout << "2- Add Item" << std::endl;
            std::cout << "3- Remove Item" << std::endl;
            std::cout << "4- Update Quantity" << std::endl;
            std::cout << "5- Sort" << std::endl;
            std::cout << "6- Ship Items" << std::endl;
            std::cout << "7- New/Open Aid Database" << std::endl;
            //std::cout << "0- Exit" << std::endl;

            unsigned int choice = mainMenu.run();

            if (choice == 0) {
                std::cout << "Exiting Program!" << std::endl;
                break;
            }
            else if (choice == 1) {
                std::cout << "\n****List Items****\n" << std::endl;
            }
            else if (choice == 2) {
                std::cout << "\n****Add Item****\n" << std::endl;
            }
            else if (choice == 3) {
                std::cout << "\n****Remove Item****\n" << std::endl;
            }
            else if (choice == 4) {
                std::cout << "\n****Update Quantity****\n" << std::endl;
            }
            else if (choice == 5) {
                std::cout << "\n****Sort****\n" << std::endl;
            }
            else if (choice == 6) {
                std::cout << "\n****Ship Items****\n" << std::endl;
            }
            else if (choice == 7) {
                std::cout << "\n****New/Open Aid Database****\n" << std::endl;
            }
            else {
                std::cout << "Value out of range [0<=val<=7]: " << choice << std::endl;
            }
        }
    }


}
