#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
// ���� :
// ��ӱ����� ��������


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
	//�����Լ� 
	//�����Ҷ� ������ �ϰ� ������ ��������� �����ڿ��� ����� ���� �κе��� ó���Ѵ�.
	virtual void Start()=0;
	//���������� ������ ����ɶ� ȣ��ȴ�.
	virtual void Update(){};
	virtual void Render(){};
	void DebugRectRender();
private:
	//�� private�� ������ϳ� �Ǽ�����
	//�ڱ⸦ ���� ������ �˾ƾ��մϴ�.
	//���Ͱ� ������ ��ġ �ȵǸ� �ȵȴ�
	//������ ������ ���õ� ���¿��� �����ؾ��Ѵ�.
	//protected�� �� �ȵǳ� �ڽĿ��� Level_�� �����Ҽ��մ�.
	GameEngineLevel* Level_;
	float4 Position_;
	float4 Scale_;
	inline void SetLevel(GameEngineLevel* _Level)
	{
		Level_ = _Level;
	}
	
};

