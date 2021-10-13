/*1950095 大数据 何正潇*/
#include <iostream>
#include <cstring>
using namespace std;

/*函数功能：实现高精度乘法*/
void mul(int num1[400], int answer[400], int num2, int& length,int& length_)
{
	int i = 0;
	int residue = 0;
	for (i = 0; i < length; i++)
	{
		int temp = num1[i];
		answer[i] = (residue + num2 * (num1[i])) % 10;
		residue = (residue + num2 * (temp)) / 10;

	}
	while (residue)
	{
		
		answer[i] = residue % 10 ;
		residue = residue / 10;
		length++;
		i++;
	}
	length_ = length;
	
}
void add(int num1[400], int num2[400], int answer[400], int& length, int& length_)
{
	int residue = 0;
	int i = 0;
	for (i = 0; i < length_; i++)
	{
		int temp = num2[i];
		answer[i] = (residue + num2[i] + num1[i]) % 10;
		residue = (residue + num1[i] + temp) / 10;
	}
	while (residue)
	{
		
		answer[i] = residue % 10;
		residue = residue / 10;
		length_++;
		i++;
	}
	
}
int main()
{
	int N, A;
	cin >> N >> A;
	int length = 0;
	int length_ = 0;
	if (A < 10 && A >= 0)
		length_ = 1;
	else
		length_ = 2;
	length = length_;
	int num1[400];
	int num2[400];
	 int answer[400];
	 memset(answer, 0, 1600);
	 memset(num1, 0, 1600);
	 num1[0] = A % 10, num1[1] = A / 10 % 10, num1[2] = A / 10 / 10 % 10;
	 for (int i = 1; i <= N; i++)
	 {
		 if (A < 10 && A >= 0)
			 length = 1;
		 else
			 length = 2;
		 if (i == 1)
		 {
			 if (length_ == 1)
				 answer[0] = A;
			 else
			 {
				 answer[0] = A % 10;
				 answer[1] = A / 10 % 10;
			 }
		 }
		 else
		 {
			 for (int j = 1; j < i; j++)
			 {
				 mul(num1, num1, A, length,length_);
			 }
			 mul(num1, num1, i, length, length_);
			 add(num1, answer, answer, length,length_);
			 for (int i = 3; i < length_; i++)
				 num1[i] = 0;
			 num1[0] = A % 10, num1[1] = A / 10 % 10, num1[2] = A / 10 / 10 % 10;
			 
		 }

	 }
	 for (int i = length_ - 1; i >= 0; i--)
		 cout << answer[i];
/*	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			mul(num1,answer,)
		}
	}*/
	 return 0;
}
