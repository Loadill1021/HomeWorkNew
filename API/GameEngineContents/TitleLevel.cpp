#include "TitleLevel.h"

TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}
void TitleLevel::Loading()
{
	//ȸ�縶�� �ٸ��� �ְ�����
	//Actor�� ��������?
}
void TitleLevel::Update()
{
	GameEngine::GlobalGameEngine().ChangeLevel("Play");
}

