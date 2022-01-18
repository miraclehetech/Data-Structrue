/*1950095 大数据 何正潇*/
#include <iostream>
#include <stack>
using namespace std;
typedef struct {
    int key;
}ElemType;
typedef struct BiTNode {
    ElemType data;
    struct BiTNode* lchild, * rchild;
    int count;
}BiTNode, * BiTree;

//插入一个整数 
void InsertBST(BiTree& T, BiTree S)
{
    BiTree p, q = NULL;
    if (!T)  
        T = S;
    else {
        p = T;
        while (p) {
            q = p;
            if (S->data.key == p->data.key) {
                p->count++;
                return;
            }
            else if (S->data.key < p->data.key)
                p = p->lchild;
            else
                p = p->rchild;
        }
        if (S->data.key < q->data.key)
            q->lchild = S;
        else
            q->rchild = S;
    }
}

//实现对p结点删除，并重接它的左右字数保持二叉树仍有序
bool Delete(BiTree& p)
{
    BiTree q, s;

    //删除时如果存在重复元素直接count--否则删除结点
    if (p->count > 1) {
        p->count--;
        return true;
    }
    if (!p->rchild) //右子树为空则只需重接它的左子树
    {
        q = p;
        p = p->lchild;
        delete q;
    }
    else if (!p->lchild) //只需重接它的右子树
    {
        q = p;
        p = p->rchild;
        delete q;
    }
    else //左右子树都不为空 
    {
        q = p;  //s的前驱结点
        s = p->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        } //转左，然后向右走到尽头
        p->data = s->data;
        p->count = s->count;
        if (q != p)
            q->rchild = s->lchild;
        else  //只是向左，并没有向右，因此s是q的左结点
            q->lchild = s->lchild;
        delete s;
    }
    return true;
}

bool DeleteBST(BiTree& T, int key)
{
    if (!T)   //不存在关键字等于key的数据元素
        return false;
    else {
        if (key == T->data.key)   //找到关键字等于key的数据元素
            return Delete(T);
        else if (key > T->data.key)
            return DeleteBST(T->rchild, key);
        else
            return DeleteBST(T->lchild, key);
    }
}
//查询最小值
int MinBST(BiTree T)
{
    BiTree p = T;
    while (p->lchild)
        p = p->lchild;
    return p->data.key;
}
//查询某个整数有多少个
int CountBST(BiTree T, int key)
{
    BiTree p = T;
    while (p) {
        if (key == p->data.key)
            return p->count;
        if (key < p->data.key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    return 0;
}
//查询某个数字的前驱
void FindPreBST(BiTree T, int key, BiTree& pre)
{
    BiTree p = T;
    stack<BiTree> S;
    while (p || !S.empty()) {
        if (p) {
            S.push(p);
            p = p->lchild;
        }
        else {
            p = S.top();
            S.pop();
            if (p->data.key >= key)
                return;
            if (p->data.key < key)
                pre = p;
            p = p->rchild;
        }
    }
}

int main()
{
    BiTree T = NULL, p;
    int op, n, key;
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 1) {
            cin >> key;
            p = new BiTNode;
            p->data.key = key;
            p->lchild = NULL;
            p->rchild = NULL;
            p->count = 1;
            InsertBST(T, p);
        }
        else if (op == 2) {
            cin >> key;
            if (!DeleteBST(T, key))
                cout << "None" << endl;
        }
        else if (op == 3) {
            cin >> key;
            cout << CountBST(T, key) << endl;
        }
        else if (op == 4)
            cout << MinBST(T) << endl;
        else if (op == 5) {
            cin >> key;
            BiTree s = NULL;
            FindPreBST(T, key, s);
            if (!s)
                cout << "None" << endl;
            else
                cout << s->data.key << endl;
        }
    }
}