#pragma once
#include <GameEngineBase/GameEngineNameObject.h>
#include <GameEngineBase/GameEngineMath.h>
// ���� :
class GameEngineActor:public GameEngineNameObject
{
private:
	//��ġ
	float4 Position_;
	//ũ��
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
	//�����Լ�
	//�����Ҷ� ������ �ϰ� ������ �����ڿ����� ����� ���� �κе��� ó���Ѵ�.
	//virtual void Start()=0;
	virtual void Start()=0;
	//���������� ������ ����ɶ� ȣ��ȴ�.
	virtual void Update(){};
	//���������� ������ ����ɶ� ȣ��ȴ�.
	virtual void Render(){};
private:

};

