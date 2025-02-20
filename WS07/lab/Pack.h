/***********************************************************************
// OOP244 Workshop #7 Lab
// Name: THANH LONG VO
// Email: tlvo2@myseneca.ca
// ID: 171587223
***********************************************************************/

#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
using namespace sdds;
namespace sdds {
	class Pack : public Container {
	private:
		// unitSize is the capacity of one of the units in the Pack. 
		// (example: 330 CC for a can of coke, or 250 CC for a bottle of water)
		int unitSize;
		// Size of the Pack is the capacity of container/unit size
		int Size;
		// Number of units currently in the pack is the content volume of the container / unit size
		int NumberOfUnits;

	public:
		// An Pack can be created using either two, three or four arguments (Using one constructor):
		// content description (same as container)
		// size: The maximum number of units the Pack can hold
		// unit size: The capacity of each unit in the pack in CCs, defaulted to 330.
		// Number of units: The number of units in the pack to the maximum of the size of the pack.Defaulted to 0
			Pack(const char* Content, int Size, int unitSize = 330, int NumberOfUnits =
				0);
		// Overrides (shadows) the operator+= of the Base class
		// Receives a number to add units to the pack and returns the number of units successfully added.
			int operator += (int units);
		// Overrides (shadows) the operator-= of the Base class
		// Receives a number to remove units from the pack and returns the number of units successfully removed.
			int operator -= (int units);
		// returns the unit size attribute
		int unit();
		// returns the content volume of the Base class divided by the unit size
		int noOfUnits();
		// return the capacity of the base class divided by the unit size
		int size();
		// Overloads the clear function of the Base class
		// Accepts three arguments: the Pack size, the unit size and the content description.
		// If the unit size is greater than zero it will call the clear of the base	class passing the product
		// of pack size and the unit size and the content description.
		// Then it will set the unit size attribute to the unit size argument.
		void clear(int packSize, int unitSize, const char* content);
		// Overrides (shadows) the print of the Base class
		// Receiving and returning an ostream reference, the print will display a valid Pack
			ostream& print(ostream& out);
		// Overrides (shadows) the read of the Base class
		// Receiving and returning an istream reference, read will get a number 
		// for the count of the units to be added to the pack if the pack is valid and not full
			istream& read(istream& in);
		// Insertions and extraction helper operator overloads
		// Overload operator<< and operator>> to be able to print and read A pack using cout and cin.
			friend ostream& operator << (ostream& out, Pack& P) {
			return P.print(out);
		}
		friend istream& operator >> (istream& in, Pack& P) {
			return P.read(in);
		}
	};
}
#endif //SDDS_PACK_H