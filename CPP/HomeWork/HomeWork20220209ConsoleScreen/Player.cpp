#include "Player.h"
#include <conio.h>
Player::Player(int _y, int _x, const char* _Text)
	:Screen_(nullptr),Pos_(_x,_y),Text_()
{

}
Player::Player(ConsoleVector _Pos, const char* _Text)
	:Screen_(nullptr),Pos_(_Pos), Text_()
{

}
Player::Player(TextScreen* _Screen, const char* _Text)
	:Screen_(_Screen)
	, Pos_(_Screen->GetSize().GetHalfVector())
	, Text_()
{
	if (nullptr == _Screen)
	{
		assert(false);
	}
	for (int i = 0; i < 3; ++i)
	{
		Text_[i] = _Text[i];
	}
}

Player::~Player()
{
}

void Player::Render()
{
	Screen_->SetPixel(Pos_,Text_);
}

void Player::Update()
{
	// Pos_.x_ += 1; // Pos_.y_ += 0;
	//   'a'
	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		Pos_.x_ -= 1;
		break;
	case 'd':
	case 'D':
		Pos_.x_ += 1;
		break;
	case 'w':
	case 'W':
		Pos_.y_ -= 1;
		break;
	case 's':
	case 'S':
		Pos_.y_ += 1;
		break;
	default:
		break;
	}
}

