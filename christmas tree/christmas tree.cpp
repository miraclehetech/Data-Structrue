#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
#include<queue>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
using namespace std;
vector<pair<int, int>>a;
int times = 0;
void dfs(int i, bool mat[][7])
{
	for (int p = 1; p <= 5; p++)
	{
		if (mat[i][p] == true)
		{
			mat[i][p] = mat[p][i] = false;
			a.push_back(pair<int, int>(i, p));
			dfs(p, mat);
		}

	}
		if (a.size() == 8)
		{
			for (int nIndex = 0; nIndex < (int)a.size(); nIndex++)
			{
				cout << a[nIndex].first << "->" << a[nIndex].second<<" ";
			}
			cout << endl;
			times++;
		}
		 if (!a.empty())
		{
			pair<int, int> temp;
			temp = a[a.size() - 1];
			mat[temp.first][temp.second] = mat[temp.second][temp.first] = 1;
			a.pop_back();
		}

}
int main()
{
	bool mat[7][7];
	bool visited[6] = { false };
	memset(mat, 1, 7 * 7 );
	mat[1][1] = mat[2][2] = mat[3][3] = mat[4][4] = mat[5][5] = mat[1][4] = mat[4][1] = mat[2][4] = (mat[4][2] = 0);
	dfs(1, mat);
	cout << "总共有几条路子" << times << endl;
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
