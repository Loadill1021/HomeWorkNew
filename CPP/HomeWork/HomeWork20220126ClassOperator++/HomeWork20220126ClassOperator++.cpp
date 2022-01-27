#include <iostream>
class MyInt
{
private:
	int Value;
public:
	MyInt();
	MyInt(int _Value);
public:
	MyInt operator--(int);
};
MyInt::MyInt()
	:Value(0)
{

}
MyInt::MyInt(int _Value)
	:Value(_Value)
{

}
MyInt MyInt::operator--(int )
{
	//현재 내 값의 복사본을 생성
	MyInt temp = *this;
	//현재 내 값을 감소
	this->Value -= 1;
	//감소 시키전 내 값을 반환
	return temp;
}
int main()
{
	int a = 0;
	int b=a--;
	MyInt myInt = MyInt();
	MyInt myInt2 = myInt--;

	
	
	
	
	
	
	int test = 0;
	test = (++test) + (++test) + (++test)+(++test);
	int test2 = test;
}