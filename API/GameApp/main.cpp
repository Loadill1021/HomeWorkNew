#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/PoketMonster.h>
PoketMonster poketmonster;
void MyGameInit()
{
    poketmonster.GameInit();
}
void MyGameLoop()
{
    poketmonster.GameLoop();
}
int __stdcall WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ char* lpCmdLine,
    _In_ int       nCmdShow)
{
    
    GameEngineWindow::GetInst().CreateGameWindow(hInstance,"PoketMonster");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(MyGameInit,MyGameLoop);
    GameEngineWindow::GetInst().Destroy();
    
    //GameEngine::Start();
}