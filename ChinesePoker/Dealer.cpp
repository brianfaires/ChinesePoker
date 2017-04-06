#include "StdAfx.h"
#include "Dealer.h"

Dealer::Dealer(void)
{
	brain = gcnew Brain();
	deck = gcnew Deck(52);
}
Dealer::~Dealer(void)
{
	delete brain;
	delete deck;
}

void Dealer::SortHand(int startingHand)
{
	int startingIndex = startingHand * 13;
	int value, j;
	int iLimit = 13 + startingIndex;

	// Insertion sort 13 elements
	for(int i = 1 + startingIndex; i < iLimit; i++)
	{
		value = deck[i];
		j = i - 1;
		while(j >= startingIndex && deck[j] > value)
		{
			// Shift array elements right, overwriting deck[i]
			deck->cards[j + 1] = deck[j];
			j--;
		}
		deck->cards[j + 1] = value;
	}
}
void Dealer::SortAll(void)
{
	SortHand(0);
	SortHand(1);
	SortHand(2);
	SortHand(3);
}

void Dealer::SimHands(long int hands)
{
	for(long int i=0; i<hands; i++)
	{
		deck->Shuffle();
		SortAll();
		brain->SimHand(deck);
	}
}