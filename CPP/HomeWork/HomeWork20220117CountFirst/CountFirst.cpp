#include <iostream>

int FindLen(const char* _Text)
{
	int Len = 0;
	while ('\0' != _Text[Len])
	{
		Len += 1;
	}
	//�ؽ�Ʈ�� ��('\0')�� ���� ��ȯ
	return Len;
}

//��ü �ؽ�Ʈ,���� ��ġ,ã�� �ؽ�Ʈ
int CountFirst(const char* _Text, int _Start, const char* _FindStr)
{
	//��ü �ؽ�Ʈ ����
	//"aaa eee ttt asdfasd" 
	//[a][a][a][''][e][e][e][' '][t][t][t][' '][a][s][d][f][a][s][d]//[\0]
	//19
	int Text_Len = FindLen(_Text);
	//ã�� �ؽ�Ʈ ����
	//eee
	//[e][e][e] 3
	int Search_Text_Len = FindLen(_FindStr);
	//19-3 16 15+1
	int Count = Text_Len - Search_Text_Len + 1;

	for (int i = _Start; i < Count; i += 1)
	{
		int count = 0;
		for (int j = 0; j < Search_Text_Len; j += 1)
		{
			if (_Text[i + j] == _FindStr[j])
			{
				count += 1;
			}
		}
		if (count == Search_Text_Len)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	//���ڼ���
	//const char* _FindStr ã��

	int Count = CountFirst("fghjhgjfgjaaaa bbb ccccaaaafghshhs", 0, "aaaa");
	//int Count = CountFirst("aaa bbb cc dfasd eee ttt asdfasd", 50, "eee");
}