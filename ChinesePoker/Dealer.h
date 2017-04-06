#pragma once
#include "Deck.h"
#include "Brain.h"

public ref class Dealer
{
public:
	Dealer(void);
	~Dealer(void);
	void SortHand(int startingHand);
	void SortAll(void);
	void SimHands(long int hands);

	Deck ^deck;
	Brain ^brain;
};
