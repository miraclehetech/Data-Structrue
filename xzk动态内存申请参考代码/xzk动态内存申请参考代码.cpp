#include <iostream>
using namespace std;

typedef int QElemtype;

typedef struct Node {
	QElemtype x;
	QElemtype y;
	struct Node* next;
}QNode;

typedef struct Queue {
	QNode* front;   //队首指针
	QNode* rear;    //队尾指针
}LinkQueue;

//初始化队列
void InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = new (nothrow) QNode;
	if (Q.front == NULL)
		return;
	Q.front->next = NULL;	//带头结点
}

//销毁队列
void DestroyQueue(LinkQueue& Q)
{
	while (Q.front) {
		Q.rear = Q.front->next;
		delete Q.front;
		Q.front = Q.rear;
	}
}

//入队列
void EnQueue(LinkQueue& Q, QElemtype x, QElemtype y)
{
	QNode* p = new(nothrow)QNode;
	if (!p)
		return;
	p->x = x;
	p->y = y;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
}

//出队列
void DeQueue(LinkQueue& Q, QElemtype& x, QElemtype& y)
{
	if (Q.front == Q.rear)
		return;
	QNode* tmp;
	tmp = Q.front->next;
	x = tmp->x;
	y = tmp->y;
	Q.front->next = tmp->next;
	if (Q.rear == tmp)     //只有一个数据时，要改动队尾指针
		Q.rear = Q.front;
	delete tmp;
}

void bfs(int** data, int** visited, int n, int m)
{
	QElemtype dx[4] = { 0,0,-1,1 };  //表示上下左右的坐标
	QElemtype dy[4] = { -1,1,0,0 };
	LinkQueue LQueue;
	InitQueue(LQueue);  //初始化队列
	int sum = 0;  //记录区域数
	for (int i = 1; i < n - 1; i++) {  //从内部遍历，不遍历边缘，但搜索边缘
		for (int j = 1; j < m - 1; j++) {
			if (!visited[i][j] && data[i][j] == 1) {
				visited[i][j] = 1;
				EnQueue(LQueue, i, j);
				while (LQueue.rear != LQueue.front) {    //如果队列仍有元素，则继续搜索
					QElemtype tx, ty;
					DeQueue(LQueue, tx, ty);    //取出队首第一个元素，进行四领域遍历
					for (int k = 0; k < 4; k++) {
						if (tx + dx[k] < 0 || tx + dx[k] >= n || ty + dy[k] < 0 || ty + dy[k] >= m)   //超过边界则跳过
							continue;
						if (visited[tx + dx[k]][ty + dy[k]] || data[tx + dx[k]][ty + dy[k]] == 0)  //已经标记过或者当前数据不是1则跳过
							continue;
						visited[tx + dx[k]][ty + dy[k]] = 1;
						EnQueue(LQueue, tx + dx[k], ty + dy[k]);   //如果为1则把当前坐标加入队列
					}
				}
				++sum;
			}
		}
	}
	cout << sum << endl;
	DestroyQueue(LQueue);
}

int main()
{
	int n, m;
	cin >> n >> m;
	int** data, ** visited;
	//动态申请二维数组
	data = new int* [n];
	visited = new int* [n];
	for (int i = 0; i < n; i++) {
		data[i] = new int[m];
		visited[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> data[i][j];
			visited[i][j] = 0;   //标记数组，0表示未被标记
		}
	}

	//广度优先搜素
	bfs(data, visited, n, m);

	//释放二维数组内存
	for (int i = 0; i < n; i++) {
		delete[]data[i];
		delete[]visited[i];
	}
	delete[]data;
	delete[]visited;

	return 0;
}