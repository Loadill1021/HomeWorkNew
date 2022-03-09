#include "GameEngineWindow.h"
#include "./GameEngineDebug.h"
//HWND hWnd: � �������� �������� ������� �� �������� �ڵ� 
//UINT message: �� �޼����� ������ ��������
//WPARAM wParam: 
//LPARAM lParam:
float XMOVE = 0.000000000001f;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	//case WM_CREATE:
		//DefWindowProc=>message�� ���ؼ� �����찡 �⺻������ ó���ϴ� ����� �Լ�
		//return DefWindowProc(hWnd, message, wParam, lParam);
	//case WM_SETFOCUS:
		//return DefWindowProc(hWnd, message, wParam, lParam);
	case WM_DESTROY:
		//�����츦 �����ϰ� ��� 
		GameEngineWindow::GetInst().Off();
		return DefWindowProc(hWnd, message, wParam, lParam);
	/*case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		Rectangle(hdc, 100, 100, 200, 200);
		EndPaint(hWnd, &ps);
		return DefWindowProc(hWnd, message, wParam, lParam);
	}*/
	case WM_MOUSEMOVE:
	{	
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}

GameEngineWindow* GameEngineWindow::Inst_ = new GameEngineWindow();
GameEngineWindow::GameEngineWindow()
	: hInst_(nullptr)
	,hWnd_(nullptr)
	,WindowOn_(true)
	,HDC_(nullptr)
{
}

GameEngineWindow::~GameEngineWindow()
{
	//���� ������ذ� �ƴ϶�� �� ������� �մϴ�.
	if (nullptr != HDC_)
	{
		ReleaseDC(hWnd_, HDC_);
		HDC_ = nullptr;
	}
	if (nullptr != hWnd_)
	{
		DestroyWindow(hWnd_);
		hWnd_ = nullptr;
	}
}
void GameEngineWindow::Off()
{
	WindowOn_ = false;
}
void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
	WNDCLASSEXA wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = _hInst;
	wcex.hIcon = nullptr;
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName ="GameEngineWindowClass";
	wcex.hIconSm = nullptr;

	RegisterClassExA(&wcex);
}
void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string& _Title)
{
	if (nullptr != hInst_)
	{
		MsgBoxAssert("�����츦 2�� ������ �߽��ϴ�.");
		return;
	}
	Title_ = _Title;
	hInst_ = _hInst;
	RegClass(hInst_);
	hWnd_ = CreateWindowExA(0L,"GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst_, nullptr);
	//ȭ�鿡 ���𰡸� �׸��� ���� �ڵ�
	HDC_ = GetDC(hWnd_);
	
	if (!hWnd_)
	{
		return;
	}
}

void GameEngineWindow::ShowGameWindow()
{
	if (!hWnd_)
	{
		MsgBoxAssert("���� �����찡 ��������� �ʾҽ��ϴ� ȭ�鿡 ����Ҽ� �����ϴ�.");
		return;
	}
	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
}

//������� �츮�� ���� ������ ������ ���� ���Ѵ�.
void GameEngineWindow::MessageLoop(void(*_LoopFunction)())
{
	MSG msg;

	while (WindowOn_)
	{
	
		if (PeekMessage(&msg, nullptr, 0,0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//���⼭ ���������� �������?
		if (nullptr == _LoopFunction)
		{
			continue;
		}
		_LoopFunction();
	}
}

