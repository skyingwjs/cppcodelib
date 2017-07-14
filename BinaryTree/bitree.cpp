#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "bitree.h"

//1.由根节点创建一棵新的二叉树

BiTree InitBiTree(BiTNode *root){
	BiTree tree=root;
	return tree;
}


//2.生成结点
BiTNode *MakeNode(Item item,BiTNode *lchild,BiTNode *rchild){
	BiTNode * pNode=(BiTNode *)malloc(sizeof(BiTNode));
	if(pNode){
		pNode->data=item;
		pNode->lchild=lchild;
		pNode->rchild=rchild;
	}
	return pNode;
}


//3.释放结点
void FreeNode(BiTNode* pNode){

	if(NULL!=pNode){
		free(pNode);
	}
}

//4.清空一棵二叉树 递归迭代
void ClearBiTree(BiTree tree){
	BiTNode *pNode=tree;
	if(pNode->lchild!=NULL)
		ClearBiTree(pNode->lchild);
	if(pNode->rchild!=NULL)
		ClearBiTree(pNode->rchild);
	FreeNode(pNode);
}

//5.销毁一棵二叉树
void DestroyBiTree(BiTree tree){
	if(tree){
		ClearBiTree(tree);
	}
}

//6.判断是否为空
int IsEmpty(BiTree tree){
	if(tree==NULL)
		return 1;
	else
		return 0;
}

//7.返回树的深度  迭代
int GetDepth(BiTree tree){

	int cd,ld,rd;
	cd=ld=rd=0;
	if(tree){
		ld=GetDepth(tree->lchild);
		rd=GetDepth(tree->rchild);
		cd = (ld > rd ? ld : rd);
		return cd+1;
	}
	else
		return 0;
}

//8.返回根
BiTree GetRoot(BiTree tree){
	return tree;
}

//9.返回结点值
Item GetItem(BiTNode *pNode){
	if(pNode!=NULL)
		return pNode->data;
}

//10.设置结点值
void SetItem(BiTNode *pNode,Item item){
	pNode->data=item;
}

//11.设置左子树
BiTree SetLChild(BiTree parent,BiTree lchild){
	if(parent!=NULL&&lchild!=NULL){
		parent->lchild=lchild;
		return lchild;
	}
	else
		return NULL;

}

//12.设置右子树
BiTree SetRChild(BiTree parent,BiTree rchild){
	if(parent!=NULL&&rchild!=NULL){
		parent->rchild=rchild;
		return rchild;
	}
	else
		return NULL;
}

//13.返回左子树
BiTree GetLChild(BiTree tree)
{
	if(tree)
		return tree->lchild;
	return NULL;
}

//14.返回右子树
BiTree GetRChild(BiTree tree)
{
	if(tree)
		return tree->rchild;
	return NULL;
}

//15.插入新子树
BiTree InsertChild(BiTree parent,int lr,BiTree child){

	if(parent){

		if (lr==0&&parent->lchild==NULL)
		{
			parent->lchild=child;
			return child;
		}
		if(lr==1&&parent->rchild==NULL)
		{
			parent->rchild=child;
			return child;
		}
	}
	return NULL;
}


//16.删除子树
void DeleteChild(BiTree parent,int lr){
	if (parent)
	{
		if (lr==0&&parent->lchild!=NULL)
		{
			FreeNode(parent->lchild);
			parent->lchild=NULL;
		}
		if (lr==1&&parent->rchild!=NULL)
		{
			FreeNode(parent->rchild);
			parent->rchild=NULL;
		}
	}
}


//17.先序遍历二叉树  递归
void PreOrderTraverse(BiTree tree,void(*visit)(Item item)){
	BiTNode *pNode=tree;
	if (pNode)
	{
		visit(pNode->data);
		PreOrderTraverse(pNode->lchild,visit);
		PreOrderTraverse(pNode->rchild,visit);
	}
}

//18.中序遍历二叉树 递归
void InOrderTraverse(BiTree tree,void(*visit)(Item item)){
	BiTNode *pNode=tree;
	if (pNode)
	{
		InOrderTraverse(pNode->lchild,visit);
		visit(pNode->data);
		InOrderTraverse(pNode->rchild,visit);
	}
}

//19.后序遍历二叉树 递归
void PostOrderTraverse(BiTree tree,void(*visit)(Item item)){
	BiTNode *pNode=tree;
	if (pNode)
	{
		PostOrderTraverse(pNode->lchild,visit);
		PostOrderTraverse(pNode->rchild,visit);
		visit(pNode->data);
	}
}

//20.打印二叉树元素
void PrintBitreeItem(Item item){
	 printf("%d ",item);
}

//21.二叉查找树 插入一个结点  递归插入
BiTree InsertNode(BiTree T,int x){  

	//这里创建一个要插入的节点  
	BiTNode *pInsert = (BiTNode *)malloc(sizeof(BiTNode));  
	pInsert->data = x;  
	pInsert->lchild = NULL;  
	pInsert->rchild = NULL;  

	if (T == NULL) {  
		T = pInsert;  
	}else if(x < T->data){
		T->lchild=InsertNode(T->lchild, x);
	}else{
		T->rchild=InsertNode(T->rchild, x);
	}

	return T;  

} 

//21.二叉查找树 插入一个结点  非递归插入
BiTNode * InsertNode2(BiTree T,int x){
	BiTNode * root=T;
	//这里创建一个要插入的节点  
	BiTNode *pInsert = (BiTNode *)malloc(sizeof(BiTNode));  
	pInsert->data = x;  
	pInsert->lchild = NULL;  
	pInsert->rchild = NULL;  

	if (T == NULL) {  
		root =T = pInsert;  
		return root; 
	}

	while(T->lchild!=pInsert&&T->rchild!=pInsert){
		if(x<T->data){
			if(T->lchild){
				T=T->lchild;
			}else{
				T->lchild=pInsert;
			}
		}else{
			if(T->rchild){
				T=T->rchild;
			}else{
				T->rchild=pInsert;
			}
		}
	}
	return root;
}

//22.二叉查找树 查找元素  非递归
BiTNode * SearchNode(BiTree T,int x){
	bool solve=false;
	while (T&&!solve){
		if(x==T->data){
			solve=true;
		}else if(x<T->data){
			T=T->lchild;
		}else{
			T=T->rchild;
		}
	}
	if(T==NULL){
		printf("未找到指定的元素\n");
	}
	return T;
}

//23.二叉查找树 删除元素 
bool DeleteNode(BiTree root,int x){
	bool isFind=false;//返回一个标志，表示是否找到被删元素 
	BiTNode *pNode=root;
	BiTNode *pParent=NULL;
	while(pNode&&!isFind){
		if (x==pNode->data){//寻找被删元素 
			isFind=true;
		}else if(x<pNode->data){//沿左子树找 
			pParent=pNode;
			pNode=pNode->lchild;
		}else {//沿右子树找 
			pParent=pNode;
			pNode=pNode->rchild;
		}
	}

	if (pNode==NULL)
	{
		printf("未找到\n");
	}
	if(pNode->lchild==NULL&&pNode->rchild==NULL){//pNode为叶子结点
		if(pNode==root){//p为根节点
			root=NULL;
		}else if(pNode==pParent->lchild){
			pParent->lchild=NULL;
		}else{
			pParent->rchild=NULL;
		}
	}else if(pNode->lchild==NULL||pNode->rchild==NULL){//p为单支子树
		if(pNode==root){//p为根节点
			if(pNode->lchild==NULL){
				root=pNode->rchild;
			}else{
				root=pNode->lchild;
			}
		}else{
			if(pNode==pParent->lchild&&pNode->lchild){//pNode是pParent左子树且pNode有左子树
				pParent->lchild=pNode->lchild;//将pNode的左子树连到pParent的左指针上去
			}else if(pNode==pParent->lchild&&pNode->rchild){
				pParent->lchild=pNode->rchild;
			}else if(pNode==pParent->rchild&&pNode->lchild){
				pParent->rchild=pNode->lchild;
			}else{
				pParent->rchild=pNode->rchild;
			}
		}
		free(pNode);
	}else{//pNode的左右子树均不为空
		BiTNode *pTemp=pNode;
		BiTNode *pCur=pNode->lchild;//从pNode的左子节点开始
		while(pCur->rchild){ //找到pNode的前驱，即pNode左子树中值最大的节点 
			pTemp=pCur;
			pCur=pCur->rchild;
		}
		pNode->data=pCur->data;//把节点pCur的值赋给pNode 
		if (pTemp==pNode){
			pNode->lchild=pCur->lchild;
		}else{
			pNode->rchild=pCur->rchild;
		}
		free(pNode);
	}

	return isFind;
}