#ifndef __BITREE_H__
#define __BITREE_H__
#include <iostream>  
#include <vector>  
#include <stack>  
#include <queue>  
using namespace std;
//二叉树结点结构
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

void createTree(TreeNode *&root);
void preOrder(TreeNode *root,vector<int>& result);
void preOrder2(TreeNode *root,vector<int>& result);
void inOrder(TreeNode *root,vector<int>& result);
void inOrder2(TreeNode *root,vector<int>& result);
void postOrder(TreeNode *root,vector<int>& result);
void postOrder2(TreeNode *root,vector<int>& result);
void levelOrder(TreeNode *root,vector<int>& result);
void print(vector<int> result);
#endif