#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

// 설명 : 게임엔진이란 게임 그자체
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

	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();
		GameType UserGame;
		//타입을 강제하고 싶어서 업캐스팅
		UserContents_ = &UserGame;
		WindowCreate();
		//UserContents_->GameInit();
		//UserContents_->GameLoop();
		EngineEnd();
	}

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		sizeof(LevelType);
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;//업캐스팅 GamEngineLevel* =나머지 Level자식들중 하나
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}

private:
	static std::map<std::string, GameEngineLevel*>AllLevel_;
	static GameEngine* UserContents_;


	//클래스로 표현하기 위해서
	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};

