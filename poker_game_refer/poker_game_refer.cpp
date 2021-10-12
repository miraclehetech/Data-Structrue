#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;


struct poker {
	char color[10]{ '\0' };
	char id[3];
	poker* next;
};

/*函数功能：删除链表第一个元素*/
void Pop(poker** pHead)
{
	poker* q;
	q = (*pHead)->next;
	delete* pHead;
	*pHead = q;

}

/*参数意义：color数组是花色，id数组是编号
函数功能：建立一个新的结点，存入花色和编号，并把next指针指向null，返回该结点地址*/
poker* _Setup(char color[], char id[])
{
	poker* pnode = new (nothrow) poker;
	pnode->next = NULL;
	strcpy(pnode->color, color);
	strcpy(pnode->id, id);
	return pnode;
}

/*参数意义：phead参数用于传入链表首地址并有权限修改其中的内容，color数组是花色，id数组是编号
函数功能：在传入的链表最末端添加元素，如果链表为空则添加在第一个位置*/
void Append(poker** pHead, char color[], char id[])
{
	poker* pnewnode1 = *pHead;
	poker* pnewnode = _Setup(color, id);
	if (*pHead == NULL)
		*pHead = pnewnode;
	else
	{
		while ((pnewnode1)->next)
		{
			pnewnode1 = pnewnode1->next;
		}
		(pnewnode1)->next = pnewnode;
	}
}

/*参数意义：传入链表的首地址，用phead指针接收
函数功能：逆置链表元素，返回新链表首地址*/
poker* Revert(poker* phead) {
	poker* pnew = NULL, * old = phead, * tag = NULL;

	while (old != NULL) {
		tag = old->next;
		old->next = pnew;
		pnew = old;
		old = tag;
	}
	return pnew;
}

/*函数功能：根据扑克牌的编号比较大小，id1大于id2返回1，否则返回0*/
int cmp(char id1[], char id2[]) {
	if (id1[0] == 'A') {
		return 0;
	}
	else if (id2[0] == 'A') {
		return 1;
	}
	else if (strcmp(id1, "10") == 0) {
		if (strcmp(id2, "10") == 0 || id2[0] == 'J' || id2[0] == 'Q' || id2[0] == 'K')
			return 0;
		else
			return 1;
	}
	else if (strcmp(id2, "10") == 0) {
		if (id1[0] == 'J' || id1[0] == 'Q' || id1[0] == 'K')
			return 1;
		else
			return 0;
	}
	else if (id1[0] == 'Q') {
		if (id2[0] == 'Q' || id2[0] == 'K')
			return 0;
		else
			return 1;
	}
	else if (id2[0] == 'Q') {
		if (id1[0] == 'K')
			return 1;
		else
			return 0;
	}

	else
		return(id1[0] > id2[0] ? 1 : 0);
}

poker* SelectSort(poker* head) {
	poker* head1, * p, * q, * pmax = NULL, * qmax = NULL;
	head1 = NULL;
	while (head) {
		for (q = pmax = head, p = head->next; p; q = p, p = p->next) {       //用p指针遍历链表，找出当前链表最大值给pmax，qmax为前驱指针 
			if (cmp(p->id, pmax->id)) {
				pmax = p;
				qmax = q;
			}
		}
		if (pmax - head) {
			qmax->next = pmax->next;
		}
		else {
			head = head->next;
		}
		pmax->next = head1;       //将找出的最大值结点头插到链表head1中 
		head1 = pmax;
	}
	return head1;
}

/*参数意义：传入链表的首地址，用phead指针接收，color数组表示花色
函数功能：根据传入的花色，从链表中抽出符合该花色的元素，根据编号从小到大排序并放置在链表最上面*/
poker* Extract(poker* phead, char color[]) {
	poker* p = phead;
	poker* pnew = new(nothrow) poker;
	pnew->next = NULL;
	poker* q = pnew, * t = NULL;
	poker* pos = NULL;//记录头指针;
	poker* pre = p;//用于删除结点
	bool f = true;//当抽取的花色已经在首位，需要修改一次头指针的地址，
	while (p) {
		if (strcmp(p->color, color) == 0) {
			t = _Setup(color, p->id);
			q->next = t;
			q = t;
			if (!f)  // 不是头结点
				pre->next = p->next;
			poker* r;
			r = p->next;
			delete p;
			p = r;
		}
		else {
			pre = p;
			if (f) { pos = p; f = false; }
			p = p->next;
		}
	}
	pnew = SelectSort(pnew->next);
	if (pnew == NULL)// 如果没有所要求的花色
		return pos;
	else
		p = pnew;
	while (p) {
		if (p->next == NULL) {
			p->next = pos;
			break;
		}
		else
			p = p->next;
	}
	return pnew;
}
int main()
{
	int n;
	scanf("%d", &n);
	char order[10];
	poker* head = NULL;//指向最后牌的位置
	while (n--) {
		scanf("%s", order);
		if (order[0] == 'P') {
			if (head == NULL) {
				printf("NULL\n");
			}
			else {
				printf("%s %s\n", head->color, head->id);
				Pop(&head);
			}
		}
		else if (order[0] == 'A') {
			char color[10], id[3];
			scanf("%s %s", color, id);
			Append(&head, color, id);
		}
		else if (order[0] == 'R')
			head = Revert(head);
		else if (order[0] == 'E') {
			char color[10];
			scanf("%s", color);
			head = Extract(head, color);
		}
	}
	poker* p, * q;
	p = head;
	if (p == NULL)
		printf("NULL\n");
	else {
		while (p) {
			q = p->next;
			printf("%s %s\n", p->color, p->id);
			delete p;
			p = q;
		}
	}
	return 0;
}