#pragma once

public ref class Deck
{
public:
	Deck(int);
	~Deck(void);
	void Shuffle(void);
	int GetCondensedID(int);
	int operator[](int);

	// Variables
	//
	int size;
	array<int> ^cards;
private: 
	System::Random ^rand;
};
