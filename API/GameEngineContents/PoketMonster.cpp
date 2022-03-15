#include "PoketMonster.h"
#include "PlayLevel.h"
#include "EndingLevel.h"
#include "TitleLevel.h"
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


