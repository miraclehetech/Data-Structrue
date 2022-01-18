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
	/*int son = -1;*///不合适
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
		while (m--) {  //m行陈述句
			string str[6];
			for (int i = 0; i < 6; i++)
				cin >> str[i];
			str[5] = str[5].substr(0, str[5].size() - 1);//把句号弄掉
			//家谱中不存在的名字不会出现在陈述句中
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
			else if (str[3] == "ancestor") {    //祖先和子孙可以是自己
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
