#include "TitleLogo.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
TitleLogo::TitleLogo() 
{
}

TitleLogo::~TitleLogo() 
{
}

void TitleLogo::Start()
{

}
void TitleLogo::Update()
{

}
void TitleLogo::Render()
{
	Rectangle(GameEngineWindow::GetDC(), 100, 100, 200, 200);
}