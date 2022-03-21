#include "Player.h"

Player::Player() 
{
}

Player::~Player() 
{
}

void Player::Start()
{
	SetPosition({ 100,100 });
	SetScale({ 200,200 });
}
void Player::Render()
{
	DebugRectRender();
}