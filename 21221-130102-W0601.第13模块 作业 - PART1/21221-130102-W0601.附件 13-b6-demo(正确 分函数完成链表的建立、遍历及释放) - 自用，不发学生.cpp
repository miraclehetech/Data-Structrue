/* �༶ ѧ�� ���� */
#include <iostream>
#include <string> //C++ string�� ��Ҫ�õ�
using namespace std;

struct student {
	string name;
	int num;
	char sex;
	struct student *next;//ָ��ṹ�������ָ��(�¸����)
};

#define OK	1
#define ERROR	0

int linklist_create(student **head);
int linklist_traverse(student *head);
int linklist_destroy(student *head);

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int linklist_create(student **head)
{
	student *p = NULL, *q = NULL;
	int i;

	for (i = 0; i < 5; i++) {
		if (i > 0)
			q = p;
		p = new(nothrow) student; //˼����Ϊʲô������malloc
		if (p == NULL)
			return ERROR;	//ע:�˴�δ�ͷ�֮ǰ������ڵ㣬��Ϊ��δ��������ͷţ��ͽ�������ϵͳ���ͷ�
		if (i == 0)
			*head = p; //headָ���1�����
		else
			q->next = p;
		cout << "�������" << i + 1 << "���˵Ļ�����Ϣ" << endl;
		cin >> p->name >> p->num >> p->sex; //�������������Ϣ
		p->next = NULL;
	}
	return OK;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int linklist_traverse(student *head)
{
	student *p;

	p = head; //p��λ��ָ���1�����
	while (p != NULL) { //ѭ���������
		cout << p->name << " " << p->num << " " << p->sex << endl;
		p = p->next;
	}
	return OK;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int linklist_destroy(student *head)
{
	student *p, *q;

	p = head; //p��λ��ָ���1�����
	while (p) {  //ѭ�����и�����ͷ�
		q = p->next;
		delete p;
		p = q;
	}
	return OK;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	student *head = NULL;

	if (linklist_create(&head) == OK) {
		linklist_traverse(head);
		linklist_destroy(head);
	}
	else
		cout << "LinkList Create failed." << endl;

	return 0;
}
