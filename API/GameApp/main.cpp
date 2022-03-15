#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

void GameLoop()
{
    // 이안에서 이제 게임을 만들건
    // 메신저를 만든걸
    // 뭘 만들건 사용자의 몫
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);
    int a = 0;
}
int __stdcall WinMain(_In_ HINSTANCE hInstance,//실행 된 프로세스의 시작주소
    _In_opt_ HINSTANCE hPrevInstance,//다른 프로그램으로 혹은 내 프로그램이 다른 프로그램을 실행시키면서 이전에 있었던 이전에 실행된 프로세스의 시작주소
    _In_ char*    lpCmdLine,//메인 파라미터
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeakCheckOn();
    GameEngineWindow::GetInst().CreateGameWindow(hInstance,"PoketMonster");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameLoop);
    GameEngineWindow::GetInst().Destroy();
}