#pragma once
#include <map>
#include <string>

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

