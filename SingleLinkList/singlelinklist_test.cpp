#include <stdio.h>
#include "singlelinklist.h"


int main(){
	Node *pHead=NULL;
	printf("1.初始化单向链表\n");
	initList(pHead);
	printf("\n");

	printf("2.创建一个单向链表，输入负数时结束创建链表\n");
	pHead=createList(pHead);
	printf("\n");

	printf("3.打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("4.获取单向链表结点个数\n");
	printf("%d\n",sizeList(pHead));
	printf("\n");

	printf("5.从链表中查找给定位置的元素\n");
	printf("链表中第3个元素为:%d\n",getElement(pHead,3));
	printf("\n");

	printf("6.从链表中查找与给定值相等的节点的数据域的地址\n");
	printf("链表中与1相等的元素节点的数据域地址为:%d\n",getElemAddr(pHead,1));
	printf("\n");

	printf("7.修改链表中某个节点的值\n");
	modifyElem(pHead,2,10);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("8.链表表头插入一个元素12\n");
	insertHeadList(&pHead,12);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("9.链表表尾插入一个元素13\n");
	insertLastList(&pHead,13);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("10.链表第3个节点处插入一个元素15\n");
	insertList(&pHead,3,15);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("11.删除链表头结点元素\n");
	deleteHeadList(&pHead);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("12.删除链表尾结点元素\n");
	deleteLastList(&pHead);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("13.删除链表的第3个元素\n");
	deleteList(&pHead,3);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("14.删除与3相等的结点\n");
	deleteXList(&pHead,3);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("15.交换第1个结点和第3个结点的值\n");
	exchangeList(&pHead,1,3);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("16.将链表进行排序\n");
	sortList(&pHead);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("17.向有序链表中插入一个结点，使链表依然有序\n");
	insertXList(&pHead,3);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("18.清除链表所有结点\n");
	clearList(&pHead);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");

	printf("19.判断链表是否为空\n");
	isEmptyList(pHead);
	printf("打印单向链表\n");
	printList(pHead);
	printf("\n");
	return 0;

}