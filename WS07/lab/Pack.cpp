/***********************************************************************
// OOP244 Workshop #7 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca 
// ID: 171587223
// Description:Creating a class called Pack out of a container that holds
// an additional attribute for the size (or capacity) of one of the units it holds.
// Version: 1.0
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include "Pack.h"
using namespace sdds;
// An Pack can be created using either two, three or four arguments (Using one constructor):
// content description (same as container)
// size: The maximum number of units the Pack can hold
// unit size: The capacity of each unit in the pack in CCs, defaulted to 330.
// Number of units: The number of units in the pack to the maximum of the size of the pack.Defaulted to 0
Pack::Pack(const char* Content, int Size, int unitSize, int NumberOfUnits)
	: Container(Content, Size * unitSize, unitSize * NumberOfUnits) {
	this->Size = Size;
	this->unitSize = unitSize;
	this->NumberOfUnits = NumberOfUnits;
}
// Overrides (shadows) the operator+= of the Base class
// Receives a number to add units to the pack and returns the number of units successfully added.
int Pack::operator += (int units) {
	int result = Container::operator+=(units * unitSize) / unitSize;
	this->NumberOfUnits += result;
	return result;
}
// Overrides (shadows) the operator-= of the Base class
// Receives a number to remove units from the pack and returns the number of units successfully removed.
int Pack::operator -= (int units) {
	int result = Container::operator-=(units * unitSize) / unitSize;
	this->NumberOfUnits -= result;
	return result;
}
// returns the unit size attribute
int Pack::unit() {
	return unitSize;
}
// returns the content volume of the Base class divided by the unit size
int Pack::noOfUnits() {
	return NumberOfUnits;
}
// return the capacity of the base class divided by the unit size
int Pack::size() {
	return Size;
}
// Overloads the clear function of the Base class
// Accepts three arguments: the Pack size, the unit size and the content description.
// If the unit size is greater than zero it will call the clear of the base class passing the product
// of pack size and the unit size and the content description. 
// Then it will set the unit size attribute to the unit size argument.
void Pack::clear(int packSize, int unitSize, const char* content) {
	if (unitSize > 0) {
		Container::clear(packSize * unitSize, content);
		this->unitSize = unitSize;
		this->NumberOfUnits = 0;
		this->Size = packSize;
	}
}
// Overrides (shadows) the print of the Base class
// Receiving and returning an ostream reference, the print will display a valid Pack
ostream& Pack::print(ostream& out) {
	Container::print(out);
	if (valid()) {
		out << ", " << NumberOfUnits << " in a pack of " << Size;
	}
	return out;
}
// Overrides (shadows) the read of the Base class
// Receiving and returning an istream reference, read will get a number 
// for the count of the units to be added to the pack if the pack is valid and not full
istream& Pack::read(istream& in) {
	int units;
	if (!valid()) {
		cout << "Broken Container, adding aborted! Press <ENTER> to continue...."
			<< endl;

		char getchar();
	}
	else if (NumberOfUnits == Size) {
		in.ignore();
		cout << "Pack is full!, press <ENTER> to continue..." << endl;
		char getchar();
	}
	else {
		cout << "Add to ";
		print(cout);
		int maxVal = Size - NumberOfUnits;

		cout << endl << "> ";
		in >> units;
		if (units > Size) {
			cout << "Invalid Integer, retry: ";
			cin >> units;
		}
		else if (units < 1 || units > maxVal) {
			cout << "Value out of range [1<=val<=" << maxVal << "]: ";
			cin >> units;
		}



		units = (*this += units);
		cout << "Added " << units << endl;
	}
	return in;
}