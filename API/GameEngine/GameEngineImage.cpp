#include "GameEngineImage.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

//그 코드 파일을 가져다쓰겟다.pragma comment
//#pragma comment(lib,"msimg32.lib")
GameEngineImage::GameEngineImage() 
	:ImageDC_(nullptr)
{
}

GameEngineImage::~GameEngineImage()
{
	if (nullptr != BitMap_)
	{
		DeleteObject(BitMap_);
	}
	if (nullptr != OldBitMap_)
	{
		DeleteObject(OldBitMap_);
	}
	if (nullptr != ImageDC_)
	{
		DeleteDC(ImageDC_);
		ImageDC_ = nullptr;
	}
}
bool GameEngineImage::Create(HDC _DC)
{
	ImageDC_ = _DC;
	ImageScaleCheck();
	return true;
}

bool GameEngineImage::Create(float4 _Scale)
{
	if (true == _Scale.IsZero2D())
	{
		MsgBoxAssert("크기가 0인 이미지를 제작하려고 했습니다.");
		return false;
	}
	// 먼저 비트맵을 만들어
	// 이미지 크기만함 디시를 만든다.
	BitMap_ = CreateCompatibleBitmap(GameEngineWindow::GetHDC(), _Scale.ix(), _Scale.iy());
	//비어있지 않는다.
	ImageDC_ = CreateCompatibleDC(nullptr);

	if (nullptr == ImageDC_)
	{
		MsgBoxAssert("ImageDC에 생성에 실패하였습니다.");
	}
	OldBitMap_ = (HBITMAP)SelectObject(ImageDC_, BitMap_);
	ImageScaleCheck();
	return true;
}
void GameEngineImage::BitCopy(GameEngineImage* _Other)
{
	BitCopy(_Other, { 0,0 }, { 0,0 }, _Other->GetScale());
}
//다른 이미지가 들어와서
void GameEngineImage::BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _OtherPivot, const float4& _OtherPivotScale)
{
	//복사 #pragma comment(lib,"msimg32.lib")가 없어도 이 함수는 사용이 가능하다
	//윈도우에서 지원해주는 일반적인 dc vs dc의 복사함수이다.
	BitBlt(
		ImageDC_,//여기에 복사해라.
		_CopyPos.ix(),//복사 받으려는 이미지의
		_CopyPos.iy(),//내 이미지의 특정부분 x
		_OtherPivotScale.ix(),//내 이미지의 이 크기만큼 x
		_OtherPivotScale.iy(),//내 이미지의 이 크기만큼 y
		_Other->ImageDC_,//복사하려는 대상은
		_OtherPivotScale.ix(),//복사하려는 대상의 시작점 X
		_OtherPivotScale.iy(),//복사하려는 대상의 시작점 Y
		SRCCOPY//복사하려는 명령
		);
}

void GameEngineImage::ImageScaleCheck()
{
	//내부에 박혀있는 BITMAP을 꺼내오는 함수
	HBITMAP CurrentBitMap = (HBITMAP)GetCurrentObject(ImageDC_,OBJ_BITMAP);
	GetObject(CurrentBitMap,sizeof(BITMAP),&Info_);
}
//class HBITMAP
//{
//	float4 Size;
//	int* Pixels;
//};