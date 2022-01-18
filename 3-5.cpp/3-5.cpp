#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<map>
#include<string>
#include<stack>
using namespace std;
map<string, int> info;
typedef struct BitNode
{
	/*int son = -1;*///������
	int sibling=0;
	int parent = 0;
	int degree;
	string name;
}BitNode, *BiTree;
void  CreateBiTree(BiTree&T,int n)
{
	stack<BitNode> a;
	int j = 0;
	int degree_now=0, degree_last=0;
	T = new BitNode[n];
    for (int i = 0; i < n; i++)
    {
		string name;
		if (i == 0)
			getchar();
		getline(cin, name);
		for (j=0; name[j] == ' '; j++)
			degree_now++;
		name=name.substr(j);
		if (i == 0)
		{
			info[name] = 0;
			T[0].degree = 0;
			T[0].sibling = -1;
			T[0].parent = -1;
			T[0].name = name;
			a.push(T[0]);
		}
		else
		{
			info[name] = i;
			T[i].degree = degree_now;
			T[i].name = name;
			if (T[i].degree >= a.top().degree)
			{
				if (T[i].degree > a.top().degree)
					T[i].parent = info[a.top().name];
				else
				{
					T[i].sibling = info[a.top().name];
					T[i].parent = T[T[i].sibling].parent;
				}
			}
			else
			{
				while (T[i].degree < a.top().degree)
					a.pop();
				if(T[i].degree== a.top().degree)
				{
					T[i].sibling = info[a.top().name];
					T[i].parent = T[T[i].sibling].parent;
				}
			}
			a.push(T[i]);
		}
		degree_now = 0;
    }
}
int main()
{
	while (1)
	{
		int n, m;
		bool found = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		BiTree a;
		CreateBiTree(a, n);
		while (m--) {  //m�г�����
			string str[6];
			for (int i = 0; i < 6; i++)
				cin >> str[i];
			str[5] = str[5].substr(0, str[5].size() - 1);//�Ѿ��Ū��
			//�����в����ڵ����ֲ�������ڳ�������
			if (str[3] == "child")
			{
				if (a[info[str[0]]].parent == info[str[5]])
					cout << "True" << endl;
				else
					cout << "False" << endl;
			}
			else if (str[3] == "sibling")
			{
				if(a[info[str[0]]].parent==a[info[str[5]]].parent)
					cout << "True" << endl;
				else
					cout << "False" << endl;
			}
			else if (str[3] == "parent")
			{
				if (a[info[str[5]]].parent == info[str[0]])
					cout << "True" << endl;
				else
					cout << "False" << endl;
			}
			else if (str[3] == "ancestor") {    //���Ⱥ�����������Լ�
				if (str[0] == str[5])
					cout << "True" << endl;
				else {
					int temp = info[str[5]];
					while (temp != -1) {
						if (a[temp].parent == info[str[0]]) {
							cout << "True" << endl;
							found = true;
							break;
						}
						temp = a[temp].parent;
					}
					if(found==false)
					cout << "False" << endl;
				}
			}
			else if (str[3] == "descendant") {
				if (str[0] == str[5])
					cout << "True" << endl;
				else {
					int temp = info[str[0]];
					while (temp != -1) {
						if (a[temp].parent == info[str[5]]) {
							cout << "True" << endl;
							found = true;
							break;
						}
						temp = a[temp].parent;
					}
					if(found==false)
					cout << "False" << endl;
				}
			}
			found = false;
		}
		cout << endl;
		delete[]a;
	}
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
