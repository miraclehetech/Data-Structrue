#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
struct s_element
{
	char	number[10];
	char	name[10];
};

class CSquential_List
{
public:
	CSquential_List(const int size);
	~CSquential_List();

	void append_elem(const s_element elem);
	int Insert_Elem(const int pos, const s_element elem);
	int Remove_Elem(const int pos);
	int Check_Name(char* num, const char* name);
	int Check_Num(char* name, const char* num);
private:
	s_element* m_elems;
	int m_size;
	int	m_num_elems;
};

/*
* Function:	constructor of  CSquential_List object
* note: when create memory, use (size + 1), because the array, m_elems[0] not used
*/
CSquential_List::CSquential_List(const int size)
{
	m_size = size;
	m_elems = new s_element[size + 1];
	m_num_elems = 0;
}

/*
* Function:	distructor of  CSquential_List object
*/
CSquential_List::~CSquential_List()
{
	delete[] m_elems;
}

/*
* Function:	append new element in the end of sequential list
*/
void CSquential_List::append_elem(const s_element elem)
{
	m_num_elems++;
	m_elems[m_num_elems] = elem;
}

/*
* Function:	insert a element at location pos
* return: -1, pos illeagally; 0, pos legally
*/
int CSquential_List::Insert_Elem(const int pos, const s_element elem)
{
	if (pos > m_num_elems)
		return -1;
	else
	{
		for (int i = m_num_elems; i >= pos; i--)
			m_elems[i + 1] = m_elems[i];
		m_elems[pos] = elem;
		m_num_elems++;
	}
	return 0;
}

/*
* Function:	remove the element at location pos
* return: -1, pos illeagally; 0, pos legally
*/
int CSquential_List::Remove_Elem(const int pos)
{
	if (pos > m_num_elems)
		return -1;
	else
	{
		for (int i = pos; i < m_num_elems; i++)
			m_elems[i] = m_elems[i + 1];
		m_num_elems--;
	}
	return 0;
}

/*
* Function:	from neame, check relevant student number, and sequence number
* return: -1, not exist; when exist, sequence number and student's number
*/
int CSquential_List::Check_Name(char* num, const char* name)
{
	for (int i = 1; i <= m_num_elems; i++)
	{
		if (strcmp(m_elems[i].name, name) == 0)
		{
			strcpy(num, m_elems[i].number);
			return i;
		}
	}
	return -1;
}

/*
* Function:	from student number, check relevant student's name and sequence number
* return: -1, not exist; when exist, sequence number and student's number
*/
int CSquential_List::Check_Num(char* name, const char* num)
{
	for (int i = 1; i <= m_num_elems; i++)
	{
		if (strcmp(m_elems[i].number, num) == 0)
		{
			strcpy(name, m_elems[i].name);
			return i;
		}
	}
	return -1;
}

int main()
{
	CSquential_List squential_list(100000);
	s_element elem;
	int num_elems, sequence_num;
	char command[100];

	//input number of elements (students)
	gets(command);
	num_elems = atoi(command);

	//input 4 (num_elems) students' information, students' number and name
	for (int i = 1; i <= num_elems; i++)
	{
		gets(command);
		char* token;
		token = strtok(command, " ");
		strcpy(elem.number, token);
		token = strtok(NULL, " ");
		strcpy(elem.name, token);
		squential_list.append_elem(elem);
	}

	while (1)
	{
		gets(command);
		char* token;
		token = strtok(command, " ");

		if (strcmp(token, "insert") == 0)
		{
			token = strtok(NULL, " ");
			sequence_num = atoi(token);
			token = strtok(NULL, " ");
			strcpy(elem.number, token);
			token = strtok(NULL, " ");
			strcpy(elem.name, token);

			if (squential_list.Insert_Elem(sequence_num, elem) == 0)
				printf("0\n");
			else
				printf("-1\n");
		}
		else if (strcmp(token, "remove") == 0)
		{
			token = strtok(NULL, " ");
			sequence_num = atoi(token);
			if (squential_list.Remove_Elem(sequence_num) == 0)
				printf("0\n");
			else
				printf("-1\n");
		}
		else if (strcmp(token, "check") == 0)
		{
			token = strtok(NULL, " ");
			if (strcmp(token, "name") == 0)
			{
				token = strtok(NULL, " ");
				strcpy(elem.name, token);
				sequence_num = squential_list.Check_Name(elem.number, elem.name);
				if (sequence_num != -1)
					printf("%d %s %s\n", sequence_num, elem.number, elem.name);
				else
					printf("-1\n");
			}
			else if (strcmp(token, "no") == 0)
			{
				token = strtok(NULL, " ");
				strcpy(elem.number, token);
				sequence_num = squential_list.Check_Num(elem.name, elem.number);
				if (sequence_num != -1)
					printf("%d %s %s\n", sequence_num, elem.number, elem.name);
				else
					printf("-1\n");
			}
		}
		else if (strcmp(token, "end") == 0)
		{
			cout<<num_elems<<endl;
			break;
		}
	}
}
