/*1950095 ������ ������*/
#include <iostream>
#include <cstring>
using namespace std;
typedef int QElemtype;
typedef int Status;
const int stack_increment = 50;
class stack
{
public:
    stack()
    {
        stackTop = 0;
        maxStackItemIndex = -1;
        stackItem = (QElemtype*)(malloc(sizeof(int) * 5000));
        notedownMax = (QElemtype*)(malloc(sizeof(int) * 5000));
    }
    void push(QElemtype x)
    {

        if (stackTop == 0)
        {
            stackItem[stackTop] = x;
            maxStackItemIndex = stackTop;
            notedownMax[stackTop] = -1;//��¼����ǰ��
            stackTop++;
        }
        else
        {
            if (stackTop >= stacksize)
            {
                /*stackItem = (QElemtype*)(realloc(stackItem, sizeof(QElemtype) * (stacksize + stack_increment)));
                notedownMax = (QElemtype*)(realloc(stackItem, sizeof(QElemtype) * (stacksize + stack_increment)));
                stackItem[stackTop] = x;
                if (x > Max())
                {
                    notedownMax[stackTop] = maxStackItemIndex;
                    maxStackItemIndex = stackTop;
                }
                else
                    notedownMax[stackTop] = -1;
                    */
                cout << "Queue is Full" << endl;
            }
            else
            {
                stackItem[stackTop] = x;
                if (x > Max())
                {
                    notedownMax[stackTop] = maxStackItemIndex;//��¼����ǰ��
                    maxStackItemIndex = stackTop;
                }
                else
                    notedownMax[stackTop] = -1;
                stackTop++;
            }
        }
    }


    QElemtype pop()
    {
        QElemtype temp;
        if (stackTop == 0)
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        else
        {
            temp = stackItem[stackTop - 1];
            if (stackTop - 1 == maxStackItemIndex)
            {
                maxStackItemIndex = notedownMax[stackTop - 1];
            }
            stackTop--;
            return temp;
        }
    }
    QElemtype Max()
    {
        if (maxStackItemIndex >= 0)
            return stackItem[maxStackItemIndex];
        else
            return -100;
    }
    ~stack()
    {
        delete[]stackItem;
        delete[]notedownMax;
    }
    void set_stacksize(int number)
    {
        stacksize = number;
        stackItem = (QElemtype*)(realloc(stackItem, sizeof(stacksize) * number));
        notedownMax = (QElemtype*)(realloc(notedownMax, sizeof(stacksize) * number));
    }
    bool whether_empty_or_not()
    {
        if (stackTop == 0)
            return 1;
        else
            return 0;
    }
    int size()
    {
        return stackTop;
    }
private:
    QElemtype* stackItem;
    int stackTop;
    QElemtype* notedownMax;
    int maxStackItemIndex;
    int stacksize;
};
class queue
{
public:
    void enQueue(int val, int number);
    int deQueue();
    void set_stacksize(int number);
    int max();
    int size();
    void  exit_push_all();
private:
    stack stackIn;
    stack stackOut;
};
void queue::enQueue(int val, int number)
{
    if (stackIn.size() + stackOut.size() >= number)
        cout << "Queue is Full" << endl;
    else
    {
        stackIn.push(val);
    }
}
void queue::set_stacksize(int number)
{
    stackIn.set_stacksize(number);
    stackOut.set_stacksize(number);
}
int queue::size()
{
    return stackIn.size() + stackOut.size();
}
int queue::deQueue()
{
    if (!stackIn.whether_empty_or_not() && stackOut.whether_empty_or_not())
    {
        while (!stackIn.whether_empty_or_not())
            stackOut.push(stackIn.pop());
        return stackOut.pop();
    }
    else if (stackIn.whether_empty_or_not() && stackOut.whether_empty_or_not())
        return stackOut.pop();
    else if (stackIn.whether_empty_or_not() && !stackOut.whether_empty_or_not())
        return stackOut.pop();
    else
        return stackOut.pop();
}
int queue::max()
{
    if (!stackIn.whether_empty_or_not() && stackOut.whether_empty_or_not())
    {
        while (!stackIn.whether_empty_or_not())
            stackOut.push(stackIn.pop());
        return stackOut.Max();
    }
    else if (stackIn.whether_empty_or_not() && stackOut.whether_empty_or_not())
        return stackOut.Max();
    else if (stackIn.whether_empty_or_not() && !stackOut.whether_empty_or_not())
        return stackOut.Max();
    else
        return (stackIn.Max() > stackOut.Max()) ? stackIn.Max() : stackOut.Max();
}
void queue::exit_push_all()
{
    if (!stackIn.whether_empty_or_not() && stackOut.whether_empty_or_not())
    {
        while (!stackIn.whether_empty_or_not())
            stackOut.push(stackIn.pop());
        while (!stackOut.whether_empty_or_not())
            cout << stackOut.pop() << " ";
    }
    else if (stackIn.whether_empty_or_not() && stackOut.whether_empty_or_not())
        return;
    else if (stackIn.whether_empty_or_not() && !stackOut.whether_empty_or_not())
    {
        while (!stackOut.whether_empty_or_not())
            cout << stackOut.pop() << " ";
    }
    else
    {
        while (!stackOut.whether_empty_or_not())
            cout << stackOut.pop() << " ";
        while (!stackIn.whether_empty_or_not())
            stackOut.push(stackIn.pop());
        while (!stackOut.whether_empty_or_not())
            cout << stackOut.pop() << " ";
    }

}
/*
typedef struct Node {
    QElemtype data;
    struct Node* next;
}QNode;
typedef struct Queue {
    QNode* front;   //����ָ��
    QNode* rear;    //��βָ��
    int count = 0;//����
}LinkQueue;
Status InitQueue(LinkQueue& Q)
{
    Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
    if (Q.front == NULL)
        return -1;
    Q.front->next = NULL;
    return 0;
}
Status DestroyQuene(LinkQueue& Q)
{
    while (Q.front)
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return 0;

}
Status Enquene(LinkQueue& Q, QElemtype x, QElemtype n)
{
    QNode* p = (QNode*)malloc(sizeof(QNode));
    if (p == NULL)
        return -1;
    if (Q.count + 1 > n)
        cout << "Queue is Full" << endl;
    else
    {
        p->data = x;
        p->next = NULL;
        Q.rear->next = p;
        Q.rear = p;
        Q.count++;
    }
    return 0;

}
Status Dequene(LinkQueue& Q)
{
    if (Q.front == Q.rear)
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    QNode* p = Q.front->next;
    Q.front->next = p->next;
    cout << p->data << endl;
    Q.count--;
    if (Q.rear == p)
        Q.rear = Q.front;
    free(p);
    return 0;
}
void exit_push_all(LinkQueue& s)
{
    if (s.front != s.rear)
    {
        while (s.front != s.rear)
        {
            s.front = s.front->next;
            cout << s.front->data << " ";

        }
        cout << s.front->data;
    }
    else
    {
        cout << "Queue is Empty" << endl;
    }
}*/
int main()
{
    queue a;
    int number;
    cin >> number;
    a.set_stacksize(number);
    char orders[20];
    while (1)
    {
        cin >> orders;
        if (!strcmp(orders, "enqueue"))
        {
            int n;
            cin >> n;
            a.enQueue(n, number);
        }
        else if (!strcmp(orders, "dequeue"))
        {
            int num;
            num = a.deQueue();
            if (num != -1)
                cout << num << endl;

        }
        else if (!strcmp(orders, "quit"))
        {
            a.exit_push_all();
            break;
        }

        else if (!strcmp(orders, "max"))
        {
            int num;
            num = a.max();
            if (num != -100)
                cout << num << endl;
            else
                cout << "Queue is Empty" << endl;
        }
        else
        {
            continue;
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