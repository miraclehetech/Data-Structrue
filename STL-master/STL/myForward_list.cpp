#include <iostream>
#include <string>
#include <forward_list>
#include <iterator>      //���е�advance�����������ƶ��������ƶ�ָ�����ȣ�
#include "myForward_list.h"   //��������
#include "myList.h"
/*
	��1�����죺
	��2��ͨ�ú�����empty(), front(��, swap(), clear(), push_front(), pop_front(), reverse(), 
	��3�����к�����inert_after(), erase_after(), before_begin(), remove(), remove_if(), unique(), sort(), merge(), 

*/

void myForward_listTest()
{
	std::cout << "------------------------this is class forward_list demo-----------------------" << std::endl;
	std::forward_list<int> myForward_list = { 1, 3, 7, 5, 5 };
	std::cout << "the front of myForward_list is : " << myForward_list.front() << std::endl;    //front��

	myForward_list.push_front(0);
	for (auto tmp : myForward_list)
		std::cout << tmp << ' ';
	std::cout << '\n';
	/*
	lst.insert_after(p, t)       //�ڵ�����p֮���λ�ò���Ԫ��t������ָ�����Ԫ�صĵ�����
	lst.insert_after(p, b, e)    //�ڵ�����p֮����뷶ΧΪ[b, e����Ԫ�أ��������һ����������ĵ�����
	*/
	auto iter = myForward_list.before_begin();
	std::advance(iter, 1);                                                          //���⻹����ʹ��iterator�е�advance�����Ե���������ƫ��
	myForward_list.insert_after(myForward_list.before_begin(), 9);                  //list ��forward_list��Ȼ��֧��+,-����������֧��++�� ��--������
	std::cout << "after inserting , myForward_list is : " << std::endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)   
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';

	myForward_list.erase_after(myForward_list.before_begin());                      //�ڵ�����p֮���λ�ò���Ԫ��t������ָ�����Ԫ�صĵ�����
	std::cout << "after erasing , myForward_list is : " << std::endl;             
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';
	  
	//myForward_list.remove(9);                                                    //ɾ��ĳһ�ض�ֵԪ��
	//myForward_list.remove_if(is_odd);                                            //���մ���ν����ɾ��ĳһԪ��

	myForward_list.unique();                                                       //�߳��ظ�����
	std::cout << "after unique , myForward_list is : " << std::endl;
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';

	myForward_list.sort();                                                         //���������ݽ�������
	std::cout << "after sorting , myForward_list is : " << std::endl;  
	for (auto iter = myForward_list.begin(); iter != myForward_list.end(); ++iter)
	{
		std::cout << *iter << std::ends;
	}
	std::cout << '\n';


}