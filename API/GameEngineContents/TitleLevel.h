#pragma once
#include <GameEngine/GameEngineLevel.h>
#include "GameEngine/GameEngine.h"
// ���� :
// Ÿ��Ʋ �ΰ� �����ְ� Ű ������ �÷��� ������ ��
// Ÿ��Ʈ �ΰ�: ȭ�鿡�� ����(Actor)
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

