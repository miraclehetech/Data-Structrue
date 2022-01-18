#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
struct Node
{

	Node* lc = nullptr;
	Node* rc = nullptr;
	char c = '\0';
	int weight = 0;
	string code;
};
int  sort(int num_count, Node** Array, char str[256])
{
	int index_min = -1, index_2nd = -1;
	int frequency_min = 0, frequency_2nd = 0;
	while (num_count > 1)
	{
		for (int i = 0; i < 128; i++)
		{
			if (Array[i] != NULL)
			{
				if (index_min == -1 || index_2nd == -1)
				{
					if (index_min == -1)
					{
						index_min = i;
						frequency_min = Array[i]->weight;
					}
					else if (index_2nd == -1)
					{
						index_2nd = i;
						frequency_2nd = Array[i]->weight;
					}
					if (index_min != -1 && index_2nd != -1)
					{
						if (Array[index_min]->weight >= Array[index_2nd]->weight)
						{
							Node* tmp = new Node;
							tmp = Array[index_min];
							Array[index_min] = Array[index_2nd];
							Array[index_2nd] = tmp;
							int temp;
							temp = frequency_2nd;
							frequency_2nd = frequency_min;
							frequency_min = temp;
						}
					}
				}

					if (Array[i]->weight < frequency_min)
					{
						index_min = i;
						frequency_min = Array[i]->weight;
					}

					else if (Array[i]->weight < frequency_2nd)
					{
						index_2nd = i;
						frequency_2nd = Array[i]->weight;
					}
					else
						continue;
				

			}

		}
		Node* tmpNode = new Node;
		tmpNode->weight = Array[index_min]->weight + Array[index_2nd]->weight;
		tmpNode->lc = Array[index_min];
		tmpNode->rc = Array[index_2nd];
		Array[index_min] = tmpNode;
		Array[index_2nd] = NULL;
		if(num_count ==2)
			return index_min;
		index_min = -1, index_2nd = -1;
		frequency_min = 0, frequency_2nd = 0;
		num_count--;
	}

}
void Huffmancoding( string code, Node* Array)
{
	if (Array == NULL)
		return;
	Array->code = code;
	Huffmancoding(code+"0", Array->lc);
	Huffmancoding(code+"1", Array->rc);
}
void Huffman_output(Node* Array, char str)
{
	ofstream  output("result.txt", ios::out|ios::app);
	if (Array == NULL)
		return;
	if (Array->c == str)
	{
		cout << Array->code<<" ";
		output << Array->code;
		return;
	}
	Huffman_output(Array->lc, str);
	Huffman_output(Array->rc, str);
}
	
void Huffman_decoding(Node* Array)
{
	ifstream input;
	Node* temp = Array;
	input.open("result.txt", ios::in);
	char encoded_str[256] = "";
	if (input.is_open() == 0)
		return;
	input >> encoded_str;
	int i = 0;
	while (encoded_str[i] != '\0')
	{
		if (encoded_str[i] == '0')
			temp = temp->lc;
		else if (encoded_str[i] == '1')
			temp = temp->rc;
		if (temp->lc == NULL)
		{
			cout << temp->c;
			temp = Array;
		}
		i++;
	}
}
int main()
{
	int num_count = 0;
	int root = 0;
	string code = "";
	char str[256];
	Node** Array;
	Array = new Node * [128];
	ifstream input;
	ofstream  output;
	input.open("note.txt", ios::in);
	char encoded_str[256]="";
	if (input.is_open() == 0)
		return -1;
	input >> str;
	input.close();
	for (int i = 0; i < 128; i++)
		Array[i] = nullptr;
	for (int i = 0; str[i] != '\0'; i += 1) {
		if (Array[str[i]] == NULL) {
			Array[str[i]] = new Node;
			Array[str[i]]->c = str[i];
		}

		Array[str[i]]->weight++;
	}
	for (int i = 0; i < 128; i++)
	{
		if (Array[i] != NULL)
			num_count++;
	}
	root = sort(num_count, Array, str);
	Huffmancoding(code, Array[root]);
	for (int i = 0; i < strlen(str); i++)
		Huffman_output(Array[root], str[i]);
	cout << endl;
	Huffman_decoding(Array[root]);
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
