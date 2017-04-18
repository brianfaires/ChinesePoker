#include "stdafx.h"
#include "StatTracker.h"

StatTracker::StatTracker(void)
{
	totalHandsH = 0;
	totalHandsL = 0;
	HH_Flush = gcnew array<unsigned int, 5>(12,13,13,13,13);
	HH_Other = gcnew array<unsigned int, 5>(12,13,13,13,13);
	HM_Flush = gcnew array<unsigned int, 5>(12,13,13,13,13);
	HM_Other = gcnew array<unsigned int, 5>(12,13,13,13,13);
	LH_Flush = gcnew array<unsigned int, 5>(12,13,13,13,13);
	LH_Other = gcnew array<unsigned int, 5>(12,13,13,13,13);
	LM_Flush = gcnew array<unsigned int, 5>(12,13,13,13,13);
	LM_Other = gcnew array<unsigned int, 5>(12,13,13,13,13);
	HS_All = gcnew array<unsigned int, 3>(13,13,13);
	LS_All = gcnew array<unsigned int, 3>(13,13,13);

	for(int i=0; i<12; i++)
		for(int j=0; j<13; j++)
			for(int k=0; k<13; k++)
			{
				HS_All[i,j,k] = 0;
				LS_All[i,j,k] = 0;
				for(int l=0; l<13; l++)
					for(int m=0; m<13; m++)
					{
						HH_Flush[i,j,k,l,m] = 0;
						HH_Other[i,j,k,l,m] = 0;
						HM_Flush[i,j,k,l,m] = 0;
						HM_Other[i,j,k,l,m] = 0;
						LH_Flush[i,j,k,l,m] = 0;
						LH_Other[i,j,k,l,m] = 0;
						LM_Flush[i,j,k,l,m] = 0;
						LM_Other[i,j,k,l,m] = 0;
					}
			}
}

StatTracker::~StatTracker(void)
{
	delete HH_Flush;
	delete HH_Other;
	delete LH_Flush;
	delete LH_Other;
	delete HM_Flush;
	delete HM_Other;
	delete LM_Flush;
	delete LM_Other;
	delete HS_All;
	delete LS_All;
}

bool StatTracker::LoadFromFile(System::String ^filename)
{
	try
	{
		System::IO::StreamReader ^sr = gcnew System::IO::StreamReader(filename);
		totalHandsH = System::Int32::Parse(sr->ReadLine());
		totalHandsL = System::Int32::Parse(sr->ReadLine());
		for(int arrayIndex = 0; arrayIndex < 8; arrayIndex++) // For each of the 5-card DBs (there are 8)
			for(int i=0;i<12;i++)
				for(int j=0;j<13;j++)
					for(int k=0;k<13;k++)
						for(int l=0;l<13;l++)
							for(int m=0;m<13;m++)
								switch(arrayIndex) {
									case 0: HH_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 1: HH_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 2: LH_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 3: LH_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 4: HM_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 5: HM_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 6: LM_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
									case 7: LM_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine()); break;
								}

		for(int arrayIndex = 0; arrayIndex < 2; arrayIndex++) // For each of the 3-card DBs (there are 2)
			for(int i=0;i<13;i++)
				for(int j=0;j<13;j++)
					for(int k=0;k<13;k++)
						switch(arrayIndex) {
							case 0: HS_All[i,j,k] = System::Int32::Parse(sr->ReadLine()); break;
							case 1: LS_All[i,j,k] = System::Int32::Parse(sr->ReadLine()); break;
						}
	
		sr->Close();
		delete sr;
		return true;
	}
	catch(System::Exception ^)
	{
		return false;
	}
}

bool StatTracker::DumpToFile(System::String ^filename)
{
	try
	{
		System::IO::StreamWriter ^sw = gcnew System::IO::StreamWriter(filename);
		sw->WriteLine(totalHandsH);
		sw->WriteLine(totalHandsL);
		for each(int i in HH_Flush)
			sw->WriteLine(i);
		for each(int i in HH_Other)
			sw->WriteLine(i);
		for each(int i in LH_Flush)
			sw->WriteLine(i);
		for each(int i in LH_Other)
			sw->WriteLine(i);
		for each(int i in HM_Flush)
			sw->WriteLine(i);
		for each(int i in HM_Other)
			sw->WriteLine(i);
		for each(int i in LM_Flush)
			sw->WriteLine(i);
		for each(int i in LM_Other)
			sw->WriteLine(i);
		for each(int i in HS_All)
			sw->WriteLine(i);
		for each(int i in LS_All)
			sw->WriteLine(i);

		sw->Close();
		delete sw;
		return true;
	}
	catch(System::Exception ^)
	{
		return false;
	}
}

bool StatTracker::Merge(StatTracker ^other)
{
	totalHandsH += other->totalHandsH;
	totalHandsL += other->totalHandsL;

	for(int j=0; j<13; j++)
	{
		for(int k=0; k<13; k++)
		{
			for(int l=0; l<13; l++)
			{
				HS_All[j,k,l] += other->HS_All[j,k,l];
				LS_All[j,k,l] += other->LS_All[j,k,l];
				
				for(int m=0; m<13; m++)
				{
					for(int i=0; i < 12; i++)
					{
						HH_Flush[i,j,k,l,m] += other->HH_Flush[i,j,k,l,m];
						HH_Other[i,j,k,l,m] += other->HH_Other[i,j,k,l,m];
						LH_Flush[i,j,k,l,m] += other->LH_Flush[i,j,k,l,m];
						LH_Other[i,j,k,l,m] += other->LH_Other[i,j,k,l,m];
						HM_Flush[i,j,k,l,m] += other->HM_Flush[i,j,k,l,m];
						HM_Other[i,j,k,l,m] += other->HM_Other[i,j,k,l,m];
						LM_Flush[i,j,k,l,m] += other->LM_Flush[i,j,k,l,m];
						LM_Other[i,j,k,l,m] += other->LM_Other[i,j,k,l,m];
					}
				}
			}
		}
	}
	return false;
}

bool StatTracker::MergeFromFile(System::String ^filename)
{
	// This functions loads a file and merges it with this StatTracker, placing no extra requirements on the memory footprint
	StatTracker^ other = gcnew StatTracker();
	other->LoadFromFile(filename);
	Merge(other);
	return false;
}
