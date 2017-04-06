namespace ChinesePoker
{
	#pragma region namespaces
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	#pragma endregion

	// Macros
	#define SUIT(x) (x & 0xF)
	#define RANK(x) ((x >> 4) & 0x3F)
	#define MAX(x, y) ((x > y) ? x : y)
	#define MIN(x, y) ((x < y) ? x : y)

	// Magic Numbers
	#define DECK_SIZE 52
	#define TOTAL_PIC_BOXES 117
	#define EMPTY 0xFFFF
}