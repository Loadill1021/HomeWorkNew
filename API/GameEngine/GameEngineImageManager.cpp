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
	//맵을 사용해서 이미지를 관리했으므로 같은 이름의 이미지가 존재할수없다.
	//이미지 로드를 안한 이미지를 사용하려고 하면 터뜨려야한다.
	if (AllRes.end() != AllRes.find(_Name))
	{
		MsgBoxAssert("이미 존재하는 이름의 이미지를를 또 만들려고 했습니다.");
		return nullptr;
	}
	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->SetName(_Name);

	//매니저는 이미지를 만드는게 아니라 만들라고 시키는거

	if (false == NewImage->Create(_Scale))
	{
		delete NewImage;
		MsgBoxAssert((_Name + "이미지를 생성하는데 실패했습니다.").c_str());
	}
	//makepair와 value_type의 차이 make_pair는 함수로 한번 객체를 만들어줘서 약간 미세하게 느리다 별차이없다.
	//AllRes.insert(std::map<std::string, GameEngineImage*>::value_type(_Name, NewImage));
	AllRes.insert(std::make_pair(_Name, NewImage));
	return NewImage;
}

GameEngineImage* GameEngineImageManager::Create(const std::string& _Name, HDC _DC)
{
	//맵을 사용해서 이미지를 관리했으므로 같은 이름의 이미지가 존재할수없다.
	//이미지 로드를 안한 이미지를 사용하려고 하면 터뜨려야한다.
	if (AllRes.end() != AllRes.find(_Name))
	{
		MsgBoxAssert("이미 존재하는 이름의 이미지를를 또 만들려고 했습니다.");
		return nullptr;
	}
	GameEngineImage* NewImage = new GameEngineImage();
	NewImage->SetName(_Name);

	//매니저는 이미지를 만드는게 아니라 만들라고 시키는거

	if (false == NewImage->Create(_DC))
	{
		delete NewImage;
		MsgBoxAssert((_Name + "이미지를 생성하는데 실패했습니다.").c_str());
	}
	//makepair와 value_type의 차이 make_pair는 함수로 한번 객체를 만들어줘서 약간 미세하게 느리다 별차이없다.
	//AllRes.insert(std::map<std::string, GameEngineImage*>::value_type(_Name, NewImage));
	AllRes.insert(std::make_pair(_Name, NewImage));
	return NewImage;
	return nullptr;
}
