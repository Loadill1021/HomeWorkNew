#pragma once
#include <Windows.h>
#include <string>
#include "GameEngineMath.h"
// 설명 :
//singletone
class GameEngineWindow
{
private:
	static GameEngineWindow* Inst_;
public:
	inline static GameEngineWindow& GetInst()
	{
		return *Inst_;
	}
	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
	static inline  HDC GETDC()
	{
		return Inst_->HDC_;
	}
public:
	void RegClass(HINSTANCE _hInst);
	void CreateGameWindow(HINSTANCE _hInst,const std::string _Title);
	//만드는 것과 띄우는 것은 다른 개념
	void ShowGameWindow();
	void MessageLoop(void(*_InitFunction)(),void(*_LoopFunction)());
	//이 위치에 이 크기로 세팅해라
	void SetWindowScaleAndPosition(float4 _Pos, float4 _Size);
	void Off();
protected:

private:
	std::string Title_;
	bool WindowOn_;
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC HDC_;//어느 윈도우에 그릴수 있는 권한
	//윈도우의 크기
	float4 Scale_;
	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;
};

