#include "BotUI.h"

BotUI::BotUI() 
{
}

BotUI::~BotUI() 
{
}
void BotUI::Start()
{
	SetPosition({ 0,500 });
	SetScale({ 1280,400 });
}
void BotUI::Render()
{
	DebugRectRender();
}
