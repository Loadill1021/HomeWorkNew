#include "Player.h"
#include <conio.h>
Player::Player(TextScreen* _Screen, const char* _Text)
	:Screen_(_Screen)
	,Pos_(_Screen->GetSize().GetHalfVector())
	,Text_()
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
}

void Player::Update()
{
}

