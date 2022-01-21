

#include <iostream>

//바이트 패딩 Byte padding
//블로그 검색
//클래스내 가장 큰 바이트 수로 
//2 4 8
class Test1
{
    char v1;
    int V2;
    char V3;
    char V4;
    __int64 V5;
    char V6;
};

class Test2
{
    char v1;
    int V2;
    char V3;
    char V4;
    __int64 V5;
    char V6;
};

class Player
{
public:
    //기준 8
    //
    //[Hp1][][][] [Att][Att][Att][Att] 8
    //[Att2][Att2][Att2][Att2][Att2][Att2][Att2][Att2]  8
    //[Att][Att][Att][Att] [][][][][][][][] 1
    
    char Hp1;
    int Att;// 8 바이트
    __int64 Att1;// 8 바이트
    char Hp;// 8 바이트
    __int64 Hp2;
};
int main()
{
    int Value = int();
    Player NewPlayer = Player();
    //913382438924
    __int64 test1= (__int64)& NewPlayer.Hp1;
    __int64 test2=(__int64)&NewPlayer.Att;
    __int64 test3=(__int64)&NewPlayer.Att1;
    __int64 test4 = (__int64)&NewPlayer.Hp;
    __int64 test5 = (__int64)&NewPlayer.Hp2;
    int size=sizeof(NewPlayer);
    //(__int64)&NewPlayer.Hp;
    //int PlayerSize = sizeof(NewPlayer);
  
}


