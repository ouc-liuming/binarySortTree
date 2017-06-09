// Search.cpp : 定义>控制台应用程序的入口点。
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
	cout << "查找数组为：";
	for (int i = 0; i < len; i++)
	{
		visit(b[i]);
	}
	cout << endl;
	initLinearList(list1,b,len);
	cout <<"顺序查找b[6]的位置为："<< sqSearch(list1,b[6],len)<<endl;
	cout << "折半查找b[2]的位置为："<<binarySearch(list1, b[2], len) << endl;	
	
	//排序二叉树
	ElemType c[] = {13,23,5,8,18,37,9};
	len = getArrayLength(c);
	BST T;
	cout << "根据数组：";
	for (int i = 0; i < len; i++)
	{
		visit(c[i]);
	}
	cout << endl;
	cout << "建立二叉排序树" << endl;
	createBST(T,c,len);
	cout << "中序遍历：" ;
	preOrderTraverse(T);
	cout << endl;
	cout << "请输入要删除的元素：";
	ElemType data;
	cin >> data;
	deleteNode(T, data);
	cout << "中序遍历:";
	preOrderTraverse(T);
	cout << endl;
	//释放内存
	relese(T);
	system("pause");
    return 0;
}

