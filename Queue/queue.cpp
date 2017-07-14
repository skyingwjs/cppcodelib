#pragma once 
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

//1.构造一个队列
Queue *InitQueue(){
	Queue *pq=(Queue*)malloc(sizeof(Queue));
	if(NULL!=pq){
		pq->front=NULL;
		pq->rear=NULL;
		pq->size=0;
	}
	return pq;
}

//2.销毁一个队列
void DestroyQueue(Queue *pq){
	if(IsEmpty(pq)!=1){
		ClearQueue(pq);
	}
	free(pq);
}

//3.清空一个队列
void ClearQueue(Queue *pq){
	while(IsEmpty(pq)!=1){
		DeQueue(pq,NULL);
	}
}

//4.判断一个队列是否为空
int IsEmpty(Queue *pq){
	if(pq->front==NULL&&pq->rear==NULL&&pq->size==0){
		return 1;
	}
	else{
		return 0;
	}
}

//5.返回队列大小
int GetSize(Queue *pq){
	return pq->size;
}

//6.返回对头元素
PNode GetFront(Queue *pq,Item *pItem){
	if(IsEmpty(pq)!=1&&pItem!=NULL){
		*pItem=pq->front->data;
	}
	return pq->front;
}

//7.返回队尾元素
PNode GetRear(Queue *pq,Item *pItem){
	if(IsEmpty(pq)!=1&&pItem!=NULL){
		*pItem=pq->rear->data;
	}
	return pq->rear;
}

//8.新元素入队
PNode EnQueue(Queue *pq,Item item){
	PNode pNode=(PNode)malloc(sizeof(Node));
	if(NULL!=pNode){
		pNode->data=item;
		pNode->next=NULL;
		if(IsEmpty(pq)){//队列为空时  第一个元素入队
			pq->front=pNode;
		}
		else{
			pq->rear->next=pNode;
		}
		pq->rear=pNode;//更新新的队尾指针
		pq->size++;
	}
	return pNode;
}

//9.队头元素出队
PNode DeQueue(Queue *pq,Item *pItem){
	PNode pNode=pq->front;
	if(IsEmpty(pq)!=1&&pNode!=NULL){
		if(pItem!=NULL)
			*pItem=pNode->data;
		pq->size--;
		pq->front=pNode->next;
		free(pNode);
		if(pq->size==0)
			pq->rear=NULL;

	}
	return pNode;
}

//10.遍历队列各数据项并调用visit函数
void QueueTraverse(Queue *pq,void (*visit)(Item item)){
	PNode pNode=pq->front;
	int i=pq->size;
	while(i--){
		visit(pNode->data);
		pNode=pNode->next;
	}
}

//11.打印队列元素
void printQueueItem(Item item)
{
	printf("该节点元素为%d\n",item);
}