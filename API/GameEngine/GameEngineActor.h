#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
// 설명 :
// 상속구조의 안좋은점


class GameEngineLevel;
class GameEngineActor:public GameEngineNameObject
{
	friend GameEngineLevel;
private:
	
public:
	
	// constrcuter destructer
	GameEngineActor();
	virtual ~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;
	
	inline void SetPosition(float4 _Value)
	{
		Position_ = _Value;
	}
	inline float4 GetPostion()
	{
		return Position_;
	}
	inline void SetScale(float4 _Value)
	{
		Scale_ = _Value;
	}
	inline float4 GetScale()
	{
		return Scale_;
	}
	
protected:
	//시점함수 
	//시작할때 뭔가를 하고 싶은데 만들어지면 생성자에서 절대로 못할 부분들을 처리한다.
	virtual void Start()=0;
	//지속적으로 게임이 실행될때 호출된다.
	virtual void Update(){};
	virtual void Render(){};
	void DebugRectRender();
private:
	//왜 private를 해줘야하나 실수방지
	//자기를 만든 레벨을 알아야합니다.
	//엑터가 레벨이 배치 안되면 안된다
	//무조건 레벨이 셋팅된 상태에서 동작해야한다.
	//protected는 왜 안되나 자식에서 Level_을 삭제할수잇다.
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}
	
};

