#include "GameEngine.h"
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngine/GameEngineLevel.h>
//현재 레벨을 알기위해서
GameEngineLevel* GameEngine::CurrentLevel_=nullptr;
GameEngineLevel* GameEngine::NextLevel_=nullptr;
std::map<std::string, GameEngineLevel*>GameEngine::AllLevel_;
//엔진이 어떤 컨텐츠를 돌릴지 모르므로 엔진을 상속받은 컨텐츠를 업캐스팅 하기 위해서  
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
    GameEngineWindow::GetInst().MessageLoop(EngineInit, EngineLoop);
}
void GameEngine::EngineInit()
{
    UserContents_->GameInit();
}
void GameEngine::EngineLoop()
{
    //엔진 수준에서 매 프레임마다 체크하고 싶은거
    UserContents_->GameLoop();
    if (nullptr != NextLevel_)
    {
        CurrentLevel_ = NextLevel_;
        NextLevel_ = nullptr;
    }
    if (nullptr == CurrentLevel_)
    {
        MsgBoxAssert("Level is nullptr GameEngine Loop Error");
    }
    // 레벨수준 시간제한이 있는 게임이라면
    // 매 프레임마다 시간을 체크해야하는데 그런일을 
    CurrentLevel_->Update();
}
void GameEngine::EngineEnd()
{
    UserContents_->GameEnd();
    //GameEngine객체를 만들어주지 않았으므로 
    //소멸자에서 처리하지않고 여기서 처리해준다.
    //GameEngine<게임>();함수로 호출
    std::map<std::string, GameEngineLevel*>::iterator StartIter=AllLevel_.begin();
    std::map<std::string, GameEngineLevel*>::iterator EndIter=AllLevel_.end();

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
void GameEngine::ChangeLevel(const std::string& _Name)
{
    std::map <std::string, GameEngineLevel* >::iterator FindIter = AllLevel_.find(_Name);
    if (AllLevel_.end() == FindIter)
    {
        MsgBoxAssert("Level Find Error");
        return;
    }
    NextLevel_ = FindIter->second;
}
//void CreateLevel(const std::string& _LevelName)
//{
//
//}
