#include <iostream>
#include "TextScreen.h"
#include "Player.h"
#include <crtdbg.h>
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	TextScreen NewScreen(10, 10, "��");
	Player NewPlayer(&NewScreen, "��");

	NewScreen.SettingScreen();
	NewScreen.PrintScreen();
	NewPlayer.Render();
	NewScreen.PrintScreen();
	while (true)
	{
		//�Ҵ� ���� �������� 2����Ʈ ���ڿ��� ä���.
		NewScreen.SettingScreen();
		//�÷��̾ �׷��ش�.Render(){NewScreen.SettingScreen()�� ȣ��}
		NewPlayer.Render();
		//�������� �ִ� ��� ���ڿ��� ������ش�.
		NewScreen.PrintScreen();
		//�÷��̾��� ������
		NewPlayer.Update();
	}
	return 0;
}