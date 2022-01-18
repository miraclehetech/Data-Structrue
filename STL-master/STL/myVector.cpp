#include <iostream>
#include <string>
#include <vector>
#include "myVector.h"
#include "myVector.h"
/*
ʵ��string�����Ĳ�����
	��1�����졢��ֵ:
	��2������������size(), empty(),  push_back(), pop_back(), insert(), erase(), clear(), swap();
*/

void myVectorTest()
{
	std::cout << "-----------------------------this is class vector demo--------------------------" << std::endl;
	std::vector<int> myVec = { 1, 3, 5, 7, 9 };
	std::vector<int> myVec1 = { 4, 6, 8 };
	std::cout << "the length of myVec��" << myVec.size() << std::endl;
	myVec.push_back(0);                                                                 //��β������ַ�
	std::cout << "after pushing, myVec is: "  << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	/*
	insert()�汾��
		��1��insert(p, t)     //�ڵ�����p֮ǰ����һ��ֵΪt������ָ������ӵ�Ԫ�صĵ�����
		��2��insert(p, b, e)  //��������[b, e��ָ����Ԫ�ز��뵽p��ָλ�ã����ص�һ������Ԫ�صĵ�����
		��3��insert(p, il)    //���б��е�Ԫ�ز��룬���ص�һ������Ԫ�صĵ�����
		                      //���ڵ�����ȷ����Χ��������ҿ���������
	*/
	auto ret = myVec.insert(myVec.begin() + 1, 2);                                //���뵥��Ԫ�أ����ظ�Ԫ�ص�����
	std::cout << "after inserting , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "���صĵ�����ֵΪ��" << *ret << std::endl;

	auto ret1 = myVec.insert(myVec.begin() + 1, myVec1.begin(), myVec1.end());     //����ϵ��Ԫ�أ����ص�һ������Ԫ�ص�����
	std::cout << "after inserting , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "���صĵ�����ֵΪ��" << *ret1 << std::endl;
		/*
	insert()�汾��
		��1��erase(p)         //ɾ��������p��ָԪ�أ�������һ��Ԫ�صĵ�����
		��2��erase(b, e)      //ɾ��������[b, e) ��Χ�ڵ�Ԫ�أ�
		                      //���ڵ�����ȷ����Χ��������ҿ���������
	*/
	auto ret2 = myVec.erase(myVec.begin() + 1);                                 //ɾ������������ָ���Ԫ�أ�
	std::cout << "after earsing , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "���صĵ�����ֵΪ��" << *ret2 << std::endl;

	auto ret3 = myVec.erase(myVec.begin() + 1, myVec.begin() + 4);              //���ص�������ָ��ķ�Χ�ڵ�Ԫ��
	std::cout << "after earsing , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << "���صĵ�����ֵΪ��" << *ret3 << std::endl;

	std::swap(myVec, myVec1);                                                   //��������������ֵ����ʵʵ���ϲ�������
	std::cout << "after swapping , myVec is : " << std::endl;
	for (auto tmp : myVec)
	{
		std::cout << tmp << ' ';
	}
	std::cout << '\n';

}