#pragma once
#include "TextScreen.h"
#include "Monster.h"
#include "Player.h"
// ���� :

extern TextScreen MainScreen;
extern Monster* AllMonsters;
extern Player MainPlayer;

class GlobalValue
{
	//Ŭ���� ���� ������ �����Ҽ��� �ֽ��ϴ�.
public:
	//Ŭ������ ���� ���������� �˴ϴ�.
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
