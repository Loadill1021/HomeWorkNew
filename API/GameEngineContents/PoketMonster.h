#pragma once
#include <GameEngine/GameEngine.h>
// Ό³Έν :
class PoketMonster:public GameEngine
{
public:
	// constrcuter destructer
	PoketMonster();
	~PoketMonster();

	// delete Function
	PoketMonster(const PoketMonster& _Other) = delete;
	PoketMonster(PoketMonster&& _Other) noexcept = delete;
	PoketMonster& operator=(const PoketMonster& _Other) = delete;
	PoketMonster& operator=(PoketMonster&& _Other) noexcept = delete;

	void GameInit()override;
	void GameLoop()override;
	void GameEnd()override;
protected:

private:

};

