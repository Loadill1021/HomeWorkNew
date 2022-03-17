#include "GameEngine.h"
#include "GameEngineBase/GameEngineWindow.h"
#include "GameEngineLevel.h"
std::map<std::string, GameEngineLevel*>GameEngine::AllLevel_;
GameEngine* GameEngine::UserContents_=nullptr;
GameEngine::GameEngine() 
{
}

GameEngine::~GameEngine() 
{
}

void GameEngine::GameInit()
{	 
}	 
void GameEngine::GameLoop()
{	 
}	 
void GameEngine::GameEnd()
{

}

void GameEngine::WindowCreate()
{
	GameEngineWindow::GetInst().CreateGameWindow(nullptr, "PoketMonster");
	GameEngineWindow::GetInst().ShowGameWindow();
	GameEngineWindow::GetInst().MessageLoop(EngineInit,EngineLoop);
}
void GameEngine::EngineEnd()
{
	UserContents_->GameEnd();

	std::map<std::string, GameEngineLevel*>::iterator StartIter = AllLevel_.begin();
	std::map<std::string, GameEngineLevel*>::iterator EndIter = AllLevel_.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		if (nullptr == StartIter->second)
		{
			continue;
		}
		delete StartIter->second;
	}
	GameEngineWindow::Destroy();
}
void GameEngine::EngineInit()
{
	UserContents_->GameInit();
}
void GameEngine::EngineLoop()
{
	UserContents_->GameLoop();
}