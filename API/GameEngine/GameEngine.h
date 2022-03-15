#pragma once
#include <map>
#include <string>

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
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		NewLevel->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}
protected:

private:
	std::map<std::string, GameEngineLevel*>AllLevel_;
};

