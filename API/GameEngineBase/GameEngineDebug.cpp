#include "GameEngineDebug.h"
#include <assert.h>
#include <Windows.h>
GameEngineDebug::GameEngineDebug()
{
}

GameEngineDebug::~GameEngineDebug() 
{
}
void GameEngineDebug::LeakCheckOn()
{
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
}

//void GameEngineDebug::MsgBoxAssert(const std::string& _Text)
//{
//	MessageBeep(0);
//	MessageBoxA(nullptr, _Text.c_str(), "Error", MB_OK);
//	assert(false);
//}

