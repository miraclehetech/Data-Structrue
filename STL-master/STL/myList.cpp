#include <iostream>
#include <list>
#include <string>
#include "myList.h"

/*
	(1)���죺
	(2)ͨ�ú�����push_back(), pop_back(), empty(), clear(), swap(), insert(), erase(), reverse()
	(3)���в�����push_front(), pop_front(), merge(), remove(), remove_if()
*/

bool  is_odd(const int x)      //�䵱һԪν��
{
	return (x % 2 == 1);
}
void myListTest()
{
	std::cout << "-----------------------------this is class List demo--------------------------" << std::endl;
	std::list<int >myList{ 3, 5 };
	myList.push_back(7);
	myList.push_front(1);                       //˫������֧�������˵Ŀ��ٲ����ɾ��
	std::cout << "after push, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

											   //���������������һ�����ڴ˲���׸��
	auto ret = myList.insert(myList.end(), 9);  
	std::cout << "after inserting, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

	std::list<int >myList1 = { 2, 4, 6, 8 };
	myList.merge(myList1);                        //�ϲ�������������,��Ԫ�����ظ������غϲ��������������������һ�ͻ����
	std::cout << "after merging, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

	myList.remove(8);                             //ɾ�������������8��Ԫ��
	std::cout << "after removing, myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

	                                               //remove_if()  //����������ʱ��ɾ��
	myList.remove_if(is_odd);
	std::cout << "after remove_if(is_odd), myList is : " << std::endl;
	for (auto tmp : myList)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';
}
