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
		//UserContents_->GameInit();
		//UserContents_->GameLoop();
		EngineEnd();
	}
	//글로벌 엔진이 없을때가 있나?
	static GameEngine& GlobalEngine()
	{
		//엔진을 기동시킨뒤 바로 생성된다.
		//엔진을 시작하지도 않았는데 엔진을 불러옴
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine Is Not Start");
		}
		return *UserContents_;
	}
	// 왜 string으로 관리중인가 편해서 
	// 레벨을 바꿀때
	// 헤더는 고칠수 있어서
	void ChangeLevel(const std::string& _Name);
protected:
	//레벨은 무조건 처음에 다 만들어져야한다.
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;//업캐스팅 GamEngineLevel* =나머지 Level자식들중 하나
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}
	
private:
	static std::map<std::string, GameEngineLevel*>AllLevel_;
	//전역 변수
	static GameEngine* UserContents_;
	
	//static으로 만든 이유?
	static GameEngineLevel* CurrentLevel_;
	static GameEngineLevel* NextLevel_;
	//클래스로 표현하기 위해서
	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};

