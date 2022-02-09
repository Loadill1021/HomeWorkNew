#include "TextScreen.h"
#include <iostream>
TextScreen::TextScreen() 
{
}

TextScreen::~TextScreen() 
{
}

void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Size_.x_ = _Width;
	Size_.y_ = _Height;
	
	for (int i = 0; i < 3; ++i)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}
	//���� ���α��� 2����Ʈ ���ڿ��� ��� �� ���̹Ƿ�
	int RealWidth = Size_.x_ * 2;
	RealWidth += 2;

	PixelData_ = new char* [Size_.y_];
	for (int i = 0; i < Size_.y_; ++i)
	{
		PixelData_[i] = new char[RealWidth];
	}
}
void TextScreen::SettingScreen()
{
	int RealWidth = Size_.x_ * 2;
	for (int y = 0; y < Size_.y_; ++y)
	{
		for (int x = 0; x < Size_.x_; ++x)
		{
			for (int i = 0; i < 2; ++i)
			{
				PixelData_[y][(x * 2) + i] = DefaultPixel_[i];
			}
		}
		PixelData_[y][RealWidth] = '\n';
		PixelData_[y][RealWidth + 1] = 0;
	}
}
void TextScreen::PrintScreen()
{
	for (int y = 0; y < Size_.y_; y++)
	{
		printf_s(PixelData_[y]);
	}
}

void TextScreen::SetPixel(ConsoleVector _Pos, const char* _DefaultValue)
{
	SetPixel(_Pos.x_, _Pos.y_, _DefaultValue);
}
//�����ε�
void TextScreen::SetPixel(int _x, int _y, const char* _DefaultValue)
{
	for (int i = 0; i < 2; ++i)
	{
		PixelData_[_y][(_x*2)+i] = _DefaultValue[i];
	}
}
