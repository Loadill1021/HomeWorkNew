#include <iostream>
//오늘의 숙제
//26숙제

class MyInt
{
private:
	int Value;
public:
	MyInt();
	MyInt(int _Value);
public:
	MyInt& operator++();
	MyInt& operator+=(const MyInt& _Otehr);
	MyInt operator+(const MyInt& _Other);
	MyInt& operator--();
	MyInt operator-(const MyInt& _Other);
	MyInt& operator-=(const MyInt& _Ohter);
	//MyInt operator()(int value);
};
MyInt::MyInt()
	:Value(0)
{

}
MyInt::MyInt(int _Value)
	: Value(_Value)
{

}
MyInt& MyInt::operator++()
{
	this->Value += 1;
	return *this;
}
MyInt& MyInt::operator+=(const MyInt& _Other)
{
	this->Value += _Other.Value;
	return *this;
}
MyInt MyInt::operator+(const MyInt& _Other)
{
   	return MyInt(this->Value+_Other.Value);
}
MyInt& MyInt::operator--()
{
	this->Value -= 1;
	return *this;
}
MyInt MyInt::operator-(const MyInt& _Other)
{
	return MyInt(this->Value - _Other.Value);
}
MyInt& MyInt::operator-=(const MyInt& _Other)
{
	this->Value -= _Other.Value;
	return *this;
}
int main()
{
	//int
	//int Value = 0;
	//int Result = 0;

	
	//1)
	//++Value;
	////2)
	//Value=++Value;//1
	////3)
	//Result += Value;
	//MyInt
	//int Value = 0;
	//int Value2 = 1;
	//int Value3 = 3;
	//4?? why 연산자 우선순위때문에
	//Value = (++Value) + (++Value); //+ (++Value) + (++Value);

	MyInt NewInt = {10};
	MyInt NewInt2 = { 20 };
	MyInt NewInt3 = { 30 };
	//MyInt NewResult = {};
	//MyInt NewResult2 = {};
	// 
	//NewInt = (++NewInt) + (++NewInt) + (++NewInt) + (++NewInt);
	//(NewInt += NewInt(1)) += NewInt(20);
	//NewInt=NewInt.operator++();
	//NewResult2=NewResult += NewInt;
	//NewInt++;
	NewInt3=NewInt + NewInt2;
	
	NewInt = 5;
	//NewInt = NewInt.operator--();
	//-3 - -3 - -3 =-9
	//            2 - 2 -2 
	//NewInt=(--NewInt) -(--NewInt)-(--NewInt);
	//-2    -2 
	//NewInt -= NewInt;
	int a = 5;
	int b=0;
	//b += a;
	//a -= a;
	NewInt3+= NewInt;
	++NewInt3;
	//int test = 5;
	//4 4 4 3 3 3     2 -4
	//test = (--test) - (--test) - (--test);

	//NewInt--;

}

//++안쓰고


//++만들어오기
//--만들어오기
