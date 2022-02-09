#pragma once

// 설명 : 수학적인 클래스들의 모음
class ConsoleMath
{
public:
	// constrcuter destructer
	ConsoleMath();
	~ConsoleMath();

	// delete Function
	ConsoleMath(const ConsoleMath& _Other) = delete;
	ConsoleMath(ConsoleMath&& _Other) noexcept = delete;
	ConsoleMath& operator=(const ConsoleMath& _Other) = delete;
	ConsoleMath& operator=(ConsoleMath&& _Other) noexcept = delete;

protected:

private:

};
//좌표 값 x좌표와 y좌표
class ConsoleVector
{
public:
	int x_;
	int y_;
	ConsoleVector()
		:x_(0), y_(0)
	{

	}
	ConsoleVector(int _x, int _y)
		:x_(_x), y_(_y)
	{

	}
	ConsoleVector GetHalfVector()
	{
		return ConsoleVector(x_ / 2, y_ / 2);
	}
	ConsoleVector& operator+=(const ConsoleVector& _Other)
	{
		x_ += _Other.x_;
		y_ += _Other.y_;
		return *this;
	}
};