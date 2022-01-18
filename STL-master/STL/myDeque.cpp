#include <iostream>
#include <string>
#include <deque>
#include "myDeque.h"

/*
	//�ص㣺֧��������ʣ��������ڲ����в����ɾ�������������˲���ɾ��������ã�
	��1��������
	��2��ͨ�ò�����push_back(), pop_back(), insert(), erase(), clear(), swap(), empty(), back(), front(), at(), []
	��3�����в�����push_front(), pop_front()
*/
void myDequeTest()
{
	std::cout << "---------------------------this is class deque demo--------------------------" << std::endl;
	std::deque<int >myDeque = { 3, 5, 7 };
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';

	myDeque.push_back(9);                                                   //�ڶ���β�����Ԫ��
	myDeque.push_front(1);                                                  //�ڶ���ͷ�����Ԫ��
	std::cout << "after pushing, myDeque is: \n";
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';

	/*
	insert()�汾��
	��1��insert(p, t)     //�ڵ�����p֮ǰ����һ��ֵΪt������ָ������ӵ�Ԫ�صĵ�����
	��2��insert(p, b, e)  //��������[b, e��ָ����Ԫ�ز��뵽p��ָλ�ã����ص�һ������Ԫ�صĵ�����
	//���ڵ�����ȷ����Χ��������ҿ���������
	*/
	auto ret = myDeque.insert(myDeque.begin() + 1, 2);
	std::cout << "after inserting, myDeque is: \n";
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';
	std::cout << "���ص���ָ���Ԫ��Ϊ��";
	std::cout << *ret << std::endl;

	auto ret1 = myDeque.erase(ret);
	std::cout << "after earsing, myDeque is: \n";
	for (auto tmp : myDeque)
	{
		std::cout << tmp << std::ends;
	}
	std::cout << '\n';
	std::cout << "���ص���ָ���Ԫ��Ϊ��";
	std::cout << *ret1 << std::endl;





	
}