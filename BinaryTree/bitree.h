#pragma once 
#ifndef __BITREE_H__
#define __BITREE_H__

typedef int Item;
typedef struct BiTNode{
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	Item data;
}BiTNode,*BiTree;


//1.����һ���µĶ�����
BiTree InitBiTree(BiTNode *root);
//2.���ɽ��
BiTNode *MakeNode(Item item,BiTNode *lchild,BiTNode *rchild);
//3.�ͷŽ��
void FreeNode(BiTNode *pNode);
//4.���һ�ö�����
void ClearBiTree(BiTree tree);
//5.����һ�ö����� 
void DestroyBiTree(BiTree tree);
//6.�ж��Ƿ�Ϊ����
int IsEmpty(BiTree tree);
//7.�õ��������
int GetDepth(BiTree tree);
//8.���ظ�
BiTree GetRoot(BiTree tree);
//9.���ؽ��ֵ
Item GetItem(BiTNode *pNode);
//10.���ý��ֵ
void SetItem(BiTNode *pNode,Item item);
//11.����������
BiTree SetLChild(BiTree parent,BiTree lchild);
//12.����������
BiTree SetRChild(BiTree parent,BiTree rchild);
//13.����������
BiTree GetLChild(BiTree tree);
//14.����������
BiTree GetRChild(BiTree tree);
//15.����������
BiTree InsertChild(BiTree parent,int lr,BiTree child);
//16.ɾ������
void DeleteChild(BiTree parent,int lr);
//17.�������������
void PreOrderTraverse(BiTree tree,void(*visit)(Item));
//18.�������������
void InOrderTraverse(BiTree tree,void (*visit)(Item));
//19.�������������
void PostOrderTraverse(BiTree tree,void (*visit)(Item));
//20.��ӡ������Ԫ��
void PrintBitreeItem(Item item);


//21.��������� ����һ�����  �ݹ����
BiTree InsertNode(BiTree T,int x);
//21.��������� ����һ�����  �ǵݹ����
BiTNode * InsertNode2(BiTree T,int x);
//22.��������� ����Ԫ��  �ǵݹ�
BiTNode * SearchNode(BiTree T,int x);
//23.��������� ɾ��Ԫ�� 
bool DeleteNode(BiTree T,int x);



#endif