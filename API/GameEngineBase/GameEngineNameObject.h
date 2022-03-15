#pragma once
#include <string>
// ���� :
// �̸��� �������ϴ� Ŭ����
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
	//const �������� �������� �ʰڴ�
	//���ڰ����� �ѱ涧 ���縦 �����ʰڴ�.
	inline void SetName(const std::string& _Name)
	{
		Name_ = _Name;
	}
	// �� �Ⱦ��ϴ� ������� �ֽ��ϴ�.
	// �ʿ��Ҷ� ��߰���.
	std::string GetNameCopy()
	{
		//���ϵǸ� string�� �ΰ� ���ܼ�
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

