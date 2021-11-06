#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <queue>
typedef struct BitNode
{
    char data;
    BitNode* lchild, * rchild;
}*BiTree,BitNode;
int  CreateBiTree(BiTree& T)
{
    char ch;	
    scanf("%c", &ch);
    if (ch == '#') T = NULL;
    else {
        if (!(T = (BitNode*)malloc(sizeof(BitNode))))
            return -1;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 0;
}
void preorder(BiTree& T)
{
    if (T == NULL)//如果二叉树为空直接返回结束程序，下同
        return;
    else
    {
        cout << T->data;  //先输出根节点的那个数字
        preorder(T->lchild);          //然后访问左孩子，开始递归
        preorder(T->rchild);          //左孩子访问完成，开始右孩子递归
    }
}
void postorder(BiTree& T)
{
    if (T == NULL)
        return;
    else
    {
        postorder(T->lchild);          //然后访问左孩子，开始递归
        postorder(T->rchild);
        cout << T->data ;
    }
}
void inorder(BiTree& T)
{
    if (T == NULL)
        return;
    else
    {
        inorder(T->lchild);
        cout << T->data;
        inorder(T->rchild);
       
    }

}
void PrintBiTree(BiTree T, int n)
{
    int i;  char ch = ' ';
    if (T) {
        PrintBiTree(T->rchild, n + 1);
        for (i = 1; i <= n; ++i) { printf("%5c", ch); }
        printf("%c\n", T->data);
        PrintBiTree(T->lchild, n + 1);
    }
}
void LevelOrderTraverse(BiTree T)//层次遍历
{
    BiTree p;  
    queue<BiTree> Q;
    if (!T) return;
    Q.push(T);//入队
    while (!Q.empty()) {
        p = Q.front(); Q.pop();//出队
        printf("%c", p->data);
        if (p->lchild)
            Q.push(p->lchild); //入队
        if (p->rchild)
            Q.push(p->rchild);//入队
    } //while
}


int main()
{
    char* input = new char[100000];
    if (input == NULL)
        return -1;
    BiTree a;
    CreateBiTree(a);
    preorder(a);
    cout << endl;
    inorder(a);
    cout << endl;
    postorder(a);
    cout << endl;
    LevelOrderTraverse(a);
    cout << endl;
    PrintBiTree(a, 0);
    cout << endl;
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
