#include "GameEngineLevel.h"
#include "GameEngine/GameEngineActor.h"
GameEngineLevel::GameEngineLevel() 
{

}

GameEngineLevel::~GameEngineLevel() 
{
	std::map<int, std::list<GameEngineActor*>>::iterator GroupStart = AllActor_.begin();

	std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd = AllActor_.end();
	for (; GroupStart != GroupEnd; ++GroupStart)
	{
		std::list<GameEngineActor*>& Group = GroupStart->second;
		std::list<GameEngineActor*>::iterator StartActor = Group.begin();
		std::list <GameEngineActor*> ::iterator EndActor = Group.end();
		for (; StartActor != EndActor; ++StartActor)
		{
			if (nullptr == *StartActor)
			{
				continue;
			}
			delete (*StartActor);
		}
	}
}
void GameEngineLevel::ActorUpdate()
{
	std::map<int, std::list<GameEngineActor*>>::iterator GroupStart = AllActor_.begin();

	std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd = AllActor_.end();
	for (; GroupStart != GroupEnd; ++GroupStart)
	{
		std::list<GameEngineActor*>& Group = GroupStart->second;
		std::list<GameEngineActor*>::iterator StartActor = Group.begin();
		std::list <GameEngineActor*> ::iterator EndActor = Group.end();
		for (; StartActor != EndActor; ++StartActor)
		{
			if (nullptr == *StartActor)
			{
				continue;
			}
			//이거 다시복습
			(*StartActor)->Update();
		}
	}
}
void GameEngineLevel::ActorReder()
{
	std::map<int, std::list<GameEngineActor*>>::iterator GroupStart = AllActor_.begin();

	std::map<int, std::list<GameEngineActor*>>::iterator GroupEnd = AllActor_.end();
	for (; GroupStart != GroupEnd; ++GroupStart)
	{
		std::list<GameEngineActor*>& Group = GroupStart->second;
		std::list<GameEngineActor*>::iterator StartActor = Group.begin();
		std::list <GameEngineActor*> ::iterator EndActor = Group.end();
		for (; StartActor != EndActor; ++StartActor)
		{
			if (nullptr == *StartActor)
			{
				continue;
			}
			(*StartActor)->Render();
		}
	}
}
