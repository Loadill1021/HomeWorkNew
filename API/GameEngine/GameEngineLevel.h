#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>
// 설명 :
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
	//시점함수
	virtual void Loading() = 0;

	//레벨 수준의 업데이트
	virtual void Update() = 0;

	//ex)타이틀 레벨에서 플레이 레벨로 바뀔때 무언가 실행되어야 할 함수
	// xxx레벨=>xxx레벨로 이전할때 현재 레벨이 실행하는 함수
	// Current레벨=>Next로 이전할때 현재 레벨이 실행하는 함수
	virtual void SceneChangeStart(){}
	//Current레벨=>Next로 이전할때 이전레벨이 실행하는 함수
	virtual void SceneChangeEnd(){}
protected:
	//자식들은 맘대로써라
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name,int _Order)
	{
		//랜더링 방식때문에 이걸 만든것
		
		//몇개가 생길지 모르므로 동적할당 하는 수밖에없다.
		ActorType* NewActor=new ActorType();
		NewActor->SetName(_Name);

		std::map<int, std::list<GameEngineActor*>>::iterator FindGroup =
			AllActor_.find(_Order);

		if (FindGroup == AllActor_.end())
		{
			//찾지 못햇다면
			// 액터를 만들려면 2단계
			//1.그룹을 만든다
			//2.액터를 만든다
			//안좋은 이유?
			AllActor_.insert(std::make_pair)
		}


		//_Order 액터들이 돌아가는 순서를 의미하게 된다.
		//가장 먼저 행동해야할 애들을 가장 작은숫자로 넣어야한다.
		//map은 연관 컨테이너
		//나는 플레이어가 가장 먼저 업데이트 하게하고싶어.
		// insert와 find를 동시에 하게 됩니다.
		
		AllActor_[_Order];
		//0번 그룹이 있고 1번 그룹이 있다. 0번 그룹이 먼저 업데이트되어야한다.

		return nullptr;
	}
	/*
	* TitleLogo*
	* MonsterLogo*
	* 템플릿 안쓰면
	* 
	* CreateTitleLogoUI
	* CreateMarioUI
	*/
private:

	std::map<int, std::list<GameEngineActor*>>AllActor_;
	//std::map<std::string,std::list<GameEngineActor*>AllActor_;
	//왜 두개로 나눠서 관리하나요?
	//std::vector로 관리하는게 더 좋다고 생각합니다.
	//이름으로 찾는건 최악의 수다.
	//왜 맵에 리스트를 사용햇나?
	//랜더링순서때문에
};
