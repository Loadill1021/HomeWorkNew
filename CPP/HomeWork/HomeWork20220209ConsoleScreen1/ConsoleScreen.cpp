#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TextScreen NewScreen(10, 10, "¤±");
	Player NewPlayer(&NewScreen, "¡ß");

	NewScreen.SettingScreen();
	NewScreen.PrintScreen();
	NewPlayer.Render();
	NewScreen.PrintScreen();
	while (true)
	{
		NewScreen.SettingScreen();
		NewPlayer.Render();
		NewScreen.PrintScreen();
		NewPlayer.Update();
	}
	return 0;
}