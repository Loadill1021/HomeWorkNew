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
	//ȭ���߾ӿ� ����
	SetPosition(GameEngineWindow::GetScale().Half());
	SetScale({ 100, 100 });
}
void TitleLogo::Update()
{

}
void TitleLogo::Render()
{
	DebugRectRender();
}