#pragma once

// ���� :
// �츮 �������� ����ϴ� ���� ���õ� ��� ��ɵ�
class GameEngineMath
{
public:
	// constrcuter destructer
	GameEngineMath();
	~GameEngineMath();

	// delete Function
	GameEngineMath(const GameEngineMath& _Other) = delete;
	GameEngineMath(GameEngineMath&& _Other) noexcept = delete;
	GameEngineMath& operator=(const GameEngineMath& _Other) = delete;
	GameEngineMath& operator=(GameEngineMath&& _Other) noexcept = delete;

protected:

private:

};

//x,y 2D
//z,w 
class float4
{
public:
	float x;
	float y;
	float z;
	float w;

};