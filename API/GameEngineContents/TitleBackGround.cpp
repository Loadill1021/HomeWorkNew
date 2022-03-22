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
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale({ 100, 200 });
}
void TitleBackGround::Render()
{
	DebugRectRender();
}