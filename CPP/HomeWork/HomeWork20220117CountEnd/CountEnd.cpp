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
//��ü �ؽ�Ʈ,���� ��ġ,ã�� �ؽ�Ʈ
int CountEnd(const char* _Text, int _End, const char* _FindStr)
{
	//�ִ���� �ѱ�� ����ó�� 
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