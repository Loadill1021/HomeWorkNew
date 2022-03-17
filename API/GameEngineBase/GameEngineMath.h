#pragma once

// 설명 :
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

class float4
{
public:
	float x;//2D X좌표
	float y;//2D Y좌표
	float z;//3차원때부터 사용
	float w;
public:
	bool IsZero2D()
	{
		return x == 0.0f && y == 0.0f;
	}
public:
	int ix()
	{
		return static_cast<int>(x);
	}
	int iy()
	{
		return static_cast<int>(y);
	}
	int iz()
	{
		return static_cast<int>(z);
	}
	int hix()
	{
		return static_cast<int>(x * 0.5f);
	}
	int hiy()
	{
		return static_cast<int>(y * 0.5f);
	}
	float4 Half()
	{
		//
		return {x * 0.5f,y * 0.5f,z * 0.5f,1.0f };
	}
public:
	float4()
		:x(0.0f), y(0.0f), z(0.0f), w(1.0f)
	{

	}
	float4(float _x,float _y)
		:x(_x),y(_y),z(0.0f),w(1.0f)
	{

	}
	float4(float _x, float _y, float _z)
		:x(_x),y(_y),z(_z),w(1.0f)
	{

	}
	float4(float _x, float _y, float _z, float _w)
		:x(_x),y(_y),z(_z),w(_w)
	{

	}
};

struct GameEngineRect
{
public:
	float4 Pos;//좌표
	float4 Scale;//크기
public:
	//현재위치의 x-크기의 반의 x좌표
	int CenterLeft()
	{
		return Pos.ix() - Scale.hix();
	}
	int CenterRight()
	{
		return Pos.ix() + Scale.hix();
	}
	int CenterTop()
	{
		return Pos.iy() - Scale.hiy();
	}
	int CenterBot()
	{
		return Pos.iy() + Scale.hiy();
	}
public:
	GameEngineRect(float4 _Pos, float4 _Scale)
		:Pos(_Pos)
		, Scale(_Scale)
	{

	}
};
