/***********************************************************************
// OOP244 Workshop #7 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {
	class Container {
	private:
		// Content: a Cstring with a maximum of 50 characters 
		// holding the description of what the container is holding.
		char Content[50];
		// Capacity: The maximum amount a container can hold in CCs.
		int Capacity;
		// Content volume: The current amount the container is holding. 
		// Obviously, this value can not exceed the Capacity.
		int Content_volume;


		bool validContainer;
	protected:
		// Sets the Container to an invalid empty state
		void setEmpty();
		// returns the Capacity of the container
		int capacity();
		// returns the Content volume of the container
		int volume();
	public:
		// A Container can be created using either two or three arguments; Content,Capacity and Content volume
		// or only the first two, in which case the Content volume is set to zero.
		// The container will be rendered invalid if the Content description is null or the Content volume exceeds the Capacity.
		Container(const char* Content, int Capacity, int Content_volume = 0);
		// A value can be added to the Container. 
		// If the container has enough space for the value, it will be added to the
		// If not, only a portion of value will be added to fill the container to its Capacity.
		int operator += (int value);
		// A value can be deducted from the Container. If the container has enough 	amount,
		// it will reduce the Content volume by the value. If not, the container will be emptied.
		int operator -= (int value);
		//Returns true if the Container is in a valid state or false if it is not.
		bool valid();
		// Accepts two arguments: the Capacity and the Content description. 
		// If the Capacity is a positive value and the Content description is a valid cString,
			// it will set the corresponding attributes and therefore making the Container valid.
		void clear(int Capacity, const char* Content);
		//Receiving and returning an ostream reference, the print will display a valid container
		ostream& print(ostream& out);
		//Receiving and returning an istream reference, read will get an amount to be added to the container
		istream& read(istream& in);
		// Insertions and extraction helper operator overloads
		// Overload operator<< and operator>> to be able to print and read A container using cout and cin.
		friend ostream& operator << (ostream& out, Container& C) {
			return C.print(out);
		}
		friend istream& operator >> (istream& in, Container& C) {
			return C.read(in);
		}
	};
}
#endif