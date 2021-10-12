/*1950095 大数据 何正潇*/
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>  
#include <string>  
using std::string; 
#include <iostream>
#define num 60000
using namespace std;
struct student
{
    char name[60] = { 0 };
    char id[60] = { 0 };
};
int insert( struct student(&p)[num], int n,int &number)
{
    if (n > number+1 || n <= 0)
        return -1;
    else
    {
        for (int i = number + 1; i >= n + 1; i--)
        {
            p[i]=p[i-1];
        }
        cin >> p[n].id >> p[n].name;
        number++;
        return 0;
    }
}
int remove(struct student(&p)[num], int n, int &number)
{
    if (n > number || n <= 0)
        return -1;
    else
    {
        for (int i = n + 1; i <= number; i++)
        {
            p[i-1]=p[i];
        }
       strcpy( p[number].id ," "),strcpy( p[number].name , "");
        number--;
        return 0;
    }

}
int checkname(struct student(&p)[num], int& number,char name[60])
{
    for (int i = 1; i < number + 1; i++)
    {
        if (!strcmp(p[i].name, name))
        {
            cout << i << " " << p[i].id << " " << p[i].name;
            cout << endl;
            return 1;
        }
    }
    cout << -1 << endl;
    return 0;
}
int check_no(struct student(&p)[num] ,int& number, char id[60])
{
    for (int i = 1; i < number + 1; i++)
    {
        if (!strcmp(p[i].id, id))
        {
            cout << i << " " << p[i].id << " " << p[i].name;
            cout << endl;
            return 1;
        }
    }
    cout << -1 << endl;
    return 0;
}
struct student p[num];
int main()
{
   char orders[60];
   int number;
   scanf("%d", &number);
   for (int i = 1; i <= number; i++)
   {
       cin >> p[i].id >> p[i].name;
   }
   while (1)
   {
       cin >> orders;
       if (!strcmp(orders, "insert"))
       {
           int n;
           scanf("%d", &n);
           cout<<insert(p, n, number)<<endl;
       }
       else if (!strcmp(orders, "remove"))
       {
           int n;
           scanf("%d", &n);
           cout<<remove(p, n, number)<<endl;

       }
       else if(!strcmp(orders,"check"))
       {
           char orders_[60];
           scanf("%s", &orders_);
           if (!strcmp(orders_, "name"))
           {
               char name[60];
               scanf("%s", &name);
               checkname(p, number, name);
           }
           else if (!strcmp(orders_, "no"))
           {
              char id[60];
              scanf("%s", &id);
               check_no(p, number, id);
           }
           else
           {
               continue;
           }
       }
       else if (!strcmp(orders, "end"))
       {
           cout << number << endl;
           break;
       }
       else
       {
           continue;
       }
   }
   return 0;
}


