/*1950095 大数据 何正潇*/

#include <iostream>
#include<fstream>
using namespace std;
ofstream outfile("result.txt", ios::out);
struct TrieNode
{
	TrieNode* arrNext[26] = { NULL };
	bool bTerminate = false;
	int count = 0;
};
class Dictionary_tree
{
public:
	Dictionary_tree(const char* p);
	Dictionary_tree();
	Dictionary_tree& add(const char* p);
	void trie_travel(TrieNode* cur);
	TrieNode* root = NULL;
};
Dictionary_tree::Dictionary_tree(const char* p)
{
	const char* temp = p;
	root = new TrieNode;
	TrieNode* temp1 = root;
	root->arrNext[temp[0] - 'a'] = new TrieNode;
	temp1 = root->arrNext[temp[0] - 'a'];
	temp++;
	while (*temp != '\0')
	{
		if (temp1->arrNext[*temp - 'a'] == NULL)
		{
			temp1->arrNext[*temp - 'a'] = new TrieNode;
			temp1 = temp1->arrNext[*temp - 'a'];
		}
		else
		{
			temp1 = temp1->arrNext[*temp - 'a'];
		}
		temp++;
	}
	if (temp1->bTerminate == false)
	{
		temp1->bTerminate = true;
		temp1->count++;
	}
	else
		temp1->count++;

}
Dictionary_tree::Dictionary_tree()
{
	root = NULL;
}
Dictionary_tree& Dictionary_tree::add(const char* p)
{
	const char* temp = p;
	TrieNode* temp1 = root;
	while (*temp != '\0')
	{
		if (temp1->arrNext[*temp - 'a'] == NULL)
		{
			temp1->arrNext[*temp - 'a'] = new TrieNode;
			temp1 = temp1->arrNext[*temp - 'a'];
		}
		else
		{
			temp1 = temp1->arrNext[*temp - 'a'];
		}
		temp++;
	}
	if (temp1->bTerminate == false)
	{
		temp1->bTerminate = true;
		temp1->count++;
	}
	else
		temp1->count++;
	return *this;
}
void Dictionary_tree::trie_travel(TrieNode* cur)
{
	static string temp;
	static int pos = 0;
	int i;
	if (cur->count != 0 || cur->bTerminate == true)
	{
		cout << "<";
		cout << temp << "," << cur->count << ">" << endl;
		outfile << temp << "," << cur->count << ">" << endl;
	}
	for (i = 0; i < 26; i++)
	{
		if (cur->arrNext[i] != NULL)
		{
			temp += i + 'a';
			trie_travel(cur->arrNext[i]);
			if (strlen(temp.c_str()) >= 1)
				temp.erase(strlen(temp.c_str()) - 1, 1);
			else
				;
		}
	}
}
int main()
{
	string temp, temp2;
	ifstream infile("count.txt", ios::in);
	infile >> temp;
	for (int i = 0; i < strlen(temp.c_str()); i++)
	{
		if (temp[i] >= 'A' && temp[i] <= 'Z')
		{
			temp[i] = temp[i] + 'a' - 'A';
		}
	}
	if (!(temp[strlen(temp.c_str()) - 1] >= 'a' && temp[strlen(temp.c_str()) - 1] <= 'z'))
	{
		temp.erase(strlen(temp.c_str()) - 1, 1);
	}
	Dictionary_tree a(temp.c_str());
	while (!infile.eof())
	{
		infile >> temp;
		for (int i = 0; i < strlen(temp.c_str()); i++)
		{
			if (temp[i] >= 'A' && temp[i] <= 'Z')
			{
				temp[i] = temp[i] + 'a' - 'A';
			}
		}
		if (!(temp[strlen(temp.c_str()) - 1] >= 'a' && temp[strlen(temp.c_str()) - 1] <= 'z'))
		{
			if (temp[strlen(temp.c_str()) - 1] == '-')
			{
				temp.erase(strlen(temp.c_str()) - 1, 1);
				infile >> temp2;
				temp.append(temp2.c_str());
			}
			else
			{
				temp.erase(strlen(temp.c_str()) - 1, 1);

			}
		}
		a.add(temp.c_str());
	}
	a.trie_travel(a.root);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
