#pragma once
#include "GameEngineBase/GameEngineNameObject.h"

// 설명 :
//화면
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
	virtual void Loading()=0;//자기 화면에 대한 리소스나 이미지 준비
	//엔진 수준의 업데이트
	virtual void Update() = 0;
private:
	//이게 없으면 Actor가 필요한 객체들마다  Create
	template<typename ActorType>
	ActorType* CreateActor(const std::string& _Name)
	{
		return nullptr;
	}
};

