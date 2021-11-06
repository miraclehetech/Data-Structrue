#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 110
typedef char SElemType;
typedef struct {
	SElemType* base;   //栈底指针
	SElemType* top;   //栈顶指针
	int stacksize;   //当前已分配的存储空间，以元素为单位
}SqStack;

//构造一个空栈S
void InitStack(SqStack& S)
{
	S.base = new(nothrow) SElemType[STACK_INIT_SIZE];
	if (S.base == NULL)    //存储分配失败
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
//删除S栈顶元素,返回给e
void Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base)
		return;
	else
		e = *(--S.top);
}
//插入元素e作为栈顶的新元素
void Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
		return;
	else
		*S.top++ = e;
}
//比较栈顶元素和新传入的运算符的优先级
char Precede(char first, char next)
{
	if (first == '(' && next == ')')   //双边括号情况
		return '=';
	else if ((first == '|' && (next == '&' || next == '!')) || (first == '&' && next == '!') || first == '#' || first == '(' || next == '('
		|| (first == '!' && next == '!'))  //注意
		return '<';
	else
		return '>';
}
/*operate运算函数 这里我考虑不能加入！，难以兼容*/
char Operate(char a, char optr, char b)
{
	if (optr == '|')
		return (a - '0' || b - '0') + '0';
	else
		return (a - '0' && b - '0') + '0';
}

int main()
{
	SqStack OPTR, OPND;
	InitStack(OPTR);  //寄存运算符   
	Push(OPTR, '#');   //运算栈底的标志
	InitStack(OPND);   //寄存操作数或运算结果  
	int i = 1;
	while (1) {
		char signal = getchar();
		if (signal== EOF)//文件读取结束
			break;
	/*只要运算符还没空以及字符还没输完执行循环*/
		while (*(OPTR.top - 1) != '#' || signal != '\r') {
			if (signal == ' ') {
				signal = getchar();
				continue;
			}//适应文件中可怕的随机空格
			else if (signal == 'V' || signal == 'F') {
				if (signal == 'V')
					Push(OPND, '1');
				else
					Push(OPND, '0');
				signal = getchar();
			}
			else {
				char pop_out;
				char x, y;
				char optr;  //运算符
				switch (Precede(*(OPTR.top - 1), signal)) {
					case '<':    //栈顶元素优先级底 
						Push(OPTR, signal);//压入
						signal = getchar();
						break;
					case '=':    //脱去括号
						Pop(OPTR, pop_out);
						signal = getchar();
						break;
					case '>':  //退栈并将运算结果入栈
						Pop(OPTR, optr);
						Pop(OPND, x);
						if (optr != '!') {
							Pop(OPND, y);
							Push(OPND, Operate(x, optr, y));
						}
						else
							Push(OPND, x == '1' ? '0' : '1');
						break;
				}
			}
		}
		getchar();
		char result;
		Pop(OPND, result);
		cout << "Expression " << i++ << ": " << (result == '1' ? 'V' : 'F') << endl;
	}
	return 0;
}