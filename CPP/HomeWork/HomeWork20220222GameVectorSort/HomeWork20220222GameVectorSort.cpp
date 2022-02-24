#include <iostream>
#include "GameVector.h"
int main()
{
	GameVectorSort<int>MyVector = GameVectorSort<int>();
	MyVector.push_back(5);
	MyVector.push_back(10);
	MyVector.push_back(5);
	MyVector.push_back(1);
	//MyVector.push_back(2);
	//MyVector.push_back(8);
	//MyVector.push_back(99);
	//MyVector.push_back(0);
	//MyVector.push_back(1);
	//MyVector.push_back(3);*/

	for (int i = 0; i < MyVector.size(); ++i)
	{
		std::cout << MyVector[i] << std::endl;
	}
	return 0;
}