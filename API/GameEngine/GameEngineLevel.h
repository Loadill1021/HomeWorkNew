#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>
// ���� :
//ȭ��
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
	//�� protected�� ������?
	//���� ����� ���� �ֵ鿡�� �ַ���
	//�������� �ε��� ��������ַ���
	//�ٸ����� �ε��� �����ϸ� �ȵȴ�. �ε��� �ѹ���
	//���� ������ ������Ʈ
	
	//�����Լ�
	//��������鼭 ���ҽ��� ���͸� ���鶧 ���
	virtual void Loading()=0;//�ڱ� ȭ�鿡 ���� ���ҽ��� �̹��� �غ�
	//�� ������ ���� �����϶� �ؾ������� �����Ѵ�.
	virtual void Update() = 0;

	//Current���� =>Next������ �����Ҷ� ���� ������ �����ϴ� �Լ�
	virtual void SceneChangeStart();
	//Current���� =>Next������ �����Ҷ� ���� ������ �����ϴ� �Լ�
	virtual void SceneChangeEnd();
protected:
	//�̰� ������ Actor�� �ʿ��� ��ü�鸶��  Create
	//���ø��� �׳� ���� �� �ڷ��� ��ŭ �Լ��� ������ִ� ����
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name,int _Order)
	{
		//���Ͱ� ��� ���� �� �� �����Ƿ�
		ActorType* NewActor = new ActorType();
		NewActor->SetName(_Name);
		//std::list<GameEngineActor*>&Group=AllActor_[_Order];
		//Group.push_back(NewActor);
		//���� ����ϴ� �Ϲ����� ��� key�� ã�Ƽ� ���� ���ٸ�

		//_Order ���͵��� ���ư��� ������ �ǹ��ϰ� �ȴ�.
		//���� �⺻������ key���� ���� ���� ���� �� ���� �����̳�
		//�÷��̾ ���� ���� ������Ʈ �ϰ��ϰ�;�.
		//insert�� find�� ���ÿ� �ϰ� �˴ϴ�.
		//std::map<int, std::list<GameEngineActor*>>::iterator FindGroup =
		//	AllActor_.find(_Order);

		if (FindGroup == AllActor_.end)
		{
			AllActor_.insert(std::make_pair(_Order, std::list<GameEngineActor*>()));
			//�̰� ���� ������ ���Ÿ�ŭ����
			AllActor_.insert(std::map<int, std::list<GameEngineActor*>>::value_type(_Order, std::list<GameEngineActor*>()));
		}
		AllActor_[_Order]
		return nullptr;
	}
private:
	//std::vector�� �����ϴ°� �� ���ٰ� �����մϴ�.
	std::map<int, std::list<GameEngineActor*>>AllActor_;
	//std::map<std::string, std::list<GameEngineActor*>> AllActor_;
	// �� �ΰ��� ������ ����
	// �̰� ����ϴ°� �־��� ����. �̸����� ã�� �������� ���� �� �ִ�
	//std::map<std::string, GameEngineActor*>AllActor_;
};

