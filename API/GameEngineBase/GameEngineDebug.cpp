#include "GameEngineDebug.h"

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
//void GameEngineDebug::MsgAssert(const std::string& _Text)
//{
//	//LPCSTR;
//	//�ڵ��� �ȳ־��ָ� �ڱ��ڽ����� ����.
//	//������ �ڵ� �־�޶�� �մϴ�.
//	//�ϰ� ����Ÿ�
//	//�� �־��ָ� �˾Ƽ� window�� �ϳ� ������ش�.
//	MessageBoxA(nullptr, _Text.c_str(), "Error", MB_OK);
//	assert(false);
//}