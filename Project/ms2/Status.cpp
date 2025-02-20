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
#include"Status.h"
#include <string.h>
#include"Utils.h"
#include<ostream>

namespace sdds
{
	Status::Status(const char* desc)
	{
		if (desc != nullptr)
		{
			ut.alocpy(Description, desc);
		}
		else
			ut.alocpy(Description, "");
		Codigo = 0;
	}

	Status& Status::operator=(int num)
	{
		Codigo = num;
		return *this;
	}
	Status& Status::operator=(const char* source)
	{
		ut.alocpy(Description, source);
		return *this;
	}
	Status::operator int() const
	{
		return Codigo;
	}
	Status::operator const char* () const
	{
		return Description;
	}
	Status::operator bool() const
	{
		if (Description == nullptr)
			return true;
		else
			return false;
	}
	Status& Status::clear()
	{
		delete[] Description;
		Description = nullptr;

		Codigo = 0;

		return *this;
	}

	std::ostream& operator<<(std::ostream& ostr, const Status& st)
	{
		if (int(st) != 0)
			ostr << "ERR#" << st.Codigo << ": ";

		if (!st)
			ostr << st.Description;

		return ostr;
	}
}