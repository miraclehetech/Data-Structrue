/*1950095 ������ ������*/
#include <iostream>
#include <cstring>
using namespace std;
typedef int QElemtype;
typedef int Status;
typedef struct Node {
	QElemtype x;
	QElemtype y;
	struct Node* next;
}QNode;

typedef struct Queue {
	QNode* front;   //����ָ��
	QNode* rear;    //��βָ��
}LinkQueue;
Status InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	if (Q.front == NULL)
		return -1;
	Q.front->next = NULL;
	return 0;
}
Status DestroyQuene(LinkQueue& Q)
{
	while(Q.front)
	{
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
	return 0;
	
}
Status Enquene(LinkQueue& Q, QElemtype x,QElemtype y)
{
	QNode*p = (QNode*)malloc(sizeof(QNode));
	if (p == NULL)
		return -1;
	p->x = x;
	p->y = y;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return 0;

}
Status Dequene(LinkQueue& Q,QElemtype& x,QElemtype& y)
{
	if (Q.front == Q.rear)
		return -1;
	QNode* p = Q.front->next;
	Q.front->next = p->next;
	x = p->x, y = p->y;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return 0;
}
void BFS(LinkQueue& Q, int **data, int** visited,int m, int n)
{
	int num = 0;
	QElemtype x, y;
	for (int i=1;i<m-1;i++)
		for (int j = 1; j < n-1; j++)
		{
			if (data[i][j] == 1 && visited[i][j] == 0)
			{
				Enquene(Q, i, j);
				visited[i][j] = 1;
				while (Q.front != Q.rear)
				{
					QElemtype change_x[4] = { 0,0,-1,1 };  //��ʾ�������ҵ�����
					QElemtype change_y[4] = { -1,1,0,0 };
					Dequene(Q, x, y);
					for (int k = 0; k < 4; k++) {
						if (x + change_x[k]  < 0 || x + change_x[k] >= m ||y + change_y[k] < 0 ||y + change_y[k] >= n)   //�����߽�������
							continue;
						if (visited[x + change_x[k]][y + change_y[k]] ==1|| data[x + change_x[k]][y + change_y[k]] == 0)  //�Ѿ���ǹ����ߵ�ǰ���ݲ���1������
							continue;
						visited[x+change_x[k]][y + change_y[k]] = 1;
						Enquene(Q, x + change_x[k], y + change_y[k]);   //���Ϊ1��ѵ�ǰ����������
					}
					
				}
				num++;
			}
			
		}
	cout << num;
}
int main()
{
	LinkQueue a;
	InitQueue(a);
	int m, n;
	cin >> m >> n;
	int** data, ** visited;
	data = new int* [m];
	visited = new int* [m];
	for (int i = 0; i < m; i++)
	{
		visited[i] = new int[n];
		data[i] = new int[n];
	}
	for (int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			cin >> data[i][j];
			visited[i][j] = 0;
		}
	
	BFS(a, data, visited, m, n);
	DestroyQuene(a);
	for (int i = 0; i < m; i++)
	{
		delete[]visited[i];
		delete[]data[i];
	}
	delete[]data;
	delete[]visited;
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
