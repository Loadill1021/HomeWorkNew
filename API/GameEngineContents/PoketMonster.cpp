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
	//���� ������ Ÿ��Ʋ������
	ChangeLevel("Play");

	//�������� ���Ǽ��� ����
	//ChagneLevel(3);
}
void PoketMonster::GameLoop()
{

}
void PoketMonster::GameEnd()
{

}
