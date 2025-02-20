/***********************************************************************
// OOP244 Workshop #7 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/


#define _CRT_SECURE_NO_WARNINGS
#include "Container.h"

using namespace sdds;
// Sets the Container to an invalid empty state
void Container::setEmpty() {
	validContainer = false;
}
// returns the Capacity of the container
int Container::capacity() {
	return Capacity;
}
// returns the Content volume of the container
int Container::volume() {
	return Content_volume;
}
// A Container can be created using either two or three arguments; Content, Capacity and Content volume
// or only the first two, in which case the Content volume is set to zero.
// The container will be rendered invalid if the Content description is null or the Content volume exceeds the Capacity.
Container::Container(const char* Content, int Capacity, int Content_volume) {
	if (Content == NULL || Content_volume > Capacity) {
		validContainer = false;
	}
	else {
		strcpy(this->Content, Content);
		this->Capacity = Capacity;
		this->Content_volume = Content_volume;
		validContainer = true;
	}
}
// A value can be added to the Container. 
// If the container has enough space for the value, it will be added to the Content volume.
// If not, only a portion of value will be added to fill the container to its Capacity.
int Container::operator += (int value) {
	if (Content_volume + value <= Capacity) {
		Content_volume += value;
	}
	else {
		value = Capacity - Content_volume;
		Content_volume = Capacity;
	}
	return value;
}
// A value can be deducted from the Container. If the container has enough amount, 
// it will reduce the Content volume by the value. If not, the container will be emptied.
int Container::operator -= (int value) {
	if (Content_volume - value >= 0) {
		Content_volume -= value;
	}
	else {
		value = Content_volume;
		Content_volume = 0;
	}
	return value;
}
//Returns true if the Container is in a valid state or false if it is not.
bool Container::valid() {
	return validContainer;
}
// Accepts two arguments: the Capacity and the Content description. 
// If the Capacity is a positive value and the Content description is a valid cString,
// it will set the corresponding attributes and therefore making the Container valid.
void Container::clear(int Capacity, const char* Content) {
	if (Capacity >= 1 && Content != NULL && strlen(Content) >= 1) {
		this->Capacity = Capacity;
		strcpy(this->Content, Content);
		this->Content_volume = 0;
		validContainer = true;
	}
}
//Receiving and returning an ostream reference, the print will display a valid container
ostream& Container::print(ostream& out) {
	if (validContainer) {
		out << Content << ": (" << Content_volume << "cc/" << Capacity << ")";
	}
	else {
		out << "****: (**cc/***)";
	}
	return out;
}
//Receiving and returning an istream reference, read will get an amount to be added to the container
istream& Container::read(istream& in) {
	int value;
	if (!validContainer) {
		cout << "Broken Container, adding aborted! Press <ENTER> to continue...."
			<< endl;
		in.ignore();
		char getchar();
	}
	else {
		cout << "Add to ";
		print(cout);
		cout << endl << "> ";
		in >> value;
		if (value > Capacity) {
			cout << "Invalid Integer, retry: ";
			cin >> value;
		}
		else if (value < 1 || value > 999) {
			cout << "Value out of range [1<=val<=999]: ";
			cin >> value;
		}


		value = (*this += value);
		cout << "Added " << value << " CCs" << endl;
	}
	return in;
}
