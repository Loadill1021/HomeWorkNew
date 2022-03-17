#pragma once
#include <GameEngineBase/GameEngineWindow.h>
#include <map>
#include <string>
// ���� : ���ӿ����̶� ���� ����ü
class GameEngineLevel;
class GameEngine
{
public:
	// constrcuter destructer
	GameEngine();
	~GameEngine();

	// delete Function
	GameEngine(const GameEngine& _Other) = delete;
	GameEngine(GameEngine&& _Other) noexcept = delete;
	GameEngine& operator=(const GameEngine& _Other) = delete;
	GameEngine& operator=(GameEngine&& _Other) noexcept = delete;


	
	virtual void GameInit()=0;
	virtual void GameLoop()=0;
	virtual void GameEnd()=0;

	template<typename LevelType>
	void CreateLevel(const std::string& _LevelName)
	{
		LevelType* NewLevel = new LevelType();
		AllLevel_.insert(std::make_pair(_LevelName, NewLevel));
	}
protected:

private:
	std::map<std::string, GameEngineLevel*>AllLevel_;
	//Ŭ������ ǥ���ϱ� ���ؼ�
	//GameEngineLevel* UserContents_;
};

