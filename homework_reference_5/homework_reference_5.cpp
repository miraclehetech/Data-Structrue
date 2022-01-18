#include <iostream>
#include <vector>	
#include <queue>
using namespace std;


#define MAX_VERTEX_NUM 2000
typedef int VertexType;
typedef struct {
	vector<int> vexs[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}ALGraph;


//创建邻接表
void CreateALGraph_adjlist(ALGraph& G)
{
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.arcnum; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		//无向图
		G.vexs[v1 - 1].push_back(v2 - 1);
		G.vexs[v2 - 1].push_back(v1 - 1);
	}
}
//广度优先搜索求出与顶点v距离不大于6的结点个数
int BFS(ALGraph G, VertexType v)
{
	bool visit[MAX_VERTEX_NUM];  // 标记数组，如果已经访问过，说明已经有最短路径了
	for (int i = 0; i < G.vexnum; i++)
		visit[i] = false;
	queue<VertexType> q;
	int level = 0;
	visit[v] = true;
	q.push(v);
	int count = 1;  // 统计关系数，自己跟自己也算 
	int last = v;  // 该层最后一次访问的结点(邻接表每行最后一个位置) 
	int tail = v;  // 每次在变的结点,指向每次遍历的最后一个结点
	while (!q.empty())
	{
		VertexType tmp = q.front();
		q.pop();
		//遍历顶点tmp指向的边，只要未被访问过就说明此时距离仍未达到count++
		for (int i = 0; i < (int)G.vexs[tmp].size(); i++) {
			if (!visit[G.vexs[tmp][i]]) {
				visit[G.vexs[tmp][i]] = true;
				q.push(G.vexs[tmp][i]);
				tail = G.vexs[tmp][i];
				count++;
			}
		}
		// 如果已经遍历完所有边对应的顶点了即该当前结点是这层最后一个结点 
		if (tmp == last) {
			level++;    // 层数 +1  
			last = tail;   // 更改 last 
		}
		// 层数够了结束 
		if (level == 6)
			break;
	}
	return count;
}


int main()
{
	ALGraph G;
	CreateALGraph_adjlist(G);
	int count;
	for (int i = 0; i < G.vexnum; i++) {
		count = BFS(G, i);
		printf("%d: %.2f%%\n", i + 1, float(count * 100.0 / G.vexnum + 0.004));
	}
	return 0;
}
