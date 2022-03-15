#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
// ���� :
//ȭ��
class GameEngineLevel:public GameEngineNameObject
{
public:
	// constrcuter destructer
	GameEngineLevel();
	virtual ~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:
	virtual void Loading()=0;//�ڱ� ȭ�鿡 ���� ���ҽ��� �̹��� �غ�
private:
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr;
	}
};

