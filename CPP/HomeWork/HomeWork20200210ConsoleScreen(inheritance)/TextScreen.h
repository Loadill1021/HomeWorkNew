#pragma once
#include "ConsoleMath.h"
// Ό³Έν :
class TextScreen
{
public:
	// constrcuter destructer
	TextScreen(int _Width, int _Height, const char* _DefaultValue);
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;

	ConsoleVector GetSize()
	{
		return Size_;
	}

	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);
	void SettingScreen();
	void PrintScreen();
	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _y, int _x, const char* _DefaultValue);
protected:
private:
	ConsoleVector Size_;//int Width,int Height
	char** PixelData_;
	char DefaultValue_[3];
};

