#pragma once
//==============================================
// Name:           Thanh Long Vo
// Student Number: 171587223
// Email:          tlvo2@myseneca.ca
// Section:        ZDD
// Workshop:       Workshop3_DIY
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
        static const int MAX_NO_OF_PASSENGERS;

        void copyName(const char* source);

    public:
        static const int MIN_TIME;
        static const int MAX_TIME;

        Train();
        ~Train();

        void initialize();
        bool validTime(int value) const;
        bool validNoOfPassengers(int value) const;
        bool load(int& notBoarded);
        bool updateDepartureTime();
        bool transfer(const Train& from);
        void set(const char* name);
        void set(int noOfPassengers, int departure);
        void set(const char* name, int noOfPassengers, int departure);
        void finalize();
        bool isInvalid() const;
        int noOfPassengers() const;
        const char* getName() const;
        int getDepartureTime() const;
        void display() const;
        static int getMinTime();
        static int getMaxTime();
    };
}

#endif


