/*1950095 大数据 何正潇*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OVERFLOW -2
#define INSERT_NUM 120

struct s_element
{
    char    id[10];
    char    name[20];
};

class CSquential_List
{
public:
    CSquential_List(const int num);
    ~CSquential_List();

    int Insert_Elem(const int pos, const s_element elem);
    int Remove_Elem(const int pos);
    int Check_Name(char* num, const char* name);
    int Check_Num(char* name, const char* num);
    int Get_Num_Elems() { return m_num_elems; }
private:
    s_element* m_elems;
    int m_size;
    int    m_num_elems;
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
        scanf("%s %s", m_elems[i].id, m_elems[i].name);
    }

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
int CSquential_List::Check_Name(char* num, const char* name)
{
    for (int i = 1; i <= m_num_elems; i++)
    {
        if (strcmp(m_elems[i].name, name) == 0)
        {
            strcpy(num, m_elems[i].id);
            return i;
        }
    }
    return -1;
}

/*
* Function:    from student number, check relevant student's name and sequence number
* return: -1, not exist; when exist, sequence number and student's number
*/
int CSquential_List::Check_Num(char* name, const char* num)
{
    for (int i = 1; i <= m_num_elems; i++)
    {
        if (strcmp(m_elems[i].id, num) == 0)
        {
            strcpy(name, m_elems[i].name);
            return i;
        }
    }
    return -1;
}

int main()
{
    s_element elem;
    int num_elems, pos;
    char str[10];

    //input number of elements (students)
    scanf("%d", &num_elems);
    CSquential_List squential_list(num_elems);

    while (1)
    {
        scanf("%s", str);

        if (strcmp(str, "insert") == 0)
        {
            scanf("%d %s %s", &pos, elem.id, elem.name);
            if (squential_list.Insert_Elem(pos, elem) == 0)
                printf("0\n");
            else
                printf("-1\n");
        }
        else if (strcmp(str, "remove") == 0)
        {
            scanf("%d", &pos);
            if (squential_list.Remove_Elem(pos) == 0)
                printf("0\n");
            else
                printf("-1\n");
        }
        else if (strcmp(str, "check") == 0)
        {
            scanf("%s", str);
            if (strcmp(str, "name") == 0)
            {
                scanf("%s", elem.name);
                pos = squential_list.Check_Name(elem.id, elem.name);
                if (pos != -1)
                    printf("%d %s %s\n", pos, elem.id, elem.name);
                else
                    printf("-1\n");
            }
            else if (strcmp(str, "no") == 0)
            {
                scanf(" %s", elem.id);
                pos = squential_list.Check_Num(elem.name, elem.id);
                if (pos != -1)
                    printf("%d %s %s\n", pos, elem.id, elem.name);
                else
                    printf("-1\n");
            }
        }
        else if (strcmp(str, "end") == 0)
        {
            printf("%d\n", squential_list.Get_Num_Elems());
            break;
        }
    }
    return 0;
}