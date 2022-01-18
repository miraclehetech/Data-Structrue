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

int main()
{
    verNode* list = NULL;
    int m, n,current;
    int count = 0;
    queue<int>a;
    stack<int>b;
    cin >> m >> n;
    int* ee = new(nothrow) int[m];
    if (ee == NULL)
        return -1;
    int* le = new(nothrow) int[m];
    if (le == NULL)
        return -1;
    for (int i = 0; i < m; i++)
        ee[i] = 0;
    list = new(nothrow) verNode[m];
    int count2=0;
    int* topo= new(nothrow)int[m];
    if (topo == NULL)
        return -1;
    for (int i = 0; i < m; i++)
        topo[i] = 0;
    int* degree = new (nothrow) int[m];
    if (degree == NULL)
        return -1;
    for (int i = 0; i < m; i++)
        degree[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int temp1, temp2;
        int weight = 0;
        cin >> temp1 >> temp2 >> weight;
        list[temp1 - 1].head = new edgeNode(temp2 - 1, weight, list[temp1 - 1].head);
    }
    for (int i = 0; i < m; i++)
    {
        for (edgeNode* temp = list[i].head; temp != NULL; temp = temp->next)
            degree[temp->end]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (degree[i] == 0)
            a.push(i);

    }
    while (!a.empty())
    {
        current = a.front();
        b.push(current);
        topo[count] =current;
        count++;
        for (edgeNode* temp = list[current].head; temp != NULL; temp = temp->next)
            if (ee[current] + temp->weight >= ee[temp->end])
                ee[temp->end] = ee[current] + temp->weight;
        a.pop();
        for (edgeNode* temp = list[current].head; temp != NULL; temp = temp->next)
            if (--degree[temp->end] == 0)
                a.push(temp->end);
    }
    delete[]degree;
    if (count != m)
    {
        cout << "0" << endl;
        return 0;
    }
    cout << "point:";
    /*for (int i = 0; i < m; i++)
    {
        for (edgeNode* temp = list[topo[i]].head; temp != NULL; temp = temp->next)
            if (ee[topo[i]] + temp->weight >= ee[temp->end])
                ee[temp->end] = ee[topo[i]] + temp->weight;
    }*/
    for (int i = 0; i < m; i++)
    {
        cout << topo[i] << " ";
    }
    cout << endl;
    int max = 0;
    int test = 0;
    for (int i = 0; i < m; i++)
        if (ee[i] >= max)
        {
            max = ee[i];
            test = i;
        }
    //cout << max << endl;
    for (int i = 0; i < m; i++)
    	{
    		le[i] = max;
    		test=i;
		}
	cout<<"topo"<<" ";
    cout<<test<<endl;
    while(!b.empty())
    {
        current = b.top();
        b.pop();
        for (edgeNode* temp = list[current].head; temp != NULL; temp = temp->next)
            if (le[temp->end] - temp->weight <= le[current])
                le[current] = le[temp->end] - temp->weight;
    }
    /*for (int i = 0; i < m; i++)
        if (le[topo[i]] == ee[topo[i]])
        {
            count2++;
        }*/
    /*int* result = new int[count2];
    int signal2 = 0;
    for (int i = 0; i < m; i++)
    {
        if (le[topo[i]] == ee[topo[i]])
        {
            result[signal2] = topo[i];
            signal2++;
        }
    }*/
  /*  int** mat;
    mat = new int* [m - 1];*/
    ////for (int i = 0; i < m; i++) {
    ////    for (edgeNode* p =list[i].head; p!=NULL; p = p->next) {
    ////        int k = p->end;
    ////        if (ee[i] + p->weight == le[k])
    ////            cout << i + 1 << "->" << k + 1 << endl;
    ////    }
    ////}
    //for (int i = 0; i < m; i++)
    //     mat[i] = new int[2];
    //for (int i = 0; i < signal2-1; i++)
    //{
    //    mat[i][0] = result[i];
    //    mat[i][1] = result[i + 1];
    //}
    //for(int i=0;i<signal2-2;i++)
    //    for (int j = 0; j < signal2-i-2; j++)
    //    {
    //        if (mat[j][0] >= mat[j + 1][0])
    //        {
    //            if (mat[j][0] > mat[j + 1][0])
    //            {
    //                int temp1 = mat[j][0], temp2 = mat[j][1];
    //                mat[j][0] = mat[j + 1][0], mat[j][1] = mat[j + 1][1];
    //                mat[j + 1][0] = temp1, mat[j + 1][1] = temp2;
    //            }
    //            else
    //            {
    //                if(mat[j][1]>mat[j+1][1])
    //                {
    //                    int temp1 = mat[j][0], temp2 = mat[j][1];
    //                    mat[j][0] = mat[j + 1][0], mat[j][1] = mat[j + 1][1];
    //                    mat[j + 1][0] = temp1, mat[j + 1][1] = temp2;
    //                }
    //            }
    //        }
    //     
    //    }
    //for (int i = 0; i < count2-1; i++)
    //{
    //    cout << mat[i][0]+1 << "->" << mat[i][1]+1<<endl;
    //}
    //��һ����������ʱ��
    cout<<"ee:"; 
    for (int i = 0; i < m; i++)
    {
        cout << ee[i] << " ";

    }
    cout << endl;
    cout<<"le:";
    for (int i = 0; i < m; i++)
    {
        cout << le[i] << " ";

    }
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
