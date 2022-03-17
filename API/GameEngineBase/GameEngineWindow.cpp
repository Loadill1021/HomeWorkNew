#include "GameEngineWindow.h"
#include "GameEngineDebug.h"
GameEngineWindow* GameEngineWindow::Inst_=new GameEngineWindow;
LRESULT CALLBACK MessageProcess(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_DESTROY:
        // �����츦 �����ϰ� ��� 
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: ���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    default:
        break;
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}
GameEngineWindow::GameEngineWindow() 
    :WindowOn_(true)
    ,hInst_(nullptr)
    ,hWnd_(nullptr)
    ,HDC_(nullptr)
{
}

GameEngineWindow::~GameEngineWindow() 
{
}
void GameEngineWindow::Off()
{
    WindowOn_ = false;
}
void GameEngineWindow::RegClass(HINSTANCE _hInst)
{
	//������ Ŭ���� ���
    WNDCLASSEXA wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = MessageProcess;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
    wcex.lpszMenuName = nullptr;
    wcex.lpszClassName = "GameEngineWindowClass";
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
    RegClass(_hInst);
    hWnd_ = CreateWindowExA(0L, "GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInst_, nullptr);
    HDC_ = GetDC(hWnd_);
    if (!hWnd_)
    {
        return;
    }
}
void GameEngineWindow::ShowGameWindow()
{
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("���� �����찡 ��������� �ʾҽ��ϴ�.ȭ�鿡 ��� �� �� �����ϴ�.");
    }
    //�̰� ȣ��Ǳ� �������� �׸����� ����.
    ShowWindow(hWnd_, SW_SHOW);
    UpdateWindow(hWnd_);
}
void GameEngineWindow::MessageLoop(void(*_InitFunction)(), void(*_LoopFunction)())
{
    if (nullptr != _InitFunction)
    {
        _InitFunction();
    }
    MSG msg;
    while (WindowOn_)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        //���� ������ ���ٸ� �ٽ� ����
        if (nullptr == _LoopFunction)
        {
            continue;
        }
        _LoopFunction();
    }
}