#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>

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

	template<typename GameType>
	static void Start()
	{
		GameEngineDebug::LeakCheckOn();
		GameType UserGame;
		//Ÿ���� �����ϰ� �; ��ĳ����
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
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;//��ĳ���� GamEngineLevel* =������ Level�ڽĵ��� �ϳ�
		Level->Loading();
		AllLevel_.insert(std::make_pair(_Name, NewLevel));
	}
	// �� string���� �������ΰ� ���ؼ� 
	// ������ �ٲܶ�
	void ChangeLevel(const std::string& _Name)
	{
		std::map<std::string,GameEngineLevel*>::iterator FindIter=AllLevel_.find(_Name);
		
		// ������ ã�� ���ߴٸ�
		// �볳�Ҽ� ���� ����
		// ���� ������ �ٲٷ��� �ؼ�
		if (FindIter == AllLevel_.end())
		{
			MsgBoxAssert("Level Find Error");
			return;
		}
		CurrentLevel_=FindIter->second;
		//���� ������ �������Ѵ�.
	}
private:
	static std::map<std::string, GameEngineLevel*>AllLevel_;
	static GameEngine* UserContents_;
	
	//static���� ���� ����?
	static GameEngineLevel* CurrentLevel_;

	//Ŭ������ ǥ���ϱ� ���ؼ�
	static void WindowCreate();
	static void EngineInit();
	static void EngineLoop();
	static void EngineEnd();
};

