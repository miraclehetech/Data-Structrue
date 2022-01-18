#include <iostream>
#include <stdio.h>
#include <string>
#include <set>

#include "mySet.h"

/*
	//����Ԫ�ض��ǰ����ֵ����Զ�����setֻ�м�ֵ����ֵ������ֵ
	��1�����죺
	��2��ͨ�ò�����empty(), insert(), erase(), size(), swap(), find(), count(), 
	��3�����в�����equal_range(), lower_bound(), upper_bound()
*/

void mySetTest()
{
	std::cout << "-----------------------------this is class set  demo--------------------------" << std::endl;
	std::set<std::string >mySet = {"a", "b", "c"};

	/*
		//insert����һ��pair��first��һ��������ָ����и����ؼ��ֵ�ֵ��second��һ��bool��������true���ʾ����ɹ���
		//��Ϊfalse���ʾ����ʧ�ܣ�˵���Ѿ����ڣ�������ʲôҲ����
		m.insert(e);                                              //����pair����
		m.insert(beg, end);                                       //����Χ�ڵ�Ԫ�ز���
		m.insert(iter, e);                                        //unknow
	*/

	bool flag = mySet.empty();
	auto ret = mySet.insert("d");                                                //�����ֵ
	std::cout << "after inserting, mySet is : \n";
	if (ret.second)
	{
		for (auto tmp : mySet)
			std::cout << tmp << std::ends;
	};
	std::cout << "\n";
	auto ret1 = mySet.erase("d");                                                //ɾ��Ԫ��
	for (auto tmp : mySet)
		std::cout << tmp << std::ends;
	std::cout << "\n";

	auto ret2 = mySet.find("a");
	if (ret2 == mySet.end())
		std::cout << "dont find it \n";
	else
		std::cout << "find it \n";

	unsigned int cnt = mySet.count("a");
	printf("a occurred %d times", cnt);

	std::set<std::string>::iterator iter_beg = mySet.lower_bound("a");
	std::set<std::string>::iterator iter_end = mySet.upper_bound("a");      //�����ؼ��ֵķ�Χ[lower_bound, upper_bound)

}