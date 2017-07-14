#pragma once 
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

//1.����һ������
Queue *InitQueue(){
	Queue *pq=(Queue*)malloc(sizeof(Queue));
	if(NULL!=pq){
		pq->front=NULL;
		pq->rear=NULL;
		pq->size=0;
	}
	return pq;
}

//2.����һ������
void DestroyQueue(Queue *pq){
	if(IsEmpty(pq)!=1){
		ClearQueue(pq);
	}
	free(pq);
}

//3.���һ������
void ClearQueue(Queue *pq){
	while(IsEmpty(pq)!=1){
		DeQueue(pq,NULL);
	}
}

//4.�ж�һ�������Ƿ�Ϊ��
int IsEmpty(Queue *pq){
	if(pq->front==NULL&&pq->rear==NULL&&pq->size==0){
		return 1;
	}
	else{
		return 0;
	}
}

//5.���ض��д�С
int GetSize(Queue *pq){
	return pq->size;
}

//6.���ض�ͷԪ��
PNode GetFront(Queue *pq,Item *pItem){
	if(IsEmpty(pq)!=1&&pItem!=NULL){
		*pItem=pq->front->data;
	}
	return pq->front;
}

//7.���ض�βԪ��
PNode GetRear(Queue *pq,Item *pItem){
	if(IsEmpty(pq)!=1&&pItem!=NULL){
		*pItem=pq->rear->data;
	}
	return pq->rear;
}

//8.��Ԫ�����
PNode EnQueue(Queue *pq,Item item){
	PNode pNode=(PNode)malloc(sizeof(Node));
	if(NULL!=pNode){
		pNode->data=item;
		pNode->next=NULL;
		if(IsEmpty(pq)){//����Ϊ��ʱ  ��һ��Ԫ�����
			pq->front=pNode;
		}
		else{
			pq->rear->next=pNode;
		}
		pq->rear=pNode;//�����µĶ�βָ��
		pq->size++;
	}
	return pNode;
}

//9.��ͷԪ�س���
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

//10.�������и����������visit����
void QueueTraverse(Queue *pq,void (*visit)(Item item)){
	PNode pNode=pq->front;
	int i=pq->size;
	while(i--){
		visit(pNode->data);
		pNode=pNode->next;
	}
}

//11.��ӡ����Ԫ��
void printQueueItem(Item item)
{
	printf("�ýڵ�Ԫ��Ϊ%d\n",item);
}