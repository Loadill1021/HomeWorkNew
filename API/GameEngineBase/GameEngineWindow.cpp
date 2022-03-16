#include "GameEngineWindow.h"
#include "GameEngineDebug.h"
#include <assert.h>
//HWND hWnd, 어떤 윈도우에 무슨일이 생겼는지 그 윈도우의 핸들 
//UINT message, 그 메세지의 종류가 뭔지
//WPARAM wParam, 
//LPARAM lParam
//실행은 마소가 알아서 해준다.

float XMOVE=0.00000001f;
GameEngineWindow* GameEngineWindow::Inst_=new GameEngineWindow();
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        //이건 실행하고
        //안실행할때도 있지만
        //내가 이메세
        //내가 할 다른일 했어
        // 나머지는 윈도우야 니가 원래 처리하던 방식대로 처리해
        return DefWindowProc(hWnd, message, wParam, lParam);
    case WM_DESTROY://윈도우창을 닫았을때
        GameEngineWindow::GetInst().Off();
        return DefWindowProc(hWnd, message, wParam, lParam);

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //TODO:여기에 hdc를 사용하는 그리기 코드를 추가합니다...
        EndPaint(hWnd, &ps);
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    
    default:
        break;
    }
    return DefWindowProc(hWnd, message, wParam, lParam);
}
GameEngineWindow::GameEngineWindow()
    :hInst_(nullptr)
    , hWnd_(nullptr)
    , WindowOn_(true)
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

    wcex.cbSize = sizeof(WNDCLASSEX);


    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    //typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = _hInst;//핸들
    wcex.hIcon = nullptr;//아이콘
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);//커서
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);//배경색
    wcex.lpszMenuName = nullptr;//메뉴 사용안하면 알아서 윈도우가 기본값으로 넣어준다.
    wcex.lpszClassName = "GameEngineWindowClass";//클래스이름
    wcex.hIconSm = nullptr;//아이콘

    RegisterClassExA(&wcex);
}
void GameEngineWindow::CreateGameWindow(HINSTANCE _hInst, const std::string _Title)
{
    if (nullptr != hInst_)
    {
        MsgBoxAssert("윈도우를 2번 띄우려고 했습니다.");
        return;
    }
    //클래스 등록은 1번만 하려고 친 코드
    Title_ = _Title;
    hInst_ = _hInst;
    RegClass(hInst_);
    //클래스로 객체를 만드는 것
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
    //보이는 모든 행위
    if (nullptr == hWnd_)
    {
        MsgBoxAssert("메인 윈도우가 만들어지지 않았습니다.화면에 출력 할수없습니다.");
        return;
    }
    //이게 호출 되기전까지는 그릴수가 없다.
    ShowWindow(hWnd_, SW_SHOW);
    //싹 한번 다시 그려줘
    UpdateWindow(hWnd_);
    //Rectangle(HDC_, 100, 100, 200, 200);
}

//메세지를 기다리면서 윈도우를 유지
void GameEngineWindow::MessageLoop(void(*_InitFunction)(),void(*_LoopFunction)())
{
    //  윈도우는 다 준비되었다.
    //  루프를 돌기전에 
    //  뭔가 준비할게 있다면 준비함수를 실행해라
    if (nullptr != _InitFunction)
    {
        _InitFunction();
    }
    MSG msg;

    if (nullptr == _LoopFunction)
    {
        MsgBoxAssert("게임이 아직 만들어지지않았습니다.");
        return;
    }

    //윈도우 내부에는 보이지 않지만
    //std::list<MSG>MessageQueue;
    while (WindowOn_)
    {
        //윈도우 메세지 처리
        if (PeekMessage(&msg, nullptr, 0,0,PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        //여기서 무슨 게임을 돌릴까요?
        //나머지 우리 게임이 돌아간다.
        if (nullptr == _LoopFunction)
        {
            continue;
        }
        _LoopFunction();
    }

    /*while (GetMessage(&msg, nullptr, 0, 0))
    {
            
    }*/
}
void GameEngineWindow::SetWindowScaleAndPosition(float4 _Pos, float4 _Scale)
{
    //800 600을 하면 메뉴바를 추가해서 잡아준다.회색창이 800 600이 되는게 아님
    //원점부터 
    //왼쪽 위점 아래쪽 위점을 담는 구조체
    //Rect
    RECT Rc = { _Pos.ix(),_Pos.iy(),_Pos.ix()+_Scale.ix(),_Pos.iy()+_Scale.iy()};
    //메뉴바 고려해서 그에 알맞은 크기를 뱉어준다.
    AdjustWindowRect(&Rc, WS_OVERLAPPEDWINDOW, FALSE);
    Rc.left;//-8
    Rc.top;//-31
    Rc.right;//1288
    Rc.bottom;//728
    Scale_ = _Scale;
    //x,y x,y
    //SWP_NOZORDER 크기가 변경되었을때 앞뒤로 가지않는다? 0을 넣어줘도 된다.
    SetWindowPos(hWnd_, nullptr,Rc.left,Rc.top,Rc.left+Rc.right ,Rc.top+Rc.bottom , SWP_NOZORDER);
}