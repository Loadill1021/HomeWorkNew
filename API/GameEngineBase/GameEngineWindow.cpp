#include "GameEngineWindow.h"
#include "GameEngineDebug.h"
#include <assert.h>
//HWND hWnd, � �����쿡 �������� ������� �� �������� �ڵ� 
//UINT message, �� �޼����� ������ ����
//WPARAM wParam, 
//LPARAM lParam
//������ ���Ұ� �˾Ƽ� ���ش�.

float XMOVE=0.00000001f;
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        //�̰� �����ϰ�
        //�Ƚ����Ҷ��� ������
        //���� �̸޼�
        //���� �� �ٸ��� �߾�
        // �������� ������� �ϰ� ���� ó���ϴ� ��Ĵ�� ó����
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_DESTROY://������â�� �ݾ�����
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //TODO:���⿡ hdc�� ����ϴ� �׸��� �ڵ带 �߰��մϴ�...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    
    default:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
GameEngineWindow* GameEngineWindow::Inst_=new GameEngineWindow();
GameEngineWindow::GameEngineWindow()
    :hInst_(nullptr)
    , hWnd_(nullptr)
    , WindowOn_(true)
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

    wcex.cbSize = sizeof(WNDCLASSEX);


    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    //typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;//�ڵ�
    wcex.hIcon = nullptr;//������
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);//Ŀ��
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);//����
    wcex.lpszMenuName = nullptr;//�޴� �����ϸ� �˾Ƽ� �����찡 �⺻������ �־��ش�.
    wcex.lpszClassName = "GameEngineWindowClass";//Ŭ�����̸�
    wcex.hIconSm = nullptr;//������

    RegisterClassExA(&wcex);
}
void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string _Title)
{
    if (nullptr != hInst_)
    {
        MsgBoxAssert("�����츦 2�� ������ �߽��ϴ�.");
        return;
    }
    //Ŭ���� ����� 1���� �Ϸ��� ģ �ڵ�
    Title_ = _Title;
    hInst_ = _hInst;
    RegClass(hInst_);
    //Ŭ������ ��ü�� ����� ��
    hWnd_ = CreateWindowExA(0L,"GameEngineWindowClass", Title_.c_str(), WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, _hInst, nullptr);
    //200, 300, 500, 700, nullptr, nullptr, hInstance, nullptr);

    HDC_ = GetDC(hWnd_);
   
    if (!hWnd_)
    {
        return;
    }
}

void GameEngineWindow::ShowGameWindow()
{
    //���̴� ��� ����
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("���� �����찡 ��������� �ʾҽ��ϴ�.ȭ�鿡 ��� �Ҽ������ϴ�.");
        return;
    }
    //�̰� ȣ�� �Ǳ��������� �׸����� ����.
    ShowWindow(hWnd_, SW_SHOW);
    //�� �ѹ� �ٽ� �׷���
    UpdateWindow(hWnd_);
    //Rectangle(HDC_, 100, 100, 200, 200);
}

//�޼����� ��ٸ��鼭 �����츦 ����
void GameEngineWindow::MessageLoop(void(*_LoopFunction)())
{
    MSG msg;

    if (nullptr == _LoopFunction)
    {
        return;
    }

    //������ ���ο��� ������ ������
    //std::list<MSG>MessageQueue;
    while (WindowOn_)
    {
        //������ �޼��� ó��
        if (PeekMessage(&msg, nullptr, 0,0,PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        //���⼭ ���� ������ �������?
        //������ �츮 ������ ���ư���.
        _LoopFunction();
    }

    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
            
    }*/
}