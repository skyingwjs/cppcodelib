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

using namespace std;//���в���©��

/*������*/
typedef struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){
	}
}ListNode; 

/*����������*/
typedef struct ComplexListNode{
	int val;
	ComplexListNode* next;
	ComplexListNode* sibling;
}ComplexListNode;




/*���������*/
typedef struct BinaryTreeNode{
	int val;
	BinaryTreeNode * left;
	BinaryTreeNode * right;

}BinaryTreeNode;

/*��������������*/
typedef struct ComplexBinaryTreeNode {
	int val;
	 ComplexBinaryTreeNode *left;
	 ComplexBinaryTreeNode *right;
	 ComplexBinaryTreeNode *parent;

}ComplexBinaryTreeNode;



/************************************************************************
1.��ά�����еĲ���
************************************************************************/
bool find(vector<vector<int> > array,int target);
bool find2(int *matrix,int rows,int cols,int number);

/************************************************************************
2.�滻�ո�
************************************************************************/
void replaceSpace(char *str,int length);

/************************************************************************
3.��β��ͷ��ӡ����
************************************************************************/
vector<int> printListFromTailToHead( ListNode * head);
vector<int> printListFromTailToHead2( ListNode* head);
/*����������ӽ��*/
void addToTail(ListNode **pHead,int value);
/*ɾ�������е�һ������ĳֵ�Ľ��*/
void removeNode(ListNode **pHead,int value);
#endif