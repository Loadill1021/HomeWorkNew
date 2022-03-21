#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
#include <Windows.h>
// 설명 :
class GameEngineImage:public GameEngineNameObject
{
public:
	// constrcuter destructer
	GameEngineImage();
	~GameEngineImage();

	// delete Function
	GameEngineImage(const GameEngineImage& _Other) = delete;
	GameEngineImage(GameEngineImage&& _Other) noexcept = delete;
	GameEngineImage& operator=(const GameEngineImage& _Other) = delete;
	GameEngineImage& operator=(GameEngineImage&& _Other) noexcept = delete;
	bool Create(float4 _Scale);
	bool Create(HDC _DC);
	inline float4 GetScale()
	{
		return float4(static_cast<float>(Info_.bmWidth), static_cast<float>(Info_.bmHeight));
	}

	inline HDC ImageDC()
	{
		return ImageDC_;
	}
	//다른 이미지가 들어와서 복사된다.
	void BitCopy(GameEngineImage* _Other);
	void BitCopy(GameEngineImage* _Other, const float4& _CopyPos, const float4& _OtherPivot, const float4& _OtherPivotScale);
protected:

private:
	HDC ImageDC_;//이미지
	HBITMAP BitMap_;//비트맵 핸들 DC는 비트맵에서 그걸 얻어오기때문에 가상의 비트맵을 만들어준다.
	HBITMAP OldBitMap_;//그 1에 1짜리 
	BITMAP Info_;//비트맵 크기
	
	// 
	void ImageScaleCheck();
};

