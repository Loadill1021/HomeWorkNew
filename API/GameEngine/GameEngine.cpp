#include "GameEngine.h"
#include "GameEngineBase/GameEngineWindow.h"
#include "GameEngineLevel.h"
#include "GameEngineImageManager.h"
#include "GameEngine/GameEngineImage.h"//cpp에서는 알아도 상관없다.
std::map<std::string, GameEngineLevel*>GameEngine::AllLevel_;
//게임 엔진 입장에서 유저가 무슨 게임을 만들지 몰라서 
GameEngine* GameEngine::UserContents_=nullptr;
//현재 레벨을 알기 위해서
GameEngineLevel* GameEngine::CurrentLevel_=nullptr;
//이유: 
GameEngineLevel* GameEngine::NextLevel_=nullptr;
GameEngineImage* GameEngine::BackBufferImage_=nullptr;
GameEngineImage* GameEngine::WindowMainImage_ = nullptr;

HDC GameEngine::BackBufferDC()
{
	return BackBufferImage_->ImageDC();
}
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
	GameEngineImageManager::Destroy();
	GameEngineWindow::Destroy();
}
void GameEngine::EngineInit()
{
	//여기서 윈도우의 크기가 결정될 것이므로
	UserContents_->GameInit();
	//백버퍼를 만들어 낸다.
	//이미지를 두개 만들어준다.
	//
	WindowMainImage_ = GameEngineImageManager::GetInst()->Create("WindowMain", GameEngineWindow::GetHDC());
	//이미지를 그려놓은 데
	BackBufferImage_ = GameEngineImageManager::GetInst()->Create("BackBuffer",GameEngineWindow::GetScale());
}
void GameEngine::EngineLoop()
{
	//여기로 다시 돌아옴 끝나기전까지
	//엔진 수준의 루프
	UserContents_->GameLoop();

	//한번의 프레임을 돌기전에 
	if (nullptr!=NextLevel_)
	{
		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->LevelChangeEnd();
		}
		CurrentLevel_ = NextLevel_;
		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->LevelChangeStart();
		}
	}
	if (nullptr==CurrentLevel_)
	{
		MsgBoxAssert("Level is nullptr=>GameEngine Loop Error");
		return;
	}
	int a = 0;
	//레벨수준의 루프
	//시간 제한이 있는 게임이라면 매프레임마다 시간을 체크해야하는데 그런일을 
	//
	//한화면을 만드는 프레임이라고 불리는 곳
	CurrentLevel_->Update();
	CurrentLevel_->ActorUpdate();
	CurrentLevel_->ActorReder();

	//윈도우 메인 이미지에 BackBuffer이미지를 복사붙여넣기해라
	WindowMainImage_->BitCopy(BackBufferImage_);
}
void GameEngine::ChangeLevel(const std::string& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

	// 레벨을 찾지 못했다면
	// 용납할수 없는 오류
	// 없는 레벨로 바꾸려고 해서
	if (FindIter == AllLevel_.end())
	{
		MsgBoxAssert("Level Find Error");
		return;
	}
	NextLevel_ = FindIter->second;
	//현재 레벨을 만들어야한다.
	//들어갈때 레벨이 나올때 레벨이 바뀌어서 혼란을 줄수있어서
}