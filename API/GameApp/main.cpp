#include <Windows.h>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineBase/GameEngineWindow.h>
#include <GameEngineContents/PoketMonster.h>
//���� ���̴� ����
//�׳� �������� ���
//PoketMonster MyGame;
//void GameInit()
//{
//    //  �ؽ�ó�� �ε��ϰ� �غ��ϰ�
//    //  ������Ʈ�� �̸� ��������
//    //MyGame.GameInit();
//}
//void GameLoop()
//{
//   // MyGame.GameLoop();
//    // ������ ����ȴ�.
//    Rectangle(GameEngineWindow::GETDC(), 100, 100, 200, 200);
//    int a = 0;
//}
int __stdcall WinMain(_In_ HINSTANCE hInstance,//���� �� ���μ����� �����ּ�
    _In_opt_ HINSTANCE hPrevInstance,//�ٸ� ���α׷����� Ȥ�� �� ���α׷��� �ٸ� ���α׷��� �����Ű�鼭 ������ �־��� ������ ����� ���μ����� �����ּ�
    _In_ char*    lpCmdLine,//���� �Ķ����
    _In_ int       nCmdShow)
{
    //���� �ڵ尡 �ƴϴ� �����츦 ���� �ڵ忡�� ���� ����� �ʴ´�.
   /* GameEngineDebug::LeakCheckOn();
    
    GameEngineWindow::GetInst().Destroy();
    MyGame.GameEnd();*/ 
    //�Լ������͸� �˷��ֽð� �����Լ��� �˷��̴ּ�.
    //�����Լ���=�Լ������͹迭
    GameEngine::Start<PoketMonster>();
}