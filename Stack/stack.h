#pragma once
#ifndef __STACK_H__
#define __STACK_H__

typedef int Item;
typedef struct Node * PNode;

//����ջ�������
typedef struct Node{
	Item data;
	PNode down;
}Node;

//����ջ����
typedef struct Stack{
	PNode top;
	int size;
}Stack;


//1.����һ����ջ
Stack * InitStack();
//2.����һ��ջ
void DestroyStack(Stack *ps);
//3.��ջ�ÿ�
void ClearStack(Stack *ps);
//4.�ж�ջ�Ƿ�Ϊ��ջ
int IsEmpty(Stack *ps);
//5.����ջ�Ĵ�С
int GetSize(Stack *ps );
//6.����ջ��Ԫ��
PNode GetTop(Stack *ps,Item *pItem);
//7.Ԫ����ջ
PNode Push(Stack *ps,Item item);
//8.Ԫ�س�ջ
PNode Pop(Stack *ps,Item *pItem);
//9.����ջ������visit����
void StackTraverse(Stack *ps,void (*visit) (Item data));
//10.��ӡջ���Ԫ��
void printStackItem(Item data);
#endif
