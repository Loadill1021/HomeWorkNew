#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
//exe∆ƒ¿œ
int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineWindow::GetInst().CreateGameWindow(hInstance,"GameWindow");
    GameEngineDebug::LeakCheckOn();
    GameEngineWindow::GetInst().ShowGameWindow();
    while (true)
    {

    }
    //GameEngineWindow::GetInst().Loop();
    GameEngineWindow::Destroy();
}