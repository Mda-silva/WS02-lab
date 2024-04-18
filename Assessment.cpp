/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	Assessment.cpp
// Version 1.0
//
// Author	Marquez DaSilva 
// Description
//
// Revision History
// -----------------------------------------------------------
// Name Marquez DaSilva           Date March 22nd 2024           Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include "Assessment.h"

using namespace std;
namespace seneca {

	

	bool read(int& value, FILE* fptr)
	{
		if (fscanf(fptr, "%d", &value) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool read(double & value, FILE* fptr)
	{
		if (fscanf(fptr, "%lf", &value) == 1)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	bool read(char* cstr, FILE* fptr)
	{

		if (fgetc(fptr) != ',') {
			return false; 
		}

		if (fscanf(fptr, "%60[^\n]\n", cstr) == 1)
		{
			fgetc(fptr);
			return true;
		}
		else
		{
			return false;
		}

	}

	bool read(Assessment& assess, FILE* fptr)
	{
		double tempMark;
		char tempTitle[61] = { 0 };

		
		if (fscanf(fptr, "%lf,%60[^\n]", &tempMark, tempTitle) == 2) {
			
			assess.m_mark = new double(tempMark);
			assess.m_title = new char[strlen(tempTitle) + 1]; 

			
			strcpy(assess.m_title, tempTitle);

			return true; 
		}
		else {
			return false; 
		}

	}

	void freeMem(Assessment*& aptr, int size)
	{
		if (aptr != nullptr) {
			for (int i = 0; i < size; ++i) {

				delete aptr[i].m_mark;
				delete[] aptr[i].m_title;
			}

			delete[] aptr;

			aptr = nullptr;

		}
	}
	int read(Assessment*& aptr, FILE * fptr)
	{

		int numReads;

		
		if (fscanf(fptr, "%d", &numReads) != 1)
		{
			return 0;
		}
		

			aptr = new Assessment[numReads];

			int numRecords = 0;

			for (int i = 0; i < numReads; ++i) {
				if (!read(aptr[i], fptr)) {
					break;
				}
				numRecords++;
			}

			if (numRecords != numReads) {

				freeMem(aptr, numRecords);
				return 0;
			}

			return numRecords;
		
	}
}
