#pragma once
#include <string>
// 설명 :
// 이름을 가지게하는 클래스
class GameEngineNameObject
{
public:
	// constrcuter destructer
	GameEngineNameObject();
	virtual ~GameEngineNameObject();

	// delete Function
	GameEngineNameObject(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject(GameEngineNameObject&& _Other) noexcept = delete;
	GameEngineNameObject& operator=(const GameEngineNameObject& _Other) = delete;
	GameEngineNameObject& operator=(GameEngineNameObject&& _Other) noexcept = delete;

protected:
	//const 원본값을 변경하지 않겠다
	//인자값으로 넘길때 복사를 하지않겠다.
	inline void SetName(const std::string& _Name)
	{
		Name_ = _Name;
	}
	// 어마어마 싫어하는 사람들이 있습니다.
	// 필요할때 써야겠죠.
	std::string GetNameCopy()
	{
		//리턴되면 string이 두개 생겨서
		return Name_;
	}
	const std::string& GetNameConstRef()
	{
		return Name_;
	}
	const char* GetNameConstPtr()
	{
		return Name_.c_str();
	}

private:
	std::string Name_;
};

