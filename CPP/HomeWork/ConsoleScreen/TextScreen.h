#pragma once
#include "ConsoleMath.h"//상위 개념끼리 형제 관계?까지는 인클루드 할 수 있다.
// 설명 : 콘솔창에 띄워주는 역활
#include <assert.h>//assert함수가 들어 있는 헤더 인클루드
class TextScreen
{
public:
	// constrcuter destructer
	TextScreen();
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

	//화면의 글자를 동적으로 할당하여 메모리를 만들어내는 작업
	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	//DefaultPixel의 문자열 앞쪽 2바이트로 화면을 전부 초기화 한다.
	void SettingScreen();

	//PixelData_의 내용을 모두 화면에 출력한다.
	void PrintScreen();

	//X Y위치에 글자를 출력한다.
	//플레이어나 몬스터를 출력하기 위해서
	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _x, int _y, const char* _DefaultValue);
protected:

private:
	//int Width_;//가로 너비
	//int Height_;//세로 높이
	ConsoleVector Size_;//로 대체
	char** PixelData_;
	char DefaultPixel_[3];//어떤 형태로 그려질지
};

