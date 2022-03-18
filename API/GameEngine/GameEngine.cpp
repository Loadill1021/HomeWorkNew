#include "GameEngine.h"
#include "GameEngineBase/GameEngineWindow.h"
#include "GameEngineLevel.h"
std::map<std::string, GameEngineLevel*>GameEngine::AllLevel_;
//���� ���� ���忡�� ������ ���� ������ ������ ���� 
GameEngine* GameEngine::UserContents_=nullptr;
//���� ������ �˱� ���ؼ�
GameEngineLevel* GameEngine::CurrentLevel_=nullptr;
//����: 
GameEngineLevel* GameEngine::NextLevel_=nullptr;
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
	//����� �ٽ� ���ƿ� ������������
	//���� ������ ����
	UserContents_->GameLoop();

	//�ѹ��� �������� �������� 
	if (nullptr!=NextLevel_)
	{
		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->SceneChangeEnd();
		}
		CurrentLevel_ = NextLevel_;
		if (nullptr != CurrentLevel_)
		{
			CurrentLevel_->SceneChangeStart();
		}
	}
	if (nullptr==CurrentLevel_)
	{
		MsgBoxAssert("Level is nullptr=>GameEngine Loop Error");
		return;
	}
	int a = 0;
	//���������� ����
	//�ð� ������ �ִ� �����̶�� �������Ӹ��� �ð��� üũ�ؾ��ϴµ� �׷����� 
	//
	//��ȭ���� ����� �������̶�� �Ҹ��� ��
	CurrentLevel_->Update();
	CurrentLevel_->ActorUpdate();
	CurrentLevel_->ActorReder();
}
void GameEngine::ChangeLevel(const std::string& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = AllLevel_.find(_Name);

	// ������ ã�� ���ߴٸ�
	// �볳�Ҽ� ���� ����
	// ���� ������ �ٲٷ��� �ؼ�
	if (FindIter == AllLevel_.end())
	{
		MsgBoxAssert("Level Find Error");
		return;
	}
	NextLevel_ = FindIter->second;
	//���� ������ �������Ѵ�.
	//���� ������ ���ö� ������ �ٲ� ȥ���� �ټ��־
}