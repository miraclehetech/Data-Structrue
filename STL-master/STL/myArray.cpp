#include <iostream>
#include <string>
#include <array>
#include "myArray.h"
/*
	��1�����죺std::array<int, 5> myArr = {2, 4, 6};
	��2��ͨ�ò�����size(), maxsize(), empty(), operator[](), at(), front(), back(), swap(),  
	��3�����в�����data(), fill()
*/
void myArrayTest()
{
	std::cout << "---------------------------this is class array demo--------------------------" << std::endl;
	std::array<int, 10 >myArray = { 3, 5 };
	for (auto tmp : myArray)
	{
		std::cout << tmp << std::ends;

	}
	std::cout << '\n';
	//ûɶ�ý�����һ�ڣ�

	auto p = myArray.data();                    //���������һ��Ԫ�ص�ָ��
	std::cout << *p << std::endl;

}