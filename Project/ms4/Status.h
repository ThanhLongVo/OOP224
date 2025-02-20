/* Citation and Sources...
Final Project Milestone 4
Module: Status
Filename: Status.h
Version 1.1
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release
2023/11/20  Update for Milestone 4
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds
{
	class Status
	{
	public:
		char* Description;
		int Codigo;// Spanish word for code is codigo
		Status(char* str = nullptr, int code = 0);
		Status(const Status& status);
		Status& operator=(const Status& status);
		~Status();
		Status& operator=(const char* str);
		Status& operator=(const int code);
		operator bool() const;
		operator int() const;
		operator char* () const;
		friend ostream& operator<<(ostream& os, const Status& status);
		Status& clear();
	};
}

#endif // !SDDS_STATUS_H