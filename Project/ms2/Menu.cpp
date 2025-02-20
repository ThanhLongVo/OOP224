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
#include "Menu.h"
#include <iostream>
#include <cstring>
#include <limits>
namespace sdds{
	Menu::Menu(const char* content) : menuContent(nullptr), numOptions(0) {
		if (content != nullptr) {
			menuContent = new char[strlen(content) + 1];
			strcpy(menuContent, content);

			// Count the number of options based on the tabs in the content
			char* token = strtok(menuContent, "\t");
			while (token != nullptr) {
				numOptions++;
				token = strtok(nullptr, "\t");
			}
		}
	}

	Menu::~Menu() {
		delete[] menuContent;
	}

	unsigned int Menu::run() {
		if (menuContent == nullptr || numOptions == 0) {
			std::cout << "Invalid Menu!\n";
			return 0;
		}

		// Print the menu content
		std::cout  << "---------------------------------\n0- Exit\n> ";

		int choice;
		while (true) {
			if (!(std::cin >> choice)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid Integer, retry: ";
				continue;
			}

			if (static_cast<unsigned int>(choice) < 0 || static_cast<unsigned int>(choice) > numOptions) {
				std::cout << "Value out of range [0<=val<=" << numOptions << "]: ";
				continue;
			}


			break;
		}

		return choice;
	}
}
