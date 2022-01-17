#include <iostream>
int ToInt(const char* _Left)
{
    int Value = 0;
    int len = 0;
    while ('\0' != _Left[len])
    {
        len += 1;
    }

    //"12" (10*1)+(10*0*1)
    //_Left[1]=='2'

    for (int i = 0; i < len; i += 1)
    {
        //자릿수
        int digit = 1;
        for (int j = i; j < len - 1; j += 1)
        {
            digit *= 10;
        }
        Value += ((_Left[i] - 48) * digit);
    }
    return Value;
}
int main()
{
    int Value = ToInt("012345");
    Value = ToInt("567890");
    char test = '0';
    test -= 48;
    test;
}