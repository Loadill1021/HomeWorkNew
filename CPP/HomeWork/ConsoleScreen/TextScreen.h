#pragma once
#include "ConsoleMath.h"//���� ���䳢�� ���� ����?������ ��Ŭ��� �� �� �ִ�.
// ���� : �ܼ�â�� ����ִ� ��Ȱ
#include <assert.h>//assert�Լ��� ��� �ִ� ��� ��Ŭ���
class TextScreen
{
public:
	// constrcuter destructer
	TextScreen();
	~TextScreen();

	// delete Function
	TextScreen(const TextScreen& _Other) = delete;
	TextScreen(TextScreen&& _Other) noexcept = delete;
	TextScreen& operator=(const TextScreen& _Other) = delete;
	TextScreen& operator=(TextScreen&& _Other) noexcept = delete;

	ConsoleVector GetSize()
	{
		return Size_;
	}

	//ȭ���� ���ڸ� �������� �Ҵ��Ͽ� �޸𸮸� ������ �۾�
	void CreateScreen(int _Width, int _Height, const char* _DefaultValue);

	//DefaultPixel�� ���ڿ� ���� 2����Ʈ�� ȭ���� ���� �ʱ�ȭ �Ѵ�.
	void SettingScreen();

	//PixelData_�� ������ ��� ȭ�鿡 ����Ѵ�.
	void PrintScreen();

	//X Y��ġ�� ���ڸ� ����Ѵ�.
	//�÷��̾ ���͸� ����ϱ� ���ؼ�
	void SetPixel(ConsoleVector _Pos, const char* _DefaultValue);
	void SetPixel(int _x, int _y, const char* _DefaultValue);
protected:

private:
	//int Width_;//���� �ʺ�
	//int Height_;//���� ����
	ConsoleVector Size_;//�� ��ü
	char** PixelData_;
	char DefaultPixel_[3];//� ���·� �׷�����
};

