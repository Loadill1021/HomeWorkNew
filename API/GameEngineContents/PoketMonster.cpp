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
	//���� ������ Ÿ��Ʋ������
	ChangeLevel("Title");

	//�������� ���Ǽ��� ����
	//ChagneLevel(3);
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}
