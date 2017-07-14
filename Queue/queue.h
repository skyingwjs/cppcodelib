#ifndef __QUEUE_H__
#define __QUEUE_H__
typedef int Item;
typedef struct Node * PNode;
typedef struct Node{
	Item data;
	PNode next;
}Node;
typedef struct Queue{
	PNode front;
	PNode rear;
	int size;
}Queue;

//1.����һ������
Queue *InitQueue();
//2.����һ������
void DestroyQueue(Queue *pq);
//3.���һ������
void ClearQueue(Queue *pq);
//4.�ж�һ�������Ƿ�Ϊ��
int IsEmpty(Queue *pq);
//5.���ض��д�С
int GetSize(Queue *pq);
//6.���ض�ͷԪ��
PNode GetFront(Queue *pq,Item *pItem);
//7.���ض�βԪ��
PNode GetRear(Queue *pq,Item *pItem);
//8.��Ԫ�����
PNode EnQueue(Queue *pq,Item item);
//9.��ͷԪ�س���
PNode DeQueue(Queue *pq,Item *pItem);
//10.�������и����������visit����
void QueueTraverse(Queue *pq,void (*visit)(Item item));
//11.��ӡ����Ԫ��
void printQueueItem(Item item);
#endif