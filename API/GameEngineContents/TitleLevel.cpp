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
	//회사마다 다를수 있겠지만
	//Actor를 만들어야죠?
	//백그라운드가 먼저 그려지고 타이틀 로고가 그려지기를 원한다.
	CreateActor<TitleBackGround>("TitleLogo",0);
	CreateActor<TitleLogo>("TitleLogo",1);
}
void TitleLevel::Update()
{
	//GameEngine::GlobalGameEngine().ChangeLevel("Play");
}

