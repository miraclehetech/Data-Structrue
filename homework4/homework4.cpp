#include <iostream>
#include<string.h> 
using namespace std;
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10
typedef int  Elemtype;
typedef int Status;
typedef struct numbers
{
	Elemtype* elem;
	int length;
	int listsize;
} SQlist;
Status Initlist_sq(SQlist& L)
{
	L.elem = (Elemtype*)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
	if (!L.elem)
		return -1;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	int i = 1;
	while (1)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
			break;
		if ((L.length+1)  >= L.listsize)
		{
			Elemtype* newbase;
			newbase = (Elemtype*)realloc(L.elem, (LISTINCREMENT+L.listsize) * sizeof(Elemtype));
			if (!newbase)
				return -1;
			L.elem = newbase;
			L.listsize = L.listsize + LISTINCREMENT;
		}
		L.elem[i++] = temp;
		L.length++;
	}
	return 0;
}
Status Initlist_sq_(SQlist& L)
{
	L.elem = (Elemtype*)malloc(LIST_INIT_SIZE * sizeof(Elemtype));
	if (!L.elem)
		return -1;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	if ((L.length + 1) >= L.listsize)
	{
		Elemtype* newbase;
		newbase = (Elemtype*)realloc(L.elem, (LISTINCREMENT + L.listsize) * sizeof(Elemtype));
		if (!newbase)
			return -1;
		L.elem = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	return 0;
}
Status ListInsert(SQlist& L, int i, Elemtype e)
{
	if (i<1 || i>(L.length+1) )
		return -1;
	if ((L.length + 1) >= L.listsize) {
		Elemtype* newbase;
		newbase = (Elemtype*)realloc(L.elem, (LISTINCREMENT + L.listsize) * sizeof(Elemtype));
		if (!newbase)
			return -1;
		L.elem = newbase;
		L.listsize = L.listsize + LISTINCREMENT;
	}
	Elemtype* q = &(L.elem[i ]);
	for (Elemtype* p = &(L.elem[L.length ]); p >= q; p--) {
		memcpy(p + 1, p, sizeof(Elemtype));
	}
	memcpy(q, &e, sizeof(Elemtype));
	L.length++;
	return 0;
}
void Mergelist(SQlist La, SQlist Lb, SQlist& Lc)
{
	int i=1, j = 1;
	int k = 0;
	int La_len = La.length, Lb_len = Lb.length;
	while ((i <= La_len) && (j <= Lb_len))
	{
		int ai = La.elem[i ], bj = Lb.elem[j ];
		if (ai <= bj)
		{
			ListInsert(Lc, ++k, ai);
			++i;
		}
		else
		{
			ListInsert(Lc, ++k, bj);
			++j;
		}
	}
	while (i <= La_len)
	{
		int ai = La.elem[i ];
		i++;
		ListInsert(Lc, ++k, ai);
	}
	while (j <= Lb_len)
	{
		int bj = Lb.elem[j];
		j++;
		ListInsert(Lc, ++k, bj);
	}
}
void Line_up(SQlist& La)
{
	for (int i = 0; i < La.length-1; i++)
	{
		for (int j = 1; j < La.length-i; j++)
		{
			if (La.elem[j] >= La.elem[j + 1])
			{
				int t = La.elem[j];
				La.elem[j] = La.elem[j + 1];
				La.elem[j + 1] = t;
			}
		}
	}
}
int main()
{
	SQlist a, b,c;
	Initlist_sq(a), Initlist_sq(b);
	Line_up(a), Line_up(b);
	Initlist_sq_(c); 
	Mergelist(a, b, c);
	for (int i = 1; i < c.length+1; i++)
		cout << c.elem[i]<<" ";
	return 0;
}
