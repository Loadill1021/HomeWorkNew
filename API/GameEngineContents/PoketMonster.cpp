#include "PoketMonster.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
#include <GameEngineBase/GameEngineWindow.h>
PoketMonster::PoketMonster() 
{
}

PoketMonster::~PoketMonster() 
{
}
void PoketMonster::GameInit()
{
	/*char Arr[10] = "Title";
	"Title" == Arr;*/
	//0,0에 가로 1280 세로 720
	GameEngineWindow::GetInst().SetWindowScaleAndPosition({0,0},{1280,720});
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	ChangeLevel("Title");
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}


