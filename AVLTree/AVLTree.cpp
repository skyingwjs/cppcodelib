// AVLTree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include"AVLTree.h"
#include<iostream>
using namespace std;

int main(int argc, char* argv[])
{
	AVLTree<int> a;
	//for (int i = 0; i < 10; i++)
	//	a.insert(i);

	for (int i = 9; i >=0; i--)
		a.insert(i);

	cout << "���ߣ�" << a.height() << endl;
	cout << "ǰ�����:";
	a.preOrder();
	cout<<endl;

	cout << "�������:";
	a.inOrder();
	cout<<endl;

	cout << "�������:";
	a.postOrder();
	cout<<endl;

	cout<<  "��α���:";
	a.levelTraversal();
	cout<<endl;

	cout << "ɾ��Ԫ��10"<<endl;
	a.remove(10);

	AVLTreeNode<int>* b = a.search_iterator(10);

	if (b != nullptr)
		cout << b->key;
	else
		cout << "�޴�Ԫ��" << endl;

	getchar();

	return 0;
}

