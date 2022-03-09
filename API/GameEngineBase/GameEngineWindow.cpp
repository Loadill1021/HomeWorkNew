#include "GameEngineWindow.h"
#include "./GameEngineDebug.h"
//HWND hWnd: 어떤 윈도우의 무슨일이 생겼는지 그 윈도우의 핸들 
//UINT message: 그 메세지의 종류가 무엇인지
//WPARAM wParam: 
//LPARAM lParam:
float XMOVE = 0.000000000001f;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	//case WM_CREATE:
		//DefWindowProc=>message에 대해서 윈도우가 기본적으로 처리하는 방식의 함수
		//return DefWindowProc(hWnd, message, wParam, lParam);
	//case WM_SETFOCUS:
		//return DefWindowProc(hWnd, message, wParam, lParam);
	case WM_DESTROY:
		//윈도우를 종료하고 모든 
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
	//내가 만들어준게 아니라면 다 지워줘야 합니다.
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
		MsgBoxAssert("윈도우를 2번 띄우려고 했습니다.");
		return;
	}
	Title_ = _Title;
	hInst_ = _hInst;
	RegClass(hInst_);
	hWnd_ = CreateWindowExA(0L,"GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst_, nullptr);
	//화면에 무언가를 그리기 위한 핸들
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
		MsgBoxAssert("메인 윈도우가 만들어지지 않았습니다 화면에 출력할수 없습니다.");
		return;
	}
	ShowWindow(hWnd_, SW_SHOW);
	UpdateWindow(hWnd_);
}

//윈도우는 우리가 무슨 게임을 돌릴지 알지 못한다.
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
		//여기서 무슨게임을 돌릴까요?
		if (nullptr == _LoopFunction)
		{
			continue;
		}
		_LoopFunction();
	}
}

