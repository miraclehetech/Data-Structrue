/*1950095 ������ ������*/
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

//����һ������ 
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

//ʵ�ֶ�p���ɾ�������ؽ����������������ֶ�����������
bool Delete(BiTree& p)
{
    BiTree q, s;

    //ɾ��ʱ��������ظ�Ԫ��ֱ��count--����ɾ�����
    if (p->count > 1) {
        p->count--;
        return true;
    }
    if (!p->rchild) //������Ϊ����ֻ���ؽ�����������
    {
        q = p;
        p = p->lchild;
        delete q;
    }
    else if (!p->lchild) //ֻ���ؽ�����������
    {
        q = p;
        p = p->rchild;
        delete q;
    }
    else //������������Ϊ�� 
    {
        q = p;  //s��ǰ�����
        s = p->lchild;
        while (s->rchild) {
            q = s;
            s = s->rchild;
        } //ת��Ȼ�������ߵ���ͷ
        p->data = s->data;
        p->count = s->count;
        if (q != p)
            q->rchild = s->lchild;
        else  //ֻ�����󣬲�û�����ң����s��q������
            q->lchild = s->lchild;
        delete s;
    }
    return true;
}

bool DeleteBST(BiTree& T, int key)
{
    if (!T)   //�����ڹؼ��ֵ���key������Ԫ��
        return false;
    else {
        if (key == T->data.key)   //�ҵ��ؼ��ֵ���key������Ԫ��
            return Delete(T);
        else if (key > T->data.key)
            return DeleteBST(T->rchild, key);
        else
            return DeleteBST(T->lchild, key);
    }
}
//��ѯ��Сֵ
int MinBST(BiTree T)
{
    BiTree p = T;
    while (p->lchild)
        p = p->lchild;
    return p->data.key;
}
//��ѯĳ�������ж��ٸ�
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
//��ѯĳ�����ֵ�ǰ��
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