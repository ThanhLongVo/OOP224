/***********************************************************************
// OOP244 Workshop #2 lab (part 1)
//
// File  File.cpp
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
#include <cstdio>
#include <cstring>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   //TODO: read functions go here    
   

   bool read(int& empNo) {
      if (fscanf(fptr, "%d,", &empNo) == 1) {
         return true;
      }
      return false;
   }

   bool read(double& salary) {
      if (fscanf(fptr, "%lf,", &salary) == 1) {
         return true;
      }
      return false;
   }

   bool read(char* empName)
   {
       return fscanf(fptr, "%[^\n]\n", empName) == 1;
   }
   
}
