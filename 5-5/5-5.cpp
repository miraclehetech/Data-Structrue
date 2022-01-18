#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
using namespace std;
int inverse_number_cnt(int* a, int n)
{
	int i, j, cnt = 0;
	for (i = 0; i < n - 1; ++i)
		for (j = i + 1; j < n; ++j)
			if (a[i] > a[j])
				++cnt;
	return cnt;
}
int main()
{
	int number;
	int store[100000];
	cin >> number;
	while (number != 0)
	{
		for (int i = 0; i < number; i++)
		{
			cin >> store[i];
		}
		int result = inverse_number_cnt(store, number);
		cout << result << endl;
		cin >> number;
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
