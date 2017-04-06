#pragma once

using namespace System::Windows::Forms;
using namespace System::Collections;
	
ref class Keyboard
{
public:
	Keyboard(void);
	~Keyboard(void);
	bool IsPressed(Keys key);
	System::Void SetState(Keys key, bool val);

	System::Collections::Generic::Dictionary<Keys, bool> ^keyState;
};
