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

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	student *head = NULL, *p = NULL, *q = NULL;
	int i;

	for (i = 0; i < 5; i++) {
		if (i > 0)
			q = p;
		p = new(nothrow) student; //˼����Ϊʲô������malloc
		if (p == NULL)
			return -1;	//ע:ע:�˴�δ�ͷ�֮ǰ������ڵ㣬�ͽ�������ϵͳ���ͷţ��Ǳ��÷���
		if (i == 0)
			head = p; //headָ���1�����
		else
			q->next = p;
		cout << "�������" << i + 1 << "���˵Ļ�����Ϣ" << endl;
		cin >> p->name >> p->num >> p->sex; //�������������Ϣ
		p->next = NULL;
	}

	p = head; //p��λ��ָ���1�����
	while (p != NULL) { //ѭ���������
		cout << p->name << " " << p->num << " " << p->sex << endl;
		p = p->next;
	}

	p = head; //p��λ��ָ���1�����
	while (p) {  //ѭ�����и�����ͷ�
		q = p->next;
		delete p;
		p = q;
	}

	return 0;
}
