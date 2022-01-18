#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <stdio.h>

#include "myStackAndQueue.h"

/*
	��1�����죺std::atack<int >myStack;
	��2��ͨ�ò�����empty(), size(),
	��3�����в�����pop(), push(),top(),
*/
void myStackTest()
{
	std::cout << "---------------------------this is class stack demo--------------------------" << std::endl;
	std::stack<int >myStack;

	myStack.push(1);
	myStack.push(2);
	myStack.push(3);                                                      //Ԫ�ؽ�ջ
	 

	int top_num = myStack.top();                                          //ջ��Ԫ��
	std::cout << "the num of myStack is: " << top_num << std::endl;
	myStack.pop();                                                        //����ջ��Ԫ��
	int top_num1 = myStack.top();
	std::cout << "the num of myStack is: " << top_num1 << std::endl;
	
}
/*
	��1�����죺  std::queue<int> myQueue;
	��2��ͨ�ò�����empty(), size(), front(), back(), 
	��3�����в�����push(), pop(), 
*/
void myQueueTest()
{
	std::cout << "---------------------------this is class queue demo--------------------------" << std::endl;
	std::queue<int > myQueue;
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);                                   //�����
	int front_num = myQueue.front();                   //����ͷԪ��
	int back_num = myQueue.back();                     //����βԪ��
	printf("the front and back num of the myQueue : %d and %d \n", front_num, back_num);

	myQueue.pop();                                     //����Ԫ�ز�����Ԫ��
	myQueue.pop();
	int front_num1 = myQueue.front();
	int back_num1 = myQueue.back();
	printf("the front and back num of the myQueue : %d and %d \n", front_num1, back_num1);





}