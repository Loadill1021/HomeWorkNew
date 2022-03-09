#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
//exe∆ƒ¿œ
void GameLoop()
{
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);
}
int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    GameEngineWindow::GetInst().CreateGameWindow(hInstance,"GameWindow");
    GameEngineDebug::LeakCheckOn();
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameLoop);
    GameEngineWindow::Destroy();
    GameEngineDebug::LeakCheckOn();
}