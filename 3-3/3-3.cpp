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
		postorder(T->lchild);          //Ȼ��������ӣ���ʼ�ݹ�
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
