/*1950095 大数据 何正潇*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
/*
 注释:此处用顺序表较为简单，因此没有使用链表，基本使用的就是归并排序的思想，与教科书例题代码相似。
*/
typedef struct poly {
	int p;//系数
	int coe;//指数
}poly;

struct list {
	struct poly* Elem;
	int length;
};


/*输出多项式*/
void print(list& L) {
	for (int i = 1; i <= L.length; i++)   //输出
		if (L.Elem[i].p != 0) //系数不为0输出
			cout << L.Elem[i].p << " " << L.Elem[i].coe << " ";
	cout << endl;
}
/*冒泡排序*/
void sort(list& L) {
	poly k;
	for (int i = 1; i <= L.length - 1; i++)
		for (int j = 1; j <= L.length - i; j++)
			if (L.Elem[j].coe > L.Elem[j + 1].coe)
			{
				k = L.Elem[j];
				L.Elem[j] = L.Elem[j + 1];
				L.Elem[j + 1] = k;
			}
}
/*归并排序*/
void add(list& L1, list& L2, list& L3) {
	sort(L1);
	sort(L2);
	int i = 1, j = 1, k = 1;
	while (i <= L1.length && j <= L2.length) {
		if (L1.Elem[i].coe < L2.Elem[j].coe)
			L3.Elem[k++] = L1.Elem[i++];
		else if (L1.Elem[i].coe > L2.Elem[j].coe)
			L3.Elem[k++] = L2.Elem[j++];
		else {
			L3.Elem[k].coe = L1.Elem[i].coe;
			L3.Elem[k++].p = L1.Elem[i++].p + L2.Elem[j++].p;
		}
	}
	while (i <= L1.length)
		L3.Elem[k++] = L1.Elem[i++];
	while (j <= L2.length)
		L3.Elem[k++] = L2.Elem[j++];
	L3.length = k - 1;
}
/*项数Delete*/
void Delete(list& L, int position)
{
	for (int i = position; i <= L.length; i++)
		L.Elem[i] = L.Elem[i + 1];
	L.length--;
}
/*乘法*/
void multiply(list& L1, list& L2, list& L3) {
	int i, j, k = 1;
	for (i = 1; i <= L1.length; i++)
		for (j = 1; j <= L2.length; j++)
		{
			L3.Elem[k].p = L1.Elem[i].p * L2.Elem[j].p;
			L3.Elem[k].coe = L1.Elem[i].coe + L2.Elem[j].coe;
			k++;
		}
	L3.length = L1.length * L2.length;
	sort(L3);
	for (int i = 1; i < L3.length; i++) {
		if (L3.Elem[i].coe == L3.Elem[i + 1].coe)
		{
			L3.Elem[i].p += L3.Elem[i + 1].p;
			Delete(L3, i + 1);
			i--;//此处需要注意
		}
	}
}

int main()
{
	list L1, L2, L3;
	L1.Elem = (poly*)malloc(10000 * sizeof(poly));
	L2.Elem = (poly*)malloc(10000 * sizeof(poly));
	L3.Elem = (poly*)malloc(10000 * sizeof(poly));
	L3.length = 0;
	cin >> L1.length;
	for (int i = 1; i <= L1.length; i++)
		cin >> L1.Elem[i].p >> L1.Elem[i].coe;//输入
	cin >> L2.length;
	for (int i = 1; i <= L2.length; i++)
		cin >> L2.Elem[i].p >> L2.Elem[i].coe;//输入
	int order;
	cin >> order;
	if (order == 0) {
		add(L1, L2, L3);
		print(L3);
	}
	else if (order == 1) {
		multiply(L1, L2, L3);
		print(L3);
	}
	else if (order == 2) {
		add(L1, L2, L3);
		print(L3);
		multiply(L1, L2, L3);
		print(L3);
	}
	free(L1.Elem);
	free(L2.Elem);
	free(L3.Elem);
	return 0;
}