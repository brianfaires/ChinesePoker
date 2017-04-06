#pragma once
#include "Database.h"
#include "Deck.h"
#include "StatTracker.h"

public ref class Brain
{
public:
	Brain(void);
	Brain(StatTracker ^_st);
	~Brain(void);
	float Evaluate(bool isHighGame, bool useHighHand, int c0, int c1, int c2, int c3, int c4);
	bool IsValid(array<int> ^first, array<int> ^small);
	bool IsValid(array<int> ^first, array<int> ^small, array<int> ^last);
	void SolveHand(bool isHighGame, Deck ^deck, int handIndex);
	void Learn(void);
	void SimHand(Deck ^deck);

	// Variables
	//
	StatTracker ^myStats;
	Database ^dbHigh;
	Database ^dbLow;
};
