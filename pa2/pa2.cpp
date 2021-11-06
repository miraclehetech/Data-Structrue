/*1950095 大数据 何正潇*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream> 
#include<cstring>
#include<cstdlib> 
#include<cmath>
using namespace std;
typedef int ElemType;
typedef int Status;
typedef  struct  Node {
	ElemType  data;     // 节点数据
	Node* next;
}Node, * LinkList;
Status InitList(LinkList& L) {
	L = (Node*)malloc(sizeof(Node) * 1);
	if (L == NULL) {
		exit(OVERFLOW);
	}
	L->data = 0;
	L->next = NULL;
	return 0;
}
Status AppendList(LinkList& L, Node* n) {
	LinkList p = L->next, q = L;
	while (p != NULL) {
		q = p;
		p = p->next;
	}q->next = n; n->next = NULL;
	return 0;
}
//回收内存
Status DestroyList(LinkList& L) {
	LinkList p = L, q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L = NULL;
	return 0;
}
//清空链表

Status ClearList(LinkList& L) {
	LinkList p = L->next, q;
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return 0;
}
void List_traverse(LinkList L)
{
	LinkList p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
	return;
}
int ListLength(LinkList L) {
	LinkList p = L;
	int length = 0;
	while (p != NULL) {
		length++;
		p = p->next;
	}
	return length-1;
}
Status GetElem(LinkList L, int i) {
	int index = 0;
	LinkList p = L;
	//检查下标合理性
	if (i <= 0 || i > ListLength(L))
		return -1;
	while (p != NULL && index < i) {
		p = p->next;
		index++;
	}
	//判断退出方式
	if (index == i && p != NULL) {
		cout << "已经找到" << endl;
		cout << "index:" << index << " " << p->data << endl;
		return 0;
	}
	else
		return 1;
}
Status GetElem_number(LinkList L, int i)
{
	LinkList p = L;
	int index = 0;
	int count = 0;
	while (p != NULL && index != i)
	{
		count++;
		p = p->next;
		if (p != NULL)
			index = p->data;
		if (index == i && p != NULL)
		{
			cout << "已经找到" << endl;
			cout << "index:" << count << " " << p->data << endl;
			return 0;
		}
		
	}

	return 1;
}

Status Insert_Number(LinkList& L, int i, int j)
{
	LinkList p = L;
	if (i <= 0 || i > ListLength(L)+1)
		return -1;
	int count = 1;

	while (count <= i - 1)
	{
		p = p->next;
		count++;
	}
	Node* temp = (Node*)malloc(sizeof(Node) * 1);
	temp->next = p->next;
	p->next = temp;
	temp->data = j;
	return 0;
}
//判断退出方式


Status Remove_Number(LinkList& L, int i)
{
	LinkList p = L;
	if (i <= 0 || i > ListLength(L))
		return -1;
	int count = 1;
	while (count <= i - 1)
	{
		p = p->next;
		count++;
	}
	Node* temp = p->next;
	p->next = p->next->next;
	free(temp);
	return 0;
}
Status Remove_Repetition(LinkList& L)
{
	LinkList p = L->next;
	LinkList q ;
	for (int i = 1; i <= ListLength(L); i++)
	{
		q = p->next;
		for (int j = i + 1; j <= ListLength(L); j++)
		{

			if (q->data == p->data)
			{
				Remove_Number(L, j);
		//			List_traverse(L);
		//			cout << endl;
					j--;
			}
			q = q->next;
		}
		p = p->next;
	}
	cout << "去重完毕" << endl;
	return 0;
}
Status order_list(LinkList& L, LinkList& L2, LinkList& L3)
{
	LinkList p = L->next, p1 = L2->next, p2 = L3;
	while (p != NULL && p1 != NULL) {
		//将当前两条链表的最值连接到L3中
		if (p->data >= p1->data)
		{
			p2->next = p;
			p = p->next;
		}
		else
		{
			p2->next = p1;
			p1 = p1->next;
		}

	}
	while (p != NULL) {
		p2->next = p;
		p = p->next;
	}
	while (p1 != NULL) {
		p2->next = p1;
		p1 = p1->next;
	}
	p2->next = NULL;
	return 0;
}
void Reverse(LinkList& L)
{
	LinkList p = L,q=L;
	if (ListLength(L) > 2)
	{
		for (int j = 1; j <= ListLength(L)-1; j++)
		{
			if (j != ListLength(L))
			{
				for (int i = 0; i < ListLength(L) - 1; i++)
				{
					p = p->next;
				}
				p->next->next = q->next;
				q->next = p->next;
				p->next = NULL;
				p = L;
				q = p;
				for (int k = 1; k < j + 1; k++)
				{
					q = q->next;
				}
			}

			//List_traverse(L);
			//cout << endl;
		}
	}
	else
	{
		p = p->next;
		p->next->next = L->next;
		L->next = p->next;
		p->next = NULL;
		p = L;
	}

	cout<<"逆转完成"<<endl;
	return ;
}
//节点产生
Status InitNode(Node*& n, int data) {
	n = (Node*)malloc(sizeof(Node) * 1);
	if (n == NULL) {
		exit(OVERFLOW);
	}
	n->data = data;
	n->next = NULL;
	return 0;
}
//初始链表数据输入
Status ManageDataInput(LinkList& L) {
	printf("请输入要输入的数据个数 : ");
	int n;
	int data;
	scanf("%d", &n);
	printf("请输入%d个数据/整数 : ", n);
	LinkList temp = L;
	for (int i = 0; i < n; i++)
	{
		cin >> data;
		temp = temp->next;
		if (InitNode(temp, data) != 0)
			return -1;
		AppendList(L, temp);
	}
	cout << "您已经输入完成" << endl;
	return 0;
}
int main()
{
	LinkList a;
	InitList(a);
	char str[20];
	int number = 0;
	ManageDataInput(a);

	while (1)
	{
		scanf("%s", str);

		if (strcmp(str, "insert") == 0)
		{
			int number, pos;
			cin >> number >> pos;
			if (Insert_Number(a, pos, number) == 0)
				cout << "插入成功" << endl;
			else
				cout << "插入失败" << endl;
		}
		else if (strcmp(str, "remove") == 0)
		{
			scanf("%s", str);
			if (strcmp(str, "location") == 0)
			{
				int pos;
				scanf("%d", &pos);
				if (Remove_Number(a, pos) == 0)
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;
			}

		}
		else if (strcmp(str, "check") == 0)
		{
			int number = 0;

			scanf("%s", str);
			if (strcmp(str, "no") == 0)
			{
				scanf(" %d", &number);
				if (GetElem_number(a, number) == 0)
					cout << "结束" << endl;
				else
					cout << "查询失败" << endl;
			}
			else if (strcmp(str, "pos") == 0)
			{
				int pos;
				cin >> pos;
				if (GetElem(a, pos) == 0)
					cout << "结束" << endl;
				else
					cout << "查询失败" << endl;
			}
		}
		else if (strcmp(str, "end") == 0)
		{
			List_traverse(a);
			break;
		}
		else if (strcmp(str, "remove_repetition") == 0)
		{
			Remove_Repetition(a);
		}
		else if (strcmp(str, "show") == 0)
		{
			List_traverse(a);
		}
		else if (strcmp(str, "reverse") == 0)
		{
			Reverse(a);
		}
		else
		{
			memset(str, '0', (strlen(str) + 1) * sizeof(char));
			cout << "输入无效" << " " << "重新输入" << endl;
		}

	}
	DestroyList(a);
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
