// Search.cpp : ����>����̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "sqSearch.h"
#include "binarySortTree.h"
#include "iostream"
using namespace std;
int main()
{
	int len;
	ElemType b[] = {1,4,7,11,23,52,56,65,73,89};
	List list1;
	len = getArrayLength(b);
	cout << "��������Ϊ��";
	for (int i = 0; i < len; i++)
	{
		visit(b[i]);
	}
	cout << endl;
	initLinearList(list1,b,len);
	cout <<"˳�����b[6]��λ��Ϊ��"<< sqSearch(list1,b[6],len)<<endl;
	cout << "�۰����b[2]��λ��Ϊ��"<<binarySearch(list1, b[2], len) << endl;	
	
	//���������
	ElemType c[] = {13,23,5,8,18,37,9};
	len = getArrayLength(c);
	BST T;
	cout << "�������飺";
	for (int i = 0; i < len; i++)
	{
		visit(c[i]);
	}
	cout << endl;
	cout << "��������������" << endl;
	createBST(T,c,len);
	cout << "���������" ;
	preOrderTraverse(T);
	cout << endl;
	cout << "������Ҫɾ����Ԫ�أ�";
	ElemType data;
	cin >> data;
	deleteNode(T, data);
	cout << "�������:";
	preOrderTraverse(T);
	cout << endl;
	//�ͷ��ڴ�
	relese(T);
	system("pause");
    return 0;
}

