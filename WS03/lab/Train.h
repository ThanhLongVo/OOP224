//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop3_LAB
//==============================================
#pragma once
#ifndef TRAIN_H
#define TRAIN_H

namespace sdds {
    class Train {
    private:
        char* name;
        int numPassengers;
        int departureTime;

        static const int MIN_TIME = 700;
        static const int MAX_TIME = 2300;
        static const int MAX_NO_OF_PASSENGERS = 1000;

        void copyName(const char* source);

    public:
        Train();
        ~Train();

        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        void finalize();
        bool isInvalid() const;
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;
    };
}

#endif
