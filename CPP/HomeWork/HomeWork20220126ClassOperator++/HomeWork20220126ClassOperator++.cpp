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
	return MyInt(this->Value -1);
}
int main()
{
	int a = 0;
	int b=a--;
	MyInt myInt = MyInt();
	MyInt myInt2=myInt--;
	
	
	
	
	
	
	int test = 0;
	test = (++test) + (++test) + (++test)+(++test);
	int test2 = test;
}