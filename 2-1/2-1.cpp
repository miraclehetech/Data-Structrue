/*1950095 大数据 何正潇*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>  
#include <string>  
using std::string;
#include <iostream>
#define num 60000
using namespace std;
typedef int SElemtype;
typedef struct
{
	SElemtype* base;
	SElemtype* top;
	int stacksize;
}Sqstack;
int InitStack(Sqstack& s,int n)
{
	s.base = (SElemtype*)malloc(n * sizeof(SElemtype));
	if (!s.base)
		return -1;
	s.top = s.base;
	s.stacksize = 100;
	return 0;
}
int Pop (Sqstack& s)
{
	if (s.top == s.base)
	{
		cout << "Stack is Empty" << endl;
		return -1;
	}
	else
	{
		cout << *--s.top << endl;
		return 0;
	}
}
int push(Sqstack& s, SElemtype e,int n)
{
	if (s.top - s.base >=n)
	{
		cout << "Stack is Full" << endl;
		return -1;
	}
	*s.top++ = e;
	return 0;
}
void exit_push_all(Sqstack& s)
{
	if (s.top != s.base)
	{
		while (s.top != s.base)
		{
			cout << *--s.top << " ";
		}
	}
	else
	{
		cout << "Stack is Empty" << endl;
	}
}
int main()
{
	Sqstack a;
	int number = 0;
	cin >> number;
	InitStack(a,number);
	while (1)
	{
		char str[20];
		cin >> str;
		if(!strcmp(str, "pop"))
		{
			Pop(a);
		}
		else if (!strcmp(str, "push"))
		{
			int number1;
			cin >> number1;
			push(a, number1, number);
		}
		else if (!strcmp(str, "quit"))
		{
			exit_push_all(a);
			break;
		}

	}
	return 0;
}
