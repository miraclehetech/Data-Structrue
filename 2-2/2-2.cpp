#include <iostream>
#include <cstring>
using namespace std;
typedef char SElemType;
typedef struct S
{
	SElemType* base;
	SElemType* top;
	int stacksize;
}Sqstack;
int InitStack(Sqstack& s)
{
	s.base = (SElemType*)malloc(100 * sizeof(SElemType));
	if (!s.base)
		return -1;
	s.top = s.base;
	s.stacksize = 100;
	return 0;
}
int Pop(Sqstack& s)
{
	if (s.top == s.base)
	{
		return -1;
	}
	else
	{
		--s.top;
		return 0;
	}
}
int push(Sqstack& s, SElemType e, int n)
{
	if (s.top - s.base >= n)
	{
		s.base = (SElemType*)realloc(s.base, (s.stacksize + 10) * sizeof(SElemType));
		if (!s.base)
			return -1;
		else
		{
			s.stacksize = s.stacksize + 10;
		}
	}
	*s.top++ = e;
	return 0;
}
void exit_push_all(Sqstack& s)
{
	if (s.top != s.base)
	{
		while (s.top != s.base)
		{
			--s.top;
		}
	}
}
int main()
{
	Sqstack in, station;
	InitStack(in), InitStack(station);
	char temp[30];
	cin >> temp;

	bool judge = 1;
	char out[30];
	int i = 0;

	while (1)
	{
		cin >> out;
		if (!cin.eof())
		{
			for (int k = 0; k < int(strlen(temp)); k++)
				push(in, temp[strlen(temp) - 1 - k], strlen(temp));
			while (in.base != in.top)
			{

				if (in.top != in.base && *(in.top - 1) == out[i])
				{
					Pop(in);
					i++;
				}
				else
				{
					if (*(station.top - 1) == out[i])
					{
						Pop(station);
						i++;
					}
					else
					{
						push(station, *(in.top - 1), 30);
						Pop(in);
					}


				}
			}
			if (station.top == station.base)
				judge = 1;
			while (station.top != station.base)
			{
				if (station.top != station.base && *(station.top - 1) == out[i])
				{
					Pop(station);
					i++;
				}
				else
				{
					judge = 0;
					break;
				}
				judge = 1;
			}
			exit_push_all(station);
			if (judge == 1)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
			judge = 0;
			i = 0;
		}
		else
		{
			break;
		}
	}

	return 0;

}