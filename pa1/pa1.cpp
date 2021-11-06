/*1950095 大数据 何正潇*/

#define _CRT_SECURE_NO_WARNINGS

#include<iostream> 
#include<cstring>
#include<cstdlib> 
#include<cmath>
#define INSERT_NUM 120
using namespace std;
struct s_element
{
	char no[8];   //8 位学号
	char name[20]; // 姓名
	double score;     // 成绩
};

class CSquential_List
{
public:
	CSquential_List(const int num);
	~CSquential_List();

	int Insert_Elem(const int pos, const s_element elem);
	int Remove_Elem(const int pos);
	void Check_Name( const char* name);
	void Check_Num( const char* num);
	int Get_Num_Elems() { return m_num_elems; }
	int Remove_Elem_Name(const char* name);
	void show();
	void remove_repetition();
	void number();
	void Check_pos(int pos);
private:
	s_element* m_elems;
	int m_size;
	int    m_num_elems;
	int student_num;//学生人数
};

/*
* Function:    constructor of  CSquential_List object
* note: when create memory, use (size + 1), because the array, m_elems[0] not used
*/
CSquential_List::CSquential_List(const int num)
{
	m_elems = (s_element*)malloc((num + INSERT_NUM + 1) * sizeof(s_element));
	if (m_elems == NULL)
		exit(OVERFLOW);

	for (int i = 1; i <= num; i++)
	{
		scanf("%s%s%lf", m_elems[i].no, m_elems[i].name, &m_elems[i].score);
	}
	cout << "输入完毕" << endl;
	m_size = num + INSERT_NUM;
	m_num_elems = num;
}

/*
* Function:    distructor of  CSquential_List object
*/
CSquential_List::~CSquential_List()
{

	free(m_elems);
}

/*
* Function:    insert a element at location pos
* return: -1, pos illeagally; 0, pos legally
*/
int CSquential_List::Insert_Elem(const int pos, const s_element elem)
{
	if (pos < 1 || pos > m_num_elems + 1)
		return -1;
	if (m_num_elems == m_size)
	{
		s_element* new_base = (s_element*)realloc(m_elems, (m_size + 1 + m_size / 2) * sizeof(s_element));
		if (new_base == NULL)
			exit(OVERFLOW);
		m_elems = new_base;
		m_size = m_size + 1 + m_size / 2;
	}
	for (int i = m_num_elems; i >= pos; i--)
		m_elems[i + 1] = m_elems[i];
	m_elems[pos] = elem;
	m_num_elems++;
	return 0;
}

/*
* Function:    remove the element at location pos
* return: -1, pos illeagally; 0, pos legally
*/
int CSquential_List::Remove_Elem(const int pos)
{
	if (pos < 1 || pos > m_num_elems)
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
* Function:    from neame, check relevant student number, and sequence number
* return: -1, not exist; when exist, sequence number and student's number
*/
void CSquential_List::Check_Name( const char* name)
{
	int count = 0;
	for (int i = 1; i <= m_num_elems; i++)
	{
		if (strcmp(m_elems[i].name, name) == 0)
		{
			
			cout << m_elems[i].no << " " << m_elems[i].name << " " << m_elems[i].score << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "查无此人" << endl;
	}
	
}

/*
* Function:    from student number, check relevant student's name and sequence number
* return: -1, not exist; when exist, sequence number and student's number
*/
void CSquential_List::Check_Num( const char* no)
{
	int count = 0;
	for (int i = 1; i <= m_num_elems; i++)
	{
		if (strcmp(m_elems[i].no, no) == 0)
		{

			cout << m_elems[i].no << " " << m_elems[i].name << " " << m_elems[i].score << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "查无此人" << endl;
	}
}
void CSquential_List::Check_pos(int pos)
{
	if (pos<1 || pos>m_num_elems)
	{
		cout << "位置无效" << endl;
		return;

	}
	else
	{
		cout<<m_elems[pos].no << " " << m_elems[pos].name << " " << m_elems[pos].score << endl;

	}
}
int CSquential_List::Remove_Elem_Name(const char* name)
{
	for (int i = 1; i <= m_num_elems; i++)
	{
		if (strcmp(m_elems[i].name, name) == 0)
		{
			Remove_Elem(i);
			return 0;
		}
	}
	return -1;

}
void CSquential_List::show()
{
	for (int i = 1; i <= m_num_elems; i++)
	{
		cout << m_elems[i].no << " " << m_elems[i].name << " " << m_elems[i].score << endl;
	}
	
}
void CSquential_List::remove_repetition()
{
	for (s_element* p = &m_elems[1]; p <= &m_elems[1 + m_num_elems]; p++)
		for (s_element* q = p + 1; q <= &m_elems[1 + m_num_elems]; q++)
		{
			if ((!strcmp(p->name, q->name) && !strcmp(p->no, q->no) && (p->score == q->score)))
			{
				Remove_Elem(q - m_elems);

			}

		}
	cout << "去重完毕" << endl;
}
void  CSquential_List::number()
{
	if (m_num_elems == 0)
		cout << "总人数为0" << endl;
	else if (m_num_elems == 1)
		cout << "总人数为1" << endl;
	else
	{


		char temp[20];
		strcpy(temp, m_elems[1].name);
		student_num = 1;
		for (int i = 2; i <= m_num_elems; i++)
		{
			if (strcmp(temp, m_elems[i].name) != 0)
				student_num++;
			strcpy(temp,  m_elems[i].name);

		}
		cout << "总人数为" << student_num << endl;
	}
}
int main()
{
	s_element elem;
	int num_elems, pos;
	char str[40];
	char name[20];
	//input number of elements (students)
	cout << "请输入初始人数" << endl;
	scanf("%d", &num_elems);
	CSquential_List squential_list(num_elems);

	while (1)
	{
		scanf("%s", str);

		if (strcmp(str, "insert") == 0)
		{
			scanf("%d %s %s %lf", &pos, elem.no, elem.name, &elem.score);
			if (squential_list.Insert_Elem(pos, elem) == 0)
				cout << "插入成功" << endl;
			else
				cout << "插入失败" << endl;
		}
		else if (strcmp(str, "remove") == 0)
		{
			scanf("%s", str);
			if (strcmp(str, "location") == 0)
			{
				scanf("%d", &pos);
				if (squential_list.Remove_Elem(pos) == 0)
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;
			}
			else if (strcmp(str, "name") == 0)
			{
				scanf("%s", &name);
				if (squential_list.Remove_Elem_Name(name) == 0)
					cout << "删除成功" << endl;
				else
					cout << "删除失败" << endl;

			}
		}
		else if (strcmp(str, "check") == 0)
		{
			scanf("%s", str);
			if (strcmp(str, "name") == 0)
			{
				scanf("%s", elem.name);
				squential_list.Check_Name(elem.name);
			}
			else if (strcmp(str, "no") == 0)
			{
				scanf(" %s", elem.no);
				squential_list.Check_Num(elem.no);
			}
			else if (strcmp(str, "pos") == 0)
			{
				int pos;
				cin >> pos;
				squential_list.Check_pos(pos);
			}
		}
		else if (strcmp(str, "end") == 0)
		{
			squential_list.show();
			break;
		}
		else if (strcmp(str, "remove_repetition") == 0)
		{
			squential_list.remove_repetition();
		}
		else if (strcmp(str, "show") == 0)
		{
			squential_list.show();
		}
		else if (strcmp(str, "number")==0)
		{
			squential_list.number();
		}
		else
		{
			memset(str, '0', (strlen(str) + 1) * sizeof(char));
			cout << "输入无效" << " " << "重新输入" << endl;
		}

	}
	return 0;
}
