#include "stdafx.h"
#include "Brain.h"
#include "StatTracker.h"

Brain::Brain(void)
{
	dbHigh = gcnew Database();
	dbLow = gcnew Database();
	myStats = gcnew StatTracker();
	Learn();
}
Brain::Brain(StatTracker ^st)
{
	dbHigh = gcnew Database();
	dbLow = gcnew Database();
	myStats = st;
	Learn();
}
Brain::~Brain(void)
{
	delete dbHigh;
	delete dbLow;
}
float Brain::Evaluate(bool isHighGame, bool useHighHand, int c0, int c1, int c2, int c3, int c4)
{
	float returnValue;
	Database5 ^data = isHighGame ? (useHighHand ? dbHigh->High : dbHigh->Middle) : (useHighHand ? dbLow->High : dbLow->Middle);

	// Flush check
	if((c0 & c1 & c2 & c3 & c4 & 0xF) != 0)
	{
		returnValue = data->Flush[RANK(c0),RANK(c1),RANK(c2),RANK(c3),RANK(c4)];
	}
	else
	{
		returnValue = data->Other[RANK(c0),RANK(c1),RANK(c2),RANK(c3),RANK(c4)];
	}
	return returnValue;
}
bool Brain::IsValid(array<int> ^first, array<int> ^small, array<int> ^last)
{
	// Check middle hand vs high hand; you can use either database as long as you use the same one for both
	if(Evaluate(true,true,first[0],first[1],first[2],first[3],first[4]) >
	   Evaluate(true,true,last[0],last[1],last[2],last[3],last[4]))
			return false;

	float smallValue;

	// Check small hand vs middle hand
	int r10 = RANK(small[0]);
	int r11 = RANK(small[1]);
	int r12 = RANK(small[2]);

	switch(r10)
	{
	case(0):
		switch(r11)
		{
		case(0):
			switch(r12)
			{
				case(0):
					smallValue = dbHigh->Middle->Other[0,0,0,1,2];
					break;
				case(1):
				case(2):
					smallValue = dbHigh->Middle->Other[0,0,1,2,3];
					break;
				default:
					smallValue = dbHigh->Middle->Other[0,0,1,2,r12];
			}
			break;
		case(1):
			switch(r12)
			{
			case(1):
				smallValue = dbHigh->Middle->Other[0,1,1,2,3];
				break;
			case(2):
			case(3):
			case(4):
				smallValue = 0;
				break;
			default:
				smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
			}
			break;
		case(2):
			switch(r12)
			{
			case(2):
				smallValue = dbHigh->Middle->Other[0,1,2,2,3];
				break;
			case(3):
			case(4):
				smallValue = 0;
				break;
			default:
				smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
			}
			break;
		case(3):
			if(r12==4)
			{
				smallValue = 0;
				break;
			}
		default:
			smallValue = dbHigh->Middle->Other[0,1,2,r11,r12];
		}
		break;
	case(1):
		switch(r11)
		{
		case(1):
			if(r12==1)
				smallValue = dbHigh->Middle->Other[0,1,1,1,2];
			else if(r12 == 2)
				smallValue = dbHigh->Middle->Other[0,1,1,2,3];
			else
				smallValue = dbHigh->Middle->Other[0,1,1,2,r12];
			break;
		case(2):
			if(r12==2)
				smallValue = dbHigh->Middle->Other[0,1,2,2,3];
			else if(r12 < 5)
				smallValue = 0;
			else
				smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
			break;
		case(3):
			if(r12==4)
				smallValue = 0;
			else
				smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
			break;					
		default:
			smallValue = dbHigh->Middle->Other[0,1,2,r11,r12];
		}
		break;
	case(2):
		if(r11==3 && r12==4)
		{
			smallValue = 0;
			break;
		}
	default:
		smallValue = dbHigh->Middle->Other[0,1,r10,r11,r12];
	}

	return smallValue <= Evaluate(true, false, first[0], first[1], first[2], first[3], first[4]);
}

bool Brain::IsValid(array<int> ^first, array<int> ^small)
{
	float smallValue;

	int r10 = RANK(small[0]);
	int r11 = RANK(small[1]);
	int r12 = RANK(small[2]);

	switch(r10)
	{
	case(0):
		switch(r11)
		{
		case(0):
			switch(r12)
			{
				case(0):
					smallValue = dbLow->High->Other[0,0,0,1,2];
					break;
				case(1):
				case(2):
					smallValue = dbLow->High->Other[0,0,1,2,3];
					break;
				default:
					smallValue = dbLow->High->Other[0,0,1,2,r12];
			}
			break;
		case(1):
			switch(r12)
			{
			case(1):
				smallValue = dbLow->High->Other[0,1,1,2,3];
				break;
			case(2):
			case(3):
			case(4):
				smallValue = 0;
				break;
			default:
				smallValue = dbLow->High->Other[0,1,2,3,r12];
			}
			break;
		case(2):
			switch(r12)
			{
			case(2):
				smallValue = dbLow->High->Other[0,1,2,2,3];
				break;
			case(3):
			case(4):
				smallValue = 0;
				break;
			default:
				smallValue = dbLow->High->Other[0,1,2,3,r12];
			}
			break;
		case(3):
			if(r12==4)
			{
				smallValue = 0;
				break;
			}
		default:
			smallValue = dbLow->High->Other[0,1,2,r11,r12];
		}
		break;
	case(1):
		switch(r11)
		{
		case(1):
			if(r12==1)
				smallValue = dbLow->High->Other[0,1,1,1,2];
			else if(r12 == 2)
				smallValue = dbLow->High->Other[0,1,1,2,3];
			else
				smallValue = dbLow->High->Other[0,1,1,2,r12];
			break;
		case(2):
			if(r12==2)
				smallValue = dbLow->High->Other[0,1,2,2,3];
			else if(r12 < 5)
				smallValue = 0;
			else
				smallValue = dbLow->High->Other[0,1,2,3,r12];
			break;
		case(3):
			if(r12==4)
				smallValue = 0;
			else
				smallValue = dbLow->High->Other[0,1,2,3,r12];
			break;					
		default:
			smallValue = dbLow->High->Other[0,1,2,r11,r12];
		}
		break;
	case(2):
		if(r11==3 && r12==4)
		{
			smallValue = 0;
			break;
		}
	default:
		smallValue = dbLow->High->Other[0,1,r10,r11,r12];
	}
	
	return smallValue <= Evaluate(false, true, first[0], first[1], first[2], first[3], first[4]);
}

void Brain::SolveHand(bool isHighGame, Deck ^deck, int handIndex)
{
	// This function assumes all sub-hands to be sorted
	//
	int startIndex = handIndex * 13;

	float topScore = 0;
	array<int> ^bestHand = gcnew array<int>(13);
	array<int> ^firstHandArray = gcnew array<int>(5);
	array<int> ^lastHandArray = gcnew array<int>(5);
	array<int> ^smallHandArray = gcnew array<int>(3);

	array<bool> ^dirtyOuter = gcnew array<bool>(deck->size);
	array<bool> ^dirtyInner = gcnew array<bool>(8);
	array<int> ^clean = gcnew array<int>(8);

	for(int a = startIndex; a < startIndex+9; a++)
	{
		dirtyOuter[a] = true;
		firstHandArray[0] = deck[a];
		for(int b = a + 1; b < startIndex+10; b++)
		{
			dirtyOuter[b] = true;
			firstHandArray[1] = deck[b];
			for(int c = b + 1; c < startIndex+11; c++)
			{
				dirtyOuter[c] = true;
				firstHandArray[2] = deck[c];
				for(int d = c + 1; d < startIndex+12; d++)
				{
					dirtyOuter[d] = true;
					firstHandArray[3] = deck[d];
					for(int e = d + 1; e < startIndex+13; e++)
					{
						dirtyOuter[e] = true;
						firstHandArray[4] = deck[e];

						float valueF = Evaluate(isHighGame, !isHighGame, firstHandArray[0], firstHandArray[1], firstHandArray[2], firstHandArray[3], firstHandArray[4]);
						
						// We have picked the high hand, now copy the remaining values into clean[] and iterate through that
						int cleanIndex=0;
						for(int i=startIndex; cleanIndex < 8; i++)
							if(!dirtyOuter[i])
								clean[cleanIndex++] = deck[i];

						for(int i = 0; i < 6; i++)
						{
							dirtyInner[i] = true;
							smallHandArray[0] = clean[i];
							for(int j = i + 1; j < 7; j++)
							{
								dirtyInner[j] = true;
								smallHandArray[1] = clean[j];
								for(int k = j + 1; k < 8; k++)
								{
									dirtyInner[k] = true;
									smallHandArray[2] = clean[k];

									// We now have the small hand, and the middle hand is implicit
									int midCounter = 0;
									for(int midIndex = 0; midCounter != 5; midIndex++)
									{
										if(!dirtyInner[midIndex])
											lastHandArray[midCounter++] = clean[midIndex];
									}
									
									float valueS = (isHighGame ? dbHigh : dbLow)->Small->All[RANK(smallHandArray[0]), RANK(smallHandArray[1]), RANK(smallHandArray[2])];
									float valueL = Evaluate(isHighGame, isHighGame, lastHandArray[0], lastHandArray[1], lastHandArray[2], lastHandArray[3], lastHandArray[4]);
									float myScore = valueF + valueL + valueS;

									if(myScore > topScore)
									{
										if((!isHighGame && IsValid(firstHandArray, smallHandArray)) || 
										  (isHighGame && IsValid(firstHandArray, smallHandArray, lastHandArray)))
										{
											topScore = myScore;
											bestHand[10] = smallHandArray[0];									
											bestHand[11] = smallHandArray[1];									
											bestHand[12] = smallHandArray[2];									
											if(isHighGame)
											{
												bestHand[0] = lastHandArray[0];									
												bestHand[1] = lastHandArray[1];									
												bestHand[2] = lastHandArray[2];									
												bestHand[3] = lastHandArray[3];									
												bestHand[4] = lastHandArray[4];									
												bestHand[5] = firstHandArray[0];									
												bestHand[6] = firstHandArray[1];									
												bestHand[7] = firstHandArray[2];									
												bestHand[8] = firstHandArray[3];									
												bestHand[9] = firstHandArray[4];
											}
											else
											{
												bestHand[0] = firstHandArray[0];									
												bestHand[1] = firstHandArray[1];									
												bestHand[2] = firstHandArray[2];									
												bestHand[3] = firstHandArray[3];									
												bestHand[4] = firstHandArray[4];									
												bestHand[5] = lastHandArray[0];									
												bestHand[6] = lastHandArray[1];									
												bestHand[7] = lastHandArray[2];									
												bestHand[8] = lastHandArray[3];									
												bestHand[9] = lastHandArray[4];
											}
										}
									}
									dirtyInner[k] = false;
								}
								dirtyInner[j] = false;
							}
							dirtyInner[i] = false;
						}
						dirtyOuter[e] = false;
					}
					dirtyOuter[d] = false;
				}
				dirtyOuter[c] = false;
			}
			dirtyOuter[b] = false;
		}
		dirtyOuter[a] = false;
	}

	// Organize the hand to equal the best permutation
	if(bestHand[0] != 0 || bestHand[1] != 0)
	{
		for(int i = 0; i < 13; i++)
			deck->cards[i + startIndex] = bestHand[i];
	}

	delete bestHand;
	delete firstHandArray;
	delete lastHandArray;
	delete smallHandArray;
	delete dirtyOuter;
	delete dirtyInner;
}
void Brain::SimHand(Deck ^deck)
{
	// This function assumes all hands to be sorted
	// This optimized function removes function calls from SolveHand(), at the cost of flexibility, brevity and increased complexity
	//
	array<int> ^r = gcnew array<int>(52); // ranks: firstHand[4:0], smallHand[7:5], lastHand[12:8]; repeat for each of the 4 hands
	array<float> ^topScore = gcnew array<float>(8);
	array<array<int> ^> ^bestHand = gcnew array<array<int> ^>(8);
	array<array<int> ^> ^firstHandArray = gcnew array<array<int> ^>(4);
	array<array<int> ^> ^lastHandArray = gcnew array<array<int> ^>(4);
	array<array<int> ^> ^smallHandArray = gcnew array<array<int> ^>(4);
	array<array<int> ^> ^clean = gcnew array<array<int> ^>(4);
	for(int i=0; i<4; i++)
	{
		firstHandArray[i] = gcnew array<int>(5);
		lastHandArray[i] = gcnew array<int>(5);
		smallHandArray[i] = gcnew array<int>(3);
		clean[i] = gcnew array<int>(8);
		bestHand[i] = gcnew array<int>(13);
		bestHand[i+4] = gcnew array<int>(13);
	}

	array<bool> ^dirtyOuter = gcnew array<bool>(deck->size);
	array<bool> ^dirtyInner = gcnew array<bool>(8);

	for(int a = 0; a < 9; a++)
	{
		r[0] = RANK(deck[a]);
		r[13] = RANK(deck[a+13]);
		r[26] = RANK(deck[a+26]);
		r[39] = RANK(deck[a+39]);
		dirtyOuter[a] = true;
		firstHandArray[0][0] = deck[a];
		firstHandArray[1][0] = deck[a+13];
		firstHandArray[2][0] = deck[a+26];
		firstHandArray[3][0] = deck[a+39];
		for(int b = a + 1; b < 10; b++)
		{
			r[1] = RANK(deck[b]);
			r[14] = RANK(deck[b+13]);
			r[27] = RANK(deck[b+26]);
			r[40] = RANK(deck[b+39]);
			dirtyOuter[b] = true;
			firstHandArray[0][1] = deck[b];
			firstHandArray[1][1] = deck[b+13];
			firstHandArray[2][1] = deck[b+26];
			firstHandArray[3][1] = deck[b+39];
			for(int c = b + 1; c < 11; c++)
			{
				r[2] = RANK(deck[c]);
				r[15] = RANK(deck[c+13]);
				r[28] = RANK(deck[c+26]);
				r[41] = RANK(deck[c+39]);
				dirtyOuter[c] = true;
				firstHandArray[0][2] = deck[c];
				firstHandArray[1][2] = deck[c+13];
				firstHandArray[2][2] = deck[c+26];
				firstHandArray[3][2] = deck[c+39];
				for(int d = c + 1; d < 12; d++)
				{
					r[3] = RANK(deck[d]);
					r[16] = RANK(deck[d+13]);
					r[29] = RANK(deck[d+26]);
					r[42] = RANK(deck[d+39]);
					dirtyOuter[d] = true;
					firstHandArray[0][3] = deck[d];
					firstHandArray[1][3] = deck[d+13];
					firstHandArray[2][3] = deck[d+26];
					firstHandArray[3][3] = deck[d+39];
					for(int e = d + 1; e < 13; e++)
					{
						r[4] = RANK(deck[e]);
						r[17] = RANK(deck[e+13]);
						r[30] = RANK(deck[e+26]);
						r[43] = RANK(deck[e+39]);
						dirtyOuter[e] = true;
						firstHandArray[0][4] = deck[e];
						firstHandArray[1][4] = deck[e+13];
						firstHandArray[2][4] = deck[e+26];
						firstHandArray[3][4] = deck[e+39];

						array<float> ^valueF = gcnew array<float>(8);//float valueF = Evaluate(isHighGame, !isHighGame, firstHandArray[0], firstHandArray[1], firstHandArray[2], firstHandArray[3], firstHandArray[4]);
						#pragma region Evaluate(firstHand)
						if((firstHandArray[0][0] & firstHandArray[0][1] & firstHandArray[0][2] & firstHandArray[0][3] & firstHandArray[0][4] & 0xF) != 0)
						{
							valueF[0] = dbHigh->Middle->Flush[r[0],r[1],r[2],r[3],r[4]];
							valueF[4] = dbLow->High->Flush[r[0],r[1],r[2],r[3],r[4]];
						}
						else
						{
							valueF[0] = dbHigh->Middle->Other[r[0],r[1],r[2],r[3],r[4]];
							valueF[4] = dbLow->High->Other[r[0],r[1],r[2],r[3],r[4]];
						}
						if((firstHandArray[1][0] & firstHandArray[1][1] & firstHandArray[1][2] & firstHandArray[1][3] & firstHandArray[1][4] & 0xF) != 0)
						{
							valueF[1] = dbHigh->Middle->Flush[r[13],r[14],r[15],r[16],r[17]];
							valueF[5] = dbLow->High->Flush[r[13],r[14],r[15],r[16],r[17]];
						}
						else
						{
							valueF[1] = dbHigh->Middle->Other[r[13],r[14],r[15],r[16],r[17]];
							valueF[5] = dbLow->High->Other[r[13],r[14],r[15],r[16],r[17]];
						}
						if((firstHandArray[2][0] & firstHandArray[2][1] & firstHandArray[2][2] & firstHandArray[2][3] & firstHandArray[2][4] & 0xF) != 0)
						{
							valueF[2] = dbHigh->Middle->Flush[r[26],r[27],r[28],r[29],r[30]];
							valueF[6] = dbLow->High->Flush[r[26],r[27],r[28],r[29],r[30]];
						}
						else
						{
							valueF[2] = dbHigh->Middle->Other[r[26],r[27],r[28],r[29],r[30]];
							valueF[6] = dbLow->High->Other[r[26],r[27],r[28],r[29],r[30]];
						}
						if((firstHandArray[3][0] & firstHandArray[3][1] & firstHandArray[3][2] & firstHandArray[3][3] & firstHandArray[3][4] & 0xF) != 0)
						{
							valueF[3] = dbHigh->Middle->Flush[r[39],r[40],r[41],r[42],r[43]];
							valueF[7] = dbLow->High->Flush[r[39],r[40],r[41],r[42],r[43]];
						}
						else
						{
							valueF[3] = dbHigh->Middle->Other[r[39],r[40],r[41],r[42],r[43]];
							valueF[7] = dbLow->High->Other[r[39],r[40],r[41],r[42],r[43]];
						}
						#pragma endregion

						// We have picked the high hand, now copy the remaining values into clean[] and iterate through that
						int cleanIndex=0;
						for(int i=0; cleanIndex < 8; i++)
							if(!dirtyOuter[i])
							{
								clean[0][cleanIndex] = deck[i];
								clean[1][cleanIndex] = deck[i+13];
								clean[2][cleanIndex] = deck[i+26];
								clean[3][cleanIndex++] = deck[i+39];
							}

						for(int i = 0; i < 6; i++)
						{
							r[5]  = RANK(clean[0][i]);
							r[18] = RANK(clean[1][i]);
							r[31] = RANK(clean[2][i]);
							r[44] = RANK(clean[3][i]);
							dirtyInner[i] = true;
							smallHandArray[0][0] = clean[0][i];
							smallHandArray[1][0] = clean[1][i];
							smallHandArray[2][0] = clean[2][i];
							smallHandArray[3][0] = clean[3][i];
							for(int j = i + 1; j < 7; j++)
							{
								r[6]  = RANK(clean[0][j]);
								r[19] = RANK(clean[1][j]);
								r[32] = RANK(clean[2][j]);
								r[45] = RANK(clean[3][j]);
								dirtyInner[j] = true;
								smallHandArray[0][1] = clean[0][j];
								smallHandArray[1][1] = clean[1][j];
								smallHandArray[2][1] = clean[2][j];
								smallHandArray[3][1] = clean[3][j];
								for(int k = j + 1; k < 8; k++)
								{
									r[7]  = RANK(clean[0][k]);
									r[20] = RANK(clean[1][k]);
									r[33] = RANK(clean[2][k]);
									r[46] = RANK(clean[3][k]);
									dirtyInner[k] = true;
									smallHandArray[0][2] = clean[0][k];
									smallHandArray[1][2] = clean[1][k];
									smallHandArray[2][2] = clean[2][k];
									smallHandArray[3][2] = clean[3][k];

									array<float> ^valueS = gcnew array<float>(8);
									#pragma region Evaluate(smallHand)
									valueS[0] = dbHigh->Small->All[r[5], r[6], r[7]];
									valueS[4] = dbLow->Small->All[r[5], r[6], r[7]];
									valueS[1] = dbHigh->Small->All[r[18], r[19], r[20]];
									valueS[5] = dbLow->Small->All[r[18], r[19], r[20]];
									valueS[2] = dbHigh->Small->All[r[31], r[32], r[33]];
									valueS[6] = dbLow->Small->All[r[31], r[32], r[33]];
									valueS[3] = dbHigh->Small->All[r[44], r[45], r[46]];
									valueS[7] = dbLow->Small->All[r[44], r[45], r[46]];
									#pragma endregion	

									// We now have the small hand, and the middle hand is implicit
									int midCounter = 0;
									for(int midIndex = 0; midCounter != 5; midIndex++)
									{
										if(!dirtyInner[midIndex])
										{
											r[midCounter+8] = RANK(clean[0][midIndex]);
											r[midCounter+21] = RANK(clean[1][midIndex]);
											r[midCounter+34] = RANK(clean[2][midIndex]);
											r[midCounter+47] = RANK(clean[3][midIndex]);
											lastHandArray[0][midCounter] = clean[0][midIndex];
											lastHandArray[1][midCounter] = clean[1][midIndex];
											lastHandArray[2][midCounter] = clean[2][midIndex];
											lastHandArray[3][midCounter++] = clean[3][midIndex];
										}
									}
									array<float> ^valueL = gcnew array<float>(8);//float valueL = Evaluate(isHighGame, isHighGame, lastHandArray[0], lastHandArray[1], lastHandArray[2], lastHandArray[3], lastHandArray[4]);
									array<float> ^maxValueF = gcnew array<float>(4);
									#pragma region Evaluate(lastHand)
									if((lastHandArray[0][0] & lastHandArray[0][1] & lastHandArray[0][2] & lastHandArray[0][3] & lastHandArray[0][4] & 0xF) != 0)
									{
										valueL[0] = dbHigh->High->Flush[r[8],r[9],r[10],r[11],r[12]];
										valueL[4] = dbLow->Middle->Flush[r[8],r[9],r[10],r[11],r[12]];
										maxValueF[0] = dbHigh->Middle->Flush[r[8],r[9],r[10],r[11],r[12]];
									}
									else
									{
										valueL[0] = dbHigh->High->Other[r[8],r[9],r[10],r[11],r[12]];
										valueL[4] = dbLow->Middle->Other[r[8],r[9],r[10],r[11],r[12]];
										maxValueF[0] = dbHigh->Middle->Other[r[8],r[9],r[10],r[11],r[12]];
									}
									if((lastHandArray[1][0] & lastHandArray[1][1] & lastHandArray[1][2] & lastHandArray[1][3] & lastHandArray[1][4] & 0xF) != 0)
									{
										valueL[1] = dbHigh->High->Flush[r[21],r[22],r[23],r[24],r[25]];
										valueL[5] = dbLow->Middle->Flush[r[21],r[22],r[23],r[24],r[25]];
										maxValueF[1] = dbHigh->Middle->Flush[r[21],r[22],r[23],r[24],r[25]];
									}
									else
									{
										valueL[1] = dbHigh->High->Other[r[21],r[22],r[23],r[24],r[25]];
										valueL[5] = dbLow->Middle->Other[r[21],r[22],r[23],r[24],r[25]];
										maxValueF[1] = dbHigh->Middle->Other[r[21],r[22],r[23],r[24],r[25]];
									}
									if((lastHandArray[2][0] & lastHandArray[2][1] & lastHandArray[2][2] & lastHandArray[2][3] & lastHandArray[2][4] & 0xF) != 0)
									{
										valueL[2] = dbHigh->High->Flush[r[34],r[35],r[36],r[37],r[38]];
										valueL[6] = dbLow->Middle->Flush[r[34],r[35],r[36],r[37],r[38]];
										maxValueF[2] = dbHigh->Middle->Flush[r[34],r[35],r[36],r[37],r[38]];
									}
									else
									{
										valueL[2] = dbHigh->High->Other[r[34],r[35],r[36],r[37],r[38]];
										valueL[6] = dbLow->Middle->Other[r[34],r[35],r[36],r[37],r[38]];
										maxValueF[2] = dbHigh->Middle->Other[r[34],r[35],r[36],r[37],r[38]];
									}
									if((lastHandArray[3][0] & lastHandArray[3][1] & lastHandArray[3][2] & lastHandArray[3][3] & lastHandArray[3][4] & 0xF) != 0)
									{
										valueL[3] = dbHigh->High->Flush[r[47],r[48],r[49],r[50],r[51]];
										valueL[7] = dbLow->Middle->Flush[r[47],r[48],r[49],r[50],r[51]];
										maxValueF[3] = dbHigh->Middle->Flush[r[47],r[48],r[49],r[50],r[51]];
									}
									else
									{
										valueL[3] = dbHigh->High->Other[r[47],r[48],r[49],r[50],r[51]];
										valueL[7] = dbLow->Middle->Other[r[47],r[48],r[49],r[50],r[51]];
										maxValueF[3] = dbHigh->Middle->Other[r[47],r[48],r[49],r[50],r[51]];
									}
									#pragma endregion
																											
									array<float> ^myScore = gcnew array<float>(8);
									#pragma region PseudoCode:if(score>topScore && IsValid()) bestHand = curHand
									int scoreIndex = 0;
									for(; scoreIndex<4; scoreIndex++)
									{	
										// For high hands
										myScore[scoreIndex] = valueF[scoreIndex] + valueL[scoreIndex] + valueS[scoreIndex];
										if(myScore[scoreIndex] > topScore[scoreIndex])
										{
											#pragma region PseudoCode:if(IsValid(firstHandArray[scoreIndex], smallHandArray[scoreIndex], lastHandArray[scoreIndex]))
											// Check middle hand vs high hand; you can use either database as long as they use the same one
											if(valueF[scoreIndex] >  maxValueF[scoreIndex])
												continue;

											float smallValue;
											// Check small hand vs middle hand
											int r10 = RANK(smallHandArray[scoreIndex][0]);
											int r11 = RANK(smallHandArray[scoreIndex][1]);
											int r12 = RANK(smallHandArray[scoreIndex][2]);

											switch(r10)
											{
											case(0):
												switch(r11)
												{
												case(0):
													switch(r12)
													{
														case(0):
															smallValue = dbHigh->Middle->Other[0,0,0,1,2];
															break;
														case(1):
														case(2):
															smallValue = dbHigh->Middle->Other[0,0,1,2,3];
															break;
														default:
															smallValue = dbHigh->Middle->Other[0,0,1,2,r12];
													}
													break;
												case(1):
													switch(r12)
													{
													case(1):
														smallValue = dbHigh->Middle->Other[0,1,1,2,3];
														break;
													case(2):
													case(3):
													case(4):
														smallValue = 0;
														break;
													default:
														smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
													}
													break;
												case(2):
													switch(r12)
													{
													case(2):
														smallValue = dbHigh->Middle->Other[0,1,2,2,3];
														break;
													case(3):
													case(4):
														smallValue = 0;
														break;
													default:
														smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
													}
													break;
												case(3):
													if(r12==4)
													{
														smallValue = 0;
														break;
													}
												default:
													smallValue = dbHigh->Middle->Other[0,1,2,r11,r12];
												}
												break;
											case(1):
												switch(r11)
												{
												case(1):
													if(r12==1)
														smallValue = dbHigh->Middle->Other[0,1,1,1,2];
													else if(r12 == 2)
														smallValue = dbHigh->Middle->Other[0,1,1,2,3];
													else
														smallValue = dbHigh->Middle->Other[0,1,1,2,r12];
													break;
												case(2):
													if(r12==2)
														smallValue = dbHigh->Middle->Other[0,1,2,2,3];
													else if(r12 < 5)
														smallValue = 0;
													else
														smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
													break;
												case(3):
													if(r12==4)
														smallValue = 0;
													else
														smallValue = dbHigh->Middle->Other[0,1,2,3,r12];
													break;					
												default:
													smallValue = dbHigh->Middle->Other[0,1,2,r11,r12];
												}
												break;
											case(2):
												if(r11==3 && r12==4)
												{
													smallValue = 0;
													break;
												}
											default:
												smallValue = dbHigh->Middle->Other[0,1,r10,r11,r12];
											}

											if(smallValue <= valueF[scoreIndex])
											{
												topScore[scoreIndex] = myScore[scoreIndex];
												bestHand[scoreIndex][0] = lastHandArray[scoreIndex][0];									
												bestHand[scoreIndex][1] = lastHandArray[scoreIndex][1];									
												bestHand[scoreIndex][2] = lastHandArray[scoreIndex][2];									
												bestHand[scoreIndex][3] = lastHandArray[scoreIndex][3];									
												bestHand[scoreIndex][4] = lastHandArray[scoreIndex][4];									
												bestHand[scoreIndex][5] = firstHandArray[scoreIndex][0];									
												bestHand[scoreIndex][6] = firstHandArray[scoreIndex][1];									
												bestHand[scoreIndex][7] = firstHandArray[scoreIndex][2];									
												bestHand[scoreIndex][8] = firstHandArray[scoreIndex][3];									
												bestHand[scoreIndex][9] = firstHandArray[scoreIndex][4];
												bestHand[scoreIndex][10] = smallHandArray[scoreIndex][0];									
												bestHand[scoreIndex][11] = smallHandArray[scoreIndex][1];									
												bestHand[scoreIndex][12] = smallHandArray[scoreIndex][2];									
											}
											#pragma endregion
										}
									}
									for(;scoreIndex<8; scoreIndex++)
									{
										// For low hands
										myScore[scoreIndex] = valueF[scoreIndex] + valueL[scoreIndex] + valueS[scoreIndex];
										if(myScore[scoreIndex] > topScore[scoreIndex])
										{
											#pragma region PseudoCode: if(IsValid(firstHandArray[scoreIndex-4], smallHandArray[scoreIndex-4]))
											float smallValue;
											int sc4 = scoreIndex-4;
											int r10 = RANK(smallHandArray[sc4][0]);
											int r11 = RANK(smallHandArray[sc4][1]);
											int r12 = RANK(smallHandArray[sc4][2]);

											switch(r10)
											{
											case(0):
												switch(r11)
												{
												case(0):
													switch(r12)
													{
														case(0):
															smallValue = dbLow->High->Other[0,0,0,1,2];
															break;
														case(1):
														case(2):
															smallValue = dbLow->High->Other[0,0,1,2,3];
															break;
														default:
															smallValue = dbLow->High->Other[0,0,1,2,r12];
													}
													break;
												case(1):
													switch(r12)
													{
													case(1):
														smallValue = dbLow->High->Other[0,1,1,2,3];
														break;
													case(2):
													case(3):
													case(4):
														smallValue = 0;
														break;
													default:
														smallValue = dbLow->High->Other[0,1,2,3,r12];
													}
													break;
												case(2):
													switch(r12)
													{
													case(2):
														smallValue = dbLow->High->Other[0,1,2,2,3];
														break;
													case(3):
													case(4):
														smallValue = 0;
														break;
													default:
														smallValue = dbLow->High->Other[0,1,2,3,r12];
													}
													break;
												case(3):
													if(r12==4)
													{
														smallValue = 0;
														break;
													}
												default:
													smallValue = dbLow->High->Other[0,1,2,r11,r12];
												}
												break;
											case(1):
												switch(r11)
												{
												case(1):
													if(r12==1)
														smallValue = dbLow->High->Other[0,1,1,1,2];
													else if(r12 == 2)
														smallValue = dbLow->High->Other[0,1,1,2,3];
													else
														smallValue = dbLow->High->Other[0,1,1,2,r12];
													break;
												case(2):
													if(r12==2)
														smallValue = dbLow->High->Other[0,1,2,2,3];
													else if(r12 < 5)
														smallValue = 0;
													else
														smallValue = dbLow->High->Other[0,1,2,3,r12];
													break;
												case(3):
													if(r12==4)
														smallValue = 0;
													else
														smallValue = dbLow->High->Other[0,1,2,3,r12];
													break;					
												default:
													smallValue = dbLow->High->Other[0,1,2,r11,r12];
												}
												break;
											case(2):
												if(r11==3 && r12==4)
												{
													smallValue = 0;
													break;
												}
											default:
												smallValue = dbLow->High->Other[0,1,r10,r11,r12];
											}
											
											if(smallValue <= valueF[scoreIndex])
											{
												topScore[scoreIndex] = myScore[scoreIndex];
												bestHand[scoreIndex][0] = firstHandArray[sc4][0];									
												bestHand[scoreIndex][1] = firstHandArray[sc4][1];									
												bestHand[scoreIndex][2] = firstHandArray[sc4][2];									
												bestHand[scoreIndex][3] = firstHandArray[sc4][3];									
												bestHand[scoreIndex][4] = firstHandArray[sc4][4];									
												bestHand[scoreIndex][5] = lastHandArray[sc4][0];									
												bestHand[scoreIndex][6] = lastHandArray[sc4][1];									
												bestHand[scoreIndex][7] = lastHandArray[sc4][2];									
												bestHand[scoreIndex][8] = lastHandArray[sc4][3];									
												bestHand[scoreIndex][9] = lastHandArray[sc4][4];
												bestHand[scoreIndex][10] = smallHandArray[sc4][0];									
												bestHand[scoreIndex][11] = smallHandArray[sc4][1];									
												bestHand[scoreIndex][12] = smallHandArray[sc4][2];									
											}
											#pragma endregion
										}
									}
									#pragma endregion									

									// Loop and Memory cleanup
									delete maxValueF;
									delete valueL;
									delete valueS;
									delete myScore;
									dirtyInner[k] = false;
								}
								dirtyInner[j] = false;
							}
							dirtyInner[i] = false;
						}
						delete valueF;
						dirtyOuter[e] = false;
					}
					dirtyOuter[d] = false;
				}
				dirtyOuter[c] = false;
			}
			dirtyOuter[b] = false;
		}
		dirtyOuter[a] = false;
	}

	// Organize the hands to equal the best permutations
	for(int i = 0; i < 52; i++)
		deck->cards[i] = bestHand[(i/13)][i%13];

	// Adjust statTracker
	for(int i=0; i<4; i++)
	{
		if(bestHand[i][0] & bestHand[i][1] & bestHand[i][2] & bestHand[i][3] & bestHand[i][4] & 0xF)
			myStats->HH_Flush[RANK(bestHand[i][0]), RANK(bestHand[i][1]), RANK(bestHand[i][2]), RANK(bestHand[i][3]), RANK(bestHand[i][4])] += 1;
		else
			myStats->HH_Other[RANK(bestHand[i][0]), RANK(bestHand[i][1]), RANK(bestHand[i][2]), RANK(bestHand[i][3]), RANK(bestHand[i][4])] += 1;

		if(bestHand[i][5] & bestHand[i][6] & bestHand[i][7] & bestHand[i][8] & bestHand[i][9] & 0xF)
			myStats->HM_Flush[RANK(bestHand[i][5]), RANK(bestHand[i][6]), RANK(bestHand[i][7]), RANK(bestHand[i][8]), RANK(bestHand[i][9])] += 1;
		else
			myStats->HM_Other[RANK(bestHand[i][5]), RANK(bestHand[i][6]), RANK(bestHand[i][7]), RANK(bestHand[i][8]), RANK(bestHand[i][9])] += 1;

		if(bestHand[i+4][0] & bestHand[i+4][1] & bestHand[i+4][2] & bestHand[i+4][3] & bestHand[i+4][4] & 0xF)
			myStats->LH_Flush[RANK(bestHand[i+4][0]), RANK(bestHand[i+4][1]), RANK(bestHand[i+4][2]), RANK(bestHand[i+4][3]), RANK(bestHand[i+4][4])] += 1;
		else
			myStats->LH_Other[RANK(bestHand[i+4][0]), RANK(bestHand[i+4][1]), RANK(bestHand[i+4][2]), RANK(bestHand[i+4][3]), RANK(bestHand[i+4][4])] += 1;

		if(bestHand[i+4][5] & bestHand[i+4][6] & bestHand[i+4][7] & bestHand[i+4][8] & bestHand[i+4][9] & 0xF)
			myStats->LM_Flush[RANK(bestHand[i+4][5]), RANK(bestHand[i+4][6]), RANK(bestHand[i+4][7]), RANK(bestHand[i+4][8]), RANK(bestHand[i+4][9])] += 1;
		else
			myStats->LM_Other[RANK(bestHand[i+4][5]), RANK(bestHand[i+4][6]), RANK(bestHand[i+4][7]), RANK(bestHand[i+4][8]), RANK(bestHand[i+4][9])] += 1;

		myStats->HS_All[RANK(bestHand[i][10]), RANK(bestHand[i][11]), RANK(bestHand[i][12])] += 1;
		myStats->LS_All[RANK(bestHand[i+4][10]), RANK(bestHand[i+4][11]), RANK(bestHand[i+4][12])] += 1;
	}
	myStats->totalHandsH += 4;
	myStats->totalHandsL += 4;

	// Memory cleanup
	for each(array<int> ^ai in bestHand)
		delete ai;
	for each(array<int> ^ai in firstHandArray)
		delete ai;
	for each(array<int> ^ai in lastHandArray)
		delete ai;
	for each(array<int> ^ai in smallHandArray)
		delete ai;
	delete bestHand;
	delete firstHandArray;
	delete lastHandArray;
	delete smallHandArray;
	delete dirtyOuter;
	delete dirtyInner;
}

void Brain::Learn(void)
{
	long int totalHandsHS = myStats->totalHandsH;
	long int totalHandsLS = myStats->totalHandsL;
	
	for(int a=0; a<13; a++)
	{
		for(int b=0; b<=a; b++)
		{
			for(int c=0; c<=b; c++)
			{
				if(myStats->HS_All[c,b,a]==0)
					totalHandsHS++;
				if(myStats->LS_All[c,b,a]==0)
					totalHandsLS++;
			}
		}
	}
	
	int lowerHandsHS=0, lowerHandsLS=0;

	// High cards
	// For 3 card hands, we only need 2 counters of each type, so use HH and LH to signal H and L respectively (<-antiquated comment?6/30/09)
	for(int a=2; a<13; a++)
	{
		for(int b=1; b<a; b++)
		{
			for(int c=0; c<b; c++)
			{
				int curHandsHS = MAX(1, (myStats->HS_All[c,b,a]));
				int curHandsLS = MAX(1, (myStats->LS_All[c,b,a]));
				dbHigh->Small->All[c,b,a] = (lowerHandsHS + (curHandsHS / 2.0f)) / (float)totalHandsHS;
				dbLow->Small->All[c,b,a] = (lowerHandsLS + (curHandsLS / 2.0f)) / (float)totalHandsLS;
				lowerHandsHS += curHandsHS;
				lowerHandsLS += curHandsLS;
			}
		}
	}
	// Pairs
	for(int a=0; a<13; a++)
	{
		for(int b=0; b<13; b++)
		{
			if(b < a)
			{
				int curHandsHS = MAX(1, (myStats->HS_All[b,a,a]));
				int curHandsLS = MAX(1, (myStats->LS_All[b,a,a]));
				dbHigh->Small->All[b,a,a] = (lowerHandsHS + (curHandsHS / 2.0f)) / (float)totalHandsHS;
				dbLow->Small->All[b,a,a] = (lowerHandsLS + (curHandsLS / 2.0f)) / (float)totalHandsLS;
				lowerHandsHS += curHandsHS;
				lowerHandsLS += curHandsLS;
			}
			else if(b > a)
			{
				int curHandsHS = MAX(1, (myStats->HS_All[a,a,b]));
				int curHandsLS = MAX(1, (myStats->LS_All[a,a,b]));
				dbHigh->Small->All[a,a,b] = (lowerHandsHS + (curHandsHS / 2.0f)) / (float)totalHandsHS;
				dbLow->Small->All[a,a,b] = (lowerHandsLS + (curHandsLS / 2.0f)) / (float)totalHandsLS;
				lowerHandsHS += curHandsHS;
				lowerHandsLS += curHandsLS;
			}
		}
	}
	// Trips
	for(int a=0; a<13; a++)
	{	
		int curHandsHS = MAX(1, (myStats->HS_All[a,a,a]));
		int curHandsLS = MAX(1, (myStats->LS_All[a,a,a]));
		dbHigh->Small->All[a,a,a] = (lowerHandsHS + (curHandsHS / 2.0f)) / (float)totalHandsHS;
		dbLow->Small->All[a,a,a] = (lowerHandsLS + (curHandsLS / 2.0f)) / (float)totalHandsLS;
		lowerHandsHS += curHandsHS;
		lowerHandsLS += curHandsLS;
	}

	///////////////////////
	// 5 card high hands //
	///////////////////////

	// Subtracting 11 because we will count an additional 11 hands below(1-1-1-1-1, 2-2-2-2-2, ... , 12-12-12-12-12) instead of checking every iteration
	long int totalHandsHH = myStats->totalHandsH - 11;
	long int totalHandsLH = myStats->totalHandsL - 11;
	long int totalHandsHM = myStats->totalHandsH - 11;
	long int totalHandsLM = myStats->totalHandsL - 11;

	for(int a=1; a<13; a++)
	{
		for(int b=0; b<=a; b++)
		{
			for(int c=0; c<=b; c++)
			{
				for(int d=0; d<=c; d++)
				{
					for(int e=0; e<=d; e++)
					{
						try
						{
							if(myStats->HH_Other[e,d,c,b,a] == 0)
								totalHandsHH++;
							if(myStats->HM_Other[e,d,c,b,a] == 0)
								totalHandsHM++;
							if(myStats->LH_Other[e,d,c,b,a] == 0)
								totalHandsLH++;
							if(myStats->LM_Other[e,d,c,b,a] == 0)
								totalHandsLM++;
						}
						catch(System::IndexOutOfRangeException^)
						{
							continue;
						}
					}
				}
			}
		}
	}

	for(int a=4; a<13; a++)
	{
		for(int b=3; b<a; b++)
		{
			for(int c=2; c<b; c++)
			{
				for(int d=1; d<c; d++)
				{
					for(int e=0; e<d; e++)
					{
						if(myStats->HH_Flush[e,d,c,b,a] == 0)
							totalHandsHH++;
						if(myStats->HM_Flush[e,d,c,b,a] == 0)
							totalHandsHM++;
						if(myStats->LH_Flush[e,d,c,b,a] == 0)
							totalHandsLH++;
						if(myStats->LM_Flush[e,d,c,b,a] == 0)
							totalHandsLM++;
					}
				}
			}
		}
	}

/*
	long int empty = 0;
	for each(long int i in myStats->HH_Flush)
		if(i==0)
			empty++;
	for each(long int i in myStats->HH_Other)
		if(i==0)
			empty++;
	
	empty = 0;
	for each(long int i in myStats->LH_Flush)
		if(i==0)
			empty++;
	for each(long int i in myStats->LH_Other)
		if(i==0)
			empty++;

	empty = 0;
	for each(long int i in myStats->HM_Flush)
		if(i==0)
			empty++;
	for each(long int i in myStats->HM_Other)
		if(i==0)
			empty++;

	empty = 0;
	for each(long int i in myStats->LM_Flush)
		if(i==0)
			empty++;
	for each(long int i in myStats->LM_Other)
		if(i==0)
			empty++;
	*/
	int lowerHandsHH = 0;
	int lowerHandsLH = 0;
	int lowerHandsHM = 0;
	int lowerHandsLM = 0;

	// High Card
	for(int a=4; a<13; a++)
	{
		for(int b=3; b<a; b++)
		{
			for(int c=2; c<b; c++)
			{
				for(int d=1; d<c; d++)
				{
					for(int e=0; e<d; e++)
					{
						if((d == e+1) && (c == d+1) && (b == c+1) && ((a == b+1) || ((a==12)&&(b==3))))
							continue;
						int curHandsHH = MAX(1, (myStats->HH_Other[e,d,c,b,a]));
						int curHandsLH = MAX(1, (myStats->LH_Other[e,d,c,b,a]));
						int curHandsHM= MAX(1, (myStats->HM_Other[e,d,c,b,a]));
						int curHandsLM= MAX(1, (myStats->LM_Other[e,d,c,b,a]));
						dbHigh->High->Other[e,d,c,b,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
						dbLow->High->Other[e,d,c,b,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
						dbHigh->Middle->Other[e,d,c,b,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
						dbLow->Middle->Other[e,d,c,b,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
						lowerHandsHH += curHandsHH;
						lowerHandsLH += curHandsLH;
						lowerHandsHM += curHandsHM;
						lowerHandsLM += curHandsLM;
					}
				}
			}
		}
	}
	// Pair
	for(int a=0; a < 13; a++)
	{
		for(int b=2; b<13; b++)
		{
			if(b==a)
				continue;
			for(int c=1; c<b; c++)
			{
				if(c==a)
					continue;
				for(int d=0; d<c; d++)
				{
					if(d==a)
						continue;
					if(d>a)
					{
						// [a,a,d,c,b]
						int curHandsHH = MAX(1, (myStats->HH_Other[a,a,d,c,b]));
						int curHandsLH = MAX(1, (myStats->LH_Other[a,a,d,c,b]));
						int curHandsHM= MAX(1, (myStats->HM_Other[a,a,d,c,b]));
						int curHandsLM= MAX(1, (myStats->LM_Other[a,a,d,c,b]));
						dbHigh->High->Other[a,a,d,c,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
						dbLow->High->Other[a,a,d,c,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
						dbHigh->Middle->Other[a,a,d,c,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
						dbLow->Middle->Other[a,a,d,c,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
						lowerHandsHH += curHandsHH;
						lowerHandsLH += curHandsLH;
						lowerHandsHM += curHandsHM;
						lowerHandsLM += curHandsLM;
					}
					else if(c>a)
					{
						// [d,a,a,c,b]
						int curHandsHH = MAX(1, (myStats->HH_Other[d,a,a,c,b]));
						int curHandsLH = MAX(1, (myStats->LH_Other[d,a,a,c,b]));
						int curHandsHM= MAX(1, (myStats->HM_Other[d,a,a,c,b]));
						int curHandsLM= MAX(1, (myStats->LM_Other[d,a,a,c,b]));
						dbHigh->High->Other[d,a,a,c,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
						dbLow->High->Other[d,a,a,c,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
						dbHigh->Middle->Other[d,a,a,c,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
						dbLow->Middle->Other[d,a,a,c,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
						lowerHandsHH += curHandsHH;
						lowerHandsLH += curHandsLH;
						lowerHandsHM += curHandsHM;
						lowerHandsLM += curHandsLM;
					}
					else if(b > a)
					{
						// [d,c,a,a,b]
						int curHandsHH = MAX(1, (myStats->HH_Other[d,c,a,a,b]));
						int curHandsLH = MAX(1, (myStats->LH_Other[d,c,a,a,b]));
						int curHandsHM= MAX(1, (myStats->HM_Other[d,c,a,a,b]));
						int curHandsLM= MAX(1, (myStats->LM_Other[d,c,a,a,b]));
						dbHigh->High->Other[d,c,a,a,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
						dbLow->High->Other[d,c,a,a,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
						dbHigh->Middle->Other[d,c,a,a,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
						dbLow->Middle->Other[d,c,a,a,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
						lowerHandsHH += curHandsHH;
						lowerHandsLH += curHandsLH;
						lowerHandsHM += curHandsHM;
						lowerHandsLM += curHandsLM;
					}
					else
					{
						// [d,c,b,a,a]
						int curHandsHH = MAX(1, (myStats->HH_Other[d,c,b,a,a]));
						int curHandsLH = MAX(1, (myStats->LH_Other[d,c,b,a,a]));
						int curHandsHM= MAX(1, (myStats->HM_Other[d,c,b,a,a]));
						int curHandsLM= MAX(1, (myStats->LM_Other[d,c,b,a,a]));
						dbHigh->High->Other[d,c,b,a,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
						dbLow->High->Other[d,c,b,a,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
						dbHigh->Middle->Other[d,c,b,a,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
						dbLow->Middle->Other[d,c,b,a,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
						lowerHandsHH += curHandsHH;
						lowerHandsLH += curHandsLH;
						lowerHandsHM += curHandsHM;
						lowerHandsLM += curHandsLM;
					}
				}
			}
		}
	}

	// Two Pair
	for(int a=1; a<13; a++)
	{
		for(int b=0; b<a; b++)
		{
			for(int c=0; c<13; c++)
			{
				if(c==a || c==b)
					continue;

				if(c<b)
				{
					// [c,b,b,a,a]
					int curHandsHH = MAX(1, (myStats->HH_Other[c,b,b,a,a]));
					int curHandsLH = MAX(1, (myStats->LH_Other[c,b,b,a,a]));
					int curHandsHM= MAX(1, (myStats->HM_Other[c,b,b,a,a]));
					int curHandsLM= MAX(1, (myStats->LM_Other[c,b,b,a,a]));
					dbHigh->High->Other[c,b,b,a,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[c,b,b,a,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[c,b,b,a,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[c,b,b,a,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
				}
				else if(c<a)
				{
					// [b,b,c,a,a]
					int curHandsHH = MAX(1, (myStats->HH_Other[b,b,c,a,a]));
					int curHandsLH = MAX(1, (myStats->LH_Other[b,b,c,a,a]));
					int curHandsHM= MAX(1, (myStats->HM_Other[b,b,c,a,a]));
					int curHandsLM= MAX(1, (myStats->LM_Other[b,b,c,a,a]));
					dbHigh->High->Other[b,b,c,a,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[b,b,c,a,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[b,b,c,a,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[b,b,c,a,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
				}
				else
				{
					// [b,b,a,a,c]
					int curHandsHH = MAX(1, (myStats->HH_Other[b,b,a,a,c]));
					int curHandsLH = MAX(1, (myStats->LH_Other[b,b,a,a,c]));
					int curHandsHM= MAX(1, (myStats->HM_Other[b,b,a,a,c]));
					int curHandsLM= MAX(1, (myStats->LM_Other[b,b,a,a,c]));
					dbHigh->High->Other[b,b,a,a,c] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[b,b,a,a,c] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[b,b,a,a,c] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[b,b,a,a,c] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
				}
			}
		}
	}
	// Trips
	for(int a=0; a<13; a++)
	{
		for(int b=1; b<13; b++)
		{
			if(b == a)
				continue;
			for(int c=0; c<b; c++)
			{
				if(c == a)
					continue;
				if(a<c)
				{
					//[a,a,a,c,b]
					int curHandsHH = MAX(1, (myStats->HH_Other[a,a,a,c,b]));
					int curHandsLH = MAX(1, (myStats->LH_Other[a,a,a,c,b]));
					int curHandsHM= MAX(1, (myStats->HM_Other[a,a,a,c,b]));
					int curHandsLM= MAX(1, (myStats->LM_Other[a,a,a,c,b]));
					dbHigh->High->Other[a,a,a,c,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[a,a,a,c,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[a,a,a,c,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[a,a,a,c,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
				}
				else if(a<b)
				{
					//[c,a,a,a,b]
					int curHandsHH = MAX(1, (myStats->HH_Other[c,a,a,a,b]));
					int curHandsLH = MAX(1, (myStats->LH_Other[c,a,a,a,b]));
					int curHandsHM= MAX(1, (myStats->HM_Other[c,a,a,a,b]));
					int curHandsLM= MAX(1, (myStats->LM_Other[c,a,a,a,b]));
					dbHigh->High->Other[c,a,a,a,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[c,a,a,a,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[c,a,a,a,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[c,a,a,a,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
				}
				else
				{
					//[c,b,a,a,a]
					int curHandsHH = MAX(1, (myStats->HH_Other[c,b,a,a,a]));
					int curHandsLH = MAX(1, (myStats->LH_Other[c,b,a,a,a]));
					int curHandsHM= MAX(1, (myStats->HM_Other[c,b,a,a,a]));
					int curHandsLM= MAX(1, (myStats->LM_Other[c,b,a,a,a]));
					dbHigh->High->Other[c,b,a,a,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[c,b,a,a,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[c,b,a,a,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[c,b,a,a,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
				}
			}
		}
	}
	// Straight
	{
		// Wheel
		//[0,1,2,3,12]
		int curHandsHH = MAX(1, (myStats->HH_Other[0,1,2,3,12]));
		int curHandsLH = MAX(1, (myStats->LH_Other[0,1,2,3,12]));
		int curHandsHM= MAX(1, (myStats->HM_Other[0,1,2,3,12]));
		int curHandsLM= MAX(1, (myStats->LM_Other[0,1,2,3,12]));
		dbHigh->High->Other[0,1,2,3,12] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
		dbLow->High->Other[0,1,2,3,12] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
		dbHigh->Middle->Other[0,1,2,3,12] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
		dbLow->Middle->Other[0,1,2,3,12] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
		lowerHandsHH += curHandsHH;
		lowerHandsLH += curHandsLH;
		lowerHandsHM += curHandsHM;
		lowerHandsLM += curHandsLM;
	}
	for(int a=0; a<9; a++)
	{
		//[a,a+1,a+2,a+3,a+4]
		int curHandsHH = MAX(1, (myStats->HH_Other[a,a+1,a+2,a+3,a+4]));
		int curHandsLH = MAX(1, (myStats->LH_Other[a,a+1,a+2,a+3,a+4]));
		int curHandsHM= MAX(1, (myStats->HM_Other[a,a+1,a+2,a+3,a+4]));
		int curHandsLM= MAX(1, (myStats->LM_Other[a,a+1,a+2,a+3,a+4]));
		dbHigh->High->Other[a,a+1,a+2,a+3,a+4] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
		dbLow->High->Other[a,a+1,a+2,a+3,a+4] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
		dbHigh->Middle->Other[a,a+1,a+2,a+3,a+4] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
		dbLow->Middle->Other[a,a+1,a+2,a+3,a+4] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
		lowerHandsHH += curHandsHH;
		lowerHandsLH += curHandsLH;
		lowerHandsHM += curHandsHM;
		lowerHandsLM += curHandsLM;
	}

	// Flush
	for(int a=4; a<13; a++)
	{
		for(int b=3; b<a; b++)
		{
			for(int c=2; c<b; c++)
			{
				for(int d=1; d<c; d++)
				{
					for(int e=0; e<d; e++)
					{
						if((d == e+1) && (c == d+1) && (b == c+1) && ((a == b+1) || ((a==12)&&(b==3))))
							continue;

						int curHandsHH = MAX(1, (myStats->HH_Other[e,d,c,b,a]));
						int curHandsLH = MAX(1, (myStats->LH_Other[e,d,c,b,a]));
						int curHandsHM= MAX(1, (myStats->HM_Other[e,d,c,b,a]));
						int curHandsLM= MAX(1, (myStats->LM_Other[e,d,c,b,a]));
						dbHigh->High->Flush[e,d,c,b,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
						dbLow->High->Flush[e,d,c,b,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
						dbHigh->Middle->Flush[e,d,c,b,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
						dbLow->Middle->Flush[e,d,c,b,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
						lowerHandsHH += curHandsHH;
						lowerHandsLH += curHandsLH;
						lowerHandsHM += curHandsHM;
						lowerHandsLM += curHandsLM;
					}
				}
			}
		}
	}

	// Full House
	for(int a=0; a<13; a++)
	{
		for(int b=0; b<13; b++)
		{
			if(b==a)
				continue;
			if(b < a)
			{
				// [b,b,a,a,a];
					int curHandsHH = MAX(1, (myStats->HH_Other[b,b,a,a,a]));
					int curHandsLH = MAX(1, (myStats->LH_Other[b,b,a,a,a]));
					int curHandsHM= MAX(1, (myStats->HM_Other[b,b,a,a,a]));
					int curHandsLM= MAX(1, (myStats->LM_Other[b,b,a,a,a]));
					dbHigh->High->Other[b,b,a,a,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
					dbLow->High->Other[b,b,a,a,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
					dbHigh->Middle->Other[b,b,a,a,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
					dbLow->Middle->Other[b,b,a,a,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
					lowerHandsHH += curHandsHH;
					lowerHandsLH += curHandsLH;
					lowerHandsHM += curHandsHM;
					lowerHandsLM += curHandsLM;
			}
			else
			{
				// [a,a,a,b,b]
				int curHandsHH = MAX(1, (myStats->HH_Other[a,a,a,b,b]));
				int curHandsLH = MAX(1, (myStats->LH_Other[a,a,a,b,b]));
				int curHandsHM= MAX(1, (myStats->HM_Other[a,a,a,b,b]));
				int curHandsLM= MAX(1, (myStats->LM_Other[a,a,a,b,b]));
				dbHigh->High->Other[a,a,a,b,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
				dbLow->High->Other[a,a,a,b,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
				dbHigh->Middle->Other[a,a,a,b,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
				dbLow->Middle->Other[a,a,a,b,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
				lowerHandsHH += curHandsHH;
				lowerHandsLH += curHandsLH;
				lowerHandsHM += curHandsHM;
				lowerHandsLM += curHandsLM;
			}
		}
	}
	// Quads
	for(int a=0; a<13; a++)
	{
		for(int b=0; b<13; b++)
		{
			if(b==a)
				continue;
			if(b < a)
			{
				// [b,a,a,a,a]
				int curHandsHH = MAX(1, (myStats->HH_Other[b,a,a,a,a]));
				int curHandsLH = MAX(1, (myStats->LH_Other[b,a,a,a,a]));
				int curHandsHM= MAX(1, (myStats->HM_Other[b,a,a,a,a]));
				int curHandsLM= MAX(1, (myStats->LM_Other[b,a,a,a,a]));
				dbHigh->High->Other[b,a,a,a,a] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
				dbLow->High->Other[b,a,a,a,a] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
				dbHigh->Middle->Other[b,a,a,a,a] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
				dbLow->Middle->Other[b,a,a,a,a] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
				lowerHandsHH += curHandsHH;
				lowerHandsLH += curHandsLH;
				lowerHandsHM += curHandsHM;
				lowerHandsLM += curHandsLM;
			}
			else
			{
				// [a,a,a,a,b]
				int curHandsHH = MAX(1, (myStats->HH_Other[a,a,a,a,b]));
				int curHandsLH = MAX(1, (myStats->LH_Other[a,a,a,a,b]));
				int curHandsHM= MAX(1, (myStats->HM_Other[a,a,a,a,b]));
				int curHandsLM= MAX(1, (myStats->LM_Other[a,a,a,a,b]));
				dbHigh->High->Other[a,a,a,a,b] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
				dbLow->High->Other[a,a,a,a,b] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
				dbHigh->Middle->Other[a,a,a,a,b] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
				dbLow->Middle->Other[a,a,a,a,b] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
				lowerHandsHH += curHandsHH;
				lowerHandsLH += curHandsLH;
				lowerHandsHM += curHandsHM;
				lowerHandsLM += curHandsLM;
			}
		}
	}
	// Straight Flush
	{
		// Steel Wheel
		int curHandsHH = MAX(1, (myStats->HH_Flush[0,1,2,3,12]));
		int curHandsLH = MAX(1, (myStats->LH_Flush[0,1,2,3,12]));
		int curHandsHM= MAX(1, (myStats->HM_Flush[0,1,2,3,12]));
		int curHandsLM= MAX(1, (myStats->LM_Flush[0,1,2,3,12]));
		dbHigh->High->Flush[0,1,2,3,12] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
		dbLow->High->Flush[0,1,2,3,12] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
		dbHigh->Middle->Flush[0,1,2,3,12] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
		dbLow->Middle->Flush[0,1,2,3,12] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
		lowerHandsHH += curHandsHH;
		lowerHandsLH += curHandsLH;
		lowerHandsHM += curHandsHM;
		lowerHandsLM += curHandsLM;
	}
	for(int a=0; a<9; a++)
	{
		//[a,a+1,a+2,a+3,a+4]
		int curHandsHH = MAX(1, (myStats->HH_Flush[a,a+1,a+2,a+3,a+4]));
		int curHandsLH = MAX(1, (myStats->LH_Flush[a,a+1,a+2,a+3,a+4]));
		int curHandsHM= MAX(1, (myStats->HM_Flush[a,a+1,a+2,a+3,a+4]));
		int curHandsLM= MAX(1, (myStats->LM_Flush[a,a+1,a+2,a+3,a+4]));
		dbHigh->High->Flush[a,a+1,a+2,a+3,a+4] = (lowerHandsHH + (curHandsHH / 2.0f)) / (float)totalHandsHH;
		dbLow->High->Flush[a,a+1,a+2,a+3,a+4] = (lowerHandsLH + (curHandsLH / 2.0f)) / (float)totalHandsLH;
		dbHigh->Middle->Flush[a,a+1,a+2,a+3,a+4] = (lowerHandsHM + (curHandsHM / 2.0f)) / (float)totalHandsHM;
		dbLow->Middle->Flush[a,a+1,a+2,a+3,a+4] = (totalHandsLM - lowerHandsLM - (curHandsLM / 2.0f)) / (float) totalHandsLM;
		lowerHandsHH += curHandsHH;
		lowerHandsLH += curHandsLH;
		lowerHandsHM += curHandsHM;
		lowerHandsLM += curHandsLM;
	}
}

#pragma region Antiquated
/*
	Old SolveAll() / AKA SimHand()
{
	int size = deck->size;
	Database ^db = brain->db;

	int firstHand, lastHand;
	array<float,3> ^smallHand;
	if(generalHandType==HIGH)
	{
		firstHand = HM;
		lastHand = HH;
		smallHand = db->HS_All;
	}
	else
	{
		firstHand = LH;
		lastHand = LM;
		smallHand = db->LS_All;
	}

	float maxSmallHand = 1;
	array<int> ^bestHand = gcnew array<int>(13);
	array<int> ^firstHandArray = gcnew array<int>(5);
	array<int> ^lastHandArray = gcnew array<int>(5);
	array<int> ^smallHandArray = gcnew array<int>(3);

	array<bool> ^dirtyOuter = gcnew array<bool>(size);
	array<bool> ^dirtyInner = gcnew array<bool>(8);
	array<int> ^clean = gcnew array<int>(8);
	
	for(int startIndex = 0; startIndex < size; startIndex += 13)
	{
		float topScore=0;
		for(int a = startIndex; a < startIndex+9; a++)
		{
			dirtyOuter[a] = true;
			firstHandArray[0] = deck[a];
			for(int b = a + 1; b < startIndex+10; b++)
			{
				dirtyOuter[b] = true;
				firstHandArray[1] = deck[b];
				for(int c = b + 1; c < startIndex+11; c++)
				{
					dirtyOuter[c] = true;
					firstHandArray[2] = deck[c];
					for(int d = c + 1; d < startIndex+12; d++)
					{
						dirtyOuter[d] = true;
						firstHandArray[3] = deck[d];
						for(int e = d + 1; e < startIndex+13; e++)
						{
							dirtyOuter[e] = true;
							firstHandArray[4] = deck[e];
							
							#pragma region Evaluate(firstHand)
							float valueF;

							int rankF0 = RANK(firstHandArray[0]);
							int rankF1 = RANK(firstHandArray[1]);
							int rankF2 = RANK(firstHandArray[2]);
							int rankF3 = RANK(firstHandArray[3]);
							int rankF4 = RANK(firstHandArray[4]);
							
							// Flush
							if((firstHandArray[0] & firstHandArray[1] & firstHandArray[2] & firstHandArray[3] & firstHandArray[4] & 0xF) != 0)
							{
								if((rankF1 + 1 == rankF2) && (rankF2 + 1 == rankF3) && (rankF3 + 1 == rankF4) && ((rankF0 + 1 == rankF1) || (rankF0 == 12 && rankF1 == 0)))
								{
									valueF = db->HandLookup(firstHand, STRAIGHT_FLUSH, rankF0, 0, 0, 0, 0);
								}
								else
								{
									valueF = db->HandLookup(firstHand, FLUSH, rankF4, rankF3, rankF2, rankF1, rankF0);
								}
							}
							else if(brain->isUnique[(firstHandArray[0] | firstHandArray[1] | firstHandArray[2] | firstHandArray[3] | firstHandArray[4]) >> 10])
							{
								// if 5 bits are high, all cards are unique by rank and hand is straight or high card
								if((rankF1 + 1 == rankF2) && (rankF2 + 1 == rankF3) && (rankF3 + 1 == rankF4) && ((rankF0 + 1 == rankF1) || (rankF0 == 12 && rankF1 == 0)))
								{
									valueF = db->HandLookup(firstHand, STRAIGHT, rankF0, 0, 0, 0, 0);
								}
								else
								{
									valueF = db->HandLookup(firstHand, HIGH_CARD, rankF4, rankF3, rankF2, rankF1, rankF0);
									maxSmallHand = smallHand[rankF4, rankF3, rankF2];
								}
							}
							else
							{
								// Paired hand
								bool pair01 = (rankF0 == rankF1);
								bool pair12 = (rankF1 == rankF2);
								bool pair23 = (rankF2 == rankF3);
								bool pair34 = (rankF3 == rankF4);
								
								if(pair01)
								{
									if(pair23) // Check for 2 pair or quads first because it allows an early exit
									{
										if(pair34)
											valueF = db->HandLookup(firstHand, FULL_HOUSE, rankF3, 0, 0, 0, 0);
										else if(pair12)
											valueF = db->HandLookup(firstHand, QUADS, rankF0, 0, 0, 0, 0);
										else
										{
											valueF = db->HandLookup(firstHand, TWO_PAIR, rankF2, rankF0, rankF4, 0, 0);
											maxSmallHand = smallHand[12,12,11];
										}
									}
									else if(pair34)
									{
										if(pair12)
										{
											valueF = db->HandLookup(firstHand, FULL_HOUSE, rankF0, 0, 0, 0, 0);
										}
										else
										{
											valueF = db->HandLookup(firstHand, TWO_PAIR, rankF4, rankF0, rankF2, 0, 0);
											maxSmallHand = smallHand[12,12,11];
										}
									}
									else if(pair12)
									{
										valueF = db->HandLookup(firstHand, TRIPS, rankF0, 0, 0, 0, 0);
										maxSmallHand = smallHand[rankF0,rankF0,rankF0];
									}
									else
									{
										valueF = db->HandLookup(firstHand, PAIR, rankF0, rankF4, rankF3, rankF2, 0);
										maxSmallHand = smallHand[rankF4,rankF0,rankF0];
									}
								}
								else if(pair12)
								{
									if(pair34)
									{
										if(pair23)
											valueF = db->HandLookup(firstHand, QUADS, rankF1, 0, 0, 0, 0);
										else
										{
											valueF = db->HandLookup(firstHand, TWO_PAIR, rankF3, rankF1, rankF0, 0, 0);
											maxSmallHand = smallHand[12,12,11];
										}
									}
									else if(pair23)
									{
										valueF = db->HandLookup(firstHand, TRIPS, rankF1, 0, 0, 0, 0);
										maxSmallHand = smallHand[rankF1,rankF1,rankF1];
									}
									else
									{
										valueF = db->HandLookup(firstHand, PAIR, rankF1, rankF4, rankF3, rankF0, 0);
										maxSmallHand = smallHand[rankF4,rankF1,rankF1];
									}
								}
								else if(pair23)
								{
									if(pair34)
									{
										valueF = db->HandLookup(firstHand, TRIPS, rankF2, 0, 0, 0, 0);
										maxSmallHand = smallHand[rankF2,rankF2,rankF2];
									}
									else
									{
										valueF = db->HandLookup(firstHand, PAIR, rankF2, rankF4, rankF1, rankF0, 0);
										maxSmallHand = smallHand[rankF4,rankF2,rankF2];
									}
								}
								else 
								{
									valueF = db->HandLookup(firstHand, PAIR, rankF3, rankF2, rankF1, rankF0, 0);
									maxSmallHand = smallHand[rankF3,rankF3,rankF2];
								}
							}
							/*
							//-------------Begin Evaluate(firstHand)------------------
							//
							float valueF;
							int rank0 = RANK(firstHandArray[0]);
							int rank1 = RANK(firstHandArray[1]);
							int rank2 = RANK(firstHandArray[2]);
							int rank3 = RANK(firstHandArray[3]);
							int rank4 = RANK(firstHandArray[4]);
							
							// Pair
							if(rank0 == rank1)
							{
								if(rank2 == rank3)
								{
									if(rank1 == rank2)
									{
										valueF = db->HandLookup(firstHand, QUADS, rank2, 0, 0, 0, 0);
										maxSmallHand = 1;
									}
									else if(rank3 == rank4)
									{
										valueF = db->HandLookup(firstHand, FULL_HOUSE, rank3, 0, 0, 0, 0);
										maxSmallHand = 1;
									}
									else
									{
										valueF = db->HandLookup(firstHand, TWO_PAIR, rank2, rank0, rank4, 0, 0);
										maxSmallHand = db->LS_All[12,12,11];
									}
								}
								else if(rank3 == rank4)
								{
									if(rank1 == rank2)
									{
										valueF = db->HandLookup(firstHand, FULL_HOUSE, rank2, 0, 0, 0, 0);
										maxSmallHand = 1;
									}
									else 
									{
										valueF = db->HandLookup(firstHand, TWO_PAIR, rank4, rank0, rank2, 0, 0);
										maxSmallHand = db->LS_All[12,12,11];
									}
								}
								else if(rank1 == rank2)
								{
									valueF = db->HandLookup(firstHand, TRIPS, rank0, 0, 0, 0, 0);
									maxSmallHand = db->LS_All[rank0,rank0,rank0];
								}
								else
								{
									valueF = db->HandLookup(firstHand, PAIR, rank0, rank4, rank3, rank2, 0);
									maxSmallHand = db->LS_All[rank0,rank0,rank4];
								}
							}
							else if(rank1 == rank2)
							{
								if(rank3 == rank4)
								{
									if(rank2 == rank3)
									{
										valueF = db->HandLookup(firstHand, QUADS, rank1, 0, 0, 0, 0);
										maxSmallHand = 1;
									}
									else
									{
										valueF = db->HandLookup(firstHand, TWO_PAIR, rank3, rank1, rank0, 0, 0);
										maxSmallHand = db->LS_All[12,12,11];
									}
								}
								else if(rank2 == rank3)
								{
									valueF = db->HandLookup(firstHand, TRIPS, rank1, 0, 0, 0, 0);
									maxSmallHand = db->LS_All[rank1,rank1,rank1];
								}
								else
								{
									valueF = db->HandLookup(firstHand, PAIR, rank1, rank4, rank3, rank0, 0);
									maxSmallHand = db->LS_All[rank4,rank1,rank1];
								}
							}
							else if(rank2 == rank3)
							{
								if(rank4 == rank3)
								{
									valueF = db->HandLookup(firstHand, TRIPS, rank2, 0, 0, 0, 0);
									maxSmallHand = db->LS_All[rank2,rank2,rank2];
								}
								else
								{
									valueF = db->HandLookup(firstHand, PAIR, rank2, rank4, rank1, rank0, 0);
									maxSmallHand = db->LS_All[rank4,rank2,rank2];
								}
							}
							else if(rank3 == rank4)
							{
								valueF = db->HandLookup(firstHand, PAIR, rank3, rank2, rank1, rank0, 0);
								maxSmallHand = db->LS_All[rank3,rank3,rank2];
							}
							// No pairs
							else if((rank1 + 1 == rank2) && (rank2 + 1 == rank3) && (rank3 + 1 == rank4) && ((rank0 + 1 == rank1) || (rank0 == 12 && rank1 == 0)))
							{
								// Straight
								if((firstHandArray[0] & firstHandArray[1] & firstHandArray[2] & firstHandArray[3] & firstHandArray[4] & 0xF) != 0)
								{
									valueF = db->HandLookup(firstHand, STRAIGHT_FLUSH, rank0, 0, 0, 0, 0);
									maxSmallHand = 1;
								}
								else
								{
									valueF = db->HandLookup(firstHand, STRAIGHT, rank0, 0, 0, 0, 0);
									maxSmallHand = 1;
								}
							}
							else if((firstHandArray[0] & firstHandArray[1] & firstHandArray[2] & firstHandArray[3] & firstHandArray[4] & 0xF) != 0)
							{
								valueF = db->HandLookup(firstHand, FLUSH, rank4, rank3, rank2, rank1, rank0);
								maxSmallHand = 1;
							}
							else
							{
								valueF = db->HandLookup(firstHand, HIGH_CARD, rank4, rank3, rank2, rank1, rank0);
								maxSmallHand = db->LS_All[rank4,rank3,rank2];
							}
							//--------------End Evaluate(firstHand)-------------------
#pragma endregion

							// We have picked the first hand, the hand that forces the maximum small hand value. Copy the remaining values into clean[] and continue iterating through that
							int cleanIndex=0;
							for(int ind=startIndex; cleanIndex < 8; ind++)
							{
								if(!dirtyOuter[ind])
									clean[cleanIndex++] = deck[ind];
							}			

							for(int i = 0; i < 6; i++)
							{
								dirtyInner[i] = true;
								smallHandArray[0] = clean[i];
								for(int j = i + 1; j < 7; j++)
								{
									dirtyInner[j] = true;
									smallHandArray[1] = clean[j];
									for(int k = j + 1; k < 8; k++)
									{
										smallHandArray[2] = clean[k];
										// We now have the small hand
										#pragma region Evaluate(SmallHand)
										//-------------Begin Evaluate(SmallHand)------------------
										float valueS;
										if(generalHandType == HIGH)
										{
											valueS = db->HS_All[RANK(smallHandArray[0]), RANK(smallHandArray[1]), RANK(smallHandArray[2])];
										}
										else
										{
											valueS = db->LS_All[RANK(smallHandArray[0]), RANK(smallHandArray[1]), RANK(smallHandArray[2])];
										}
										//--------------End Evaluate(SmallHand)-------------------
										#pragma endregion

										// Check hand legality
										if(valueS > maxSmallHand)
											continue;

										dirtyInner[k] = true; // These are usually at the start of the loop, but not this one because of previous continues				
										// The middle hand is implicit from the dirty bits
										int midCounter = 0;
										for(int midIndex = 0; midCounter != 5; midIndex++)
										{
											if(!dirtyInner[midIndex])
												lastHandArray[midCounter++] = clean[midIndex];
										}
										dirtyInner[k] = false; // This is usually at the end of a loop. Doing it here allows us to use 'continue's below.
											
										float value2;
										#pragma region Evaluate(lastHand)
										int rankL0 = RANK(lastHandArray[0]);
										int rankL1 = RANK(lastHandArray[1]);
										int rankL2 = RANK(lastHandArray[2]);
										int rankL3 = RANK(lastHandArray[3]);
										int rankL4 = RANK(lastHandArray[4]);
										
										// Flush
										if((lastHandArray[0] & lastHandArray[1] & lastHandArray[2] & lastHandArray[3] & lastHandArray[4] & 0xF) != 0)
										{
											if((rankL1 + 1 == rankL2) && (rankL2 + 1 == rankL3) && (rankL3 + 1 == rankL4) && ((rankL0 + 1 == rankL1) || (rankL0 == 12 && rankL1 == 0)))
											{
												if(generalHandType==HIGH)
												{
													if(valueF > db->HM_Straight_Flush[rankL0])
														continue;
													else
														value2 = db->HH_Straight_Flush[rankL0];
												}
												else 
													value2 = db->LM_Straight_Flush[rankL0];
											}
											else
											{
												if(generalHandType==HIGH)
												{
													if(valueF > db->HM_Flush[rankL4-5][rankL3-3,rankL2-2,rankL1-1,rankL0])
														continue;
													else
														value2 = db->HH_Flush[rankL4-5][rankL3-3,rankL2-2,rankL1-1,rankL0];
												}
												else
													value2 = db->LM_Flush[rankL4-5][rankL3-3,rankL2-2,rankL1-1,rankL0];
											}
										}
										else if(brain->isUnique[(lastHandArray[0] | lastHandArray[1] | lastHandArray[2] | lastHandArray[3] | lastHandArray[4]) >> 10])
										{
											// if 5 bits are high, all cards are unique by rank and hand is straight or high card
											if((rankL1 + 1 == rankL2) && (rankL2 + 1 == rankL3) && (rankL3 + 1 == rankL4) && ((rankL0 + 1 == rankL1) || (rankL0 == 12 && rankL1 == 0)))
											{
												if(generalHandType==HIGH)
												{
													if(valueF > db->HM_Straight[rankL0])
														continue;
													else
														value2 = db->HH_Straight[rankL0];
												}
												else
													value2 = db->LM_Straight[rankL0];
											}
											else
											{
												if(generalHandType==HIGH)
												{
													if(valueF > db->HM_High_Card[rankL4-5][rankL3-3,rankL2-2,rankL1-1,rankL0])
														continue;
													else
														value2 = db->HH_High_Card[rankL4-5][rankL3-3,rankL2-2,rankL1-1,rankL0];
												}
												else
													value2 = db->LM_High_Card[rankL4-5][rankL3-3, rankL2-2, rankL1-1, rankL0];
											}
										}
										else
										{
											// Paired hand
											bool pair01 = (rankL0 == rankL1);
											bool pair12 = (rankL1 == rankL2);
											bool pair23 = (rankL2 == rankL3);
											bool pair34 = (rankL3 == rankL4);
											
											if(pair01)
											{
												if(pair23) // Check for 2 pair or quads first because it allows an early exit
												{
													if(pair34)
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Full_House[rankL3])
																continue;
															else
																value2 = db->HH_Full_House[rankL3];
														}
														else
															value2 = db->LM_Full_House[rankL3];
													}
													else if(pair12)
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Quads[rankL0])
																continue;
															else
																value2 = db->HH_Quads[rankL0];
														}
														else
															value2 = db->LM_Quads[rankL0];
													}
													else
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Two_Pair[rankL2,rankL0,rankL4])
																continue;
															else
																value2 = db->HH_Two_Pair[rankL2,rankL0,rankL4];
														}
														else
															value2 = db->LM_Two_Pair[rankL2,rankL0,rankL4];
													}
												}
												else if(pair34)
												{
													if(pair12)
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Full_House[rankL0])
																continue;
															else
																value2 = db->HH_Full_House[rankL0];
														}
														else
															value2 = db->LM_Full_House[rankL0];
													}
													else
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Two_Pair[rankL4,rankL0,rankL2])
																continue;
															else
																value2 = db->HH_Two_Pair[rankL4,rankL0,rankL2];
														}
														else
															value2 = db->LM_Two_Pair[rankL4,rankL0,rankL2];
													}
												}
												else if(pair12)
												{
													if(generalHandType==HIGH)
													{
														if(valueF > db->HM_Trips[rankL0])
															continue;
														else
															value2 = db->HH_Trips[rankL0];
													}
													else
														value2 = db->LM_Trips[rankL0];
												}
												else
												{
													if(generalHandType==HIGH)
													{
														if(valueF > db->HM_Pair[rankL0,rankL4,rankL3,rankL2])
															continue;
														else
															value2 = db->HH_Pair[rankL0,rankL4,rankL3,rankL2];
													}
													else
														value2 = db->LM_Pair[rankL0,rankL4,rankL3,rankL2];
												}
											}
											else if(pair12)
											{
												if(pair34)
												{
													if(pair23)
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Quads[rankL1])
																continue;
															else
																value2 = db->HH_Quads[rankL1];
														}
														else
															value2 = db->LM_Quads[rankL1];
													}
													else
													{
														if(generalHandType==HIGH)
														{
															if(valueF > db->HM_Two_Pair[rankL3,rankL1,rankL0])
																continue;
															else
																value2 = db->HH_Two_Pair[rankL3,rankL1,rankL0];
														}
														else
															value2 = db->LM_Two_Pair[rankL3,rankL1,rankL0];
													}
												}
												else if(pair23)
												{
													if(generalHandType==HIGH)
													{
														if(valueF > db->HM_Trips[rankL1])
															continue;
														else
															value2 = db->HH_Trips[rankL1];
													}
													else
														value2 = db->LM_Trips[rankL1];
												}
												else
												{
													if(generalHandType==HIGH)
													{
														if(valueF > db->HM_Pair[rankL2,rankL4,rankL3,rankL0])
															continue;
														else
															value2 = db->HH_Pair[rankL2,rankL4,rankL3,rankL0];
													}
													else
														value2 = db->LM_Pair[rankL2,rankL4,rankL3,rankL0];
												}
											}
											else if(pair23)
											{
												if(pair34)
												{
													if(generalHandType==HIGH)
													{
														if(valueF > db->HM_Trips[rankL2])
															continue;
														else
															value2 = db->HH_Trips[rankL2];
													}
													else
														value2 = db->LM_Trips[rankL2];
												}
												else
												{
													if(generalHandType==HIGH)
													{
														if(valueF > db->HM_Pair[rankL2,rankL4,rankL1,rankL0])
															continue;
														else
															value2 = db->HH_Pair[rankL2,rankL4,rankL1,rankL0];
													}
													else
														value2 = db->LM_Pair[rankL2,rankL4,rankL1,rankL0];
												}
											}
											else 
											{
												if(generalHandType==HIGH)
												{
													if(valueF > db->HM_Pair[rankL3,rankL2,rankL1,rankL0])
														continue;
													else
														value2 = db->HH_Pair[rankL3,rankL2,rankL1,rankL0];
												}
												else
													value2 = db->LM_Pair[rankL3,rankL2,rankL1,rankL0];
											}
										}
											
										/*
										//-------------Begin Evaluate(lastHand)------------------
										int rankM0 = RANK(lastHandArray[0]);
										int rankM1 = RANK(lastHandArray[1]);
										int rankM2 = RANK(lastHandArray[2]);
										int rankM3 = RANK(lastHandArray[3]);
										int rankM4 = RANK(lastHandArray[4]);
										
										// Pair
										if(rankM0 == rankM1)
										{
											if(rankM2 == rankM3)
											{
												if(rankM1 == rankM2)
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Quads[rankM0])
															continue;
														value2 = db->HH_Quads[rankM0];
													}
													else
														value2 = db->LM_Quads[rankM0];
												}
												else if(rankM3 == rankM4)
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Full_House[rankM3])
															continue;
														value2 = db->HH_Full_House[rankM3];
													}
													else
														value2 = db->LM_Full_House[rankM3];
												}
												else
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Two_Pair[rankM2,rankM0,rankM4])
															continue;
														value2 = db->HH_Two_Pair[rankM2,rankM0,rankM4];
													}
													else
														value2 = db->LM_Two_Pair[rankM2,rankM0,rankM4];
												}
											}
											else if(rankM3 == rankM4)
											{
												if(rankM1 == rankM2)
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Full_House[rankM0])
															continue;
														value2 = db->HH_Full_House[rankM0];
													}
													else
														value2 = db->LM_Full_House[rankM0];
												}
												else 
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Two_Pair[rankM4,rankM0,rankM2])
															continue;
														value2 = db->HH_Two_Pair[rankM4,rankM0,rankM2];
													}
													else
														value2 = db->LM_Two_Pair[rankM4,rankM0,rankM2];
												}
											}
											else if(rankM1 == rankM2)
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Trips[rankM0])
														continue;
													value2 = db->HH_Trips[rankM0];
												}
												else
													value2 = db->LM_Trips[rankM0];
											}
											else
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Pair[rankM0,rankM4,rankM3,rankM2])
														continue;
													value2 = db->HH_Pair[rankM0,rankM4,rankM3,rankM2];
												}
												else
													value2 = db->LM_Pair[rankM0,rankM4,rankM3,rankM2];
											}
										}
										else if(rankM1 == rankM2)
										{
											if(rankM3 == rankM4)
											{
												if(rankM2 == rankM3)
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Quads[rankM3])
															continue;
														value2 = db->HH_Quads[rankM3];
													}
													else
														value2 = db->LM_Quads[rankM3];
												}
												else
												{
													if(generalHandType == HIGH)
													{
														if(valueF > db->HM_Two_Pair[rankM3,rankM1,rankM0])
															continue;
														value2 = db->HH_Two_Pair[rankM3,rankM1,rankM0];
													}
													else
														value2 = db->LM_Two_Pair[rankM3,rankM1,rankM0];
												}
											}
											else if(rankM2 == rankM3)
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Trips[rankM1])
														continue;
													value2 = db->HH_Trips[rankM1];
												}
												else
													value2 = db->LM_Trips[rankM1];
											}
											else
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Pair[rankM1,rankM4,rankM3,rankM0])
														continue;
													value2 = db->HH_Pair[rankM1, rankM4, rankM3, rankM0];
												}
												else
													value2 = db->LM_Pair[rankM1,rankM4,rankM3,rankM0];
											}
										}
										else if(rankM2 == rankM3)
										{
											if(rankM4 == rankM3)
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Trips[rankM2])
														continue;
													value2 = db->HH_Trips[rankM2];
												}
												else
													value2 = db->LM_Trips[rankM2];
											}
											else
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Pair[rankM2,rankM4,rankM1,rankM0])
														continue;
													value2 = db->HH_Pair[rankM2,rankM4,rankM1,rankM0];
												}
												else
													value2 = db->LM_Pair[rankM2,rankM4,rankM1,rankM0];
											}
										}
										else if(rankM3 == rankM4)
										{
											if(generalHandType == HIGH)
											{
												if(valueF > db->HM_Pair[rankM3,rankM2,rankM1,rankM0])
													continue;
												value2 = db->HH_Pair[rankM3,rankM2,rankM1,rankM0];
											}
											else
												value2 = db->LM_Pair[rankM3,rankM2,rankM1,rankM0];
										}
										// No pairs
										else if((rankM1 + 1 == rankM2) && (rankM2 + 1 == rankM3) && (rankM3 + 1 == rankM4) && ((rankM0 + 1 == rankM1) || (rankM0 == 12 && rankM1 == 0)))
										{
											// Straight
											if((lastHandArray[0] & lastHandArray[1] & lastHandArray[2] & lastHandArray[3] & lastHandArray[4] & 0xF) != 0)
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Straight_Flush[rankM0])
														continue;
													value2 = db->HH_Straight_Flush[rankM0];
												}
												else
													value2 = db->LM_Straight_Flush[rankM0];
											}
											else
											{
												if(generalHandType == HIGH)
												{
													if(valueF > db->HM_Straight[rankM0])
														continue;
													value2 = db->HH_Straight[rankM0];
												}
												else
													value2 = db->LM_Straight[rankM0];
											}
										}
										else if((lastHandArray[0] & lastHandArray[1] & lastHandArray[2] & lastHandArray[3] & lastHandArray[4] & 0xF) != 0)
										{
											if(generalHandType == HIGH)
											{
												if(valueF > db->HM_Flush[rankM4-5][rankM3-3,rankM2-2,rankM1-1,rankM0])
													continue;
												value2 = db->HH_Flush[rankM4-5][rankM3-3,rankM2-2,rankM1-1,rankM0];
											}
											else
												value2 = db->LM_Flush[rankM4-5][rankM3-3,rankM2-2,rankM1-1,rankM0];
										}
										else
										{
											if(generalHandType == HIGH)
											{
												if(valueF > db->HM_High_Card[rankM4-5][rankM3-3,rankM2-2,rankM1-1,rankM0])
													continue;
												value2 = db->HH_High_Card[rankM4-5][rankM3-3,rankM2-2,rankM1-1,rankM0];
											}
											else
												value2 = db->LM_High_Card[rankM4-5][rankM3-3,rankM2-2,rankM1-1,rankM0];
										}
										//--------------End Evaluate(midHand)-------------------
										*
										#pragma endregion

										// Hand has already proven it is valid (IsValid() will return true)
										float myScore = valueF + valueS + value2;
										if(myScore > topScore)
										{
											#pragma region Set Top Score
											topScore = myScore;
											if(generalHandType == LOW)
											{
												bestHand[0] = firstHandArray[0];									
												bestHand[1] = firstHandArray[1];									
												bestHand[2] = firstHandArray[2];									
												bestHand[3] = firstHandArray[3];									
												bestHand[4] = firstHandArray[4];									
												bestHand[5] = lastHandArray[0];									
												bestHand[6] = lastHandArray[1];									
												bestHand[7] = lastHandArray[2];									
												bestHand[8] = lastHandArray[3];									
												bestHand[9] = lastHandArray[4];									
												bestHand[10] = smallHandArray[0];									
												bestHand[11] = smallHandArray[1];									
												bestHand[12] = smallHandArray[2];
											}
											else // generalHandType == HIGH
											{
												bestHand[0] = lastHandArray[0];									
												bestHand[1] = lastHandArray[1];									
												bestHand[2] = lastHandArray[2];									
												bestHand[3] = lastHandArray[3];									
												bestHand[4] = lastHandArray[4];									
												bestHand[5] = firstHandArray[0];									
												bestHand[6] = firstHandArray[1];									
												bestHand[7] = firstHandArray[2];									
												bestHand[8] = firstHandArray[3];									
												bestHand[9] = firstHandArray[4];									
												bestHand[10] = smallHandArray[0];									
												bestHand[11] = smallHandArray[1];									
												bestHand[12] = smallHandArray[2];
											}
#pragma endregion
										}
									}
									dirtyInner[j] = false;
								}
								dirtyInner[i] = false;
							}
							dirtyOuter[e] = false;
						}
						dirtyOuter[d] = false;
					}
					dirtyOuter[c] = false;
				}
				dirtyOuter[b] = false;
			}
			dirtyOuter[a] = false;
		}

		// Organize the actual hand to equal the best permutation (assumes the same cards are in both arrays)
		for(int i = 0; i < 13; i++)
			deck->cards[i + startIndex] = bestHand[i];
	}

	delete bestHand;
	delete firstHandArray;
	delete lastHandArray;
	delete smallHandArray;
	delete dirtyOuter;
	delete dirtyInner;
}
*/
/*

		// Check middle hand vs high hand
		if(valH > db->HH_High_Card[7][8,8,8,7])
		{
			if(valM <= db->HM_High_Card[7][8,8,8,7])
				return true;
			if(valH > db->HH_Pair[12,11,10,9])
			{
				if(valM <= db->HM_Pair[12,11,10,9])
					return true;						
				if(valH > db->HH_Two_Pair[12,11,10])
				{
					if(valM <= db->HM_Two_Pair[12,11,10])
						return true;
					if(valH > db->HH_Trips[12])
					{
						if(valM <= db->HM_Trips[12])
							return true;
						if(valH > db->HH_Straight[8])
						{
							if(valM <= db->HM_Straight[8])
								return true;
							if(valH > db->HH_Flush[7][8,8,8,7])
							{
								if(valM <= db->HM_Flush[7][8,8,8,7])
									return true;
								if(valH > db->HH_Full_House[12])
								{
									if(valM <= db->HM_Full_House[12])
										return true;
									if(valH > db->HH_Quads[12])
									{
										if(valM <= db->HM_Quads[12])
											return true;
										// Both hands are Straight Flushes
										return a >= f;
									}
									else if(valM > db->HM_Quads[12])
										return false;
									else
										return b > g;
								}
								else if(valM > db->HM_Full_House[12])
									return false;
								else
									return c > h;
							}
							else if(valM > db->HM_Flush[7][8,8,8,7])
								return false;
							else
							{
								if(RANK(e) > RANK(j)) return true;
								if(RANK(j) > RANK(e)) return false;
								if(RANK(d) > RANK(i)) return true;
								if(RANK(i) > RANK(d)) return false;
								if(RANK(c) > RANK(h)) return true;
								if(RANK(h) > RANK(c)) return false;
								if(RANK(b) > RANK(g)) return true;
								if(RANK(g) > RANK(b)) return false;
								return (RANK(a) >= RANK(f));
							}
						}
						else if(valM > db->HM_Straight[8])
							return false;
						else
							return RANK(a) > RANK(f);
					}
					else if(valM > db->HM_Trips[12])
						return false;
					else
						return RANK(c) > RANK(h);
				}
				else if(valM > db->HM_Two_Pair[12,11,10])
					return false;
				else
				{
					if(RANK(d) > RANK(i)) return true;
					if(RANK(i) > RANK(d)) return false;
					if(RANK(b) > RANK(g)) return true;
					if(RANK(g) > RANK(b)) return false;
					if(RANK(e) > RANK(j)) return true;
					if(RANK(j) > RANK(e)) return false;
					if(RANK(c) > RANK(h)) return true;
					if(RANK(h) > RANK(c)) return false;
					return RANK(a) >= RANK(f);
				}
			}
			if(valM > db->HM_Pair[12,11,10,9])
				return false;
			else
			{
				// Both hands are 1 pair
				// Find pair values
				int pairValue, pairValue2;
				if(RANK(a) == RANK(b))
				{
					pairValue = a;
				}
				else if(RANK(b) == RANK(c))
				{
					pairValue = b;
				}
				else if(RANK(c) == RANK(d))
				{
					pairValue = c;
				}
				else // RANK(d) == RANK(e)
				{
					pairValue = d;
				}

				if(RANK(f) == RANK(g))
				{
					pairValue2 = f;
				}
				else if(RANK(g) == RANK(h))
				{
					pairValue2 = g;
				}
				else if(RANK(h) == RANK(i))
				{
					pairValue2 = h;
				}
				else //RANK(i) == RANK(j)
				{
					pairValue2 = i;
				}

				if(RANK(pairValue) < RANK(pairValue2))
					return false;
				if(RANK(pairValue) > RANK(pairValue2))
					return true;
				
				// Pairs are the same value
				if(RANK(e) > RANK(j))
					return true;
				if(RANK(j) > RANK(e))
					return false;
				if(RANK(d) > RANK(i))
					return true;
				if(RANK(i) > RANK(d))
					return false;
				if(RANK(c) > RANK(h))
					return true;
				if(RANK(h) > RANK(c))
					return false;
				if(RANK(b) > RANK(g))
					return true;
				if(RANK(g) > RANK(b))
					return false;
				return RANK(a) >= RANK(f);
			}
		}
		else if(valM > db->HM_High_Card[7][8,8,8,7])
			return false;
		else
		{
			// Both hands are high cards only
			if(RANK(e) > RANK(j))
				return true;
			if(RANK(j) > RANK(e))
				return false;
			if(RANK(d) > RANK(i))
				return true;
			if(RANK(i) > RANK(d))
				return false;
			if(RANK(c) > RANK(h))
				return true;
			if(RANK(h) > RANK(c))
				return false;
			if(RANK(b) > RANK(g))
				return true;
			if(RANK(g) > RANK(b))
				return false;
			return RANK(a) >= RANK(f);
		}
	}
*/
/*	else if(isUnique[(c0 | c1 | c2 | c3 | c4) >> 10])
	{
		returnValue = data->High_Card[rank4][rank3,rank2,rank1,rank0];
	}
	else
	{
		// Paired hand, max of 4 comparisons and 1 array lookup
		if((rank0 == rank1)
		{
			if(rank2 == rank3)
			{
				if(rank3 == rank4)
				{
					returnValue = data->Full_House[rank3];
				}
				else if(rank1 == rank2)
				{
					returnValue = data->Quads[rank0];
				}
				else
				{
					returnValue = data->Two_Pair[rank2,rank0,rank4];
				}
			}
			else if(rank3 == rank4)
			{
				if(rank1 == rank2)
				{
					returnValue = data->Full_House[rank0];
				}
				else
				{
					returnValue = data->Two_Pair[rank4,rank0,rank2];
				}
			}
			else if(rank1 == rank2)
			{
				returnValue = data->Trips[rank0];
			}
			else
			{
				returnValue = data->Pair[rank0,rank4,rank3,rank2];
			}
		}
		else if(rank1 == rank2)
		{
			if(rank3 == rank4)
			{
				if(rank2 == rank3)
				{
					returnValue = data->Quads[rank1];
				}
				else
				{
					returnValue = data->Two_Pair[rank3,rank1,rank0];
				}
			}
			else if(rank2 == rank3)
			{
				returnValue = data->Trips[rank1];
			}
			else
			{
				returnValue = data->Pair[rank1,rank4,rank3,rank0];
			}
		}
		else if(rank2 == rank3)
		{
			if(rank3 == rank4)
			{
				returnValue = data->Trips[rank2];
			}
			else
			{
				returnValue = data->Pair[rank2,rank4,rank1,rank0];
			}
		}
		else
		{
			returnValue = data->Pair[rank3,rank2,rank1,rank0];
		}
	}
	return returnValue;
}
*/

#pragma endregion
/*
void Brain::Learn(void)
{
	float rankValue;
	float offset = 0;
	float inc = 0.0000005f;
	
	float HCval = 0.0f;
	float Pval = 0.1f;
	float TPval = 0.2f;
	float Tval = 0.3f;
	float Sval = 0.4f;
	float Fval = 0.5f;
	float FHval = 0.7f;
	float Qval = 0.9f;
	float SFval = 0.98f;

	float LowHCval = 0.9f;
	float LowPval = 0.1f;
	float LowTPval = 0.07f;
	float LowTval = 0.06f;
	float LowSval = 0.05f;
	float LowFval = 0.04f;
	float LowFHval = 0.03f;
	float LowQval = 0.02f;
	float LowSFval = 0.01f;

	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 13; j++)
		{
			for(int k = 0; k < 13; k++)
			{
				//continue;
				// 3 card hands
				if(i == j && j == k)
				{
					rankValue = 0.8f + 0.015f * offset;
				}
				else if(i == j)
				{
					rankValue = 0.1f + 0.05f * j + 0.001f * k;
				}
				else if(j == k)
				{
					rankValue = 0.1f + 0.05f * j + 0.001f * i;
				}
				else if(i == k)
				{
					rankValue = 0.1f + 0.05f * i + 0.001f * j;
				}
				else if(i > j && j > k)
				{
					rankValue = 0.005f * i + 0.0001f * j + 0.000005f * k;
				}
				dbHigh->Small->All[i,j,k] = rankValue;
				dbLow->Small->All[i,j,k] = rankValue;
				offset += inc;
			}
		}
	}
	
	offset = 0;	
	for(int i = 0; i < 12; i++)
		for(int j = i; j < 13+i; j++)
			for(int k = j; k < 13; k++)
				for(int l = k; l < 13; l++)
					for(int m = l; m < 13; m++)
					{	
						bool isStraight = j+1==k && k+1==l && l+1==m && (i+1==j || (i==12 && j==0));
						if(i==j)
						{
							if(j==k)
							{
								if(k==l)
									rankValue = Qval;
								else
									rankValue = (l==m ? FHval : Tval);
							}
							else if(k==l)
								rankValue = (l==m ? FHval : TPval);
							else
								rankValue = (l==m ? TPval : Pval);

						}
						else if(j==k)
						{
							if(k==l)
								rankValue = (l==m ? Qval : Tval);
							else if(l==m)
								rankValue = TPval;
						}
						else if(k==l)
						{
							rankValue = (l==m ? Tval : Pval);
						}
						else if(l==m)
						{
							rankValue = Pval;
						}
						else
						{
							rankValue = isStraight ? Sval : HCval;
						}

						//dbHigh->Middle->Flush[i,j,k,l,m] = ((i==j || j==k || k==l || l==m) ? 0 : (isStraight ? SFval : Fval)) + offset;
						//dbHigh->Middle->Other[i,j,k,l,m] = rankValue + offset;
						dbHigh->High->Flush[i,j,k,l,m] = ((i==j || j==k || k==l || l==m) ? 0 : (isStraight ? SFval : Fval)) + offset;
						dbHigh->High->Other[i,j,k,l,m] = rankValue + offset;
						//dbLow->High->Flush[i,j,k,l,m] = ((i==j || j==k || k==l || l==m) ? 0 : (isStraight ? SFval : Fval)) + offset;
						//dbLow->High->Other[i,j,k,l,m] = rankValue + offset;
						//dbLow->Middle->Flush[i,j,k,l,m] = (i==j || j==k || k==l || l==m) ? 0 : (1 - (isStraight?SFval:Fval) + offset) * 0.01f;
						//dbLow->Middle->Other[i,j,k,l,m] = (1 - rankValue) + offset;

						offset += inc;
						
						//dbHigh->High->Other[i,j,k,l,m] = HCval + offset;
						//dbLow->High->Other[i,j,k,l,m] = HCval + offset;
						//dbLow->Middle->Other[i,j,k,l,m] = LowHCval - 10*offset;
						//dbHigh->High->Flush[i,j,k,l,m] = Fval + offset;
						//dbHigh->Middle->Flush[i,j,k,l,m] = Fval + offset;
						//dbLow->High->Flush[i,j,k,l,m] = Fval + offset;
						//dbLow->Middle->Flush[i,j,k,l,m] = LowFval - offset/100;
					}
}
*/