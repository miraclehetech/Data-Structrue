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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
