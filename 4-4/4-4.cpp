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
struct length
{
    int distance, position;
};
bool operator<(const length& v1, const length& v2) {
    return v1.distance > v2.distance;
}
int* Dijkstra(int start, int Noedge, int vertex, verNode* list)
{
    priority_queue< length> p;
    int* distance = new int[vertex];
    int* prev = new int[vertex];
    bool* known = new bool[vertex];
    int min = Noedge;
    int u;
    for (int i = 0; i < vertex; i++)
    {
        known[i] = false;
        if (i != start - 1)
            distance[i] = Noedge;
        else
        {
            distance[i] = 0;
            length temp;
            temp.distance = distance[i], temp.position = i;
            p.push(temp);
        }
   
    }
    prev[start-1] = start-1;
    distance[start-1] = 0;
    while (!p.empty() )
    {
        if (known[p.top().position] == false)
        {
            min = p.top().distance;
            u = p.top().position;
        }
        p.pop();
        known[u] = true;
        for (edgeNode* temp = list[u].head; temp != NULL; temp = temp->next)
        {
            if (!known[temp->end] && distance[temp->end] > min + temp->weight)
            {
                distance[temp->end] = min + temp->weight;
                length temp1;
                temp1.distance = distance[temp->end], temp1.position = temp->end;
                if (known[temp1.position] == false)
                    p.push(temp1);
                prev[temp->end] = u;
            }
        }
    }
    return distance;

}
int main()
{
   // priority_queue<length, vector<length>, greater<length> > p;
    verNode* list = NULL;
    int m, n,s;
    cin >> m >> n>>s;
    list = new verNode[m];
    int* distance;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        int weight = 0;
        cin >> temp1 >> temp2 >> weight;
        list[temp1-1].head = new edgeNode(temp2-1, weight, list[temp1-1].head);
        list[temp2 - 1].head = new edgeNode(temp1 - 1, weight, list[temp2 - 1].head);

    }
    distance=Dijkstra(s, INT_MAX, m, list);
    for (int i = 0; i < m; i++)
    {
        cout << distance[i] << " ";
    }
    return 0;
}