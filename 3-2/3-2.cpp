/*看看运算树层数的代码*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
typedef struct BitNode
{
	int left_child=0;
	int right_child=0;
	char data;
} BitNode;
bool judge(BitNode* k,BitNode* q, int left_child, int right_child)
{
	
	if (left_child == -1 && right_child == -1)
		return true;
	else if (left_child * right_child < 0)
		return false;
	else if (k[left_child].data != q[right_child].data)
		return false;
	else
	{
		bool re1 = judge(k, q, int(k[left_child].left_child), int(q[right_child].left_child));
		bool re2 = judge(k, q, int(k[left_child].right_child), int(q[right_child].right_child));
		if (re1 && re2)
			return true;
		else
		{
			bool re1 = judge(k, q, int(k[left_child].right_child), int(q[right_child].left_child));
			bool re2 = judge(k, q, int(k[left_child].left_child), int(q[right_child].right_child));
			if (re1 && re2)
				return true;
			else
				return false;
		}
	}
}
int  Depth(BitNode* k,int i)
{
	if (i==-1)
	{
		return 0;
	}
	else
	{
		int depl= Depth(k,k[i].left_child);
		int depr = Depth(k,k[i].right_child);
		if (depl >= depr)
			return depl + 1;
		else
			return depr + 1;
		
	}

}
int main()
{
	int number,number_2,depth_1=0,depth_2=0,index_1=0,index_2=0,depth_temp=0;
	cin >> number;
	BitNode* bit,*bit2;
	bit = new BitNode[number];
	for (int i = 0; i < number; i++)
	{
		int index = 1;
		char s[10000],s1[10000];
		cin >> bit[i].data >> s>> s1;
		if (s[0] == '-')
			bit[i].left_child = -1;
		else
		{
			for (int k = strlen(s) - 1; k >= 0; k--)
			{
				bit[i].left_child = bit[i].left_child + (s[k]-'0') * index;
				index *= 10;
			}
		}
		index = 1;
		if (s1[0] == '-')
			bit[i].right_child = -1;
		else
		{
			for (int k = strlen(s1) - 1; k >= 0; k--)
			{
				bit[i].right_child = bit[i].right_child + (s1[k]-'0') * index;
				index *= 10;
			}
		}
		
	}
	cin >> number_2;
	bit2 = new BitNode[number_2];
	for (int i = 0; i < number_2; i++)
	{
		int index = 1;
		char s[10000], s1[10000];
		cin >> bit2[i].data >> s >> s1;
		if (s[0] == '-')
			bit2[i].left_child = -1;
		else
		{
			for (int k = strlen(s) - 1; k >= 0; k--)
			{
				bit2[i].left_child = bit2[i].left_child + (s[k]-'0') * index;
				index *= 10;
			}
		}
		index = 1;
		if (s1[0] == '-')
			bit2[i].right_child = -1;
		else
		{
			for (int k = strlen(s1) - 1; k >= 0; k--)
			{
				bit2[i].right_child = bit2[i].right_child + (s1[k] -'0') * index;
				index *= 10;
			}
		}

	}
	for (int i = 0; i < number; i++)
	{
		int temp = Depth(bit, i);
		if (temp >= depth_1)
		{
			index_1 = i;
			depth_1 = temp;
		}
	}
	for (int i = 0; i < number_2; i++)
	{
		int temp = Depth(bit2, i);
		if (temp >= depth_2)
		{
			index_2 = i;
			depth_2 = temp;
		}
	}
	int result = judge(bit, bit2, index_1, index_2);
	if (result == 1)
	{
		cout << "Yes" << endl;
		cout << depth_1<< endl;
		cout << depth_2 << endl;
	}
	else
	{
		cout << "No" << endl;
		cout << depth_1 << endl;
		cout << depth_2 << endl;
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
