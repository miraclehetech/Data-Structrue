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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
