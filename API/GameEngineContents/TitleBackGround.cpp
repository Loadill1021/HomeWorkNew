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
	SetPosition(GameEngineWindow::GetInst().GetScale().Half());
	SetScale(GameEngineWindow::GetScale());
}
void TitleBackGround::Render()
{
	DebugRectRender();
}