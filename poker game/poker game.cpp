/*1950095 大数据 何正潇*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h> 
typedef int Status;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10


using namespace std;
typedef struct Node {
	char number;
	char colors[10];
	struct Node* next;
	struct Node* Prior;
}*Link, * Position;
typedef struct
{
	Link head, tail;
	int len;

}LinkList;
int cmp(char id1, char id2)
{
	if (id1 == 'A')
		return 0;
	else
		return (id2 - id1) > 0 ? 0 : 1;
}
Status count_length(Node* L)
{
	int length = 0;
	Link a = L;
	a = a->next;
	while (a != L)
	{
		length++;
		a = a->next;
	}
	return length;
}
Status Initlist(Linklist& L)
{
	L.head = (Node*)malloc(sizeof(Node));
	if (!L.head)
		return -1;
	L.head->next = L.head;
	L.tail = L.head;
	L.len = 0;
	return 0;
}
Status Append(Linklist& L, char colors[10], char number, int signal)
{
	if (signal == 0)
	{
		Link p;
		p = L.tail;
		p->next = (Node*)malloc(sizeof(Node));
		if (!p->next)
			return -1;
		p->next->Prior = p;
		strcpy(p->next->colors, colors);
		p->next->number = number;
		L.tail = p->next;
		p->next->next = L.head;
		L.len += 1;
	}
	else
	{
		Link p;
		p = (Node*)malloc(sizeof(Node));
		if (!p)
			return -1;
		else
		{
			p->Prior = L.head;
			p->next = L.head->next;
			L.head->next->Prior = p;
			L.head->next = p;
			strcpy(p->colors, colors);
			p->number = number;
			L.len += 1;
		}
	}
	return 0;
}
Status Pop(Linklist& L, int signal)
{
	Link p;
	if (signal == 1)
	{
		p = L.tail;
		if (p == L.head)
		{
			cout << "NULL" << endl;
			return 0;
		}
		else
		{
			cout << p->colors << " " << p->number << endl;
			L.tail->Prior->next = L.tail->next;
			L.tail = L.tail->Prior;
			free(p);
		}
	}
	else
	{
		Link p;
		p = L.head->next;
		if (p == L.head)
		{
			cout << "NULL" << endl;
			return 0;
		}
		else
		{
			cout << p->colors << " " << p->number << endl;
			L.head->next = L.head->next->next;
			L.head->next->Prior = L.head;
			free(p);

		}
	}
	return 0;
}
Status Reverse(int& signal)
{
	if (signal == 1)
		signal = 0;
	else
		signal = 1;
	return 0;
}
Status extract(Linklist& L, int signal, char colors[10])
{
	Link p, q, z, head;
	head = (Node*)malloc(sizeof(Node));
	z = head;
	int times = 0;
	if (!head)
		return -1;
	else
	{
		if (signal == 0)
		{
			p = L.head->next;
			while (p != L.head)
			{
				if (!strcmp(p->colors, colors))
				{
					z->next = (Node*)malloc(sizeof(Node));
					z->next->Prior = z;
					z = z->next;
					strcpy(z->colors, p->colors);
					z->number = p->number;
					// cout << p->colors << " " << p->number << endl;
					p->next->Prior = p->Prior;
					p->Prior->next = p->next;
					q = p->next;
					free(p);
					times++;
				}
				else
				{
					q = p->next;
				}
				p = q;
			}
			z->next = head;
			Link h = head->next;
			for (int i = 0; i < times - 1; i++)
			{
				h = head->next;
				for (int j = 0; j < times - i - 1; j++)
				{

					if (cmp(h->number, h->next->number))
					{
						Link a, b, c, d;
						a = h->Prior, b = h, c = h->next, d = h->next->next;
						h->next->Prior = a;
						a->next = h->next;
						h->next->next = b;
						h->Prior = c;
						h->next = d;
						d->Prior = h;
					}
					h = h->next;
				}
			}
			Link m = head->next;

			L.tail->next = head->next;
			L.tail->next->Prior = L.tail;
			for (int i = 0; i < times-1; i++)
			{
				m = m->next;

			}
			m->next = L.head;
			L.head->Prior = m;
			L.tail = m;
			/*for (int i = 0; i < times; i++)
			{
				L.tail->next->Prior = L.tail;
				L.tail = L.tail->next;
				L.tail->next = L.head;
				L.head->Prior = L.tail;
				m = m->next;
			}*/

		}
		else
		{
			Link p;
			p = L.tail;
			while (p != L.head)
			{
				if (!strcmp(p->colors, colors))
				{
					cout << p->colors << " " << p->number << endl;
					p->Prior->next = p->next;
					p->next->Prior = p->Prior;
					q = p->Prior;
					free(p);
				}
				else
				{
					q = p->Prior;
				}
				p = q;
			}
		}
	}
	return 0;
}
Status output(Linklist& L, int signal)
{
	Link  p;
	if (signal == 1)
	{
		p = L.head->next;
		if (p == L.tail)
		{
			cout << "Null" << endl;
			return -1;
		}
		while (p != L.head)
		{
			cout << p->colors << " " << p->number << endl;
			p = p->next;
			free(p->Prior);
		}
	}
	else
	{
		Link p;
		p = L.tail;
		if (p == L.head)
		{
			cout << "Null" << endl;
			return -1;
		}
		while (p != L.head)
		{

			cout << p->colors << " " << p->number << endl;
			p = p->Prior;
			free(p->next);
		}


	}
	return 0;
}
int main()
{
	Linklist a;
	Initlist(a);
	int number = 0;
	int signal = 1;
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		char orders[10];
		cin >> orders;
		if (!strcmp(orders, "Pop"))
			Pop(a, signal);
		else if (!strcmp(orders, "Append"))
		{
			char colors[10];
			char num;
			cin >> colors >> num;
			Append(a, colors, num, signal);
		}
		else if (!strcmp(orders, "Revert"))
		{
			Reverse(signal);
		}
		else if (!strcmp(orders, "Extract"))
		{
			char colors[10];
			cin >> colors;
			extract(a, signal, colors);
		}
		else
		{
			i--;
			continue;
		}
	}
	output(a, signal);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
