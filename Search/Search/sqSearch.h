#pragma once
#include "stdafx.h"
#include "iostream"
using namespace std;
#define INIT_LISTSIZE 100
typedef int ElemType;
typedef int Status;
template<typename T>
int getArrayLength(T &array) {
	return (sizeof(array)/sizeof(array[0]));
}
typedef struct LinearList {
	ElemType *elem;
	int length;
}List;
bool initLinearList(List &L,ElemType b[],int len){
	L.elem = (ElemType *)malloc(INIT_LISTSIZE*sizeof(ElemType));
	if (L.elem==NULL)
	{
		cout << "内存分配失败！" << endl;
		exit(OVERFLOW);
	}
	L.length = 0;
	for (int i = 1; i <= len; i++)
	{
		L.elem[i] = b[i - 1];
		++L.length;
	}
	return true;
}
//顺序查找,返回所查找元素的位置
Status sqSearch(List &L, ElemType key, int len) {
	L.elem[0] = key;
	int j;
	for (j = len; L.elem[j] != key; j--);
	return j;
}
//折半查找
Status binarySearch(List &L, ElemType key, int len) {
	int low = 1, high = len;
	while (low<=high)
	{
		int mid = (low + high) / 2;
		if (L.elem[mid] == key){
			return mid;
		}
		else
		{
			if (key < L.elem[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
}