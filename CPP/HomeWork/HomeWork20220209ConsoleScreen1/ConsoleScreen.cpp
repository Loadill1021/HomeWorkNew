#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TextScreen NewScreen(10, 10, "ㅁ");
	Player NewPlayer(&NewScreen, "◆");

	NewScreen.SettingScreen();
	NewScreen.PrintScreen();
	NewPlayer.Render();
	NewScreen.PrintScreen();
	while (true)
	{
		//할당 받은 힙공간에 2바이트 문자열로 채운다.
		NewScreen.SettingScreen();
		//플레이어를 그려준다.Render(){NewScreen.SettingScreen()을 호출}
		NewPlayer.Render();
		//힙공간에 있는 모든 문자열을 출력해준다.
		NewScreen.PrintScreen();
		//플레이어의 움직임
		NewPlayer.Update();
	}
	return 0;
}