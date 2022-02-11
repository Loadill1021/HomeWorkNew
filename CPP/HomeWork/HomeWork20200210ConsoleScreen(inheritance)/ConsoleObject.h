#pragma once
#include "ConsoleMath.h"//수학적인 것들의 모임
#include "TextScreen.h"//콘솔창에 띄우기
// 설명 : 플레이어,몬스터가 공통으로 가질 것들
class ConsoleObject
{
public:
	// constrcuter destructer
	ConsoleObject(
		TextScreen* _Screen,
		const char* _Text,
		const ConsoleVector& _Pos
	);
	~ConsoleObject();

	// delete Function
	ConsoleObject(const ConsoleObject& _Other) = delete;
	ConsoleObject(ConsoleObject&& _Other) noexcept = delete;
	ConsoleObject& operator=(const ConsoleObject& _Other) = delete;
	ConsoleObject& operator=(ConsoleObject&& _Other) noexcept = delete;
	
	ConsoleVector GetPos()
	{
		return Pos_;
	}
	void SetPos(ConsoleVector _Value)
	{
		Pos_ = _Value;
	}
	
	void SetMove(ConsoleVector _Value)
	{
		Pos_ += _Value;
	}
	bool isWall(ConsoleVector _Value);
	//{
	//	ConsoleVector Pos = this->Pos_+_Value;
	//	if (0 > Pos.x_ ||
	//		0 > Pos.y_ ||
	//		Pos.x_ >= Screen_->GetSize().x_ ||
	//		Pos.y_ >= Screen_->GetSize().y_)
	//	{
	//		return true;
	//	}
	//	return false;
	//}
	void Render();
protected:

private:
	//Has a개념
	TextScreen* Screen_;//모니터는 하나니까
	ConsoleVector Pos_;//위치
	char Text_[3];//찍힐 모양
};

