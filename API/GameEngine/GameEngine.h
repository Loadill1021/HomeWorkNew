#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>
// 설명 :
// 게임엔진이란 게임 그자체의 시작점과 끝점 실행중을 담당하는 녀석이다.
// 레벨을 관리하고 만드는 것 담당.
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

	// 내가 만드는 프레임 워크에서는
	// GameEngine 이 세가지를 구현안하면
	// 내용이 없다고 하더라도 안되.
	virtual void GameInit()=0;
	virtual void GameLoop()=0;
	virtual void GameEnd()=0;
	
	//이렇게 안하면
	//Level 종류가 많으면 PlayLevel TitleLevel EndingLevel을 알지 못해서 각각 함수를 만들어야한다.
	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();
		
		GameType UserGame;
		UserContents_=&UserGame;

		
		WindowCreate();
		EngineEnd();
	}

	static GameEngine& GlobalGameEngine()
	{
		//없을 가능성이없다.
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine Is Not Start");
		}
		return *UserContents_;
	}
	
	//관리 어떤 자료구조를 사용해서 관리하고 있나
	//string으로 관리하고 있다=>편해서
	//헤더에 구현하지 않는 이유
	//헤더를 보고 구현을 고칠수 있어서
	void ChangeLevel(const std::string& _Name);

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;//업캐스팅 
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}
private:
	static std::map<std::string, GameEngineLevel*>AllLevel_;
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;
	static GameEngine* UserContents_;
	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};
// 게임 엔진이 겉으로는 책임을 지겠다.
// 너희들이 시작할때 윈도우 같은걸 몰라도 되게하겠다.

// 오로지 인터페이스만 제공하겠다.
//class IGameEngineInstance
//{
//	virtual void GameInit() = 0;
//	virtual void GameLoop() = 0;
//	virtual void GameEnd() = 0;
//};
