#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>
// ���� :
class GameEngineActor;
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
	//�����Լ�
	virtual void Loading() = 0;

	//���� ������ ������Ʈ
	virtual void Update() = 0;

	//ex)Ÿ��Ʋ �������� �÷��� ������ �ٲ� ���� ����Ǿ�� �� �Լ�
	// xxx����=>xxx������ �����Ҷ� ���� ������ �����ϴ� �Լ�
	// Current����=>Next�� �����Ҷ� ���� ������ �����ϴ� �Լ�
	virtual void SceneChangeStart(){}
	//Current����=>Next�� �����Ҷ� ���������� �����ϴ� �Լ�
	virtual void SceneChangeEnd(){}
protected:
	//�ڽĵ��� ����ν��
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name,int _Order)
	{
		//������ ��Ķ����� �̰� �����
		
		//��� ������ �𸣹Ƿ� �����Ҵ� �ϴ� ���ۿ�����.
		ActorType* NewActor=new ActorType();
		NewActor->SetName(_Name);

		std::map<int, std::list<GameEngineActor*>>::iterator FindGroup =
			AllActor_.find(_Order);

		if (FindGroup == AllActor_.end())
		{
			//ã�� ���޴ٸ�
			// ���͸� ������� 2�ܰ�
			//1.�׷��� �����
			//2.���͸� �����
			//������ ����?
			AllActor_.insert(std::make_pair)
		}


		//_Order ���͵��� ���ư��� ������ �ǹ��ϰ� �ȴ�.
		//���� ���� �ൿ�ؾ��� �ֵ��� ���� �������ڷ� �־���Ѵ�.
		//map�� ���� �����̳�
		//���� �÷��̾ ���� ���� ������Ʈ �ϰ��ϰ�;�.
		// insert�� find�� ���ÿ� �ϰ� �˴ϴ�.
		
		AllActor_[_Order];
		//0�� �׷��� �ְ� 1�� �׷��� �ִ�. 0�� �׷��� ���� ������Ʈ�Ǿ���Ѵ�.

		return nullptr;
	}
	/*
	* TitleLogo*
	* MonsterLogo*
	* ���ø� �Ⱦ���
	* 
	* CreateTitleLogoUI
	* CreateMarioUI
	*/
private:

	std::map<int, std::list<GameEngineActor*>>AllActor_;
	//std::map<std::string,std::list<GameEngineActor*>AllActor_;
	//�� �ΰ��� ������ �����ϳ���?
	//std::vector�� �����ϴ°� �� ���ٰ� �����մϴ�.
	//�̸����� ã�°� �־��� ����.
	//�� �ʿ� ����Ʈ�� ����޳�?
	//����������������
};
