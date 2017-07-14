#pragma once
#ifndef __OFFER_H__
#define __OFFER_H__

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>

using namespace std;//此行不能漏掉

/*链表结点*/
typedef struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){
	}
}ListNode; 

/*复杂链表结点*/
typedef struct ComplexListNode{
	int val;
	ComplexListNode* next;
	ComplexListNode* sibling;
}ComplexListNode;




/*二叉树结点*/
typedef struct BinaryTreeNode{
	int val;
	BinaryTreeNode * left;
	BinaryTreeNode * right;

}BinaryTreeNode;

/*随机链二叉树结点*/
typedef struct ComplexBinaryTreeNode {
	int val;
	 ComplexBinaryTreeNode *left;
	 ComplexBinaryTreeNode *right;
	 ComplexBinaryTreeNode *parent;

}ComplexBinaryTreeNode;



/************************************************************************
1.二维数组中的查找
************************************************************************/
bool find(vector<vector<int> > array,int target);
bool find2(int *matrix,int rows,int cols,int number);

/************************************************************************
2.替换空格
************************************************************************/
void replaceSpace(char *str,int length);

/************************************************************************
3.从尾到头打印链表
************************************************************************/
vector<int> printListFromTailToHead( ListNode * head);
vector<int> printListFromTailToHead2( ListNode* head);
/*向链表中添加结点*/
void addToTail(ListNode **pHead,int value);
/*删除链表中第一个含有某值的结点*/
void removeNode(ListNode **pHead,int value);
#endif