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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
