#include "bitree.h"

int main(){
	freopen("bitree.txt","r",stdin);
	TreeNode *root=NULL;
	vector<int> result;
	cout<<"1. ����������"<<endl;
	createTree(root);
	cout<<"------------------------"<<endl;

	cout<<"2.1 �ݹ��������"<<endl;
	preOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"2.2 �ǵݹ��������"<<endl;
	preOrder2(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"3.1 �ݹ��������"<<endl;
	inOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"3.2 �ǵݹ��������"<<endl;
	inOrder2(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"4.1 �ݹ�������"<<endl;
	postOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"4.2 �ǵݹ�������"<<endl;
	postOrder2(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;

	cout<<"5.  ��α���"<<endl;
	levelOrder(root,result);
	print(result);
	result.clear();
	cout<<"------------------------"<<endl;
	system("pause");
	return 0;
}