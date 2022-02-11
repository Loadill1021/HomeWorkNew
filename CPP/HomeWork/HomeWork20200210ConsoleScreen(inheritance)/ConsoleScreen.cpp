#include <iostream>
//#include "TextScreen.h"
//#include "ConsoleObject.h"
//#include "Player.h"
#include <crtdbg.h>
//#include "Monster.h"
#include "ConsoleGloballInst.h"
//#include "Monster.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//TextScreen t1(10, 10, "¡á");
	//ConsoleObject NewPlayer(&t1, "£ª", { 2,1 });
	//Player NewPlayer(&t1, "¡Ù");
	//Monster NewMonster[10];// (&t1, "¢¾", { 9,9 });
	//t1.SettingScreen();
	while (true)
	{
		MainScreen.SettingScreen();
		MainPlayer.Render();
		//NewMonster.Render();
		MainScreen.PrintScreen();
		MainPlayer.Update();
		if (MainPlayer.isFin())
		{
			break;
		}
	}
	delete[] AllMonsters;
	return 0;
}