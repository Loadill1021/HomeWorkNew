#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleLogo.h"
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
	//��׶��尡 ���� �׷����� Ÿ��Ʋ �ΰ� �׷����⸦ ���Ѵ�.
	CreateActor<TitleBackGround>("TitleLogo",0);
	CreateActor<TitleLogo>("TitleLogo",1);
}
void TitleLevel::Update()
{
	//GameEngine::GlobalGameEngine().ChangeLevel("Play");
}

