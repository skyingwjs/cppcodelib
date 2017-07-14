#ifndef __BST_H__
#define __BST_H__

#include <iostream>
using namespace std;
//����������ڵ���Ϣ
template<class T>
class TreeNode
{
    public:
        TreeNode():lson(NULL),rson(NULL),freq(1){}
        T data;//ֵ
        unsigned int freq;//Ƶ��
        TreeNode* lson;//ָ������ӵ�����
        TreeNode* rson;//ָ���Ҷ��ӵ�����
};


//���������������Ժͷ�������
template<class T>
class BST
{
    private:
        TreeNode<T>* root;//���ڵ�

        void insertpri(TreeNode<T>* &node,T x);//����
        TreeNode<T>* findpri(TreeNode<T>* node,T x);//����
        void insubtree(TreeNode<T>* node);//�������
        void deletepri(TreeNode<T>* &node,T x);//ɾ��

    public:
        BST():root(NULL){}
        void insert(T x);//����ӿ�
        TreeNode<T>* find(T x);//���ҽӿ�
        void deletenode(T x);//ɾ���ӿ�
        void traversal();//�����ӿ�

};

//����
template<class T>
void BST<T>::insertpri(TreeNode<T>* &node,T x)
{
	if(node==NULL)//����ڵ�Ϊ��,���ڴ˽ڵ㴦����x��Ϣ
	{
		node=new TreeNode<T>();
		node->data=x;
		return;
	}
	if(node->data>x)//���xС�ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		insertpri(node->lson,x);
	}
	else if(node->data<x)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		insertpri(node->rson,x);
	}
	else 
		++(node->freq);//������,�Ͱ�Ƶ�ʼ�1
}


//����ӿ�
template<class T>
void BST<T>::insert(T x)
{
	insertpri(root,x);
}


//����
template<class T>
TreeNode<T>* BST<T>::findpri(TreeNode<T>* node,T x)
{
	if(node==NULL)//����ڵ�Ϊ��˵��û�ҵ�,����NULL
	{
		return NULL;
	}
	if(node->data>x)//���xС�ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		return findpri(node->lson,x);
	}
	else if(node->data<x)//���x���ڽڵ��ֵ,�ͼ����ڽڵ���������в���x
	{
		return findpri(node->rson,x);
	}
	else return node;//������,���ҵ��˴˽ڵ�
}

//���ҽӿ�
template<class T>
TreeNode<T>* BST<T>::find(T x)
{
	return findpri(root,x);
}


//ɾ��
template<class T>
void BST<T>::deletepri(TreeNode<T>* &node,T x)
{
	if(node==NULL) 
		return ;//û���ҵ�ֵ��x�Ľڵ�
	if(x < node->data)
		deletepri(node->lson,x);//���xС�ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
	else if(x > node->data)
		deletepri(node->rson,x);//���x���ڽڵ��ֵ,�ͼ����ڽڵ����������ɾ��x
	else//������,�˽ڵ����Ҫɾ���Ľڵ�
	{
		if(node->lson&&node->rson)//�˽ڵ�����������
		{
			TreeNode<T>* temp=node->rson;//tempָ��ڵ���Ҷ���
			while(temp->lson!=NULL) 
				temp=temp->lson;//�ҵ���������ֵ��С�Ľڵ�
			//������������С�ڵ��ֵ��ֵ�����ڵ�
			node->data=temp->data;
			node->freq=temp->freq;
			deletepri(node->rson,temp->data);//ɾ������������Сֵ�Ľڵ�
		}
		else//�˽ڵ���1����0������
		{
			TreeNode<T>* temp=node;
			if(node->lson==NULL)//���Ҷ��ӻ���û�ж���
				node=node->rson;
			else if(node->rson==NULL)//�������
				node=node->lson;
			delete temp;
		}
	}
	return;
}


//ɾ���ӿ�
template<class T>
void BST<T>::deletenode(T x)
{
	deletepri(root,x);
}


//�����������
template<class T>
void BST<T>::insubtree(TreeNode<T>* node)
{
	if(node==NULL) return;
	insubtree(node->lson);//�ȱ���������
	cout<<node->data<<" ";//������ڵ�
	insubtree(node->rson);//�ٱ���������
}

//��������ӿ�
template<class T>
void BST<T>::traversal()
{
	insubtree(root);
}

#endif