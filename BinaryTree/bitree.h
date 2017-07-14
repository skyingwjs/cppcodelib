#pragma once 
#ifndef __BITREE_H__
#define __BITREE_H__

typedef int Item;
typedef struct BiTNode{
	struct BiTNode *lchild;
	struct BiTNode *rchild;
	Item data;
}BiTNode,*BiTree;


//1.构造一棵新的二叉树
BiTree InitBiTree(BiTNode *root);
//2.生成结点
BiTNode *MakeNode(Item item,BiTNode *lchild,BiTNode *rchild);
//3.释放结点
void FreeNode(BiTNode *pNode);
//4.清空一棵二叉树
void ClearBiTree(BiTree tree);
//5.销毁一棵二叉树 
void DestroyBiTree(BiTree tree);
//6.判断是否为空树
int IsEmpty(BiTree tree);
//7.得到树的深度
int GetDepth(BiTree tree);
//8.返回根
BiTree GetRoot(BiTree tree);
//9.返回结点值
Item GetItem(BiTNode *pNode);
//10.设置结点值
void SetItem(BiTNode *pNode,Item item);
//11.设置左子树
BiTree SetLChild(BiTree parent,BiTree lchild);
//12.设置右子树
BiTree SetRChild(BiTree parent,BiTree rchild);
//13.返回左子树
BiTree GetLChild(BiTree tree);
//14.返回右子树
BiTree GetRChild(BiTree tree);
//15.插入新子树
BiTree InsertChild(BiTree parent,int lr,BiTree child);
//16.删除子树
void DeleteChild(BiTree parent,int lr);
//17.先序遍历二叉树
void PreOrderTraverse(BiTree tree,void(*visit)(Item));
//18.中序遍历二叉树
void InOrderTraverse(BiTree tree,void (*visit)(Item));
//19.后序遍历二叉树
void PostOrderTraverse(BiTree tree,void (*visit)(Item));
//20.打印二叉树元素
void PrintBitreeItem(Item item);


//21.二叉查找树 插入一个结点  递归插入
BiTree InsertNode(BiTree T,int x);
//21.二叉查找树 插入一个结点  非递归插入
BiTNode * InsertNode2(BiTree T,int x);
//22.二叉查找树 查找元素  非递归
BiTNode * SearchNode(BiTree T,int x);
//23.二叉查找树 删除元素 
bool DeleteNode(BiTree T,int x);



#endif