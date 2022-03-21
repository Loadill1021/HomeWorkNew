#include "GameEngine.h"
#include "GameEngineBase/GameEngineWindow.h"
#include "GameEngineLevel.h"
#include "GameEngineImageManager.h"
#include "GameEngine/GameEngineImage.h"//cpp������ �˾Ƶ� �������.
std::map<std::string, GameEngineLevel*>GameEngine::AllLevel_;
//���� ���� ���忡�� ������ ���� ������ ������ ���� 
GameEngine* GameEngine::UserContents_=nullptr;
//���� ������ �˱� ���ؼ�
GameEngineLevel* GameEngine::CurrentLevel_=nullptr;
//����: 
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
void GameEngine::EngineInit()
{
	//���⼭ �������� ũ�Ⱑ ������ ���̹Ƿ�
	UserContents_->GameInit();
	
	//�̹����� �ΰ� ������ش�.
	//����۸� ����� ����.
	WindowMainImage_ = GameEngineImageManager::GetInst()->Create("WindowMain", GameEngineWindow::GetHDC());
	BackBufferImage_ = GameEngineImageManager::GetInst()->Create("BackBuffer",GameEngineWindow::GetScale());
	//�̹����� �׷����� ��
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
	//���������� ����
	//�ð� ������ �ִ� �����̶�� �������Ӹ��� �ð��� üũ�ؾ��ϴµ� �׷����� 
	//
	//��ȭ���� ����� �������̶�� �Ҹ��� ��
	CurrentLevel_->Update();
	CurrentLevel_->ActorUpdate();
	CurrentLevel_->ActorReder();

	//������ ���� �̹����� BackBuffer�̹����� ����ٿ��ֱ��ض�
	WindowMainImage_->BitCopy(BackBufferImage_);
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
	//�̹����� �����ش�.
	GameEngineImageManager::Destroy();
	GameEngineWindow::Destroy();
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