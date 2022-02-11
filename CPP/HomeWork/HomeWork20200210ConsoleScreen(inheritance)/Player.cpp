#include "Player.h"
#include <iostream>
#include <conio.h>
Player::Player(
	TextScreen* _Screen,
	const char* _Text)
	:ConsoleObject(_Screen,_Text,_Screen->GetSize().GetHalfVector())
{
	isFinish_ = false;
}

Player::~Player() 
{
}
void Player::Update()
{
	int Value = _getch();
	//ConsoleVector PrePos = this->GetPos();
	switch (Value)
	{
	case 'q':
	case 'Q':
		this->isFinish_ = true;
		break;
	case 'a':
	case 'A':
		if (isWall({ -1, 0 }))
		{
			//SetPos({ 0, 0 });
			break;
		}
		SetMove({ -1, 0 });
		break;
	case 's':
	case 'S':
		if (isWall({ 0,+1 }))
		{
			//SetPos({ 0, 0 });
			break;
		}
		SetMove({ 0,+1 });
		break;
	case 'd':
	case 'D':
		if (isWall({ +1,0 }))
		{
			//SetPos({ 0, 0 });
			break;
		}
		SetMove({ +1,0 });
		break;
	case 'w':
	case 'W':
		if (isWall({ 0,-1 }))
		{
			//SetPos({ 0, 0 });
			break;
		}
		SetMove({ 0,-1 });
		break;
	}
}
bool Player::isFin()
{
	return isFinish_;
}
