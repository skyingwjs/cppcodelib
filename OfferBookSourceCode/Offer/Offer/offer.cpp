
#include "offer.h"
/************************************************************************
查找二维数组中的某个数字 C++实现
************************************************************************/
bool find(vector<vector<int> >array,int target){
	int rows=array.size();
	int cols=array[0].size();
	int row=rows-1;
	int col=0;
	for(;row>=0 && col<cols;){

		if(array[row][col]==target){
			return true;
		}else if(array[row][col]<target){
			col++;
			continue;
		}else{
			row--;
			continue;
		}
	}
	return false;
}

/************************************************************************
查找二维数组中的某个数字 C实现
************************************************************************/
bool find2(int *matrix,int rows,int cols,int number){
	bool found=false;
	if(matrix && rows>0 && cols>0){
		int row=rows-1;
		int col=0;

		while(row>=0 && col<cols){
			if(matrix[row*cols+col]==number){
				found=true;
				break;
			}else if(matrix[row*cols+col]<number){
				col++;
				continue;
			}else{
				row--;
				continue;
			}
		}

	}
	return found;
}

/************************************************************************
替换字符串中的空格
************************************************************************/
void replaceSpace(char *str,int length){
	if(str==NULL||length<=0){
		return;
	}

	int originalLength=0;
	int newLength=0;
	int numOfBlank=0;
	int i=0;
	while(str[i]!='\0'){
		++originalLength;
		if(str[i]==' '){
			numOfBlank++;
		}
		++i;
	}
	newLength=2*numOfBlank+originalLength;
	if(newLength>length)
		return;

	int indexOfOriginal=originalLength;
	int indexOfNew=newLength;

	while(indexOfOriginal>=0&&indexOfNew>indexOfOriginal){
		if(str[indexOfOriginal]==' '){
			str[indexOfNew--]='0';
			str[indexOfNew--]='2';
			str[indexOfNew--]='%';
		}else{
			str[indexOfNew--]=str[indexOfOriginal];
		}
		--indexOfOriginal;
	}
}

/************************************************************************
从尾到头打印链表中的元素 利用reverse函数实现
************************************************************************/
vector<int> printListFromTailToHead(ListNode * pHead){
	vector<int> result;
	if(pHead!=NULL){
		ListNode *pNode=pHead;
		do{
			result.push_back(pNode->val);
			pNode=pNode->next;
		}while (pNode!=NULL);
	}
	reverse(result.begin(),result.end());
	return result;
}

/************************************************************************
从尾到头打印链表中的元素，利用insert函数实现
************************************************************************/
vector<int> printListFromTailToHead2(ListNode * pHead){
	vector<int> result;
	if(pHead!=NULL){
		ListNode *pNode=pHead;
		do{
			result.insert(result.begin(),pNode->val);
			pNode=pNode->next;
		}while (pNode!=NULL);
	}
	return result;
}

/************************************************************************
从尾到头打印链表中的元素,递归实现
************************************************************************/
vector<int> printListFromTailToHead3(ListNode * pHead){
	vector<int> value;
	if(pHead != NULL)
	{
		value.insert(value.begin(),pHead->val);
		if(pHead->next != NULL)
		{
			vector<int> tempVec = printListFromTailToHead2(pHead->next);
			if(tempVec.size()>0)
				value.insert(value.begin(),tempVec.begin(),tempVec.end());  
		}         

	}
	return value;
}

/************************************************************************
在链表尾部加一个结点
************************************************************************/
void addToTail(ListNode **pHead,int value){
	ListNode *pNew=new ListNode();
	pNew->val=value;
	pNew->next=NULL;

	if(pHead==NULL){
		*pHead=pNew;
	}else{
		ListNode* pNode=*pHead;
		while(pNode->next!=NULL){
			pNode=pNode->next;
		}
		pNode->next=pNew;
	}

}

/************************************************************************
删除链表中第一个值为val的结点
************************************************************************/
void removeNode(ListNode **pHead,int value){
	if(pHead==NULL || *pHead==NULL){
		return;
	}

	ListNode *pToBeDeleted=NULL;
	if((*pHead)->val==value){
		pToBeDeleted=*pHead;
		*pHead=(*pHead)->next;
	}else{
		ListNode* pNode=*pHead;
		while(pNode->next!=NULL && pNode->next->val!=value){
			pNode=pNode->next;
		}

		if(pNode->next!=NULL&&pNode->next->val==value){
			pToBeDeleted=pNode->next;
			pNode->next=pNode->next->next;
		}
	}

	if(pToBeDeleted!=NULL){
		delete pToBeDeleted;
		pToBeDeleted=NULL;
	}
}

/************************************************************************
在O(1)时间内删除链表结点,基于假设：要删除的结点的确在链表中
************************************************************************/
void deleteNode(ListNode **pHead,ListNode *pToBeDeleted){
	if(!pHead||!pToBeDeleted){
		return;
	}

	if(pToBeDeleted->next!=NULL){
		ListNode *pNext=pToBeDeleted->next;
		pToBeDeleted->val=pNext->val;
		pToBeDeleted->next=pToBeDeleted->next;

		delete pToBeDeleted;
		pToBeDeleted=NULL;
	}else if(*pHead==pToBeDeleted){
		delete pToBeDeleted;
		pToBeDeleted=NULL;
		*pHead=NULL;
	}else{
		ListNode *pNode=*pHead;
		while(pNode->next!=pToBeDeleted){
			pNode=pNode->next;
		}

		delete pToBeDeleted;
		pToBeDeleted=NULL;
		pNode->next=NULL;
	}	
}

/************************************************************************
链表中的倒数第k个结点，两个指针遍历，便可只遍历一遍，考察鲁棒性
************************************************************************/
ListNode *findKthToTail(ListNode *pListHead,unsigned int k){
	if(!pListHead || k==0){
		return NULL;
	}
	ListNode *pAhead=pListHead;
	ListNode *pBehind=pListHead;

	for(unsigned int i=0;i<k-1;i++){
		if(pAhead->next!=NULL){
			pAhead=pAhead->next;
		}else{
			return NULL;
		}
	}

	while(pAhead->next!=NULL){
		pAhead=pAhead->next;
		pBehind=pBehind->next;
	}
	return pBehind;
}

/************************************************************************
反转链表
************************************************************************/
ListNode *reserveList(ListNode *pHead){
	if(!pHead)
		return NULL;
	ListNode *pPrev=NULL;
	ListNode *pCur=pHead;
	ListNode *pNext=pCur->next;

	while(pCur){
		pCur->next=pPrev;
		if(pNext==NULL)
			break;
		pPrev=pCur;
		pCur=pNext;
		pNext=pNext->next;
	}

	return pCur;
}

/************************************************************************
合并两个排序的链表  递归实现
************************************************************************/
ListNode *merge(ListNode *pHead1,ListNode *pHead2){
	if(pHead1==NULL){
		return pHead2;
	}
	if(pHead2==NULL){
		return pHead1;
	}
	ListNode *pMergeHead=NULL;

	if(pHead1->val<pHead2->val){
		pMergeHead=pHead1;
		pMergeHead->next=merge(pHead1->next,pHead2);
	}else{
		pMergeHead=pHead2;
		pMergeHead->next=merge(pHead1,pHead2->next);
	}
	return pMergeHead;
}

/************************************************************************
合并两个排序的链表  非递归实现
************************************************************************/
ListNode *merge2(ListNode *pHead1,ListNode *pHead2){
	if(pHead1==NULL){
		return pHead2;
	}
	if(pHead2==NULL){
		return pHead1;
	}
	ListNode *pMergeHead=NULL;
	ListNode *pCur=NULL;
	ListNode *pCur1=pHead1;
	ListNode *pCur2=pHead2;

	while(pCur1!=NULL && pCur2!=NULL){
		if(pCur1->val<pCur2->val){
			if(pMergeHead==NULL){
				pMergeHead=pCur1;	
			}else{
				pCur->next=pCur1;
			}
			pCur=pCur1;		
			pCur1=pCur1->next;
			if(pCur1==NULL){
				pCur->next=pCur2;
				break;
			}
		}else{
			if(pMergeHead==NULL){
				pMergeHead=pCur2;
			}else{
				pCur->next=pCur2;				
			}
			pCur=pCur2;
			pCur2=pCur2->next;
			if(pCur2==NULL){
				pCur->next=pCur1;
				break;
			}
		}
	}
	return pMergeHead;
}

/************************************************************************
合并两个排序的链表  非递归实现,结构清晰
************************************************************************/
ListNode *merge3(ListNode *pHead1,ListNode *pHead2){
	if(pHead1==NULL){
		return pHead2;
	}
	if(pHead2==NULL){
		return pHead1;
	}
	ListNode *pMergeHead=NULL;
	ListNode *pCur=NULL;
	ListNode *pCur1=pHead1;
	ListNode *pCur2=pHead2;

	/*非递归解法*/
	while(pCur1!=NULL&&pCur2!=NULL){
		if(pCur1->val<=pCur2->val){
			if(pMergeHead==NULL){
				pMergeHead=pCur=pCur1;
			}else{
				pCur->next=pCur1;
				pCur=pCur->next;
			}
			pCur1=pCur1->next;
		}else{
			if(pMergeHead==NULL){
				pMergeHead=pCur=pCur2;
			}else{
				pCur->next=pCur2;
				pCur=pCur->next;
			}
			pCur2=pCur2->next;
		}
	}

	if(pCur1==NULL){
		pCur->next=pCur2;
	}
	if(pCur2==NULL){
		pCur->next=pCur1;
	}
	return pMergeHead;
}

/************************************************************************
获取链表的长度
************************************************************************/
unsigned int getListLength(ListNode *pHead){
	unsigned int length=0;
	ListNode *pNode=pHead;
	while(pNode!=NULL){
		++length;
		pNode=pNode->next;
	}
	return length;
}


/************************************************************************
两个链表的第一个公共结点
************************************************************************/
ListNode* findFirstCommonNode(ListNode *pHead1,ListNode *pHead2){
	unsigned int length1=getListLength(pHead1);
	unsigned int length2=getListLength(pHead2);
	int lengthDif=length1-length2;
	ListNode *pListHeadLong=pHead1;
	ListNode *pListHeadShort=pHead2;
	if(length2>length1){
		pListHeadLong=pHead2;
		pListHeadShort=pHead1;
		lengthDif=length2-length1;
	}

	for(int i=0;i<lengthDif;i++){
		pListHeadLong=pListHeadLong->next;
	}

	while(pListHeadLong!=NULL && 
		  pListHeadShort!=NULL &&
		  pListHeadLong!=pListHeadShort){
			  pListHeadLong=pListHeadLong->next;
			  pListHeadShort=pListHeadShort->next;
	}

	ListNode *pFirstCommonNode=pListHeadLong;
	return pFirstCommonNode;
}

/************************************************************************
复杂链表的复制
************************************************************************/

/*step1:复制原始链表的任意结点N并创建新节点N' ,再把N'接到N的后面*/
void cloneNodes(ComplexListNode *pHead){
	ComplexListNode *pNode=pHead;

	while(pNode!=NULL){
		ComplexListNode *pCloned=new ComplexListNode();
		pCloned->val=pNode->val;
		pCloned->sibling=NULL;
		pCloned->next=pNode->next;

		pNode->next=pCloned;
		pNode=pCloned->next;
	}
}

/*step2:设置复制出来的结点N'的sibling， 如果原始链表上结点N的sibling指向S,则它对应的
复制结点的N'指向S的下一结点S'*/
void connectSiblingNodes(ComplexListNode *pHead){
	ComplexListNode *pNode=pHead;
	while(pNode!=NULL){
		ComplexListNode *pCloned=pNode->next;
		if(pNode->sibling!=NULL){
			pCloned->sibling=pNode->sibling->next;
		}
		pNode=pCloned->next;
	}
}

/*将长链表拆分成两个链表，技术位置上的结点构成原始链表，偶数位置上的结点构成复制出来的】
链表*/

ComplexListNode *reconnectNodes(ComplexListNode *pHead){
	ComplexListNode *pNode=pHead;
	ComplexListNode *pClonedHead=NULL;
	ComplexListNode *pClonedNode=NULL;

	if(pNode!=NULL){
		pClonedHead=pClonedNode=pNode;
		pNode->next=pClonedNode->next;
		pHead=pNode->next;
	}

	while(pNode!=NULL){
		pClonedNode->next=pNode->next;
		pClonedNode=pClonedNode->next;

		pNode->next=pClonedNode->next;
		pNode=pNode->next;
	}

	return pClonedHead;
}

/*复制复杂链表的完整过程*/
ComplexListNode *cloneComplexList(ComplexListNode *pHead){
	cloneNodes(pHead);
	connectSiblingNodes(pHead);
	return reconnectNodes(pHead);
}

/************************************************************************
圆圈中最后剩下的数字
************************************************************************/
/*经典解法：用环形链表模拟圆圈*/
int lastRemaining(unsigned int n,unsigned int m){
	if(n<1||m<1)
		return -1;
	list<int> numbers;
	for(int i=0;i<n;i++){
		numbers.push_back(i);
	}
	list<int>::iterator current=numbers.begin();

	while(numbers.size()>1){
		for(int i=1;i<m;i++){		
			current++;
			if(current==numbers.end())
				current=numbers.begin();
		}

		list<int>::iterator next=++current;
		if(current==numbers.end())
			current=numbers.begin();

		--current;
		numbers.erase(current);
		current=next;
	}

	return *current;
}

/*创新解法：观察规律，求得递推公式*/
int lastRemaining2(unsigned int n,unsigned int m){
	if(n<1||m<1)
		return -1;

	int last=0;
	for(int i=2;i<=n;i++){
		last=(last+m)%i;
	}
	return last;
}

/************************************************************************
链表中环的入口节点
************************************************************************/
/*step1:用一快一慢两个指针 得到环中的某一个结点的指针 进而求得结点的数目*/
ListNode *meetingNode(ListNode *pHead){
	if(pHead==NULL){
		return NULL;
	}

	ListNode *pSlow=pHead->next;
	if(pSlow==NULL){
		return NULL;
	}

	ListNode *pFast=pSlow->next;
	while(pFast!=NULL && pSlow!=NULL){
		if(pSlow==pFast){
			return pFast;
		}

		pSlow=pSlow->next;
		pFast=pFast->next;

		if(pFast!=NULL)
			pFast=pFast->next;
	}
}

/*step2:求出环中结点的数目 并求得环的入口节点*/
ListNode * entryNodeOfLoop(ListNode *pHead){

	ListNode *meetNode=meetingNode(pHead);
	if(meetNode==NULL){
		return NULL;
	}

	ListNode* pNode1=meetNode;
	unsigned int nodesInLoop=0;
	while(pNode1->next!=meetNode){
		++nodesInLoop;
		pNode1=pNode1->next;
	}

	pNode1=pHead;
	for(int i=0;i<nodesInLoop;i++){
		pNode1=pNode1->next;
	}

	ListNode *pNode2=pHead;
	while(pNode1!=pNode2){
		pNode1=pNode1->next;
		pNode2=pNode2->next;
	}

	return pNode1;
}


/************************************************************************
删除链表中重复的结点
************************************************************************/
void deleteDuplication(ListNode **pHead){
	if(pHead==NULL || *pHead==NULL)
		return ;
	ListNode* pPreNode=NULL;
	ListNode* pNode=*pHead;

	while(pNode!=NULL){
		ListNode* pNext=pNode->next;
		bool needDelete=false;
		if(pNext!=NULL && pNext->val==pNode->val){
			needDelete=true;
		}

		if(!needDelete){
			pPreNode=pNode;
			pNode=pNode->next;
		}else{
			ListNode* pToBeDel=pNode;
			int value=pNode->val;

			while(pToBeDel!=NULL && pToBeDel->val==value){
				pNext=pToBeDel->next;

				delete pToBeDel;
				pToBeDel=NULL;

				pToBeDel=pNext;
			}

			if(pPreNode==NULL){
				*pHead=pNext;
			}else{
				pPreNode->next=pNext;
			}
			pNode=pNext;
		}
	}
}





/************************************************************************
重建二叉树  递归实现
************************************************************************/
/*reconstructCore*/
BinaryTreeNode *reconstructCore(int *startPreoder,int *endPreorder,
								int *startInorder,int *endInorder){
	//前序遍历的第一个数字是根节点，构造根节点
	int rootValue=startPreoder[0];
	BinaryTreeNode *root=new BinaryTreeNode();
	root->val=rootValue;
	root->left=root->right=NULL;

	//递归出口 即递归退出条件
	if(startPreoder==endPreorder){
		if(startInorder==endInorder && *startPreoder==*startInorder){
			return root;//递归到最内层时，树只有一个结点  此时退出
		}else{
			throw exception("Invalid Input");
		}
	}

	//在中序遍历中找到根节点
	int *rootInorder=startInorder;
	while(rootInorder<endInorder && *rootInorder!=rootValue){
		rootInorder++;
	}

	//在中序遍历数组中为找到根节点
	if(rootInorder==endInorder && *rootInorder!=rootValue){
		throw exception("Invalid Input");
	}

	//计算左子树结点个数
	int leftLength=rootInorder-startInorder;
	int *leftPreoderEnd=startPreoder+leftLength;

	if(leftLength>0){
		//构建左子树
		root->left=reconstructCore(startPreoder+1,leftPreoderEnd,
								   startInorder,rootInorder-1);
	}

	if(leftLength<endPreorder-startPreoder){
		//构建右子树
		root->right=reconstructCore(leftPreoderEnd+1,endPreorder,
									rootInorder+1,endInorder);
	}
	return root;
}

/*reconstructBinaryTree*/
BinaryTreeNode *reconstructBinaryTree(int* preorder,int* inorder,int length ){
	if(preorder==NULL || inorder==NULL || length<=0)
		return NULL;

	return reconstructCore(preorder,preorder+length-1,
						   inorder,inorder+length-1);
}


/************************************************************************
重建二叉树  递归实现2  利用辅助空间 下面的解法鲁棒性不是很好，需要完善特殊情况下的处理
************************************************************************/
BinaryTreeNode * reconstructBinaryTree(vector<int> pre,vector<int> in){
	
	int inLen=in.size();
	if(inLen==0){
		return NULL;
	}
	//创建根节点 根节点的值为先序遍历的是一个元素
	BinaryTreeNode *root=new BinaryTreeNode();
	root->val=pre[0];
	root->left=root->right=NULL;


	//在中序遍历中找到根节点元素值的位置（索引）
	int rootValIdx=0;
	for(int i=0;i<inLen;i++){
		if(in[i]==pre[0]){
			rootValIdx=i;
			break;
		}
	}
	//左右子树的中序 前序遍历结果
	vector<int> leftIn,leftPre,rightIn,rightPre;

	//对于中序遍历，根节点左边的节点位于二叉树的左边，根节点右边的节点位于二叉树的右边,利用上述这点，对二叉树节点进行归并
	//存储左子树的前序，中序遍历结果
	for(int j=0;j<rootValIdx;j++){
		leftIn.push_back(in[j]);
		leftPre.push_back(pre[j+1]);
	}
	//存储右子树的前序，中序遍历结果
	for(int k=rootValIdx+1;k<inLen;k++){
		rightIn.push_back(in[k]);
		rightPre.push_back(pre[k]);
	}

	//和shell排序的思想类似，取出前序和中序遍历根节点左边和右边的子树
	//递归，再对其进行上述所有步骤，即再区分子树的左、右子子数，直到叶节点
	root->left=reconstructBinaryTree(leftPre,leftIn);
	root->right=reconstructBinaryTree(rightPre,rightIn);
	return root;

}   

/************************************************************************
把二叉树打印成多行
************************************************************************/
void printBinaryTree(BinaryTreeNode *pRoot){
	if(pRoot==NULL)
		return;

	std::queue<BinaryTreeNode*> nodes;
	nodes.push(pRoot);
	int toBePrinted=1;
	int nextLevel=0;

	while(!nodes.empty()){
		BinaryTreeNode* pNode=nodes.front();
		printf("%d  ",pNode->val);

		if(pNode->left!=NULL){
			nodes.push(pNode->left);
			++nextLevel;
		}

		if(pNode->right!=NULL){
			nodes.push(pNode->right);
			++nextLevel;
		}

		nodes.pop();
		--toBePrinted;

		if(toBePrinted==0){
			toBePrinted=nextLevel;
			nextLevel=0;
		}
	}
}

/************************************************************************
按之字形顺序打印二叉树
************************************************************************/
void printBinaryTree2(BinaryTreeNode *pRoot){
	if(pRoot==NULL)
		return;
	std::stack<BinaryTreeNode *>levels[2];
	int current=0;
	int next=1;

	levels[current].push(pRoot);
	while(!levels[0].empty() || !levels[1].empty()){
		BinaryTreeNode *pNode =levels[current].top();
		levels[current].pop();

		printf("%d ",pNode->val);

		if(current==0){
			if(pNode->left!=NULL)
				levels[next].push(pNode->left);
			if(pNode->right!=NULL)
				levels[next].push(pNode->right);
		}else{
			if(pNode->right!=NULL)
				levels[next].push(pNode->right);
			if(pNode->left!=NULL)
				levels[next].push(pNode->left);
		}

		if(levels[current].empty()){
			current=1-current;
			next=1-next;
		}

	}
}

/************************************************************************
从上往下打印二叉树
************************************************************************/
void printFromTopToBottom(BinaryTreeNode *pRoot){

	if(pRoot==NULL)
		return;

	std::deque<BinaryTreeNode *> duqueTreeNodes;
	duqueTreeNodes.push_back(pRoot);

	while(duqueTreeNodes.size()){
		BinaryTreeNode * pNode=duqueTreeNodes.front();
		duqueTreeNodes.pop_front();

		printf("%d ",pNode->val);

		if(pNode->left)
			duqueTreeNodes.push_back(pNode->left);
		if(pNode->right)
			duqueTreeNodes.push_back(pNode->right);
	}
}





/************************************************************************
序列化二叉树 递归解法
************************************************************************/
void serialize(BinaryTreeNode *pRoot,ostream &stream){
	if(pRoot==NULL){
		stream<<"$,";
		return;
	}

	stream<<pRoot->val<<",";
	serialize(pRoot->left,stream);
	serialize(pRoot->right,stream);
}

/************************************************************************
反序列化二叉树 递归解法
************************************************************************/
void deserialize(BinaryTreeNode **pRoot,istream &stream){
	int number;
	//readstream每次从流中读取一个数字或字符‘$’,若读取的是数字则返回true，否则返回false
	//if(readstream(stream,&number)){
	//	*pRoot=new BinaryTreeNode();
	//	(*pRoot)->val=number;
	//	(*pRoot)->left=NULL;
	//	(*pRoot)->right=NULL;

	//	deserialize(&((*pRoot)->left),stream);
	//	deserialize(&((*pRoot)->right),stream);
	//}
}

/************************************************************************
二叉搜索树中的第k个结点
************************************************************************/
BinaryTreeNode * kthNodeCore(BinaryTreeNode *pRoot,unsigned int &k){
	BinaryTreeNode *target=NULL;

	if(pRoot->left!=NULL)
		target=kthNodeCore(pRoot->left,k);
	

	if(target==NULL){
		if(k==1)
			target=pRoot;
		k--;//why？？？？
	}

	if(target==NULL && pRoot->right!=NULL)
		target=kthNodeCore(pRoot->right,k);

	return target;
}

BinaryTreeNode *kthNode(BinaryTreeNode *pRoot,unsigned int k){
	if(pRoot==NULL || k==0){
		return NULL;
	}

	return kthNodeCore(pRoot,k);
}

/************************************************************************
树的子结构
************************************************************************/
bool doesTree1HaveTree2(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2){
	if(pRoot2==NULL)
		return true;
	if(pRoot1==NULL)
		return false;
	if(pRoot1->val!=pRoot2->val)
		return false;

	return doesTree1HaveTree2(pRoot1->left,pRoot2->left)&&
		doesTree1HaveTree2(pRoot1->right,pRoot2->right);
}

bool hasSubtree(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2){
	bool result=false;

	if(pRoot1!=NULL && pRoot2!=NULL){
		if(pRoot1->val==pRoot2->val)
			result= doesTree1HaveTree2(pRoot1,pRoot2);
		if(!result)
			result=hasSubtree(pRoot1->left,pRoot2);
		if(!result)
			result=hasSubtree(pRoot1->right,pRoot2);
	}

	return result;
}
/************************************************************************
二叉树的镜像 递归实现
************************************************************************/
void mirrorRecursively(BinaryTreeNode *pRoot){
	if(pRoot==NULL)
		return;
	if(pRoot->left==NULL && pRoot->right==NULL)
		return;

	BinaryTreeNode *pTemp=pRoot->left;
	pRoot->left=pRoot->right;
	pRoot->right=pTemp;

	if(pRoot->left)
		mirrorRecursively(pRoot->left);
	if(pRoot->right)
		mirrorRecursively(pRoot->right);
}

/************************************************************************
二叉树镜像  循环压栈实现
************************************************************************/
void mirrorRecursively2(BinaryTreeNode *pRoot){
	if(pRoot==NULL)
		return;
	
	std::stack<BinaryTreeNode *> treeNodes;
	treeNodes.push(pRoot);

	while(treeNodes.size()>0){
		BinaryTreeNode *pParent=treeNodes.top();
		treeNodes.pop();

		BinaryTreeNode *pTemp=pParent->left;
		pParent->left=pParent->right;
		pParent->right=pTemp;

		if(pParent->left)
			treeNodes.push(pParent->left);
		if(pParent->right)
			treeNodes.push(pParent->right);
	}
}

/************************************************************************
二叉搜索树的后序遍历序列
************************************************************************/
bool verifySquenceOfBST(int sequence[],int length){
	if(sequence==NULL || length<=0)
		return false;

	int root=sequence[length-1];

	//在二叉搜索树中左子树的结点小于右子树的结点
	int i=0;
	for (;i<length-1;++i){
		if(sequence[i]>root)
			break;
	}

	//在二叉搜索树中右子树的结点大于左子树的结点
	int j=i;
	for(;j<length-1;++j){
		if (sequence[j]<root)
			return false;
	}

	//判断左子树是不是二叉搜索树
	bool left=true;
	if(i>0)
		left=verifySquenceOfBST(sequence,i);

	//判断由子树是不是二叉搜索树
	bool right=true;
	if(i<length-1)
		right=verifySquenceOfBST(sequence+i,length-i-1);

	return left&&right;

}

/************************************************************************
二叉树中和为某一值的路径
************************************************************************/

void findPathCore(BinaryTreeNode *pRoot,
				  int expectedSum,
				  std::vector<int> &path,
				  int currentSum){

	currentSum+=pRoot->val;
	path.push_back(pRoot->val);

	//如果是叶节点 并且路径上的和等于输入的值，则打印该路径

	bool isLeaf=pRoot->left==NULL && pRoot->right==NULL;

	if(currentSum==expectedSum && isLeaf){

		printf("A path is found");
		std::vector<int>::iterator iter =path.begin();

		for(;iter!=path.end();iter++){
			printf("%d\t",*iter);
		}

		printf("\n");
	}

	//如果不是叶节点 则遍历它的子节点
	if(pRoot->left){
		findPathCore(pRoot->left,expectedSum,path,currentSum);
	}
	if(pRoot->right){
		findPathCore(pRoot->right,expectedSum,path,currentSum);
	}

	//在返回父节点之前，在路径上删除当前结点
	path.pop_back();
}

void findPath(BinaryTreeNode *pRoot,int expectedSum){
	if(pRoot==NULL)
		return;

	std::vector<int > path;
	int currentSum=0;
	findPathCore(pRoot,expectedSum,path,currentSum);
}

/************************************************************************
二叉搜索树与双向链表
************************************************************************/
void convertNode(BinaryTreeNode *pNode,BinaryTreeNode **pLastNodeInList){

	if(pNode==NULL)
		return;
	BinaryTreeNode *pCurrent=pNode;
	if(pCurrent->left!=NULL)
		convertNode(pCurrent->left,pLastNodeInList);

	pCurrent->left=*pLastNodeInList;

	if(*pLastNodeInList!=NULL)
		(*pLastNodeInList)->right=pCurrent;
	*pLastNodeInList=pCurrent;

	if(pCurrent->right!=NULL)
		convertNode(pCurrent->right,pLastNodeInList);

}

BinaryTreeNode *convert(BinaryTreeNode *pRootOfTree){
	BinaryTreeNode* pLastNodeInList=NULL;
	convertNode(pRootOfTree,&pLastNodeInList);

	//pLastNodeInList指向双向链表的尾节点 我们需要返回头结点
	BinaryTreeNode *pHeadOfList=pLastNodeInList;
	while(pHeadOfList!=NULL && pHeadOfList->left!=NULL){
		pHeadOfList=pHeadOfList->left;
	}
	return pHeadOfList;
}

/************************************************************************
求二叉树的深度 简洁方法
************************************************************************/
int treeDepth(BinaryTreeNode *pRoot){
	if(pRoot==NULL)
		return;

	int nLeft=treeDepth(pRoot->left);
	int nRight=treeDepth(pRoot->right);
	return (nLeft>nRight)?nLeft+1:nRight+1;
}

/************************************************************************
判断一棵树是不是平衡二叉树 后续遍历实现（简洁高效）
************************************************************************/
bool isBalancedCore(BinaryTreeNode *pRoot,int *pDepth){
	if(pRoot==NULL){
		*pDepth=0;
		return true;
	}

	int left,right;

	if(isBalancedCore(pRoot->left,&left) && isBalancedCore(pRoot->right,&right)){
		int diff=left-right;
		if(diff<=1||diff>=-1){
			*pDepth=1+(left>right?left:right);
			return true;
		}
	}

	return false;
}

bool isBalanced(BinaryTreeNode *pRoot){
	int depth=0;
	return isBalancedCore(pRoot,&depth);
}

/************************************************************************
二叉树的下一个结点
************************************************************************/
ComplexBinaryTreeNode *getNextNode(ComplexBinaryTreeNode *pNode){
	if(pNode==NULL)
		return NULL;
	ComplexBinaryTreeNode *pNext=NULL;

	if(pNode->right!=NULL){
		ComplexBinaryTreeNode *pRight=pNode->right;
		while(pRight->left!=NULL)
			pRight=pRight->left;
		pNext=pRight;
	}else if(pNode->parent!=NULL){
		ComplexBinaryTreeNode* pCurrent=pNode;
		ComplexBinaryTreeNode* pParent=pNode->parent;

		while(pParent!=NULL && pCurrent==pParent->right){
			pCurrent=pParent;
			pParent=pParent->parent;
		}

		pNext=pParent;
	}

	return pNext;
}

/************************************************************************
对称的二叉树  构造一种与前序遍历对称的算法
************************************************************************/
bool isSymmetricalCore(BinaryTreeNode *pRoot1,BinaryTreeNode *pRoot2){

	if(pRoot1==NULL && pRoot2==NULL){
		return true;
	}

	if(pRoot1==NULL ||pRoot2==NULL){
		return false;
	}

	if(pRoot1->val!=pRoot2->val){
		return false;
	}

	return isSymmetricalCore(pRoot1->left,pRoot2->right)&&
		isSymmetricalCore(pRoot1->right,pRoot2->left);
}

bool isSymmetrical(BinaryTreeNode *pRoot){
	return isSymmetricalCore(pRoot,pRoot);
}

/************************************************************************
用两个栈实现一个队列
************************************************************************/
template <class T> 
class CQueue{
public:
	CQueue(){

	}
	~CQueue(){

	}

	void appendTail(const T& node){
		stack1.push(node);
	}

	T deleteHead(){
		if(stack2.size()<=0){
			while(stack1.size()>0){
				T& data=stack1.top();
				stack1.pop();
				stack2.push(data);
			}
		}

		if(stack2.size()==0){
			throw new exception("queue is empty");
		}

		T head=stack2.top();
		stack2.pop();
		return head;
	}

private:
	stack<T> stack1;
	stack<T> stack2;
};

/************************************************************************
包含 min函数的栈
************************************************************************/
template <class T> 
class StackWithMin{
public:
	void push(const T& value){
		if(min_stack.size()==0 || value<min_stack.top())
			min_stack.push(value);
		else
			min_stack.push(min_stack.top());
	}

	void pop(){
		assert(min_stack.size()>0 && data_stack.size()>0);
		data_stack.pop();
		min_stack.pop();
	}

	const T& min() const{
		assert(min_stack.size()>0 && data_stack.size()>0);
		return min_stack.top();
	}
private:
	stack<T> data_stack;
	stack<T> min_stack;
};

/************************************************************************
栈的压人弹出序列
************************************************************************/
bool isPopOrder(const int* pPush,const int *pPop,int nLength){
	bool bPossible=false;

	if(pPush!=NULL && pPop!=NULL && nLength>0){
		const int *pNextPush=pPush;
		const int *pNextPop=pPop;
		stack<int> stackData;

		while(pNextPop-pPop<nLength){
			while(stackData.empty() && stackData.top()!=*pNextPop){
				if(pNextPush-pPush==nLength)
					break;
				stackData.push(*pNextPush);
				pNextPush++;
			}

			if(stackData.top()!=*pNextPush)
				break;

			stackData.pop();
			pNextPop++;
		}

		if(stackData.empty() && pNextPop-pPop==nLength)
			bPossible=true;
	}
	return bPossible;
}

/************************************************************************
快速排序算法
************************************************************************/
void swap(int &a,int &b){
	if(a!=b){
		a=a^b;
		b=a^b;
		a=a^b;
	}
}

int partition(int data[],int length,int start,int end){
	if(data==NULL || length<=0 ||start<0 || end>=length)
		throw new exception("Invalid Parameters");

	//int index=randInRange(start,end);
	int index =(start+end)/2;
	swap(data[index],data[end]);

	int small=start-1;
	for(index=start;index<end;index++){
		if(data[index]<data[end]){
			++small;
			if(small!=index){
				swap(data[index],data[small]);
			}
		}
	}

	++small;
	swap(data[small],data[end]);

	return small;
}

void quickSort(int data[],int length,int start,int end){
	if(start==end)
		return;
	int index=partition(data,length,start,end);
	if(index>0)
		quickSort(data,length,start,index-1);
	if(index<end)
		quickSort(data,length,index+1,end);
}

/************************************************************************
对公司年龄进行排序
************************************************************************/

void sortAges(int ages[],int length){
	if(ages==NULL || length<=0)
		return;
	const int oldestAge=99;
	int timesOfAge[oldestAge+1];

	for(int i=0;i<=oldestAge;i++){
		timesOfAge[i]=0;
	}

	for(int i=0;i<length;++i){
		int age=ages[i];
		if(age<0 || age >oldestAge)
			throw new exception("age out of range");
		++timesOfAge[age];
	}

	int index=0;
	for(int i=0;i<=oldestAge;++i){
		for(int j=0;j<timesOfAge[i];++j){
			ages[index]=i;
			index++;
		}
	}
}

/************************************************************************
旋转数组中最小的数字
************************************************************************/
int minInOrder(int *numbers,int index1,int index2){
	int result=numbers[index1];
	for(int i=index1+1;i<=index2;i++){
		if(result>numbers[i])
			result=numbers[i];
	}

	return result;
}

int minNumInRotateArray(int *numbers,int length){
	if(numbers==NULL || length<=0)
		throw new exception("Invalisd Parameters");
	int index1=0;
	int index2=length-1;
	int indexMid=index1;

	while(numbers[index1]>=numbers[index2]){
		if(index2-index1==1){
			indexMid=index2;
			break;
		}

		indexMid=(index1+index2)/2;

		if(numbers[index1]==numbers[index2] && numbers[index1]==numbers[indexMid]){
			return minInOrder(numbers,index1,index2);
		}

		if(numbers[indexMid]>=numbers[index1])
			index1=indexMid;
		else if(numbers[indexMid]<=numbers[index2])
			index2=indexMid;
	}
	return numbers[indexMid];
}

/************************************************************************
fibonacci 数列的循环解法
************************************************************************/
long long fibonacci(unsigned n){
	int result[2]={0,1};
	if(n<2)
		return result[n];
	long long fibNMinusOne=1;
	long long fibNMinusTwo=0;
	long long fibN=0;

	for(unsigned int i=2;i<=n;++i){
		fibN=fibNMinusOne+fibNMinusTwo;
		fibNMinusTwo=fibNMinusOne;
		fibNMinusOne=fibN;
	}

	return fibN;
}

/************************************************************************
二进制中1的个数
************************************************************************/
int numOf1(int n){
	int count=0;
	while(n){
		++count;
		n=(n-1)&n;
	}
}

/************************************************************************
数值的整数次方
************************************************************************/
double powerWithUnsignedExponent(double base,unsigned int exponent){
	if(exponent==0)
		return 1;
	if(exponent==1)
		return base;
	double result =powerWithUnsignedExponent(base,exponent>>1);
	result*=result;
	if(exponent&0x01==1)
		result*=base;
	return result;
}

bool equal(double num1,double num2){
	if(num1-num2>-0.0000001 || num1-num2<0.00000001){
		return true;
	}else{
		return false;
	}
}

bool g_InputInvalid=false;

double power(double base,int exponent){
	g_InputInvalid=false;
	if(equal(base,0.0)&&exponent<0){
		g_InputInvalid=true;
		return 0.0;
	}

	unsigned int absExponent=(unsigned int )(exponent);
	if(exponent<0)
		absExponent=(unsigned int)(-exponent);

	double result=powerWithUnsignedExponent(base,exponent);
	if(exponent<0)
		result=1.0/result;
	 return result;
}

/************************************************************************
打印1到最大的n位数  大数问题
************************************************************************/

/*字符串数组模拟整数自加，并判断是否溢出*/
bool increment(char *number){
	bool isOverflow=false;
	int nTakeOver=0;
	int nLength=strlen(number);

	for(int i=nLength-1;i>=0;i--){
		int nSum=number[i]-'0'+nTakeOver;
		if(i==nLength-1)
			nSum++;
		if(nSum>=10){
			if(i==0){
				isOverflow=true;
			}else{
				nSum-=10;
				nTakeOver=1;
				number[i]='0'+nSum;
			}
		}else{
			number[i]='0'+nSum;
			break;
		}
	}

	return isOverflow;
}

/*打印字符数组的的数 主要是考虑前面的补0的位不要打印出来*/
void printNumber(char *number){
	bool isBegining0=true;
	int nLength=strlen(number);

	for(int i=0;i<nLength;i++){
		if(isBegining0 && number[i]!='0'){
			isBegining0=false;
		}

		if(!isBegining0){
			printf("%c",number[i]);
		}
	}

	printf("\t");
}

void print1ToMaxOfNDigits(int n){
	if(n<=0)
		return ;
	char *number=new char[n+1];
	memset(number,'0',n);
	number[n]='\0';

	while(!increment(number)){
		printNumber(number);
	}

	delete[] number;
}

/************************************************************************
打印1到最大的n位数  大数问题  思路2：全排列 递归  为看懂！！！！！
************************************************************************/

/************************************************************************
调整数组顺序使奇数位于偶数前面 一般性解法
************************************************************************/
void reorderOddEven(int *pData,unsigned int length){
	if(pData==NULL || length==0)
		return;

	int *pBegin=pData;
	int *pEnd=pData+length-1;
	while(pBegin<pEnd){

		//向后移动pBegin 直到它指向偶数
		while(pBegin<pEnd && (*pBegin&0x01)!=0)
			pBegin++;
		//向前移动pEnd 直到它指向奇数
		while(pBegin<pEnd && (*pEnd&0X01)==0)
			pEnd--;

		if(pBegin<pEnd){
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}

	}
}




/************************************************************************
调整数组顺序使奇数位于偶数前面 可扩展性解法
************************************************************************/

bool isEven(int n){
	return (n&0x01)==0;
}


void reorderOddEvenCore(int *pData,unsigned int length,bool (*func)(int)){
	if(pData==NULL || length==0)
		return;

	int *pBegin=pData;
	int *pEnd=pData+length-1;
	while(pBegin<pEnd){

		//向后移动pBegin 直到它指向偶数
		while(pBegin<pEnd && !func(*pBegin))
			pBegin++;
		//向前移动pEnd 直到它指向奇数
		while(pBegin<pEnd && func(*pEnd))
			pEnd--;

		if(pBegin<pEnd){
			int temp=*pBegin;
			*pBegin=*pEnd;
			*pEnd=temp;
		}

	}
}


void reorder(int *pData,unsigned int length){
	reorderOddEvenCore(pData,length,isEven);
}

/************************************************************************
顺时针打印矩阵 多重循环 边界判断
************************************************************************/

void printMatrixInCircle(int **numbers,int rows,int columns,int start){

	int endX=rows-1-start;
	int endY=columns-1-start;

	//从左到右打印一行
	if(start<endY){
		for(int i=start;i<=endY;i++){
			int number=numbers[start][i];
			printf("%d ",number);
		}
	}

	//从上到下打印一行
	if(start<endX){
		for(int i=start+1;i<=endX;i++){
			int number=numbers[i][endY];
			printf("%d ",number);
		}
	}
	//从右到左打印一行
	if(start<endX && start<endY){
		for(int i=endY-1;i>=start;--i){
			int number=numbers[endX][i];
			printf("%d ",number);
		}

	}
	//从下到上打印一行
	if(start<endY &&start<endX-1){
		for(int i=endX-1;i>=start+1;i--){
			int number=numbers[i][start];
			printf("%d ",number);
		}
	}
}

void printMartrixClockwisely(int **numbers,int rows,int columns){
	if(numbers==NULL || rows<=0 || columns<=0)
		return;
	int start=0;

	while(rows>2*start && columns>2*start){
		printMatrixInCircle(numbers,rows,columns,start);
		start++;
	}
}

/************************************************************************
字符串的排列 递归过程不理解？？？？？？？？？？？？？？？
************************************************************************/
void permutationCore(char *pStr,char *pBegin){

	if(*pBegin=='\0'){
		printf("%s",pStr);
	}else{
		for(char *pCh=pBegin;*pCh!='\0';++pCh){
			char temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;

			permutationCore(pStr,pBegin+1);

			temp=*pCh;
			*pCh=*pBegin;
			*pBegin=temp;
		}
	}
}

void permutation(char *pStr){
	if(pStr==NULL)
		return;
	permutationCore(pStr,pStr);
}

/************************************************************************
数组中出现次数超过一半的数字 思路1:基于随机快速排序 寻找中位数
************************************************************************/
bool g_bInputInvalid=false;

bool checkInvalidArray(int *numbers,int length){
	g_bInputInvalid=true;
	if(numbers==NULL || length<=0)
		g_bInputInvalid=false;
	return g_bInputInvalid;
}

bool checkMoreThanHalf(int* numbers,int length,int number){
	int times=0;
	for(int i=0;i<length;i++){
		if(numbers[i]==number)
			times++;
	}

	bool isMoreThanHalf=true;
	if(2*times<=length){
		g_bInputInvalid=true;
		isMoreThanHalf=false;
	}
	return isMoreThanHalf;
}

int moreThanHalfNumber(int *numbers,int length){
	if(checkInvalidArray(numbers,length))
		return 0;
	int middle=length>>1;
	int start=0;
	int end=length-1;
	int index=partition(numbers,length,start,end);

	while(index!=middle){
		if(index>middle){
			end=index-1;
			index=partition(numbers,length,start,end);
		}else{
			start=index+1;
			index=partition(numbers,length,start,end);
		}
	}

	int result=numbers[middle];
	if(!checkMoreThanHalf(numbers,length,result));
		result=0;

	return result;
}

/************************************************************************
数组中出现次数超过一半的数字 思路2:数组中一个数字出现的次数超过数组长度的一半，说明它出现的
次数比其他所有数字出现的次数和还要多
************************************************************************/
int moreThanHalfNumber2(int *numbers,int length){
	if(checkInvalidArray(numbers,length))
		return 0;
	int result=numbers[0];
	int times=1;
	for( int i=1;i<length;i++){
		if(times==0){
			result=numbers[i];
			times=1;
		}else if(numbers[i]==result){
			times++;
		}else{
			times--;
		}
	}

	if(!checkMoreThanHalf(numbers,length,result))
		result=0;
	return result;

}

/************************************************************************
求一个数组中最小的k个数 思路1：基于partion的思想
************************************************************************/
void getLeastNumbers(int *input,int n,int *output,int k){

	if(input==NULL || output==NULL || k>n || n<=0 ||k<=0)
		return;
	int start=0;
	int end=n-1;
	int index=partition(input,n,start,end);
	while(index!=k-1){
		if(index>k-1){
			end=index-1;
			index=partition(input,n,start,end);
		}else{
			start=index+1;
			index=partition(input,n,start,end);
		}
	}

	for(int i=0;i<k;i++){
		output[i]=input[i];
	}
}


/************************************************************************
求一个数组中最小的k个数 思路2：基于最大堆的思想  适合海量数据
************************************************************************/
typedef multiset<int, greater<int> > intSet;
typedef multiset<int, greater<int> >::iterator setIterator;
void getLeastNumbers2(const vector<int> & data,intSet &leastNumbers,int k){
	leastNumbers.clear();

	if(k<1 || data.size()<k)
		return;

	vector<int>::const_iterator iter=data.begin();
	for(;iter!=data.end();iter++){
		if(leastNumbers.size()<k){
			leastNumbers.insert(*iter);
		}else{
			setIterator iterGreatest=leastNumbers.begin();
			if(*iter<*leastNumbers.begin()){
				leastNumbers.erase(iterGreatest);
				leastNumbers.insert(*iter);
			}
		}
	}
}

/************************************************************************
连续子数组的最大和
************************************************************************/
int findGreatestSumOfSubArray(int *pData,int nLength){
	if(pData==NULL || nLength<=0){
		g_InputInvalid=true;
		return 0;
	}
	
	g_InputInvalid=false;
	int nCurSum=0;
	int nGreatestSum=0xF0000000;
	for(int i=0;i<nLength;i++){
		if(nCurSum<=pData[i])
			nCurSum=pData[i];
		else
			nCurSum+=pData[i];

		if(nCurSum>nGreatestSum)
			nGreatestSum=nCurSum;
	}
	return nGreatestSum;
}

/************************************************************************
从1到n整数中1出现的次数
************************************************************************/
int powerBase10(unsigned int n){
	int result=1;
	for(unsigned int i=0;i<n;i++){
		result*=10;

	}
	return result;
}

int numberOf1(const char*strN){
	if(!strN || *strN<'0'|| *strN>'9' || *strN=='\0')
		return 0;
	int first=*strN-'0';//first为最高位数字
	unsigned int length=static_cast<unsigned int>(strlen(strN));//n的总位数

	if(length==1 && first==0)//n==0
		return 0;
	if(length==1 && first>0)// n==[1,9]
		return 1;
	//假设strN是 "21345"
	//numFirstDigit是数字10000到19999中第一个位中1的数目（最高位中1的数目）
	int numFirstDigit=0;
	if(first>1)
		numFirstDigit=powerBase10(length-1);
	else if(first==1)
		numFirstDigit=atoi(strN+1)+1;
	//numOtherDigits是1346——21345中除第一位外，其他数位中1 的个数
	int numOtherDigits=first*(length-1)*powerBase10(length-2);
	//numRecursive是1--1345中1的个数
	int numRecursive=numberOf1(strN+1);

	return numFirstDigit+numOtherDigits+numRecursive;
}


int numberOf1Between1AndN(int n){
	if(n<=0)
		return 0;
	char strN[50];
	sprintf(strN,"%d",n);
	return numberOf1(strN);
}



/************************************************************************
把数组排成最小的数
************************************************************************/
const int g_MaxNumberLength=10;
char* g_StrCombine1=new char[2*g_MaxNumberLength+1];
char* g_StrCombine2=new char[2*g_MaxNumberLength+1];

int compare(const void * strNumber1,const void *strNumber2){
	strcpy(g_StrCombine1,*(const char**)strNumber1);
	strcat(g_StrCombine1,*(const char**)strNumber2);

	strcpy(g_StrCombine2,*(const char**)strNumber2);
	strcat(g_StrCombine2,*(const char**)strNumber1);

	return strcmp(g_StrCombine1,g_StrCombine2);

}

void printMinNumber(int *numbers,int length){
	if(numbers==NULL ||length<=0)
		return;
	char **strNumbers=(char **)(new int[length]);
	for(int i=0;i<length;++i){
		strNumbers[i]=new char[g_MaxNumberLength+1];
		sprintf(strNumbers[i],"%d",numbers[i]);
	}

	qsort(strNumbers,length,sizeof(char*),compare);
	for(int i=0;i<length;++i){
		printf("%s",strNumbers[i]);
	}
	printf("\n");

	for(int i=0;i<length;i++){
		delete[] strNumbers[i];
	}

	delete[] strNumbers;
}

/************************************************************************
丑数
************************************************************************/
int min3(int number1,int number2,int number3){
	int res=(number1<number2)?number1:number2;
	res=(res<number3)?res:number3;
	return res;
}

int getUglyNumber(int index){
	if(index<=0)
		return 0;
	int *pUglyNumbers=new int[index];
	pUglyNumbers[0]=1;
	int nextUglyIndex=1;

	int* pMultiply2=pUglyNumbers;
	int* pMultiply3=pUglyNumbers;
	int* pMultiply5=pUglyNumbers;

	while(nextUglyIndex<index){
		int minValue=min3(*pMultiply2*2,*pMultiply3*3,*pMultiply5*5);
		pUglyNumbers[nextUglyIndex]=minValue;
		while(*pMultiply2*2<=pUglyNumbers[nextUglyIndex])
			++pMultiply2;
		while(*pMultiply3*3<=pUglyNumbers[nextUglyIndex])
			++pMultiply3;
		while(*pMultiply5*5<=pUglyNumbers[nextUglyIndex])
			++pMultiply5;
		++nextUglyIndex;
	}
	int ugly=pUglyNumbers[nextUglyIndex-1];
	delete[] pUglyNumbers;
	return ugly;
}





/************************************************************************
第一个只出现一次的字符
************************************************************************/
char firstNotReaptingChar(char*pString){
	if(pString==NULL)
		return '\0';
	const int tableSize=256;
	unsigned int hashTable[tableSize];
	for(unsigned int i=0;i<tableSize;i++){
		hashTable[i]=0;
	}
	char *pHashKey=pString;
	while(*(pHashKey)!='\0'){
		hashTable[*(pHashKey++)]++;
	}

	pHashKey=pString;
	while(*pHashKey!='\0'){
		if(hashTable[*pHashKey]==1)
			return *pHashKey;
		pHashKey++;
	}
	return '\0';

}




/************************************************************************
数组中的逆序对
************************************************************************/
int inversePairsCore(int*data,int*copy,int start,int end){
	if(start==end){
		copy[start]=data[start];
		return 0;
	}
	int length=(end-start)/2;
	int left=inversePairsCore(data,copy,start,start+length);
	int right=inversePairsCore(data,copy,start+length+1,end);
	//i初始化为前半段最后一个数字下标
	int i=start+length;
	//j初始化为后半段最后一个数字下标
	int j=end;
	int indexCopy=end;
	int count=0;

	while(i>=start && j>=start+length+1){
		if(data[i]>data[j]){
			copy[indexCopy--]=data[i--];
			count+=j-start-length;
		}else{
			copy[indexCopy--]=data[j--];
		}
	}

	for(;i>=start;--i){
		copy[i]=data[i];
	}

	for(;j>=start+length+1;--j){
		copy[j]=data[j];
	}

	return left+right+count;
	
}

int inversePairs(int *data,int length){
	if(data==NULL || length<=0)
		return 0;
	int *copy=new int[length];
	for(int i=0;i<length;i++){
		copy[i]=data[i];
	}

	int count=inversePairsCore(data,copy,0,length-1);

	delete[] copy;
	return count;
}










/************************************************************************
数字在排序数组中出现的次数
************************************************************************/










/************************************************************************
数组中只出现一次的数字
************************************************************************/