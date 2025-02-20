//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop3_DIY
//==============================================
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
#include <iostream>
#include <cstring>
namespace sdds {
    const int Train::MIN_TIME = 700;
    const int Train::MAX_TIME = 2300;
    const int Train::MAX_NO_OF_PASSENGERS = 1000;
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

    bool Train::load(int& notBoarded) {
        notBoarded = 0;
        if (numPassengers >= MAX_NO_OF_PASSENGERS) {
            return false; // The train is already full
        }
        int passengersToAdd;
        std::cout << "Enter number of passengers boarding:" << std::endl;
        std::cin >> passengersToAdd;
        if (passengersToAdd < 0) {
            return false; // Invalid input
        }
        if (numPassengers + passengersToAdd > MAX_NO_OF_PASSENGERS) {
            notBoarded = numPassengers + passengersToAdd - MAX_NO_OF_PASSENGERS;
            numPassengers = MAX_NO_OF_PASSENGERS;
        }
        else {
            numPassengers += passengersToAdd;
        }
        return true;
    }

    bool Train::updateDepartureTime() {
        int newTime;
        std::cout << "Enter new departure time:" << std::endl;
        std::cin >> newTime;
        if (newTime >= 700 && newTime <= 2300 && newTime % 100 < 60) {
            departureTime = newTime;
            return true;
        }
        else {
            departureTime = -1;
            return false;
        }
    }



    bool Train::transfer(const Train& from) {
        if (isInvalid() || from.isInvalid()) {
            std::cout << "Transfer Failed!" << std::endl;
            return false;
        }

        char* combinedName = new char[strlen(name) + strlen(from.name) + 3];
        strcpy(combinedName, name);
        strcat(combinedName, ", ");
        strcat(combinedName, from.name);

        int totalPassengers = numPassengers + from.numPassengers;

        if (totalPassengers <= MAX_NO_OF_PASSENGERS) {
            numPassengers = totalPassengers;
            delete[] name;
            name = combinedName;
            return true;
        }
        else {
            int passengersLeftBehind = totalPassengers - MAX_NO_OF_PASSENGERS;
            numPassengers = MAX_NO_OF_PASSENGERS;
            delete[] name;
            name = combinedName;
            std::cout << "Train is full; " << passengersLeftBehind << " passengers of " << from.name << " could not be boarded!" << std::endl;
            return false;
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
    int Train::getMinTime() {
        return MIN_TIME;
    }

    int Train::getMaxTime() {
        return MAX_TIME;
    }
}
