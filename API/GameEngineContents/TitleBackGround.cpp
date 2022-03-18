#include "TitleBackGround.h"
#include <GameEngineBase/GameEngineWindow.h>
TitleBackGround::TitleBackGround() 
{
	//Level_=nullptr;actor를 상속받은 자식이 Level_을 만질수잇어서
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