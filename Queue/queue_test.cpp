#include <stdio.h>
#include "queue.h"

int main(){
	Queue *pq = InitQueue();
	int i,item;
	printf("0-9������Ӳ�������£�\n");
	for(i=0;i<10;i++)
	{
		EnQueue(pq,i);
		GetRear(pq,&item);
		printf("%d ",item);
	}
	
	printf("\n�Ӷ�ͷ����β��������ÿ��Ԫ��ִ��print������\n");    
	QueueTraverse(pq,printQueueItem);
	
	printf("������Ԫ�����γ����в�������£�\n");
	for(i=0;i<10;i++)
	{
		DeQueue(pq,&item);
		printf("%d ",item);
	}
	ClearQueue(pq);
	if(IsEmpty(pq))
		printf("\n�������ÿճɹ�\n");
	DestroyQueue(pq);
	printf("�����ѱ�����\n");
	
	return 0;
}