#include "ConsoleObject.h"
#include <assert.h>
ConsoleObject::ConsoleObject(
	TextScreen* _Screen,
	const char* _Text,
	const ConsoleVector& _Pos
) 
	:Screen_(_Screen),
	Pos_(_Pos)
{
	/*if (nullptr == Screen_)
	{
		assert(false);
	}*/
	if (nullptr == _Text)
	{
		assert(false);
	}
	for (int i = 0; i < 3; ++i)
	{
		Text_[i] = _Text[i];
	}
}

ConsoleObject::~ConsoleObject() 
{
}
void ConsoleObject::Render()
{
	if (nullptr == Screen_)
	{
		assert(false);
	}
	Screen_->SetPixel(Pos_,Text_);
}
bool ConsoleObject::isWall(ConsoleVector _Value)
{
	ConsoleVector Pos = this->Pos_ + _Value;
	if (0 > Pos.x_)
	{
		return true;
	}
	if (0 > Pos.y_)
	{
		return true;
	}
	if (Pos.x_ >= Screen_->GetSize().x_)
	{
		return true;
	}
	if (Pos.y_ >= Screen_->GetSize().y_)
	{
		return true;
	}
	return false;
}