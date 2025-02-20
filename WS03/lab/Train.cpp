//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop3_LAB
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iostream>
#include <cstring>

namespace sdds {
    Train::Train() {
        name = nullptr;
        numPassengers = -1;
        departureTime = -1;
    }

    Train::~Train() {
        finalize();
    }

    void Train::initialize() {
        finalize();
    }

    bool Train::validTime(int value) const {
        return (value >= MIN_TIME && value <= MAX_TIME && value % 100 < 60);
    }

    bool Train::isInvalid() const {
        return (name == nullptr || numPassengers == -1 || !validTime(departureTime));
    }

    bool Train::validNoOfPassengers(int value) const {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* newName) {
        finalize();
        if (newName != nullptr && newName[0] != '\0') {
            copyName(newName);
        }
    }

    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            numPassengers = noOfPassengers;
            departureTime = departure;
        }
        else {
            numPassengers = -1;
            departureTime = -1;
            finalize(); // Set the name to nullptr when the other attributes are invalid
        }
    }


    void Train::set(const char* newName, int noOfPassengers, int departure) {
        set(newName);
        set(noOfPassengers, departure);
    }

    void Train::finalize() {
        if (name != nullptr) {
            delete[] name;
            name = nullptr;
        }
        numPassengers = -1;
        departureTime = -1;
    }

    int Train::noOfPassengers() const {
        return numPassengers;
    }

    const char* Train::getName() const {
        return (name != nullptr) ? name : "No Name";
    }

    int Train::getDepartureTime() const {
        return departureTime;
    }

    void Train::display() const {
        if (!isInvalid()) {
            std::cout << "NAME OF THE TRAIN:    " << getName() << std::endl;
            std::cout << "NUMBER OF PASSENGERS: " << noOfPassengers() << std::endl;
            std::cout << "DEPARTURE TIME:       " << getDepartureTime() << std::endl;
        }
        else {
            std::cout << "Train in an invalid State!" << std::endl;
        }
    }

    void Train::copyName(const char* source) {
        name = new char[strlen(source) + 1];
        strcpy(name, source);
    }
}
