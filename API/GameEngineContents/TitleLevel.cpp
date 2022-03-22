#include "TitleLevel.h"
#include "GameEngine/GameEngine.h"
#include "TitleBackGround.h"
#include "TitleLogo.h"
#include "Product.h"
TitleLevel::TitleLevel() 
{
}

TitleLevel::~TitleLevel() 
{
}

void TitleLevel::Loading()
{
	CreateActor<TitleBackGround>("TitleLogo",0);
	CreateActor<TitleLogo>("TitleLogo",1);
	//CreateActor<Product>("제작자", 2);
	//백그라운드가 먼저 그려지고 타이틀로고가 그려지길 원한다.
}
void TitleLevel::Update()
{
	//GameEngine::GlobalEngine().ChangeLevel("Play");
}