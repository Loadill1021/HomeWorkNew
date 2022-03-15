#pragma once
#include <Windows.h>
#include <string>
// ���� :
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
	//����� �Ͱ� ���� ���� �ٸ� ����
	void ShowGameWindow();
	void MessageLoop(void(*_InitFunction)(),void(*_LoopFunction)());
	void Off();
protected:

private:
	bool WindowOn_;
	std::string Title_;
	HINSTANCE hInst_;
	HWND hWnd_;
	HDC HDC_;//��� �����쿡 �׸��� �ִ� ����
	// constrcuter destructer
	GameEngineWindow();
	~GameEngineWindow();

	// delete Function
	GameEngineWindow(const GameEngineWindow& _Other) = delete;
	GameEngineWindow(GameEngineWindow&& _Other) noexcept = delete;
	GameEngineWindow& operator=(const GameEngineWindow& _Other) = delete;
	GameEngineWindow& operator=(GameEngineWindow&& _Other) noexcept = delete;
};

