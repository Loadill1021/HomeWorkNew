#pragma once
#include "GameEngineImage.h" //어차피 이녀석을 안쓸수는 없어서
#include <GameEngineBase/GameEngineMath.h>
#include <map>
#include <string>
// 설명 :
// 기본적으로 리소스는 그냥 쓸수도 있지만 이름이 있다고 가정하고 쓸겁니다.
// 언제어디서나 게임엔진 이미지매니저를 쓰면 된다
class GameEngineImageManager
{
private:
	static GameEngineImageManager* Inst_;
public:
	static GameEngineImageManager* GetInst()
	{
		return Inst_;
	}
	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}
		delete Inst_;
		Inst_ = nullptr;
	}
public:

	// constrcuter destructer
	GameEngineImageManager();
	~GameEngineImageManager();

	// delete Function
	GameEngineImageManager(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager(GameEngineImageManager&& _Other) noexcept = delete;
	GameEngineImageManager& operator=(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager& operator=(GameEngineImageManager&& _Other) noexcept = delete;

	//빈 이미지를 만든다. ex)1280 ,280을 이미지를 만들어줘=> 2차원배열
	GameEngineImage* Create(const std::string& _Name, float4 _Scale);
	GameEngineImage* Create(const std::string& _Name, HDC _DC);
protected:

private:
	//맵을 쓴 이유 같은 이름의 이미지가 두개 존재할수없다.
	std::map<std::string, GameEngineImage*>AllRes;
};

