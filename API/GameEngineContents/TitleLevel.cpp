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
	CreateActor<TitleBackGround>("TitleLogo",0);
	CreateActor<TitleLogo>("Ÿ��Ʋ�ΰ�",1);
	//��׶��尡 ���� �׷����� Ÿ��Ʋ�ΰ� �׷����� ���Ѵ�.
}
void TitleLevel::Update()
{
	//GameEngine::GlobalEngine().ChangeLevel("Play");
}