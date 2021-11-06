#include <iostream>
using namespace std;

#define STACK_INIT_SIZE 110
typedef char SElemType;
typedef struct {
	SElemType* base;   //ջ��ָ��
	SElemType* top;   //ջ��ָ��
	int stacksize;   //��ǰ�ѷ���Ĵ洢�ռ䣬��Ԫ��Ϊ��λ
}SqStack;

//����һ����ջS
void InitStack(SqStack& S)
{
	S.base = new(nothrow) SElemType[STACK_INIT_SIZE];
	if (S.base == NULL)    //�洢����ʧ��
		return;
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}
//ɾ��Sջ��Ԫ��,���ظ�e
void Pop(SqStack& S, SElemType& e)
{
	if (S.top == S.base)
		return;
	else
		e = *(--S.top);
}
//����Ԫ��e��Ϊջ������Ԫ��
void Push(SqStack& S, SElemType e)
{
	if (S.top - S.base >= S.stacksize)
		return;
	else
		*S.top++ = e;
}
//�Ƚ�ջ��Ԫ�غ��´��������������ȼ�
char Precede(char first, char next)
{
	if (first == '(' && next == ')')   //˫���������
		return '=';
	else if ((first == '|' && (next == '&' || next == '!')) || (first == '&' && next == '!') || first == '#' || first == '(' || next == '('
		|| (first == '!' && next == '!'))  //ע��
		return '<';
	else
		return '>';
}
/*operate���㺯�� �����ҿ��ǲ��ܼ��룡�����Լ���*/
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
	InitStack(OPTR);  //�Ĵ������   
	Push(OPTR, '#');   //����ջ�׵ı�־
	InitStack(OPND);   //�Ĵ��������������  
	int i = 1;
	while (1) {
		char signal = getchar();
		if (signal== EOF)//�ļ���ȡ����
			break;
	/*ֻҪ�������û���Լ��ַ���û����ִ��ѭ��*/
		while (*(OPTR.top - 1) != '#' || signal != '\r') {
			if (signal == ' ') {
				signal = getchar();
				continue;
			}//��Ӧ�ļ��п��µ�����ո�
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
				char optr;  //�����
				switch (Precede(*(OPTR.top - 1), signal)) {
					case '<':    //ջ��Ԫ�����ȼ��� 
						Push(OPTR, signal);//ѹ��
						signal = getchar();
						break;
					case '=':    //��ȥ����
						Pop(OPTR, pop_out);
						signal = getchar();
						break;
					case '>':  //��ջ������������ջ
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