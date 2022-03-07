#pragma once
#include <crtdbg.h>
#include <string>
#include <assert.h>
#include <Windows.h>
// 설명 :
class GameEngineDebug
{
public:
	// constrcuter destructer
	//릭체크(객체 없이 편하게 쓰려고 전역함수로 만든다.)
	static void LeakCheckOn();
	//static void MsgBoxAssert(const std::string& _Text);
protected:

private:
	GameEngineDebug();
	~GameEngineDebug();

	// delete Function
	GameEngineDebug(const GameEngineDebug& _Other) = delete;
	GameEngineDebug(GameEngineDebug&& _Other) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _Other) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _Other) noexcept = delete;


};
#define MsgBoxAssert(Text) MessageBeep(0);\
MessageBoxA(nullptr, Text, "Error", MB_OK);\
assert(false);

