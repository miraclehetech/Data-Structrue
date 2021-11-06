#include <iostream>
#include <stack>
using namespace std;

class Data {
private:
    long n; //函数的输入参数
    //int returnAddress; //函数的返回地址(这题显然不需要)
public:
    void set(int number);
    long get_number();
};
//设置参数n
void Data::set(int number)
{
   n = number;
}
//取得参数n
long Data::get_number()
{
    return n;;
}


void Recursive(stack<Data>& myStack)
{
    Data digit;
    int n;
    cin >> n;
    while (n > 1) {   //挺简单的，就一直把整个数据给他嗯压进去就行
        digit.set(n);
        myStack.push(digit);
        --n;
    }
}

//开始回导
long backtracking(stack<Data>& myStack)
{
    Data digit;
    long sum = 1;
    while (!myStack.empty()) {
        digit = myStack.top();
        myStack.pop();
        sum *= digit.get_number();
    }
    return sum;
}

int main()
{
    stack<Data> myStack;
    cout << "请输入阶乘数(使用栈模拟): ";
    Recursive(myStack);
    cout << backtracking(myStack) << endl;
    return 0;
}