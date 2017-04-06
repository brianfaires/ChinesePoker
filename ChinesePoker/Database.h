#pragma once
#include "stdafx.h"
#include "Database5.h"
#include "Database3.h"

public ref class Database
{
public:
	Database(void);
	~Database(void);
public:
	Database5 ^High;
	Database5 ^Middle;
	Database3 ^Small;
};
