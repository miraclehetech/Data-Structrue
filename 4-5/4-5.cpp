#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
#include<queue>
#include <climits>
using namespace std;
struct edgeNode
{
	int end;
	int weight;
	edgeNode* next;
	edgeNode(int e, int w, edgeNode* n = NULL)
	{
		end = e;
		weight = w;
		next = n;
	}
};
struct verNode
{

	edgeNode* head;
	verNode(edgeNode* h = NULL)
	{
		head = h;
	}
};
int Bfs(verNode* list, int i, bool* judge, int m)
{
	queue<int>a;
	int count = 0;
	int layer = 0;
	judge[i] = true;
	a.push(i);
	int record1 = 1;
	int signal;
	while (layer <= 6)
	{
		signal = 0;
		for (int i = 0; i < record1; i++)
		{
			int current = a.front();
			a.pop();
			for (edgeNode* temp = list[current].head; temp != NULL; temp = temp->next)
			{
				if (judge[temp->end] == false)
				{
					a.push(temp->end);
					judge[temp->end] = true;
					signal = signal + 1;
				}
			}
		}
		record1 = signal;
		layer++;
	}
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		if (judge[i] == true)
			result++;
	}
	return result;

}
void refresh(bool* judge,int m)
{
	for (int i = 0; i < m; i++)
	{
		judge[i] = false;
	}
}
int main()
{
	verNode* list = NULL;
	bool* judge = NULL;
	int m, n;
	int count = 0;
	queue<int>a;
	stack<int>b;
	cin >> m >> n;
	judge = new(nothrow) bool[m];
	list = new(nothrow) verNode[m];
	for (int i = 0; i < m; i++)
		judge[i] = false;
	for (int i = 0; i < n; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;
		list[temp2 - 1].head = new edgeNode(temp1 - 1, 1, list[temp2 - 1].head);
		list[temp1 - 1].head = new edgeNode(temp2 - 1, 1, list[temp1 - 1].head);

	}
	for (int i = 0; i < m; i++)
	{
		refresh(judge, m);
		int result = Bfs(list, i, judge, m);
		printf("%d: %.2f%%\n", i + 1, float((float)result * 100.0 / m ));
	}
}
