#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
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
    char ver;
    edgeNode* head;
    verNode(edgeNode* h = NULL)
    {
        head = h;
    }
};
using namespace std;
int main()
{
    verNode* list=NULL;
    int choice;
    int m, n;
    int** matrix;
    char* point;
    cin >> choice;
    cin >> m >> n;
    matrix = new int* [m];
    for(int i=0;i<m;i++)
         matrix[i]= new int[m];
    point = new char[m];
    list = new verNode[m];
    for(int i=0;i<m;i++)
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 0;
        }
    switch (choice)
    {
        case 1:
            for (int i = 0; i < m; i++)
            {
                cin >> point[i];
                list[i].ver = point[i];
            }
            for (int i = 0; i < n; i++)
            {
                char temp1, temp2;
                cin >> temp1 >> temp2;
                int sign1, sign2;
                for (int j = 0; j < m; j++)
                {
                    if (point[j] == temp1)
                        sign1 = j;
                    if (point[j] == temp2)
                        sign2 = j;
                }
                matrix[sign1][sign2] = 1;
                list[sign1].head = new edgeNode(sign2, 1, list[sign1].head);

            }
            break;
        case 2:
            for (int i = 0; i < m; i++)
            {
                cin >> point[i];
                list[i].ver = point[i];
            }
            for (int i = 0; i < n; i++)
            {
                char temp1, temp2;
                int weight = 0;
                cin >> temp1 >> temp2>>weight;
                int sign1, sign2;
                for (int j = 0; j < m; j++)
                {
                    if (point[j] == temp1)
                        sign1 = j;
                    if (point[j] == temp2)
                        sign2 = j;
                }
                matrix[sign1][sign2] = weight;
                list[sign1].head = new edgeNode(sign2, weight, list[sign1].head);

            }
            break;
        case 3:
            for (int i = 0; i < m; i++)
            {
                cin >> point[i];
                list[i].ver = point[i];
            }
            for (int i = 0; i < n; i++)
            {
                char temp1, temp2;
                cin >> temp1 >> temp2;
                int sign1, sign2;
                for (int j = 0; j < m; j++)
                {
                    if (point[j] == temp1)
                        sign1 = j;
                    if (point[j] == temp2)
                        sign2 = j;
                }
                matrix[sign1][sign2] = 1;
                matrix[sign2][sign1] = 1;
                list[sign1].head = new edgeNode(sign2, 1, list[sign1].head);
                list[sign2].head = new edgeNode(sign1, 1, list[sign2].head);

            }
            break;
        case 4:
            for (int i = 0; i < m; i++)
            {
                cin >> point[i];
                list[i].ver = point[i];
            }
            for (int i = 0; i < n; i++)
            {
                char temp1, temp2;
                int weight = 0;
                cin >> temp1 >> temp2 >> weight;
                int sign1, sign2;
                for (int j = 0; j < m; j++)
                {
                    if (point[j] == temp1)
                        sign1 = j;
                    if (point[j] == temp2)
                        sign2 = j;
                }
                matrix[sign1][sign2] = weight;
                matrix[sign2][sign1] = weight;
                list[sign1].head = new edgeNode(sign2, weight, list[sign1].head);
                list[sign2].head = new edgeNode(sign1, weight, list[sign2].head);
            }
            break;
    }
    for (int i = 0; i < m; i++)
        cout << point[i] << ' ';
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        edgeNode* n = list[i].head;
        cout << list[i].ver << "-->";
        while (n != NULL)
        {
            if (choice == 1 || choice == 3)
            {
                cout << n->end << " ";
            }
            else
            {
                cout << n->end <<","<<n->weight<<" ";
            }
            n = n->next;
        }
        cout << endl;
    }

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
