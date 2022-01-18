/*1950095 大数据 何正潇*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>  
#include <string>  
using std::string;
#include <iostream>
#define num 60000
using namespace std;
int main()
{
	int number;
	cin >> number;
	int* temp = NULL;
	temp = new int[number];
	for (int i = 0; i < number; i++)
	{
		cin >> temp[i];
	}
	int max = 0;
	int sum = 0;
	for (int i = 0; i < number; i++)
	{
		if (sum <= 0 && temp[i] >= 0)
		{
			sum = temp[i];
			if (sum >= max)
				max =sum;
		}
		else if (sum >= 0)
		{
			sum += temp[i];
			if (sum >= max)
				max = sum;
		}
		else
			continue;
	}
	cout << max;
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
