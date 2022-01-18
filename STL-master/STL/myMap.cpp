#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <stdio.h>
#include "myMap.h"
/*
	��1�����죺std::map<string, int>, std::pair<string, int>, std::make_pair(v1, v2)
	��2�����������first, second, insert(), erase(), count(), find(), operator[](); 
*/
void myMapTest()
{
	std::cout << "----------------------------this is class map demo---------------------------" << std::endl;
	std::map<std::string, int>myMap;
	
	auto myPair1 = std::pair<std::string, int>("hello", 1);
	auto myPair2 = std::make_pair("world", 10);

	/*
		//insert����һ��pair��first��һ��������ָ����и����ؼ��ֵ�ֵ��second��һ��bool��������true���ʾ����ɹ���
		//��Ϊfalse���ʾ����ʧ�ܣ�˵���Ѿ����ڣ�������ʲôҲ������ֻ���ֶ���++
		m.insert(e);                                          //����pair����
		m.insert(beg, end);                                   //����Χ�ڵ�Ԫ�ز���
		m.insert(iter, e);                                    //unknow
	*/
	auto ret1 = myMap.insert(myPair1); 
	if (ret1.second)
		std::cout << "insert successfully\n";                                //����pair����
	printf("%s---->%d\n", ret1.first->first.c_str(), ret1.first->second);
	auto ret2 = myMap.insert(myPair2);
	if (ret2.second)
		std::cout << "insert successfully\n";
	printf("%s---->%d\n", ret2.first->first.c_str(), ret2.first->second);

	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}
	printf("\n");

	++myMap["word"];                                                         //ʹ���±���������������ڣ��򴴽��µļ�ֵ��(word, 0)
	std::cout << "after operator[], myMap is : \n";
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}
	/*
		m.erase(k);                             //ɾ���ؼ���Ϊk��Ԫ��
		m.erase(p);                             //ɾ��������pָ���Ԫ��
		m.erase(b, e);                          //ɾ����Χ�ڵ�Ԫ��
	*/
	myMap.erase("word");
	std::cout << "after erasing, myMap is : \n";
	for (auto iter = myMap.begin(); iter != myMap.end(); ++iter)
	{
		printf("%s---->%d\n", iter->first.c_str(), iter->second);
	}

	unsigned cnt = myMap.count("hello");                                            //���عؼ��ֵĶ���
	printf("hello occurred %d times\n", cnt);
	std::cout << "find keyword hello : \n";
	auto ret3 = myMap.find("hello");                                                //���عؼ��ֵĵ�����
	printf("%s---->%d\n", ret3->first.c_str(), ret3->second);


}
