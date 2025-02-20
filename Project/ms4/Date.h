/* Citation and Sources...
Final Project Milestone 4
Module: Date
Filename: Date.h
Version 1.1
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/09  Preliminary release
2023/11/18  Edit for Milestone 4
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H__
#define SDDS_DATE_H__
#include <iostream>
#include "Status.h"
namespace sdds
{
	const int MAXIMUM_YEAR_VALUE = 2030;

	class Date
	{
	private:
		int Year;
		int Month;
		int Day;
		Status status;
		bool Format;
		bool validate();
	public:
		Date();
		Date(int m_year, int m_month, int m_day);
		int uniqueValue()const;
		const Status& state();
		bool formatted(bool m_format);
		operator bool() const;
		//void clear();
		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;

	};
	bool operator==(const Date& one, const Date& two);
	bool operator!=(const Date& one, const Date& two);
	bool operator>=(const Date& one, const Date& two);
	bool operator<=(const Date& one, const Date& two);
	bool operator<(const Date& one, const Date& two);
	bool operator>(const Date& one, const Date& two);
	std::istream& operator>>(std::istream&, Date&);
	std::ostream& operator<<(std::ostream&, const Date&);
}

#endif
