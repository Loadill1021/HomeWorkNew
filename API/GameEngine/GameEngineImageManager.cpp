#include "GameEngineImageManager.h"
#include "GameEngineBase/GameEngineDebug.h"
GameEngineImageManager* GameEngineImageManager::Inst_=new GameEngineImageManager();

GameEngineImageManager::GameEngineImageManager()
{
}

GameEngineImageManager::~GameEngineImageManager() 
{
	std::map<std::string, GameEngineImage*>::iterator StartIter=AllRes.begin();
	std::map<std::string, GameEngineImage*>::iterator EndIter=AllRes.end();

	for (; StartIter!=EndIter;++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second;
			StartIter->second = nullptr;
		}
	}
}

GameEngineImage* GameEngineImageManager::Create(const std::string& _Name, float4 _Scale)
{
	//���� ����ؼ� �̹����� ���������Ƿ� ���� �̸��� �̹����� �����Ҽ�����.
	//�̹��� �ε带 ���� �̹����� ����Ϸ��� �ϸ� �Ͷ߷����Ѵ�.
	if (AllRes.end() != AllRes.find(_Name))
	{
		MsgBoxAssert("�̹� �����ϴ� �̸��� �̹������� �� ������� �߽��ϴ�.");
		return nullptr;
	}
	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->SetName(_Name);

	//�Ŵ����� �̹����� ����°� �ƴ϶� ������ ��Ű�°�

	if (false == NewImage->Create(_Scale))
	{
		delete NewImage;
		MsgBoxAssert((_Name + "�̹����� �����ϴµ� �����߽��ϴ�.").c_str());
	}
	//makepair�� value_type�� ���� make_pair�� �Լ��� �ѹ� ��ü�� ������༭ �ణ �̼��ϰ� ������ �����̾���.
	//AllRes.insert(std::map<std::string, GameEngineImage*>::value_type(_Name, NewImage));
	AllRes.insert(std::make_pair(_Name, NewImage));
	return NewImage;
}

GameEngineImage* GameEngineImageManager::Create(const std::string& _Name, HDC _DC)
{
	//���� ����ؼ� �̹����� ���������Ƿ� ���� �̸��� �̹����� �����Ҽ�����.
	//�̹��� �ε带 ���� �̹����� ����Ϸ��� �ϸ� �Ͷ߷����Ѵ�.
	if (AllRes.end() != AllRes.find(_Name))
	{
		MsgBoxAssert("�̹� �����ϴ� �̸��� �̹������� �� ������� �߽��ϴ�.");
		return nullptr;
	}
	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->SetName(_Name);

	//�Ŵ����� �̹����� ����°� �ƴ϶� ������ ��Ű�°�

	if (false == NewImage->Create(_DC))
	{
		delete NewImage;
		MsgBoxAssert((_Name + "�̹����� �����ϴµ� �����߽��ϴ�.").c_str());
	}
	//makepair�� value_type�� ���� make_pair�� �Լ��� �ѹ� ��ü�� ������༭ �ణ �̼��ϰ� ������ �����̾���.
	//AllRes.insert(std::map<std::string, GameEngineImage*>::value_type(_Name, NewImage));
	AllRes.insert(std::make_pair(_Name, NewImage));
	return NewImage;
	return nullptr;
}
