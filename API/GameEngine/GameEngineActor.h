#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
// 설명 :
class GameEngineActor:public GameEngineNameObject
{
private:
	//위치
	float4 Position_;
	//크기
	float4 Scale_;
public:
	// constrcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

protected:
	//시점함수
	//시작할때 뭔가를 하고 싶은데 생성자에서는 절대로 못할 부분들을 처리한다.
	//virtual void Start()=0;
	virtual void Start()=0;
	//지속적으로 게임이 실행될때 호출된다.
	virtual void Update(){};
	//지속적으로 게임이 실행될때 호출된다.
	virtual void Render(){};
private:

};

