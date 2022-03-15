#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// ���� :
//ȭ��
class GameEngine;
class GameEngineLevel:public GameEngineNameObject
{
	friend GameEngine;
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
	//�� protected�� ������?
	//���� ����� ���� �ֵ鿡�� �ַ���
	//�������� �ε��� ��������ַ���
	//�ٸ����� �ε��� �����ϸ� �ȵȴ�. �ε��� �ѹ���
	virtual void Loading()=0;//�ڱ� ȭ�鿡 ���� ���ҽ��� �̹��� �غ�
	//���� ������ ������Ʈ
	virtual void Update() = 0;
private:
	//�̰� ������ Actor�� �ʿ��� ��ü�鸶��  Create
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr;
	}
};

