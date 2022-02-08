#include "TextScreen.h"
#include <iostream>
TextScreen::TextScreen() 
	: Width_(10)
	 ,Height_(20)
	 ,PixelData_(nullptr)
	 ,DefaultPixel_("a")
{
}

TextScreen::~TextScreen() 
{
	if (nullptr != PixelData_)
		delete[] PixelData_;
}
void TextScreen::CreateScreen(int _Width, int _Height, const char* _DefaultValue)
{
	Width_ = _Width;
	Height_ = _Height;
	for (int i = 0; i < 3; ++i)
	{
		DefaultPixel_[i] = _DefaultValue[i];
	}
	//[][][]\n
	//[][][]\n
	//[][][]\n0
	int Real_Width = Width_*2;
	Real_Width += 1;
	PixelData_ = new char[Real_Width * Height_+1];
	for (int y = 0; y < Height_; ++y)
	{
		char* LineStart = &PixelData_[(y * Real_Width)];
		for (int x = 0; x < Width_; ++x)
		{
			for (int i = 0; i < 2; ++i)
			{
				LineStart[x*2+i] = DefaultPixel_[i];
			}
		}
		LineStart[(Width_ * 2)] = '\n';
	}
	PixelData_[(Real_Width * Height_)] = 0;
}
void TextScreen::PrintScreen()
{
	printf_s(PixelData_);
}