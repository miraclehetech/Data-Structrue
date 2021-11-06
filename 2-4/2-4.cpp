/*1950095 大数据 何正潇*/
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
	QNode* front;   //队首指针
	QNode* rear;    //队尾指针
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
					QElemtype change_x[4] = { 0,0,-1,1 };  //表示上下左右的坐标
					QElemtype change_y[4] = { -1,1,0,0 };
					Dequene(Q, x, y);
					for (int k = 0; k < 4; k++) {
						if (x + change_x[k]  < 0 || x + change_x[k] >= m ||y + change_y[k] < 0 ||y + change_y[k] >= n)   //超过边界则跳过
							continue;
						if (visited[x + change_x[k]][y + change_y[k]] ==1|| data[x + change_x[k]][y + change_y[k]] == 0)  //已经标记过或者当前数据不是1则跳过
							continue;
						visited[x+change_x[k]][y + change_y[k]] = 1;
						Enquene(Q, x + change_x[k], y + change_y[k]);   //如果为1则把当前坐标加入队列
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
