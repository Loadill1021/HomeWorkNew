#include "PoketMonster.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "EndingLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
PoketMonster::PoketMonster() 
{
}

PoketMonster::~PoketMonster() 
{
}

void PoketMonster::GameInit()
{
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({ 100, 100 }, { 1280, 720 });
	
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	//시작 레벨을 타이틀레벨로
	ChangeLevel("Play");

	//가독성과 편의성을 위함
	//ChagneLevel(3);
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}
