#pragma once
#include <Windows.h>
#include <string>
// 설명 :
class GameEngineWindow
{
private:
	static GameEngineWindow* Inst_;
public:
	void RegClass(HINSTANCE _hInst);
	inline static GameEngineWindow& GetInst()
	{
		return *Inst_;
	}
	static void Destroy()
	{
		if (nullptr!=Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
public:
	void CreateGameWindow(HINSTANCE _hInst, const std::string& _Title);
	void ShowGameWindow();
	void MessageLoop(void(*_LoopFunction)());
	void Off();
	static inline HDC GETDC() 
	{
		return Inst_->HDC_;
	}
protected:

private:
	bool WindowOn_;
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC HDC_;//어느 윈도우에 그릴수있는 권한
	std::string Title_;
	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;
};

