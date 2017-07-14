#pragma  once
#ifndef __DOUBLE_LIST_H___
#define __DOUBLE_LIST_H___

typedef int ElemType;
typedef struct Node* PNode;
typedef struct Node{
	ElemType data;
	PNode previous;
	PNode next;
}Node;

typedef struct DList{
	PNode head;
	PNode tail;
	int size;
}DList;

//构造值为data的结点 并返回该节点地址
PNode MakeNode(ElemType data);

//释放p所指向的结点
void FreeNode(PNode P);

//构造一个空的双向链表
DList *InitList();

//销毁一个双向链表
void DestroyList(DList *pList);

//清空链表 释放原链表结点空间
void ClearList(DList *pList);

//返回头结点地址
PNode GetHead(DList *pList);

//返回尾结点地址
PNode GetTail(DList *pList);

//返回链表大小
int  GetSize(DList *pList);

//返回结点p的直接后继结点的地址
PNode GetNext(PNode p);

//返回结点p的直接前驱结点的地址
PNode GetPrevious(PNode p);

//将p所指向的结点插入第一个结点之前
PNode InsFirst(DList *pList,PNode p);

//将链表的第一个结点删除 并返回其地址
PNode DelFirst(DList *pList);

//获得结点的数据项
ElemType GetItem(PNode p);

//设置结点的数据项
void SetItem(PNode p,ElemType data);

//删除链表尾节点并返回其地址，改变链表表尾指针指向新的结点
PNode Remove(DList *pList);

//删除链表中值为data的结点
PNode DelItem(DList *pList,ElemType data);

//删除链表中第i个节点
PNode DelNode(DList *pList,int i);

//在链表中结点p之前 插入新的结点s
PNode InsBefore(DList *pList,PNode p,PNode s);

////在链表中结点p之后 插入新的结点s
PNode InsAfter(DList *pList,PNode p,PNode s);

//返回在链表中第i个结点的地址（位置）
PNode LocatePos(DList *pList,int i);

//依次对链表中每个元素调用函数visit()
void ListTraverse(DList *pList,void (*visit)());

#endif