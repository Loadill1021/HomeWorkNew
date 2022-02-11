#pragma once
#include "TextScreen.h"
#include "Monster.h"
#include "Player.h"
// Ό³Έν :

class ConsoleGloballInst
{
public:
	// constrcuter destructer
	ConsoleGloballInst();
	~ConsoleGloballInst();

	// delete Function
	ConsoleGloballInst(const ConsoleGloballInst& _Other) = delete;
	ConsoleGloballInst(ConsoleGloballInst&& _Other) noexcept = delete;
	ConsoleGloballInst& operator=(const ConsoleGloballInst& _Other) = delete;
	ConsoleGloballInst& operator=(ConsoleGloballInst&& _Other) noexcept = delete;

protected:

private:

};

