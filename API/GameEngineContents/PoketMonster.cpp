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
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<EndingLevel>("Ending");
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}


