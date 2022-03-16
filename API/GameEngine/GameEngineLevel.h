#pragma once
#include "GameEngineBase/GameEngineNameObject.h"
#include <list>
#include <map>
// 설명 :
//화면
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
	//왜 protected에 놨을까?
	//보통 상속을 받은 애들에게 주려고
	//엔진에서 로딩을 실행시켜주려고
	//다른데서 로딩을 실행하면 안된다. 로딩은 한번만
	//엔진 수준의 업데이트
	
	//시점함수
	//만들어지면서 리소스나 엑터를 만들때 써라
	virtual void Loading()=0;//자기 화면에 대한 리소스나 이미지 준비
	//이 레벨이 현재 레벨일때 해야할일을 실행한다.
	virtual void Update() = 0;

	//Current레벨 =>Next레벨로 이전할때 현재 레벨이 실행하는 함수
	virtual void SceneChangeStart();
	//Current레벨 =>Next레벨로 이전할때 이전 레벨이 실행하는 함수
	virtual void SceneChangeEnd();
protected:
	//이게 없으면 Actor가 필요한 객체들마다  Create
	//템플릿은 그냥 내가 쓴 자료형 만큼 함수를 만들어주는 문법
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name,int _Order)
	{
		//엑터가 몇개가 될지 알 수 없으므로
		ActorType* NewActor = new ActorType();
		NewActor->SetName(_Name);
		//std::list<GameEngineActor*>&Group=AllActor_[_Order];
		//Group.push_back(NewActor);
		//맵을 사용하는 일반적인 방법 key로 찾아서 만일 없다면

		//_Order 액터들이 돌아가는 순서를 의미하게 된다.
		//맵은 기본적으로 key값이 가장 작은 값이 앞 연관 컨테이너
		//플레이어가 가장 먼저 업데이트 하게하고싶어.
		//insert와 find를 동시에 하게 됩니다.
		//std::map<int, std::list<GameEngineActor*>>::iterator FindGroup =
		//	AllActor_.find(_Order);

		if (FindGroup == AllActor_.end)
		{
			AllActor_.insert(std::make_pair(_Order, std::list<GameEngineActor*>()));
			//이게 좀더 빠른데 눈꼽만큼차이
			AllActor_.insert(std::map<int, std::list<GameEngineActor*>>::value_type(_Order, std::list<GameEngineActor*>()));
		}
		AllActor_[_Order]
		return nullptr;
	}
private:
	//std::vector로 관리하는게 더 좋다고 생각합니다.
	std::map<int, std::list<GameEngineActor*>>AllActor_;
	//std::map<std::string, std::list<GameEngineActor*>> AllActor_;
	// 왜 두개로 나눠서 관리
	// 이걸 사용하는건 최악의 수다. 이름으로 찾고 싶을때가 있을 수 있다
	//std::map<std::string, GameEngineActor*>AllActor_;
};

