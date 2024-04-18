/***********************************************************************
// OOP244 Workshop 2 p1: tester program
//
// File	Assessment.h
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



#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H

#include <iostream>
#include <cstdio>
#include <cstring>

namespace seneca
{

	struct Assessment {

		double* m_mark;
		char* m_title;

	};

	bool read(int& value, FILE* fptr);

	bool read(double& value, FILE* fptr);

	bool read(char* cstr, FILE* fptr);

	bool read(Assessment& assess, FILE* fptr);

	void freeMem(Assessment*& aptr, int size);

	int read(Assessment*& aptr, FILE* fptr);

}

#endif