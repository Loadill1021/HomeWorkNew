#include <iostream>

int FindLen(const char* _Text)
{
	int Len = 0;
	while (0 != _Text[Len])
	{
		Len += 1;
	}
	return Len;
}
//전체 텍스트,시작 위치,찾을 텍스트
int CountEnd(const char* _Text, int _End, const char* _FindStr)
{
	//최대길이 넘길시 예외처리 
	int len = FindLen(_Text)-1;
	if (_End > len)
	{
		_End = len;
	}


	int Search_Text_Len = FindLen(_FindStr);
	for (int i = _End; i >= 0; i -= 1)
	{
		int flag = 0;
		for (int j = 0; j < Search_Text_Len; j += 1)
		{
			if (_Text[i + j] != _FindStr[j])
			{
				flag = 1;
			}
		}
		if (0 == flag)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int Count = CountEnd("aaa ttt eee asdfasd", 50, "asdfasd");
}