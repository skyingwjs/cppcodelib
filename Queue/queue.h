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

//1.构造一个队列
Queue *InitQueue();
//2.销毁一个队列
void DestroyQueue(Queue *pq);
//3.清空一个队列
void ClearQueue(Queue *pq);
//4.判断一个队列是否为空
int IsEmpty(Queue *pq);
//5.返回队列大小
int GetSize(Queue *pq);
//6.返回对头元素
PNode GetFront(Queue *pq,Item *pItem);
//7.返回队尾元素
PNode GetRear(Queue *pq,Item *pItem);
//8.新元素入队
PNode EnQueue(Queue *pq,Item item);
//9.队头元素出队
PNode DeQueue(Queue *pq,Item *pItem);
//10.遍历队列各数据项并调用visit函数
void QueueTraverse(Queue *pq,void (*visit)(Item item));
//11.打印队列元素
void printQueueItem(Item item);
#endif