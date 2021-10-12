#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#ifndef OVERFLOW
#define OVERFLOW	-2
#endif // !OVERFLOW
#define s_size 10
#define INSERT_NUM		115	
typedef int Status;

struct Student
{
	char no[9];
	char stu_name[20];
};
typedef Student ElemType;
typedef struct {
	ElemType* elem; //存放动态申请空间的首地址
	int length; //记录当前长度
	int listsize; //当前分配的元素的个数
} sqlist;
Status InitList(sqlist* L, int num);
Status DestroyList(sqlist* L);
Status ListInsert(sqlist* L, int i, ElemType e);
Status ListDelete(sqlist* L, int i);
int LocateElem(sqlist L, ElemType e, Status(*compare)(ElemType* e1, ElemType* e2));
Status MyCompare_no(ElemType* e1, ElemType* e2)
{
	return strcmp((*e1).no, (*e2).no) == 0;
}
Status MyCompare_name(ElemType* e1, ElemType* e2)
{
	return strcmp((*e1).stu_name, (*e2).stu_name) == 0;
}
int main()
{
	sqlist L;
	ElemType e;
	int num, i;
	char s[s_size];
	scanf("%d", &num);//读取人数
	InitList(&L, num);//根据人数建立线性表
	while (1) {
		scanf("%s", s);//读取命令
		//根据命令进行操作
		if (strcmp(s, "insert") == 0) {
			//读取并执行插入操作
			scanf("%d %s %s", &i, (e.no), e.stu_name);
			if (ListInsert(&L, i, e) == OK)
				printf("0\n");
			else
				printf("-1\n");
		}
		else if (strcmp(s, "remove") == 0) {
			//读取并执行删除操作
			scanf("%d", &i);
			if (ListDelete(&L, i) == OK)
				printf("0\n");
			else
				printf("-1\n");
		}
		else if (strcmp(s, "check") == 0) {
			//读取并执行check no或者check name操作
			scanf("%s", s);
			if (strcmp(s, "name") == 0) {
				scanf("%s", e.stu_name);
				i = LocateElem(L, e, MyCompare_name);
			}
			else {
				scanf("%s", (e.no));
				i = LocateElem(L, e, MyCompare_no);
			}
			if (i) {
				printf("%d %s %s\n", i, L.elem[i - 1].no, L.elem[i - 1].stu_name);
			}
			else
				printf("-1\n");;
		}
		else if (strcmp(s, "end") == 0) {
			//打印长度并结束
			printf("%d\n", L.length);
			break;
		}
	}
	//销毁线性表
	DestroyList(&L);
	return 0;
}
//根据num建立线性表，读取数据
Status InitList(sqlist* L, int num)
{
	L->elem = (ElemType*)malloc((num + INSERT_NUM) * sizeof(ElemType));
	if (L->elem == NULL) {
		exit(OVERFLOW);
	}
	for (int i = 0; i < num; i++) {
		scanf("%s %s", &(L->elem[i].no), L->elem[i].stu_name);
	}
	L->length = num;
	L->listsize = num + INSERT_NUM;
	return OK;
}
//在线性表的i位置插入元素
Status ListInsert(sqlist* L, int i, ElemType e)
{
	if (i<1 || i>L->length + 1)
		return ERROR;
	if (L->length >= L->listsize) {
		ElemType* newbase;
		newbase = (ElemType*)realloc(L->elem, (L->listsize + L->listsize / 2) * sizeof(ElemType));
		if (!newbase) {
			return OVERFLOW;
		}
		L->elem = newbase;
		L->listsize = L->listsize + INSERT_NUM;
	}
	ElemType* q = &(L->elem[i - 1]);
	for (ElemType* p = &(L->elem[L->length - 1]); p >= q; p--) {
		memcpy(p + 1, p, sizeof(ElemType));
	}
	memcpy(q, &e, sizeof(ElemType));
	L->length++;
	return OK;
}
//删除i位置的元素
Status ListDelete(sqlist* L, int i)
{
	if (i<1 || i>L->length)
		return ERROR;
	ElemType* p = &(L->elem[i]);
	for (ElemType* q = &(L->elem[L->length - 1]); p <= q; p++) {
		memcpy(p - 1, p, sizeof(ElemType));
	}
	L->length--;
	return OK;
}
//根据外部定义的compare规则找到对应元素
int LocateElem(sqlist L, ElemType e, Status(*compare)(ElemType* e1, ElemType* e2))
{
	ElemType* p = L.elem;
	int i = 1;
	while (i <= L.length && (*compare)(p++, &e) == FALSE)
		i++;
	return (i <= L.length) ? i : 0;
}
//销毁线性表
Status DestroyList(sqlist* L)
{
	if (L->elem)
		free(L->elem);
	L->length = 0;  //可不要
	L->listsize = 0;  //可不要
	return OK;
}