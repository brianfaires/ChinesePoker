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
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							HH_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							HH_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							LH_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							LH_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							HM_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							HM_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							LM_Flush[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<12;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					for(int l=0;l<13;l++)
						for(int m=0;m<13;m++)
							LM_Other[i,j,k,l,m] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<13;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					HS_All[i,j,k] = System::Int32::Parse(sr->ReadLine());
		for(int i=0;i<13;i++)
			for(int j=0;j<13;j++)
				for(int k=0;k<13;k++)
					LS_All[i,j,k] = System::Int32::Parse(sr->ReadLine());
		
		/*
		for(int j=0; j<HM_Flush->Length; j++)
			for each(int i in HM_Flush[j])
				i = System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Straight)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Trips)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Two_Pair)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Pair)
			i = System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<HM_High_Card->Length; j++)
			for each(int i in HM_High_Card[j])
				i = System::Int32::Parse(sr->ReadLine());

		for each(int i in HS_All)
			i = System::Int32::Parse(sr->ReadLine());

		for each(int i in LH_Straight_Flush)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Quads)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Full_House)
			i = System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LH_Flush->Length; j++)
			for each(int i in LH_Flush[j])
				i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Straight)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Trips)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Two_Pair)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Pair)
			i = System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LH_High_Card->Length; j++)
			for each(int i in LH_High_Card[j])
				i = System::Int32::Parse(sr->ReadLine());

		for each(int i in LM_Straight_Flush)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Quads)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Full_House)
			i = System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LM_Flush->Length; j++)
			for each(int i in LM_Flush[j])
				i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Straight)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Trips)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Two_Pair)
			i = System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Pair)
			i = System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LM_High_Card->Length; j++)
			for each(int i in LM_High_Card[j])
				i = System::Int32::Parse(sr->ReadLine());

		for each(int i in LS_All)
			i = System::Int32::Parse(sr->ReadLine());
	*/
	
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

		//for each(int i in HH_Straight_Flush)
		//	sw->WriteLine(i);
		//for each(int i in HH_Quads)
		//	sw->WriteLine(i);
		//for each(int i in HH_Full_House)
		//	sw->WriteLine(i);
		//for(int j=0; j<HH_Flush->Length; j++)
		//	for each(int i in HH_Flush[j])
		//		sw->WriteLine(i);
		//for each(int i in HH_Straight)
		//	sw->WriteLine(i);
		//for each(int i in HH_Trips)
		//	sw->WriteLine(i);
		//for each(int i in HH_Two_Pair)
		//	sw->WriteLine(i);
		//for each(int i in HH_Pair)
		//	sw->WriteLine(i);
		//for(int j=0; j<HH_High_Card->Length; j++)
		//	for each(int i in HH_High_Card[j])
		//		sw->WriteLine(i);

		//for each(int i in HM_Straight_Flush)
		//	sw->WriteLine(i);
		//for each(int i in HM_Quads)
		//	sw->WriteLine(i);
		//for each(int i in HM_Full_House)
		//	sw->WriteLine(i);
		//for(int j=0; j<HM_Flush->Length; j++)
		//	for each(int i in HM_Flush[j])
		//		sw->WriteLine(i);
		//for each(int i in HM_Straight)
		//	sw->WriteLine(i);
		//for each(int i in HM_Trips)
		//	sw->WriteLine(i);
		//for each(int i in HM_Two_Pair)
		//	sw->WriteLine(i);
		//for each(int i in HM_Pair)
		//	sw->WriteLine(i);
		//for(int j=0; j<HM_High_Card->Length; j++)
		//	for each(int i in HM_High_Card[j])
		//		sw->WriteLine(i);

		//for each(int i in HS_All)
		//	sw->WriteLine(i);

		//for each(int i in LH_Straight_Flush)
		//	sw->WriteLine(i);
		//for each(int i in LH_Quads)
		//	sw->WriteLine(i);
		//for each(int i in LH_Full_House)
		//	sw->WriteLine(i);
		//for(int j=0; j<LH_Flush->Length; j++)
		//	for each(int i in LH_Flush[j])
		//		sw->WriteLine(i);
		//for each(int i in LH_Straight)
		//	sw->WriteLine(i);
		//for each(int i in LH_Trips)
		//	sw->WriteLine(i);
		//for each(int i in LH_Two_Pair)
		//	sw->WriteLine(i);
		//for each(int i in LH_Pair)
		//	sw->WriteLine(i);
		//for(int j=0; j<LH_High_Card->Length; j++)
		//	for each(int i in LH_High_Card[j])
		//		sw->WriteLine(i);

		//for each(int i in LM_Straight_Flush)
		//	sw->WriteLine(i);
		//for each(int i in LM_Quads)
		//	sw->WriteLine(i);
		//for each(int i in LM_Full_House)
		//	sw->WriteLine(i);
		//for(int j=0; j<LM_Flush->Length; j++)
		//	for each(int i in LM_Flush[j])
		//		sw->WriteLine(i);
		//for each(int i in LM_Straight)
		//	sw->WriteLine(i);
		//for each(int i in LM_Trips)
		//	sw->WriteLine(i);
		//for each(int i in LM_Two_Pair)
		//	sw->WriteLine(i);
		//for each(int i in LM_Pair)
		//	sw->WriteLine(i);
		//for(int j=0; j<LM_High_Card->Length; j++)
		//	for each(int i in LM_High_Card[j])
		//		sw->WriteLine(i);

		//for each(int i in LS_All)
		//	sw->WriteLine(i);

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
	/*
	int counter = 0;
try
	{
		System::IO::StreamReader ^sr = gcnew System::IO::StreamReader(filename);

	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			for(int k = 0; k < 13; k++)
			{
				// 3 card hands
				if(i == j && j == k)
				{
					HS_All[i,j,k] += System::Int32::Parse(sr->ReadLine());;
					LS_All[i,j,k] = 0.8f + 0.015f * offset;
				}
				else if(i == j)
				{
					HS_All[i,j,k] = 0.1f + 0.05f * j + 0.001f * k;
					LS_All[i,j,k] = 0.1f + 0.05f * j + 0.001f * k;
				}
				else if(j == k)
				{
					HS_All[i,j,k] = 0.1f + 0.05f * j + 0.001f * i;
					LS_All[i,j,k] = 0.1f + 0.05f * j + 0.001f * i;
				}
				else if(i == k)
				{
					HS_All[i,j,k] = 0.1f + 0.05f * i + 0.001f * j;
					LS_All[i,j,k] = 0.1f + 0.05f * i + 0.001f * j;
				}
				else
				{
					HS_All[i,j,k] = 0.005f * i + 0.0001f * j + 0.000005f * k;
					LS_All[i,j,k] = 0.005f * i + 0.0001f * j + 0.000005f * k;
				}

				offset += inc;
			}
		}
	}
	
	offset = 0;
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 2+i; j++)
			for(int k = 0; k < 2+i; k++)
				for(int l = 0; l < 2+i; l++)
					for(int m = 0; m < 1+i; m++)
					{
						HH_High_Card[i][j,k,l,m] = HCval + (offset += inc);
						HM_High_Card[i][j,k,l,m] = HCval + offset;
						LH_High_Card[i][j,k,l,m] = HCval + offset;
						LM_High_Card[i][j,k,l,m] = LowHCval - 10*offset;
						HH_Flush[i][j,k,l,m] = Fval + offset;
						HM_Flush[i][j,k,l,m] = Fval + offset;
						LH_Flush[i][j,k,l,m] = Fval + offset;
						LM_Flush[i][j,k,l,m] = LowFval - offset/100;
						offset += inc;
					}

	
	offset = 0;
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			for(int k = 0; k < 12; k++)
			{
				for(int l = 0; l < 11; l++)
				{
					HH_Pair[i,j,k,l] = Pval + offset;
					HM_Pair[i,j,k,l] = Pval + offset;
					LH_Pair[i,j,k,l] = Pval + offset;
					LM_Pair[i,j,k,l] = LowPval - offset/100;
					offset += inc;
				}
			}
		}
	}

	offset = 0;
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 12; j++)
		{
			for(int k = 0; k < 13; k++)
			{
				HH_Two_Pair[i,j,k] = TPval + 0.001f * offset;
				HM_Two_Pair[i,j,k] = TPval + 0.001f * offset;
				LH_Two_Pair[i,j,k] = TPval + 0.001f * offset;
				LM_Two_Pair[i,j,k] = LowTPval - 0.00001f * offset;
				offset += inc;
			}
		}
	}
	
	for(int i = 0; i < 9; i++)
	{
		HH_Straight_Flush[i] = SFval + 0.001f * i;
		HM_Straight_Flush[i] = SFval + 0.001f * i;
		LH_Straight_Flush[i] = SFval + 0.001f * i;
		LM_Straight_Flush[i] = LowSFval - 0.0001f * i;
		HH_Straight[i] = Sval + 0.001f * i;
		HM_Straight[i] = Sval + 0.001f * i;
		LH_Straight[i] = Sval + 0.001f * i;
		LM_Straight[i] = LowSval - 0.0001f * i;
	}

	for(int i = 0; i < 13; i++)
	{
		HH_Quads[i] = Qval + 0.001f * i;
		HM_Quads[i] = Qval + 0.001f * i;
		LH_Quads[i] = Qval + 0.001f * i;
		LM_Quads[i] = LowQval - 0.0001f * i;
		HH_Full_House[i] = FHval + 0.002f * i;
		HM_Full_House[i] = FHval + 0.002f * i;
		LH_Full_House[i] = FHval + 0.002f * i;
		LM_Full_House[i] = LowFHval - 0.0001f * i;
		HH_Trips[i] = Tval + 0.001f * i;
		HM_Trips[i] = Tval + 0.001f * i;
		LH_Trips[i] = Tval + 0.001f * i;
		LM_Trips[i] = LowTval - 0.0001f * i;
	}


		for each(int i in HH_Straight_Flush)
			HH_Straight_Flush[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HH_Quads)
			HH_Quads[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HH_Full_House)
			HH_Full_House[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<HH_Flush->Length; j++)
			for(int k=0; k < HH_Flush[j]->Length; k++)
				;//HH_Flush[j][k]
				//HH_Flush[j][counter++, (counter/((j+2)*(j+1)))%(j+2), (counter/(j+1))%(j+2), (counter%(j+1))] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HH_Straight)
			HH_Straight[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HH_Trips)
			HH_Trips[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HH_Two_Pair)
			HH_Two_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HH_Pair)
			HH_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<HH_High_Card->Length; j++)
			for each(int i in HH_High_Card[j])
				HH_High_Card[j][counter++] += System::Int32::Parse(sr->ReadLine());

		for each(int i in HM_Straight_Flush)
			HM_Straight_Flush[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Quads)
			HM_Quads[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Full_House)
			HM_Full_House[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<HM_Flush->Length; j++)
			for each(int i in HM_Flush[j])
				HM_Flush[j][counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Straight)
			HM_Straight[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Trips)
			HM_Trips[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Two_Pair)
			HM_Two_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in HM_Pair)
			HM_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<HM_High_Card->Length; j++)
			for each(int i in HM_High_Card[j])
				HM_High_Card[j][counter++] += System::Int32::Parse(sr->ReadLine());

		for each(int i in HS_All)
			HS_All[counter++] += System::Int32::Parse(sr->ReadLine());

		for each(int i in LH_Straight_Flush)
			LH_Straight_Flush[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Quads)
			LH_Quads[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Full_House)
			LH_Full_House[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LH_Flush->Length; j++)
			for each(int i in LH_Flush[j])
				LH_Flush[j][counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Straight)
			LH_Straight[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Trips)
			LH_Trips[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Two_Pair)
			LH_Two_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LH_Pair)
			LH_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LH_High_Card->Length; j++)
			for each(int i in LH_High_Card[j])
				LH_High_Card[j][counter++] += System::Int32::Parse(sr->ReadLine());

		for each(int i in LM_Straight_Flush)
			LM_Straight_Flush[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Quads)
			LM_Quads[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Full_House)
			LM_Full_House[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LM_Flush->Length; j++)
			for each(int i in LM_Flush[j])
				LM_Flush[j][counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Straight)
			LM_Straight[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Trips)
			LM_Trips[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Two_Pair)
			LM_Two_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for each(int i in LM_Pair)
			LM_Pair[counter++] += System::Int32::Parse(sr->ReadLine());
		for(int j=0; j<LM_High_Card->Length; j++)
			for each(int i in LM_High_Card[j])
				LM_High_Card[j][counter++] += System::Int32::Parse(sr->ReadLine());

		for each(int i in LS_All)
			LS_All[counter++] += System::Int32::Parse(sr->ReadLine());
	
	
		sr->Close();
		delete sr;
		return true;

	}
	catch(System::Exception ^e)
	{
		return false;
	}
*/
}
