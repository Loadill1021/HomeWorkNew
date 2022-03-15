#pragma once
#include <map>
#include <string>
#include <GameEngineBase/GameEngineDebug.h>
// ���� :
// ���ӿ����̶� ���� ����ü�� �������� ���� �������� ����ϴ� �༮�̴�.
// ������ �����ϰ� ����� �� ���.
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

	// ���� ����� ������ ��ũ������
	// GameEngine �� �������� �������ϸ�
	// ������ ���ٰ� �ϴ��� �ȵ�.
	virtual void GameInit()=0;
	virtual void GameLoop()=0;
	virtual void GameEnd()=0;
	
	//�̷��� ���ϸ�
	//Level ������ ������ PlayLevel TitleLevel EndingLevel�� ���� ���ؼ� ���� �Լ��� �������Ѵ�.
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
		//���� ���ɼ��̾���.
		if (nullptr == UserContents_)
		{
			MsgBoxAssert("GEngine ERROR Engine Is Not Start");
		}
		return *UserContents_;
	}
	
	//���� � �ڷᱸ���� ����ؼ� �����ϰ� �ֳ�
	//string���� �����ϰ� �ִ�=>���ؼ�
	//����� �������� �ʴ� ����
	//����� ���� ������ ��ĥ�� �־
	void ChangeLevel(const std::string& _Name);

protected:
	template<typename LevelType>
	void CreateLevel(const std::string& _Name)
	{
		LevelType* NewLevel = new LevelType();
		NewLevel->SetName(_Name);
		GameEngineLevel* Level = NewLevel;//��ĳ���� 
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
// ���� ������ �����δ� å���� ���ڴ�.
// ������� �����Ҷ� ������ ������ ���� �ǰ��ϰڴ�.

// ������ �������̽��� �����ϰڴ�.
//class IGameEngineInstance
//{
//	virtual void GameInit() = 0;
//	virtual void GameLoop() = 0;
//	virtual void GameEnd() = 0;
//};
