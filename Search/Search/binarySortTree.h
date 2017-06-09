#pragma once
#include "stdafx.h"
#include "iostream"
using namespace std;
//设计数据结构，构造二叉树
typedef struct node {
	ElemType data;
	struct node *lchild, *rchild;
}*BST;
//插入元素
bool insertBST(BST &T, ElemType element) {
	if (T==NULL)
	{
		T = new node;
		T->data = element;
		T->lchild = T->rchild = NULL;
		return true;
	}
	if (T->data==element)   //元素的值不能和树中已有的值相等
	{
		return false;
	}
	if (element<T->data)
	{
		insertBST(T->lchild,element);
	}
	else
	{
		insertBST(T->rchild,element);
	}
}
//创建二叉排序树
void createBST(BST &T,ElemType array[],int len){   //Debug模式下，未初始化的栈内存上的指针全部填成0xcccccccc;
	T = NULL;
	for (int i = 0; i < len; i++)
	{
		insertBST(T,array[i]);
	}
}
void visit(ElemType elem) {
	cout << elem << "  ";
}
//中序遍历
void preOrderTraverse(BST &T) {
	if (T!=NULL)
	{
		preOrderTraverse(T->lchild);
		visit(T->data);
		preOrderTraverse(T->rchild);
	}
}
//释放内存
void relese(BST &T) {
	if (T==NULL)
	{
		return;
	}
	relese(T->lchild);
	relese(T->rchild);
	delete T;
}
//删除某个结点
bool deleteNode(BST &T, ElemType element) {
	if (T==NULL)
	{
		return false;
	}
	BST p,q,s,parent;
	p = T;
	while (p!=NULL)
	{
		if (p->data == element)  break;
		parent = p;
		p = (p->data < element) ? p->rchild: p->lchild;
	}
	if (p==NULL)
	{
		cout << "该二叉排序树中无您要删除的值！"<<endl;
		return false;
	}
	if ((p->lchild==NULL)&&(p->rchild==NULL))
	{
		//重置其父亲结点的左右子孩子
		if (parent->lchild != NULL&&parent->lchild->data==element)
		{
			parent->lchild = NULL;
		}
		if (parent->rchild!=NULL&&parent->rchild->data==element)
		{
			parent->rchild = NULL;
		}
		return true;
	}
	else if (p->lchild!=NULL&&p->rchild==NULL)
	{
		//要让p的左孩子接上
		s=p->lchild;
		p ->data= s->data;
		p->lchild = s->lchild;
		delete s;
		return true;
	}
	else if (p->lchild==NULL&&p->rchild!=NULL)
	{
		//要让p的右孩子接上
		s = p->rchild;
		p->data = s->data;
		p->rchild = s->rchild;
		delete s;
		return true;
	}
	else
	{
		q = p;
		s = p->lchild;
		while (s->rchild!=NULL)
		{
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q!=p)
		{
			q->rchild = s->lchild;
		}
		else
		{
			q->lchild = s->lchild;
		}
		delete s;
		return true;
	}
}