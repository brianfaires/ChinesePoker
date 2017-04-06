#include "stdafx.h"
#include "Database.h"

Database::Database(void)
{
	High = gcnew Database5();
	Middle = gcnew Database5();
	Small = gcnew Database3();
}
Database::~Database(void)
{
	delete High;
	delete Middle;
	delete Small;
}