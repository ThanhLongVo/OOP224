/* Citation and Sources...
Final Project Milestone 2
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/09  Preliminary release

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

#include<ostream>

namespace sdds
{
	class Status
	{
		char* Description = nullptr;
		int Codigo;
	public:
		Status(const char* desc = nullptr);

		Status& operator=(int num);
		Status& operator=(const char* source);
		operator int() const;
		operator const char* () const;
		operator bool() const;
		Status& clear();
		friend std::ostream& operator<<(std::ostream& ostr, const Status& st);
	};
	std::ostream& operator<<(std::ostream& ostr, const Status& st);
}
#endif // !SDDS_STATUS_H
