#include <stdio.h>
#include "bst.h"

int main(){
	BST<int> bst;
	bst.insert(10);
	bst.insert(8);
	bst.insert(12);
	bst.insert(14);
	bst.insert(6);
	bst.insert(16);
	bst.insert(4);
	bst.insert(2);

	bst.traversal();
	cout<<endl;
	TreeNode<int>* pnode=bst.find(16);
	cout<<pnode->data<<endl;

	bst.deletenode(10);
	bst.traversal();

	return 0;
}