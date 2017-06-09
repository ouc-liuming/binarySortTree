#pragma once
#include "stdafx.h"
#include "iostream"
using namespace std;
//������ݽṹ�����������
typedef struct node {
	ElemType data;
	struct node *lchild, *rchild;
}*BST;
//����Ԫ��
bool insertBST(BST &T, ElemType element) {
	if (T==NULL)
	{
		T = new node;
		T->data = element;
		T->lchild = T->rchild = NULL;
		return true;
	}
	if (T->data==element)   //Ԫ�ص�ֵ���ܺ��������е�ֵ���
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
//��������������
void createBST(BST &T,ElemType array[],int len){   //Debugģʽ�£�δ��ʼ����ջ�ڴ��ϵ�ָ��ȫ�����0xcccccccc;
	T = NULL;
	for (int i = 0; i < len; i++)
	{
		insertBST(T,array[i]);
	}
}
void visit(ElemType elem) {
	cout << elem << "  ";
}
//�������
void preOrderTraverse(BST &T) {
	if (T!=NULL)
	{
		preOrderTraverse(T->lchild);
		visit(T->data);
		preOrderTraverse(T->rchild);
	}
}
//�ͷ��ڴ�
void relese(BST &T) {
	if (T==NULL)
	{
		return;
	}
	relese(T->lchild);
	relese(T->rchild);
	delete T;
}
//ɾ��ĳ�����
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
		cout << "�ö���������������Ҫɾ����ֵ��"<<endl;
		return false;
	}
	if ((p->lchild==NULL)&&(p->rchild==NULL))
	{
		//�����丸�׽��������Ӻ���
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
		//Ҫ��p�����ӽ���
		s=p->lchild;
		p ->data= s->data;
		p->lchild = s->lchild;
		delete s;
		return true;
	}
	else if (p->lchild==NULL&&p->rchild!=NULL)
	{
		//Ҫ��p���Һ��ӽ���
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