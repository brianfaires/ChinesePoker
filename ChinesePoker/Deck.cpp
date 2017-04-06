#include "StdAfx.h"
#include "Deck.h"

Deck::Deck(int _size)
{
	size = _size;
	cards = gcnew array<int>(size);
	rand = gcnew System::Random();
	
	for(int i = 0; i < size; i++)
	{
		cards[i] = i;
		cards[i] >>= 2; // Remove the suit bits, rank remains
		cards[i] <<= 4; // make 4 bits for suit

		switch(i%4)
		{
		case(0):
			cards[i] |= 0x1;
			break;
		case(1):
			cards[i] |= 0x2;
			break;
		case(2):
			cards[i] |= 0x4;
			break;
		case(3):
			cards[i] |= 0x8;
			break;
		}
	}
}

Deck::~Deck(void)
{
	delete cards;
	delete rand;
}

void Deck::Shuffle(void)
{
	int tempIndex;
	int tempCard;
	
	for(int i = 0; i < size; i++)
	{
		tempIndex = rand->Next(0, size);
		tempCard = cards[i];
		cards[i] = cards[tempIndex];
		cards[tempIndex] = tempCard;
	}
}


int Deck::operator[](int index)
{
	return cards[index];
}

int Deck::GetCondensedID(int index)
{
	int suit = index & 0xF;
	index >>= 4;
	index <<= 2;
	switch(suit)
	{
	case(0x1):
		break;
	case(0x2):
		index |= 0x1;
		break;
	case(0x4):
		index |= 0x2;
		break;
	case(0x8):
		index |= 0x3;
		break;
	}
	return index & 0x3F;
}