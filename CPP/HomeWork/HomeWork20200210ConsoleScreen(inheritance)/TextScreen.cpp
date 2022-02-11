#include <iostream>
#include "TextScreen.h"
#include <assert.h>
TextScreen::TextScreen(int _Width, int _Height, const char* _DefaultValue)
	:Size_(0, 0),
	PixelData_(nullptr)
{
	CreateScreen(_Width,_Height, _DefaultValue);
}

TextScreen::~TextScreen() 
{
	for (int i = 0; i < Size_.y_; i++)
	{
		if (nullptr != PixelData_[i])
		{
			delete[] PixelData_[i];
			PixelData_[i] = nullptr;
		}
	}
	if (nullptr != PixelData_)
	{
	delete[] PixelData_;
	PixelData_ = nullptr;
	}
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Size_.x_ = _Width;
	Size_.y_ = _Height;
	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;
	for (int i = 0; i < 3; ++i)
	{
		DefaultValue_[i] = _DefaultValue[i];
	}

	PixelData_ = new char* [Size_.y_];

	for (int i = 0; i < Size_.y_; ++i)
	{
		PixelData_[i] = new char[RealWidth];
	}
}
void TextScreen::SettingScreen()
{
	//3 3
	//00 01 02 03 04 05 06 
	//10 11 12 13 14 15 16
	//20 21 22 23 24 25 26 27
	//¤±¤±¤±\n

	
	for (int y = 0; y < Size_.y_; ++y)
	{
		for (int x = 0; x < Size_.x_; ++x)
		{
			for (int i = 0; i < 2; ++i)
			{
				PixelData_[y][x * 2 + i] = DefaultValue_[i];
			}
		}
		PixelData_[y][Size_.x_ * 2] = '\n';
		PixelData_[y][Size_.x_ * 2+1] = 0;
	}
}

void TextScreen::PrintScreen()
{
	system("cls");
	for (int i = 0; i < Size_.y_; ++i)
	{
		printf_s(PixelData_[i]);
	}
}
void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	SetPixel(_Pos.y_, _Pos.x_, _DefaultValue);

}
void TextScreen::SetPixel(int _y, int _x, const char* _DefaultValue)
{
	if(0 > _x)
	{
		assert(false);
	}

	if (0 > _y)
	{
		assert(false);
	}

	if (Size_.x_ <= _y)
	{
		assert(false);
	}

	if (Size_.y_ <= _y)
	{
		assert(false);
	}

	for (int i = 0; i < 2; ++i)
	{
		PixelData_[_y][_x*2+i]=_DefaultValue[i];
	}

}