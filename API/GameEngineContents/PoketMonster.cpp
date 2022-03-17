#include "PoketMonster.h"
#include "PlayLevel.h"
#include "TitleLevel.h"
#include "EndingLevel.h"

PoketMonster::PoketMonster() 
{
}

PoketMonster::~PoketMonster() 
{
}

void PoketMonster::GameInit()
{
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
	//시작 레벨을 타이틀레벨로
	ChangeLevel("Title");

	//가독성과 편의성을 위함
	//ChagneLevel(3);
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}
