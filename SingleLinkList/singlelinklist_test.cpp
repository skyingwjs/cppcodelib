#include <stdio.h>
#include "singlelinklist.h"


int main(){
	Node *pHead=NULL;
	printf("1.��ʼ����������\n");
	initList(pHead);
	printf("\n");

	printf("2.����һ�������������븺��ʱ������������\n");
	pHead=createList(pHead);
	printf("\n");

	printf("3.��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("4.��ȡ�������������\n");
	printf("%d\n",sizeList(pHead));
	printf("\n");

	printf("5.�������в��Ҹ���λ�õ�Ԫ��\n");
	printf("�����е�3��Ԫ��Ϊ:%d\n",getElement(pHead,3));
	printf("\n");

	printf("6.�������в��������ֵ��ȵĽڵ��������ĵ�ַ\n");
	printf("��������1��ȵ�Ԫ�ؽڵ���������ַΪ:%d\n",getElemAddr(pHead,1));
	printf("\n");

	printf("7.�޸�������ĳ���ڵ��ֵ\n");
	modifyElem(pHead,2,10);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("8.�����ͷ����һ��Ԫ��12\n");
	insertHeadList(&pHead,12);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("9.�����β����һ��Ԫ��13\n");
	insertLastList(&pHead,13);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("10.�����3���ڵ㴦����һ��Ԫ��15\n");
	insertList(&pHead,3,15);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("11.ɾ������ͷ���Ԫ��\n");
	deleteHeadList(&pHead);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("12.ɾ������β���Ԫ��\n");
	deleteLastList(&pHead);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("13.ɾ������ĵ�3��Ԫ��\n");
	deleteList(&pHead,3);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("14.ɾ����3��ȵĽ��\n");
	deleteXList(&pHead,3);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("15.������1�����͵�3������ֵ\n");
	exchangeList(&pHead,1,3);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("16.�������������\n");
	sortList(&pHead);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("17.�����������в���һ����㣬ʹ������Ȼ����\n");
	insertXList(&pHead,3);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("18.����������н��\n");
	clearList(&pHead);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");

	printf("19.�ж������Ƿ�Ϊ��\n");
	isEmptyList(pHead);
	printf("��ӡ��������\n");
	printList(pHead);
	printf("\n");
	return 0;

}