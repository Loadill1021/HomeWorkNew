#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>
// Ό³Έν :
class GameEngineLevel:public GameEngineNameObject
{
public:
	// constrcuter destructer
	GameEngineLevel();
	~GameEngineLevel();

	// delete Function
	GameEngineLevel(const GameEngineLevel& _Other) = delete;
	GameEngineLevel(GameEngineLevel&& _Other) noexcept = delete;
	GameEngineLevel& operator=(const GameEngineLevel& _Other) = delete;
	GameEngineLevel& operator=(GameEngineLevel&& _Other) noexcept = delete;

protected:

private:
	//std::map<int, std::list<GameEngineActor*>>AllActor_;
};

