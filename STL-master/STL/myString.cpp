/*
ʵ��string�����Ĳ�����
��1�����졢��ֵ:
��2������������size(), empty(),  push_back(), pop_back(), insert(), erase(), clear();
��3��string���в�����substr(), append(), replace(), find()ϵ�к���, compare()
*/
#include <iostream>
#include <string>
#include <string.h>
#include "myString.h"


void myStringTest()
{
	std::cout << "-----------------------------this is class string demo--------------------------" << std::endl;
	std::string str1 = "hello world";
	std::cout << "the length of str1��" << str1.size() << std::endl;
	str1.push_back('!');                                 //��β������ַ�
	std::cout << "after pushing, str1 is: " << str1 << std::endl;
	
	auto ret = str1.insert(str1.begin() + 5, '@');       //���ܵ������汾���ص���ָ�����Ԫ�صĵ�����
	std::cout << "after inserting, str1 is : " << str1 << std::endl;
	std::cout << "���뷵�صĵ�������ָ���ֵΪ��" << *ret << std::endl;

	auto ret1 = str1.insert(6, "#");                     //����Ϊ�±�ģ���������ַ��������ص��ǲ���֮��str1������,��ס�ַ����±��Ǵ�0��ʼ��
	std::cout << "after inserting, str1 is : " << str1 << std::endl;
	std::cout << "���뷵�ص�ֵΪ��" << ret1 << std::endl;

	auto ret2 = str1.erase(str1.begin() + 5);            //���ܵ������汾�ģ�����ɾ��Ԫ��֮��ĵ�����
	std::cout << "after earsing , str1 is: " << str1 << std::endl;
	std::cout << "���صĵ�����ָ��Ԫ��Ϊ��" << *ret2 << std::endl;

	auto ret3 = str1.erase(5, 1);                       //�����±�����ģ�,����ɾ�����ȣ�����ɾ��Ԫ��֮�������
	std::cout << "after earsing , str1 is: " << str1 << std::endl;
	std::cout << "���صĵ�����ָ��Ԫ��Ϊ��" << ret3 << std::endl;
	//string s.substr(pos, n) //n��ȱʧ������β
	std::string str2 = str1.substr(0, 5);                //��0��ʼ������Ϊ5���Ӵ�����5ȱʧ����Ĭ�ϵ�ĩβ
	std::cout << "after substr, str2 is :" << str2 << std::endl;

	str1.append("!!!");                                   //��β������Ӵ�
	std::cout << "after appending, str1 is :" << str1 << std::endl;

	//string &s.replace(range, args)                      //��range��Χ�ڵ�Ԫ�أ��滻Ϊargs�����Բ�һ����
	//�������ֳ����ģ�
	str1.replace(5, 1, "###");                            //(pos, len, str)��ʽ
	std::cout << "after replace, str1 is : " << str1 << std::endl;

	str1.replace(str1.begin() + 5, str1.begin() + 7, "%%%");  //(iterator1, iterator2, string)��ʽ
	std::cout << "after replace, str1 is : " << str1 << std::endl;

	//s.compare() ��Ŀǰ�ͼ�ס��һ�����У�����Ҳ�ǲ�ס
	str1.compare(str2);

	/*
	findϵ�к�����
	(1) s.find(args)          //����s�е�һ�γ��ֵ�λ��,�������Ӵ��������е�һ���ַ����±�
	(2) s.rfind(args)         //�������һ��...
	(3) s.find_first_of(args) //��s�в���args���κ�һ���ַ��ĵ�һ�γ��ֵ�λ�ã�
	(4) s.find_last_of(args)  //��s�в���args���κ�һ���ַ����һ�γ��ֵ�λ�á�
	(5) s.find_first_not_of(args)   //��s�в��ҵ�һ������args�е��ַ�
	(6) s.find_last_not_of(args)    //�������һ������args�е��ַ�
	*/
	auto pos = str1.find(str2);
	std::cout << "str2 is at the pos : " << pos << " of str1" << std::endl;
	std::string numbers("01234556789");
	std::string name("r2d2");
	auto pos1 = name.find_first_of(numbers);
	std::cout << "number first at the pos : " << pos1 << " of name" << std::endl;

	if (str1.compare(str2))    
		std::cout << "str1 > str2" << std::endl;
}