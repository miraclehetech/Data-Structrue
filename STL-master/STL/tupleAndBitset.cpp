#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <list>

using namespace std;
/*
	��1�����죺tuple<T1, T2, ..., Tn> t();     make_tuple(v1, v2, ... vn);   //����һ��Ԫ�飬 Ԫ����һ�����ٶ���������ݽṹ
	��2��

*/
void tupleAndBitsetTest()
{
	std::cout << "------------------------this is class tupleAndBitset demo----------------------" << std::endl;
	tuple<string, vector<double>, int, list<int>> someVal("constants", { 3.14, 2.718 }, 42, { 0, 1, 2, 3, 4, 5 });
	auto myVecOfTuple = get<1>(someVal);
	cout << "the vec of the tuple is: " << endl;
	for (auto tmp : myVecOfTuple)
		cout << tmp << ends;
	cout << endl;
	cout << "������˾���̫��˽����ô�������еĺ��¶������㣿" << endl;

}