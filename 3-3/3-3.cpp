#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
typedef struct BitNode
{
	char data;
	BitNode* lchild, * rchild;
}*BiTree, BitNode;
void  CreateBiTree(BiTree& T,char input[100],int& i,int&times,int number)
{
	if (input[i] == 7) 
	{
		T = NULL;
		i++;
	}
	else 
	{
		if (times < number)
		{
			T = new BitNode;
			T->data = input[i];
			i++;
			times++;
			CreateBiTree(T->lchild, input, i, times, number);
			CreateBiTree(T->rchild, input, i, times, number);
		}
		else
			return;
	}
	return;
}
void inorder(BiTree& T)
{
	if (T == NULL)
		return;
	else
	{
		inorder(T->lchild);
		cout << T->data;
		inorder(T->rchild);

	}

}
void postorder(BiTree& T)
{
	if (T == NULL)
		return;
	else
	{
		postorder(T->lchild);          //然后访问左孩子，开始递归
		postorder(T->rchild);
		cout << T->data;
	}
}
int main()
{
	int number;
	BiTree a;
	cin >> number;
	stack<char>pos;
	int j = 0;
	int i = 0;
	int initial = 0;
	char input[100];
	char result[10000];
	int times = 0;
	//cin >> input;
	/*if (strcmp(input, "push") == 0)
	{
		j++;
		cin >> result[i];
		pos.push(result[i]);
		i++;
	}*/
	for(i=0;;i++)
	{
		cin >> input;
		if (strcmp(input, "push") == 0)
		{
			j++;
			cin >> result[i];
			pos.push(result[i]);
		}
		else
		{
			result[i]=7,result[i+1] =7;
			pos.pop();
		}
		if (j == number)
		{
			if (pos.empty() == 1)
				break;
		}
	}
	result[i + 2] = '\0';
	CreateBiTree(a,result, initial,times,number);
	postorder(a);
	//inorder(a);
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
