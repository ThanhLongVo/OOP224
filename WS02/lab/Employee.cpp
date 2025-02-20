/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  Employee.cpp
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//    To be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// THANH LONG VO   20-SEP-2023
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Employee.h"
#include "File.h"
#include <iomanip>
#include <algorithm> 
#include <fstream>
#include <cstring> 


using namespace std;
namespace sdds
{
    int noOfEmployees;
    Employee* employees;

    void sort()
    {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (employees[j].m_empNo > employees[j + 1].m_empNo)
                {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    bool load(Employee& emp)
    {
        bool ok = false;
        char name[128];

        if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
        {
            emp.m_name = new char[strlen(name) + 1];


            strcpy(emp.m_name, name);

            ok = true;
        }
        return ok;
    }

    bool load()
    {
        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE))
        {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];

            for (int j = 0; j < noOfEmployees; j++)
            {
                i += load(employees[j]);
            }

            if (i != noOfEmployees)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else
            {
                ok = true;
            }

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    void display(const Employee& emp)
    {
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }

    void display()
    {
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (int i = 0; i < noOfEmployees; i++)
        {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    void deallocateMemory()
    {
        for (int i = 0; i < noOfEmployees; i++)
        {
            delete[] employees[i].m_name;
        }

        delete[] employees;
    }

}
