#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
//1.构造一个空栈
Stack * InitStack(){
	Stack *ps=(Stack *)malloc(sizeof(Stack));
	if(NULL!=ps){
		ps->top=NULL;
		ps->size=0;
	}
	return ps;
}

//2.销毁一个栈
void DestroyStack(Stack *ps){
	if(IsEmpty(ps)!=1){
		ClearStack(ps);
	}
	free(ps);
}

//3.清空一个栈
void ClearStack(Stack *ps){
	while(IsEmpty(ps)!=1){
		Pop(ps,NULL);
	}
}

//4.判断栈是否为空
int IsEmpty(Stack *ps){
	if(ps->top==NULL&&ps->size==0)
		return 1;
	else 
		return 0;
}

//5.获得栈的大小
int GetSize(Stack *ps ){
	return ps->size;
}

//6.获取栈顶元素
PNode GetTop(Stack *ps,Item *pItem){
	if(IsEmpty(ps)!=1&&pItem!=NULL){
		*pItem=ps->top->data;
	}
	return ps->top;
}

//7.元素入栈
PNode Push(Stack *ps,Item item){
	PNode pNode=(PNode)malloc(sizeof(Node));
	if(NULL!=pNode){
		pNode->data=item;
		//上一次的栈顶结点的指针赋给当前入栈结点的down 
		//当前入栈元素作为新的栈顶元素
		pNode->down=GetTop(ps,NULL);
		//每入栈一个元素 栈的大小加1
		ps->size++;
		//更新栈顶指针
		ps->top=pNode;
	}
	return pNode;
}

//8.元素出栈
PNode Pop(Stack *ps,Item *pItem){
	PNode p=ps->top;
	if(IsEmpty(ps)!=1&&p!=NULL){
		if(NULL!=pItem)
			*pItem=p->data;
		ps->size--;
		ps->top=ps->top->down;
		free(p);
	}
	return ps->top;//返回新的栈顶指针
}

//9.遍历栈并访问visit函数
void StackTraverse(Stack *ps,void (*visit)(Item data)){
	PNode p=ps->top;
	int i=ps->size;
	while(i--){
		visit(p->data);
		p=p->down;
	}
}
//10.打印栈结点数据域函数
void printStackItem(Item data)
{
	printf("该节点元素为%d\n",data);
}