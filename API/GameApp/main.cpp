#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>

void GameLoop()
{
    // �̾ȿ��� ���� ������ �����
    // �޽����� �����
    // �� ����� ������� ��
    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);
    int a = 0;
}
int __stdcall WinMain(_In_ HINSTANCE hInstance,//���� �� ���μ����� �����ּ�
    _In_opt_ HINSTANCE hPrevInstance,//�ٸ� ���α׷����� Ȥ�� �� ���α׷��� �ٸ� ���α׷��� �����Ű�鼭 ������ �־��� ������ ����� ���μ����� �����ּ�
    _In_ char*    lpCmdLine,//���� �Ķ����
    _In_ int       nCmdShow)
{
    GameEngineDebug::LeakCheckOn();
    GameEngineWindow::GetInst().CreateGameWindow(hInstance,"PoketMonster");
    GameEngineWindow::GetInst().ShowGameWindow();
    GameEngineWindow::GetInst().MessageLoop(GameLoop);
    GameEngineWindow::GetInst().Destroy();
}