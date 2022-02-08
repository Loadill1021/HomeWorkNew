#include <iostream>
#include "TextScreen.h"
#include <crtdbg.h>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TextScreen text=TextScreen();
	text.CreateScreen(2, 2, "£¾");
	text.PrintScreen();
	return 0;
}