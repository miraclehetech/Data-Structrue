#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
bool judge(int p)
{
    if (p == 1)
        return 1;
    if (p == 2)
        return 0;
    for (int i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0)
            return 1;
        else
            ;
    } 
    return 0;

}
int hash_map(char *name,int p)
{
    long long sum = 0;
    for (int i = 0; i < (int)strlen(name)-1; i++)
    {
        sum += name[i];
        sum %= p;
        sum *= 37;
        sum %= p;
    }
    sum += name[strlen(name) - 1];
    sum %= p;
    return sum;
}
int main()
{
    int n,result;
    long p;
    char* temp;
    temp = new char[100000];
    cin >> n >> p;
    while (judge(p))
    {
        p++;
    }
    int* list = new(nothrow)int[p];
    memset(list, 0, p * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        result = hash_map(temp,p);
        if (list[result] == 0)
        {
            list[result] = 1;
            cout << result << " ";
        }
        else
        {
            bool signal = 0;
            int temp = result;
            for (int i = 1; i <= p/2; i++)
            {
                result = (temp + i * i) % p;
                if (list[result] == 0)
                {
                    list[result] = 1;
                    signal = 1;
                    cout << result << " ";
                    break;
                }
                result = (temp - i * i) % p;
                result = (result + p) % p;
                if (list[result] == 0)
                {
                    list[result] = 1;
                    signal = 1;
                    cout << result << " ";
                    break;
                }
            }
            if (signal == 0)
                cout << '-' << " ";
        }
    }
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
