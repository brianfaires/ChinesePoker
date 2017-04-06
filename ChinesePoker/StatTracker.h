#pragma once
#include "stdafx.h"

public ref class StatTracker
{
public:
	StatTracker(void);
	~StatTracker(void);
	bool LoadFromFile(System::String ^filename);
	bool DumpToFile(System::String ^filename);
	bool Merge(StatTracker ^other);
	bool MergeFromFile(System::String ^filename);

	long int totalHandsH;
	long int totalHandsL;

	array<unsigned int, 5> ^HH_Flush;
	array<unsigned int, 5> ^HH_Other;
	array<unsigned int, 5> ^HM_Flush;
	array<unsigned int, 5> ^HM_Other;
	array<unsigned int, 5> ^LH_Flush;
	array<unsigned int, 5> ^LH_Other;
	array<unsigned int, 5> ^LM_Flush;
	array<unsigned int, 5> ^LM_Other;
	array<unsigned int, 3> ^HS_All;
	array<unsigned int, 3> ^LS_All;
};
