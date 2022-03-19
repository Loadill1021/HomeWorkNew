#include "GameEngineActor.h"
#include <GameEngineBase/GameEngineWindow.h>
#include "GameEngine.h"
GameEngineActor::GameEngineActor() 
	:Level_(nullptr)
{
}

GameEngineActor::~GameEngineActor()
{
}
void GameEngineActor::DebugRectRender()
{
	GameEngineRect DebugRect(Position_,Scale_);

	//SetPixel(GameEngineWindow::GetHDC(), 100, 100, RGB(255, 0, 0));
	//Rectangle(GameEngineWindow::GetHDC(), 100, 100, 500, 500);
	/*Rectangle(
		GameEngineWindow::GetHDC(),
		DebugRect.CenterLeft(),
		DebugRect.CenterTop(),
		DebugRect.CenterRight(),
		DebugRect.CenterBot());*/
		Rectangle(
			GameEngine::BackBufferDC(),
			DebugRect.CenterLeft(),
			DebugRect.CenterTop(),
			DebugRect.CenterRight(),
			DebugRect.CenterBot());
}


