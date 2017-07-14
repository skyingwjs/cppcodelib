#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "bitree.h"

//1.�ɸ��ڵ㴴��һ���µĶ�����

BiTree InitBiTree(BiTNode *root){
	BiTree tree=root;
	return tree;
}


//2.���ɽ��
BiTNode *MakeNode(Item item,BiTNode *lchild,BiTNode *rchild){
	BiTNode * pNode=(BiTNode *)malloc(sizeof(BiTNode));
	if(pNode){
		pNode->data=item;
		pNode->lchild=lchild;
		pNode->rchild=rchild;
	}
	return pNode;
}


//3.�ͷŽ��
void FreeNode(BiTNode* pNode){

	if(NULL!=pNode){
		free(pNode);
	}
}

//4.���һ�ö����� �ݹ����
void ClearBiTree(BiTree tree){
	BiTNode *pNode=tree;
	if(pNode->lchild!=NULL)
		ClearBiTree(pNode->lchild);
	if(pNode->rchild!=NULL)
		ClearBiTree(pNode->rchild);
	FreeNode(pNode);
}

//5.����һ�ö�����
void DestroyBiTree(BiTree tree){
	if(tree){
		ClearBiTree(tree);
	}
}

//6.�ж��Ƿ�Ϊ��
int IsEmpty(BiTree tree){
	if(tree==NULL)
		return 1;
	else
		return 0;
}

//7.�����������  ����
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

//8.���ظ�
BiTree GetRoot(BiTree tree){
	return tree;
}

//9.���ؽ��ֵ
Item GetItem(BiTNode *pNode){
	if(pNode!=NULL)
		return pNode->data;
}

//10.���ý��ֵ
void SetItem(BiTNode *pNode,Item item){
	pNode->data=item;
}

//11.����������
BiTree SetLChild(BiTree parent,BiTree lchild){
	if(parent!=NULL&&lchild!=NULL){
		parent->lchild=lchild;
		return lchild;
	}
	else
		return NULL;

}

//12.����������
BiTree SetRChild(BiTree parent,BiTree rchild){
	if(parent!=NULL&&rchild!=NULL){
		parent->rchild=rchild;
		return rchild;
	}
	else
		return NULL;
}

//13.����������
BiTree GetLChild(BiTree tree)
{
	if(tree)
		return tree->lchild;
	return NULL;
}

//14.����������
BiTree GetRChild(BiTree tree)
{
	if(tree)
		return tree->rchild;
	return NULL;
}

//15.����������
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


//16.ɾ������
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


//17.�������������  �ݹ�
void PreOrderTraverse(BiTree tree,void(*visit)(Item item)){
	BiTNode *pNode=tree;
	if (pNode)
	{
		visit(pNode->data);
		PreOrderTraverse(pNode->lchild,visit);
		PreOrderTraverse(pNode->rchild,visit);
	}
}

//18.������������� �ݹ�
void InOrderTraverse(BiTree tree,void(*visit)(Item item)){
	BiTNode *pNode=tree;
	if (pNode)
	{
		InOrderTraverse(pNode->lchild,visit);
		visit(pNode->data);
		InOrderTraverse(pNode->rchild,visit);
	}
}

//19.������������� �ݹ�
void PostOrderTraverse(BiTree tree,void(*visit)(Item item)){
	BiTNode *pNode=tree;
	if (pNode)
	{
		PostOrderTraverse(pNode->lchild,visit);
		PostOrderTraverse(pNode->rchild,visit);
		visit(pNode->data);
	}
}

//20.��ӡ������Ԫ��
void PrintBitreeItem(Item item){
	 printf("%d ",item);
}

//21.��������� ����һ�����  �ݹ����
BiTree InsertNode(BiTree T,int x){  

	//���ﴴ��һ��Ҫ����Ľڵ�  
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

//21.��������� ����һ�����  �ǵݹ����
BiTNode * InsertNode2(BiTree T,int x){
	BiTNode * root=T;
	//���ﴴ��һ��Ҫ����Ľڵ�  
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

//22.��������� ����Ԫ��  �ǵݹ�
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
		printf("δ�ҵ�ָ����Ԫ��\n");
	}
	return T;
}

//23.��������� ɾ��Ԫ�� 
bool DeleteNode(BiTree root,int x){
	bool isFind=false;//����һ����־����ʾ�Ƿ��ҵ���ɾԪ�� 
	BiTNode *pNode=root;
	BiTNode *pParent=NULL;
	while(pNode&&!isFind){
		if (x==pNode->data){//Ѱ�ұ�ɾԪ�� 
			isFind=true;
		}else if(x<pNode->data){//���������� 
			pParent=pNode;
			pNode=pNode->lchild;
		}else {//���������� 
			pParent=pNode;
			pNode=pNode->rchild;
		}
	}

	if (pNode==NULL)
	{
		printf("δ�ҵ�\n");
	}
	if(pNode->lchild==NULL&&pNode->rchild==NULL){//pNodeΪҶ�ӽ��
		if(pNode==root){//pΪ���ڵ�
			root=NULL;
		}else if(pNode==pParent->lchild){
			pParent->lchild=NULL;
		}else{
			pParent->rchild=NULL;
		}
	}else if(pNode->lchild==NULL||pNode->rchild==NULL){//pΪ��֧����
		if(pNode==root){//pΪ���ڵ�
			if(pNode->lchild==NULL){
				root=pNode->rchild;
			}else{
				root=pNode->lchild;
			}
		}else{
			if(pNode==pParent->lchild&&pNode->lchild){//pNode��pParent��������pNode��������
				pParent->lchild=pNode->lchild;//��pNode������������pParent����ָ����ȥ
			}else if(pNode==pParent->lchild&&pNode->rchild){
				pParent->lchild=pNode->rchild;
			}else if(pNode==pParent->rchild&&pNode->lchild){
				pParent->rchild=pNode->lchild;
			}else{
				pParent->rchild=pNode->rchild;
			}
		}
		free(pNode);
	}else{//pNode��������������Ϊ��
		BiTNode *pTemp=pNode;
		BiTNode *pCur=pNode->lchild;//��pNode�����ӽڵ㿪ʼ
		while(pCur->rchild){ //�ҵ�pNode��ǰ������pNode��������ֵ���Ľڵ� 
			pTemp=pCur;
			pCur=pCur->rchild;
		}
		pNode->data=pCur->data;//�ѽڵ�pCur��ֵ����pNode 
		if (pTemp==pNode){
			pNode->lchild=pCur->lchild;
		}else{
			pNode->rchild=pCur->rchild;
		}
		free(pNode);
	}

	return isFind;
}