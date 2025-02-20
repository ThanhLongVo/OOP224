/* Citation and Sources...
Final Project Milestone 3
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	Thanh Long Vo
Revision History
-----------------------------------------------------------
Date        Reason
2023/11/16  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H_
#define SDDS_STATUS_H_
namespace sdds {
    class Status {
        char* Description{};
        int Codigo{};// Spanish word for code is codigo
    public:
        Status(const char* desc = nullptr);
        // Rule of three
        Status(const Status& S);
        Status& operator=(const Status& S);
        ~Status();
        //
        Status& operator=(int statusCode);
        Status& operator=(const char* desc);
        operator int() const;
        operator const char* ()const;
        operator bool() const;
        Status& clear();
        std::ostream& display(std::ostream& ostr)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Status& S);
}


#endif // !SDDS_STATUS_H_