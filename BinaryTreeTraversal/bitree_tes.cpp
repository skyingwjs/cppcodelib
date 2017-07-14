#include "bitree.h"

int main(){
	freopen("bitree.txt","r",stdin);
	TreeNode *root=NULL;
	vector<int> result;
	cout<<"1. 创建二叉树"<<endl;
	createTree(root);
	cout<<"------------------------"<<endl;

	cout<<"2.1 递归先序遍历"<<endl;
	preOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"2.2 非递归先序遍历"<<endl;
	preOrder2(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"3.1 递归中序遍历"<<endl;
	inOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"3.2 非递归中序遍历"<<endl;
	inOrder2(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"4.1 递归后序遍历"<<endl;
	postOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"4.2 非递归后序遍历"<<endl;
	postOrder2(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"5.  层次遍历"<<endl;
	levelOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;
	system("pause");
	return 0;
}