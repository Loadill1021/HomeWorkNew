#include "Head.h"
#include <conio.h>
#include "Body.h"
Head::Head() 
{
}

Head::~Head() 
{
	if (0 != AllBody.size())
	{
		size_t Size = AllBody.size();
		for (size_t i = 0; i < Size; ++i)
		{ 
			if (nullptr != AllBody.back())
			{
				delete AllBody.back();
				AllBody.pop_back();
			}
		}
	}
}


void Head::Update() 
{

	int Value = _getch();

	switch (Value)
	{
	case 'a':
	case 'A':
		// 화면바깥으로 이동하면 이동이 안되게 해주세요.
		InScreenMovement({ -1, 0 });
		break;
	case 'd':
	case 'D':
		InScreenMovement({ 1, 0 });
		break;
	case 'w':
	case 'W':
		InScreenMovement({ 0, -1 });
		break;
	case 's':
	case 'S':
		InScreenMovement({ 0, 1 });
		break;
	case 'q':
	case 'Q':
		// 무슨일인가가 벌어져서
		// 게임이 종료된다.
		Death();
		return;
	default:
		break;
	}

	return;
}



void Head::OverLap(ConsoleObject* _Link)
{
	AllBody.push_back((Body*)_Link);
}