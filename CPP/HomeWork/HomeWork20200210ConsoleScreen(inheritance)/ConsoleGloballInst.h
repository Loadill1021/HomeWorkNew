#pragma once
#include "TextScreen.h"
#include "Monster.h"
#include "Player.h"
// 설명 :

extern TextScreen MainScreen;
extern Monster* AllMonsters;
extern Player MainPlayer;

class GlobalValue
{
	//클래스 정적 변수를 선언할수가 있습니다.
public:
	//클래스에 속한 전역변수가 됩니다.
	//static TextScreen MainScreen;
	//static Monster* AllMonsters;
	//static Player MainPlayer;
	TextScreen MainScreen;
	Monster* AllMonsters;
	Player MainPlayer;
};

extern GlobalValue Inst;


//class ConsoleGloballInst
//{
//public:
//	// constrcuter destructer
//	ConsoleGloballInst();
//	~ConsoleGloballInst();
//
//	// delete Function
//	ConsoleGloballInst(const ConsoleGloballInst& _Other) = delete;
//	ConsoleGloballInst(ConsoleGloballInst&& _Other) noexcept = delete;
//	ConsoleGloballInst& operator=(const ConsoleGloballInst& _Other) = delete;
//	ConsoleGloballInst& operator=(ConsoleGloballInst&& _Other) noexcept = delete;
//
//protected:
//
//private:
//
//};
//
