#pragma once
#include "ConsoleMath.h"//��ġ
#include "TextScreen.h"//��
// ���� :
class Player
{
public:
	// constrcuter destructer
	Player(int _y, int _x, const char* _Text);
	Player(ConsoleVector _Pos, const char* _Text);
	Player(TextScreen* _Screen, const char* _Text);
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;

	ConsoleVector GetPos()
	{
		return Pos_;
	}
	void SetPos(ConsoleVector _Value)
	{
		Pos_ = _Value;
	}
	void Render();
	void Update();
protected:

private:
	// Has a �����̶�� �մϴ�.
	TextScreen* Screen_;
	//�÷��̾ ǥ���� ���ڿ�

	ConsoleVector Pos_;
	char Text_[3];
};

