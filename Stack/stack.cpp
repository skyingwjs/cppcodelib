#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
//1.����һ����ջ
Stack * InitStack(){
	Stack *ps=(Stack *)malloc(sizeof(Stack));
	if(NULL!=ps){
		ps->top=NULL;
		ps->size=0;
	}
	return ps;
}

//2.����һ��ջ
void DestroyStack(Stack *ps){
	if(IsEmpty(ps)!=1){
		ClearStack(ps);
	}
	free(ps);
}

//3.���һ��ջ
void ClearStack(Stack *ps){
	while(IsEmpty(ps)!=1){
		Pop(ps,NULL);
	}
}

//4.�ж�ջ�Ƿ�Ϊ��
int IsEmpty(Stack *ps){
	if(ps->top==NULL&&ps->size==0)
		return 1;
	else 
		return 0;
}

//5.���ջ�Ĵ�С
int GetSize(Stack *ps ){
	return ps->size;
}

//6.��ȡջ��Ԫ��
PNode GetTop(Stack *ps,Item *pItem){
	if(IsEmpty(ps)!=1&&pItem!=NULL){
		*pItem=ps->top->data;
	}
	return ps->top;
}

//7.Ԫ����ջ
PNode Push(Stack *ps,Item item){
	PNode pNode=(PNode)malloc(sizeof(Node));
	if(NULL!=pNode){
		pNode->data=item;
		//��һ�ε�ջ������ָ�븳����ǰ��ջ����down 
		//��ǰ��ջԪ����Ϊ�µ�ջ��Ԫ��
		pNode->down=GetTop(ps,NULL);
		//ÿ��ջһ��Ԫ�� ջ�Ĵ�С��1
		ps->size++;
		//����ջ��ָ��
		ps->top=pNode;
	}
	return pNode;
}

//8.Ԫ�س�ջ
PNode Pop(Stack *ps,Item *pItem){
	PNode p=ps->top;
	if(IsEmpty(ps)!=1&&p!=NULL){
		if(NULL!=pItem)
			*pItem=p->data;
		ps->size--;
		ps->top=ps->top->down;
		free(p);
	}
	return ps->top;//�����µ�ջ��ָ��
}

//9.����ջ������visit����
void StackTraverse(Stack *ps,void (*visit)(Item data)){
	PNode p=ps->top;
	int i=ps->size;
	while(i--){
		visit(p->data);
		p=p->down;
	}
}
//10.��ӡջ�����������
void printStackItem(Item data)
{
	printf("�ýڵ�Ԫ��Ϊ%d\n",data);
}