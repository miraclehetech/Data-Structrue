#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>

using namespace std;
int main()
{
	int number;
	cin >> number;
    unsigned int** result = NULL;
	int* length;
	length = new int[number];
	result = new unsigned  int* [number];
	for (int i = 0; i < number; i++)
	{
		result[i] = new  unsigned int[500];
	}
	for (int i = 0; i < number; i++)
		memset(result[i], 0, sizeof(int) * 500);
	for (int temp = 0; temp < number; temp++)
	{
		char s1[205], s2[205];
		int str1[205], str2[205];
		int len1, len2, i;
		scanf("%s %s", s1, s2);
		len1 = strlen(s1), len2 = strlen(s2);
		memset(str1, 0, 205);//初始化0
		memset(str2, 0, 205);
		int len = 0;
		for (i = 0; i < len1; ++i)
			str1[i] = s1[len1 - 1 - i] - '0';
		for (i = 0; i < len2; ++i)
			str2[i] = s2[len2 - 1 - i] - '0';

		for (i = 0; i < len1; ++i)
		{
			int b = 0;   //每遍历完数组a的一个数，进位b都要初始化为0
			int j = 0;
			if (len2 == 1 && str2[0] == 0)
			{
				length[temp] = 1;
				result[temp][0] = 0;
				break;
			}
			else
			{
				for (j = 0; j < len2 || b; ++j)//当str[j]没遍历完，或者最高位满十需要进位，进位不为0
				{
					if (j < len2)
					{
						int t = result[temp][i + j] + str1[i] * str2[j] + b;
						result[temp][i + j] = t % 10;  //余数就是该ans[i+j]位置的数
						b = t / 10;
					}
					else
					{
						result[temp][i + j] = b;
						b = 0;
					}
				}
				length[temp] = i + j;
			}
		}
	}
	for (int i = 0; i < number; i++)
	{
		for (int j = length[i]-1; j >=0 ; j--)
			cout << result[i][j];
		cout << endl;

	}
	return 0;
}
