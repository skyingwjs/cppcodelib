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

//����ֵΪdata�Ľ�� �����ظýڵ��ַ
PNode MakeNode(ElemType data);

//�ͷ�p��ָ��Ľ��
void FreeNode(PNode P);

//����һ���յ�˫������
DList *InitList();

//����һ��˫������
void DestroyList(DList *pList);

//������� �ͷ�ԭ������ռ�
void ClearList(DList *pList);

//����ͷ����ַ
PNode GetHead(DList *pList);

//����β����ַ
PNode GetTail(DList *pList);

//���������С
int  GetSize(DList *pList);

//���ؽ��p��ֱ�Ӻ�̽��ĵ�ַ
PNode GetNext(PNode p);

//���ؽ��p��ֱ��ǰ�����ĵ�ַ
PNode GetPrevious(PNode p);

//��p��ָ��Ľ������һ�����֮ǰ
PNode InsFirst(DList *pList,PNode p);

//������ĵ�һ�����ɾ�� ���������ַ
PNode DelFirst(DList *pList);

//��ý���������
ElemType GetItem(PNode p);

//���ý���������
void SetItem(PNode p,ElemType data);

//ɾ������β�ڵ㲢�������ַ���ı������βָ��ָ���µĽ��
PNode Remove(DList *pList);

//ɾ��������ֵΪdata�Ľ��
PNode DelItem(DList *pList,ElemType data);

//ɾ�������е�i���ڵ�
PNode DelNode(DList *pList,int i);

//�������н��p֮ǰ �����µĽ��s
PNode InsBefore(DList *pList,PNode p,PNode s);

////�������н��p֮�� �����µĽ��s
PNode InsAfter(DList *pList,PNode p,PNode s);

//�����������е�i�����ĵ�ַ��λ�ã�
PNode LocatePos(DList *pList,int i);

//���ζ�������ÿ��Ԫ�ص��ú���visit()
void ListTraverse(DList *pList,void (*visit)());

#endif