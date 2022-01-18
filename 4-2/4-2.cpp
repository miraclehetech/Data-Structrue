#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;
void dfs(int** matrix, bool* visited,int number,const int m,int depth)
{
    if (depth == 0)
        cout << number;
    else
        cout << " " << number;
    visited[number] = true;
    for (int i = 0; i < m; i++)
    {
        if (matrix[number][i] != 0)
        {
            if (visited[i] == false)
                dfs(matrix, visited, i, m,depth+1);
            else
                continue;
        }
    }
}
void bfs(int** matrix, bool* visited,  const int m)
{
    queue<int>a;
    for (int i = 0; i < m; i++)
    {
        if (visited[i] == true)
            continue;
        cout << "{";
        a.push(i);
        int num = 0;
        while (!a.empty())
        {
            int current = a.front();
            a.pop();
            if (visited[current] == true)
            {
                continue;
            }
          //  cout << current << " ";
            visited[current] = 1;
            for(int i=0;i<m;i++)
                if (matrix[current][i] != 0)
                {
                    if (visited[i] == false)
                    {
                        a.push(i);
                    }
                    
                }
          //  if (!a.empty())
            if(num!=0)
            cout << " " << current;
           if(num==0)
            cout << current;
           num++;
            //else
               // cout << current;
        }
        cout << "}";
    }
   
}
int main()
{

    int m, n;
    int** matrix;
    char* point;
    cin >> m >> n;
    bool* visited = new bool[m];
    for (int i = 0; i < m; i++)
    {
        visited[i] = false;
    }
    matrix = new int* [m];
    for (int i = 0; i < m; i++)
        matrix[i] = new int[m];
    point = new char[m];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        matrix[temp1][temp2] = 1;
        matrix[temp2][temp1] = 1;

    }
    for (int i = 0; i < m; i++)
    {
        if (visited[i] == true)
            continue;
        else
        {
            cout << "{";
            dfs(matrix, visited,  i, m,0);
            cout << "}";
        }
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        visited[i] = false;
    }
    bfs(matrix, visited, m);
    cout << endl;
    return 0;
}