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
	//CreateActor<Product>("������", 2);
	//��׶��尡 ���� �׷����� Ÿ��Ʋ�ΰ� �׷����� ���Ѵ�.
}
void TitleLevel::Update()
{
	//GameEngine::GlobalEngine().ChangeLevel("Play");
}