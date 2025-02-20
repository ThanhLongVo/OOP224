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
#ifndef SDDS_DATE_H
#define SDDS_DATA_H
#include"Status.h"
#include <iostream>

namespace sdds
{
	const int MAXIMUM_YEAR_VALUE = 2030;
	class Date
	{
		int Year;
		int Month;
		int Day;
		Status status;
		bool Format;

		bool validate();
		int unique_date_value();

	public:
		Date();
		Date(int y, int m, int d);
		~Date();
		bool operator ==(Date& d);
		bool operator !=(Date& d);
		bool operator <(Date& d);
		bool operator >(Date& d);
		bool operator <=(Date& d);
		bool operator >=(Date& d);
		Status& state();
		Date& formatted(bool flag = false);
		operator bool() const;
		std::ostream& write(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr = std::cin);
		friend std::ostream& operator<<(std::ostream& ostr, const Date& d);
		friend std::istream& operator>>(std::istream& istr, Date& d);
	};

	std::ostream& operator<<(std::ostream& ostr, const Date& d);
	std::istream& operator>>(std::istream& istr, Date& d);

}
#endif // !SDDS_DATE_H
