#pragma once
#include "GameEngineImage.h" //������ �̳༮�� �Ⱦ����� ���
#include <GameEngineBase/GameEngineMath.h>
#include <map>
#include <string>
// ���� :
// �⺻������ ���ҽ��� �׳� ������ ������ �̸��� �ִٰ� �����ϰ� ���̴ϴ�.
// ������𼭳� ���ӿ��� �̹����Ŵ����� ���� �ȴ�
class GameEngineImageManager
{
private:
	static GameEngineImageManager* Inst_;
public:
	static GameEngineImageManager* GetInst()
	{
		return Inst_;
	}
	static void Destroy()
	{
		if (nullptr == Inst_)
		{
			return;
		}
		delete Inst_;
		Inst_ = nullptr;
	}
public:

	// constrcuter destructer
	GameEngineImageManager();
	~GameEngineImageManager();

	// delete Function
	GameEngineImageManager(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager(GameEngineImageManager&& _Other) noexcept = delete;
	GameEngineImageManager& operator=(const GameEngineImageManager& _Other) = delete;
	GameEngineImageManager& operator=(GameEngineImageManager&& _Other) noexcept = delete;

	//�� �̹����� �����. ex)1280 ,280�� �̹����� �������=> 2�����迭
	GameEngineImage* Create(const std::string& _Name, float4 _Scale);
	GameEngineImage* Create(const std::string& _Name, HDC _DC);
protected:

private:
	//���� �� ���� ���� �̸��� �̹����� �ΰ� �����Ҽ�����.
	std::map<std::string, GameEngineImage*>AllRes;
};

