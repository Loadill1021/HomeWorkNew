#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
TitleBackGround::TitleBackGround() 
{
	//Level_=nullptr;actor�� ��ӹ��� �ڽ��� Level_�� �������վ
}

TitleBackGround::~TitleBackGround() 
{
}

void TitleBackGround::Start()
{
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale({ 100, 200 });
}
void TitleBackGround::Render()
{
	DebugRectRender();
}