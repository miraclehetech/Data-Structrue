#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<map>
#include<string>
#include<stack>
#include<iostream>
#include<iomanip>
using namespace std;

void binary_search(int number, int sequence[],int temp,int signal)
{
    if (signal == 0)
    {
        int low = 0, high = number - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (temp == sequence[mid])
            {
                while (mid-1>=0&&sequence[mid - 1] == temp)
                {
                    mid = mid - 1;
                }
                cout << mid << endl;
                break;
            }
            if (temp < sequence[mid])
                high = mid - 1;
            else
                low = mid + 1;
 

        }
        if (low > high)
            cout << -1 << endl;
    }
    else
    {
        int low = 0, high = number - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (temp == sequence[mid])
            {
                while (sequence[mid + 1] == temp&&mid+1<=number-1)
                {
                    mid = mid + 1;
                }
                cout << mid << endl;
                break;
            }
            if (temp < sequence[mid])
                high = mid - 1;
            else
                low = mid + 1;

        }
        if (low > high)
            cout << -1 << endl;
    }
}
int main()
{
    int number;
    int* sequence = NULL;
    cin >> number;
    sequence = new int[number];
    for (int i = 0; i < number; i++)
    {
        cin >> sequence[i];
    }
    while (1)
    {
        char str[100];
        cin >> str;
        if (strcmp(str, "lower") == 0)
        { 
            int temp;
            cin >> temp;
            binary_search(number, sequence, temp,0);
        }
        else if (strcmp(str, "upper") == 0)
        {
            int temp;
            cin >> temp;
            binary_search(number, sequence, temp, 1);
        }
        else
            break;
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
