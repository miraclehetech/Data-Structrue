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
    if (T == NULL)//���������Ϊ��ֱ�ӷ��ؽ���������ͬ
        return;
    else
    {
        cout << T->data;  //��������ڵ���Ǹ�����
        preorder(T->lchild);          //Ȼ��������ӣ���ʼ�ݹ�
        preorder(T->rchild);          //���ӷ�����ɣ���ʼ�Һ��ӵݹ�
    }
}
void postorder(BiTree& T)
{
    if (T == NULL)
        return;
    else
    {
        postorder(T->lchild);          //Ȼ��������ӣ���ʼ�ݹ�
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
void LevelOrderTraverse(BiTree T)//��α���
{
    BiTree p;  
    queue<BiTree> Q;
    if (!T) return;
    Q.push(T);//���
    while (!Q.empty()) {
        p = Q.front(); Q.pop();//����
        printf("%c", p->data);
        if (p->lchild)
            Q.push(p->lchild); //���
        if (p->rchild)
            Q.push(p->rchild);//���
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
