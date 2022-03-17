#pragma once
#include <Windows.h>
#include <string>
#include <assert.h>
#include <crtdbg.h>
// ���� :
class GameEngineDebug
{
public:
	static void LeakCheckOn();

	//static void MsgBoxAssert(const std::string& _Text);
protected:

private:
	// constrcuter destructer
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

