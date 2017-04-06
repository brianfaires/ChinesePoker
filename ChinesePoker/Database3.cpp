#include "StdAfx.h"
#include "Database3.h"

Database3::Database3(void)
{
	All = gcnew array<float, 3>(13, 13, 13);
}

Database3::~Database3(void)
{
	delete All;
}

