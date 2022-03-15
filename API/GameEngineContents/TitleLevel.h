#pragma once
#include <GameEngine/GameEngineLevel.h>
#include "GameEngine/GameEngine.h"
// 설명 :
// 타이틀 로고 보여주고 키 누르면 플레이 레벨로 감
// 타이트 로고: 화면에서 등장(Actor)
class TitleLevel:public GameEngineLevel
{
public:
	// constrcuter destructer
	TitleLevel();
	~TitleLevel();

	// delete Function
	TitleLevel(const TitleLevel& _Other) = delete;
	TitleLevel(TitleLevel&& _Other) noexcept = delete;
	TitleLevel& operator=(const TitleLevel& _Other) = delete;
	TitleLevel& operator=(TitleLevel&& _Other) noexcept = delete;
protected:
	void Loading()override;
	void Update()override;
private:

};

