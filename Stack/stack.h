#pragma once
#ifndef __STACK_H__
#define __STACK_H__

typedef int Item;
typedef struct Node * PNode;

//定义栈结点类型
typedef struct Node{
	Item data;
	PNode down;
}Node;

//定义栈类型
typedef struct Stack{
	PNode top;
	int size;
}Stack;


//1.构造一个空栈
Stack * InitStack();
//2.销毁一个栈
void DestroyStack(Stack *ps);
//3.把栈置空
void ClearStack(Stack *ps);
//4.判断栈是否为空栈
int IsEmpty(Stack *ps);
//5.返回栈的大小
int GetSize(Stack *ps );
//6.返回栈定元素
PNode GetTop(Stack *ps,Item *pItem);
//7.元素入栈
PNode Push(Stack *ps,Item item);
//8.元素出栈
PNode Pop(Stack *ps,Item *pItem);
//9.遍历栈并访问visit函数
void StackTraverse(Stack *ps,void (*visit) (Item data));
//10.打印栈结点元素
void printStackItem(Item data);
#endif
