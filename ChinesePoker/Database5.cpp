#include "StdAfx.h"
#include "Database5.h"

Database5::Database5(void)
{
	Flush = gcnew array<float,5>(12,13,13,13,13);
	Other = gcnew array<float,5>(12,13,13,13,13);
}

Database5::~Database5(void)
{
	delete Flush;
	delete Other;
}