#include "bitree.h"

/************************************************************************
1.创建二叉树
************************************************************************/
void createTree(TreeNode *&root){
	int val;
	//按先序顺序输入二叉树中结点的值，‘-1’表示空树
	cin>>val;
	//空节点的处理
	if(val==-1){
		root =NULL;
		return;
	}

	root=new TreeNode(val);
	createTree(root->left);
	createTree(root->right);
}

/************************************************************************
2.1 递归先序遍历
************************************************************************/
void preOrder(TreeNode *root,vector<int>& result){
	if(root==NULL)
		return;
	result.push_back(root->val);
	preOrder(root->left,result);
	preOrder(root->right,result);
}

/************************************************************************
2.2 非递归先序遍历
************************************************************************/
void preOrder2(TreeNode *root,vector<int>& result){
	if(root==NULL)
		return;
	stack<TreeNode *> stackNodes;
	stackNodes.push(root);
	TreeNode *pNode=NULL;
	while(!stackNodes.empty()){
		pNode=stackNodes.top();
		stackNodes.pop();
		result.push_back(pNode->val);

		if(pNode->right){
			stackNodes.push(pNode->right);
		}

		if(pNode->left){
			stackNodes.push(pNode->left);
		}
	}

}

/************************************************************************
3.1 递归中序遍历
************************************************************************/
void inOrder(TreeNode *root,vector<int>& result){
	if(root==NULL)
		return;
	inOrder(root->left,result);
	result.push_back(root->val);
	inOrder(root->right,result);
}

/************************************************************************
3.2 非递归中序遍历
************************************************************************/
void inOrder2(TreeNode *root,vector<int>& result){
	stack<TreeNode *>stackNodes;
	TreeNode *pNode=root;

	while(pNode!=NULL || !stackNodes.empty()){
		if(pNode!=NULL){		
			stackNodes.push(pNode);
			pNode=pNode->left;
		}else{
			pNode=stackNodes.top();
			stackNodes.pop();
			result.push_back(pNode->val);
			pNode=pNode->right;
		}
	}
}

/************************************************************************
4.1 递归后序遍历
************************************************************************/
void postOrder(TreeNode *root,vector<int>& result){
	if(root==NULL)
		return;
	postOrder(root->left,result);
	postOrder(root->right,result);
	result.push_back(root->val);
}

/************************************************************************
4.2 非递归后序遍历
************************************************************************/
void postOrder2(TreeNode *root,vector<int>& result){
	if(root==NULL)
		return;
	stack<TreeNode *> stackNodes;
	stackNodes.push(root);
	TreeNode *pNode=NULL;
	while(!stackNodes.empty()){
		pNode=stackNodes.top();
		stackNodes.pop();
		result.insert(result.begin(),pNode->val);

		if(pNode->left){
			stackNodes.push(pNode->left);
		}
		if(pNode->right){
			stackNodes.push(pNode->right);
		}
	}
}

/************************************************************************
5 层次遍历
************************************************************************/
void levelOrder(TreeNode *root,vector<int>& result){
	if(root==NULL)
		return;
	queue<TreeNode *> q;
	q.push(root);
	TreeNode *pNode;

	while(!q.empty()){
		pNode=q.front();
		q.pop();
		result.push_back(pNode->val);

		if(pNode->left){
			q.push(pNode->left);
		}

		if(pNode->right){
			q.push(pNode->right);
		}
	}
}

/************************************************************************
6 输出结果
************************************************************************/
void print(vector<int> result){
	int size=result.size();

	for(int i=0;i<size;++i){
		cout<<result[i]<<" ";
	}
	cout<<endl;
}