#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
typedef struct BitNode
{
    char data;
    BitNode* lchild, * rchild;
    int Ltag , Rtag ;
}*BiTree, BitNode;
int  CreateBiTree(BiTree& T)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') T = NULL;
    else {
        if (!(T = (BitNode*)malloc(sizeof(BitNode))))
            return -1;
        T->data = ch;
        T->Ltag = T->Rtag = 0;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 0;
}
void InorderBitree(BiTree& T)
{
    if (T == NULL)
        return;
    InorderBitree(T->lchild);
    cout << T->data;
    InorderBitree(T->rchild);
}
void inorder_th(BiTree p, BiTree& pre)
{
    if (p)
    {
        inorder_th(p->lchild, pre);
        if (!p->lchild)
        {
            p->Ltag = 1;
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->Rtag = 1;
            pre->rchild = p;
        }
        pre = p;
        inorder_th(p->rchild, pre);
    }
}
void Inorder(BiTree& Thrt, BiTree T)
{
    Thrt = new BitNode;
    Thrt->Ltag = 0, Thrt->Rtag = 1;
    Thrt->rchild = Thrt;
    if (!T)
        Thrt->lchild = Thrt;
    else
    {
        Thrt->lchild = T;
        BiTree pre = Thrt;
        inorder_th(T,pre);
        pre->rchild = Thrt, pre->Rtag = 1;
        Thrt->rchild = pre;
    }
}
void show_pre(BiTree p,bool&judge, BiTree Thrt)
{
    if (p->Ltag == 0) {
        p = p->lchild;
        while (p->Rtag == 0)
            p = p->rchild;
        if (p == NULL)
            cout << "prev is NULL" << endl;
        else if (p!=Thrt)
            cout << "prev is " << p->data << p->Ltag << endl;
        else
            cout << "prev is NULL" << endl;
    }
    else {
        if (p->lchild == NULL)
            cout << "prev is NULL" << endl;
        else if (p->lchild!=Thrt)
            cout << "prev is " << p->lchild->data << p->lchild->Ltag << endl;
        else
            cout << "prev is NULL" << endl;
    }
    judge = 1;
}
void show_post(BiTree p, BiTree Thrt)
{
    if (p->Rtag == 0) {
        p = p->rchild;
        while (p->Ltag == 0)
            p = p->lchild;
        if (p == NULL)
            cout << "succ is NULL" << endl;
        else if (p!=Thrt)
            cout << "succ is " << p->data << p->Rtag << endl;
        else
            cout << "succ is NULL" << endl;
    }
    else {
        if (p->rchild == NULL)
            cout << "succ is NULL" << endl;
        else if (p->rchild!=Thrt)
            cout << "succ is " << p->rchild->data << p->rchild->Rtag << endl;
        else
            cout << "succ is NULL" << endl;
    }
}
void InorderTraverse_Thr(BiTree T,char a)
{
    bool judge = 0;
    BiTree p = T->lchild;
    while (p != T)
    {
        while (p->Ltag == 0)
        {
            p = p->lchild;
        }
        if (p->data == a)
        {
            show_post(p,T);
            show_pre(p, judge,T);
        }
        while (p->Rtag == 1 && p->rchild != T)
        {
            p = p->rchild;
            if (p->data == a)
            {
                show_post(p,T);
                show_pre(p, judge,T);
           
            }
        }
        p = p->rchild;
    }
    if (judge == 0)
        cout << "Not found" << endl;
}
int main()
{
    BiTree a,b;
    CreateBiTree(a);
    InorderBitree(a);
    cout << endl;
    char target;
    cin >> target;
    Inorder(b, a);
    InorderTraverse_Thr(b, target);
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
