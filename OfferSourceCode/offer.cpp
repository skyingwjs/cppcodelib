#include "offer.h"

bool Solution::find(vector<vector<int> > array,int target){
	int rowCount=array.size();
	int colCount=array[0].size();
	int i,j;
	for(i=rowCount-1,j=0;i>=0&&j<colCount;){
		if(array[i][j]==target){
			return true;
		}
		if(array[i][j]>target){
			i--;
			continue;
		}
		if(array[i][j]<target){
			j++;
			continue;
		}
	}
	return false;
}


void Solution::replaceSpace(char *str,int length){
	if(NULL==str||length<=0)
		return ;
	int oldCharNum=0;
	int newCharNum=0;
	int spaceNum=0;
	int i=0;
	for(;str[i]!='\0';i++){
		if(str[i]==' '){
			spaceNum++;
		}
		oldCharNum++;
	}
	newCharNum=oldCharNum+2*spaceNum;
	if(newCharNum>length)
		return;
	int oldCharIdx=oldCharNum;
	int newCharIdx=newCharNum;
	while(newCharIdx!=oldCharIdx){
		if(str[oldCharIdx]==' '){
			str[newCharIdx--]='0';
			str[newCharIdx--]='2';
			str[newCharIdx--]='%';

		}else{
			str[newCharIdx--]=str[oldCharIdx];
		}
		oldCharIdx--;
	}
}

vector<int> Solution::printListFromTailToHead( ListNode * head){
	vector<int> value;
	if(head!=NULL){
		ListNode * pNode=head;
		while(pNode!=NULL){
				value.insert(value.begin(),pNode->val);
				pNode=pNode->next;
		}
	}
	return value;
}

vector<int> Solution::printListFromTailToHead2(struct ListNode* head) {
	vector<int> value;
	if(head != NULL)
	{
		value.insert(value.begin(),head->val);
		if(head->next != NULL)
		{
			vector<int> tempVec = printListFromTailToHead2(head->next);
			if(tempVec.size()>0)
				value.insert(value.begin(),tempVec.begin(),tempVec.end());  
		}         

	}
	return value;
}

TreeNode * Solution::reconstructBinaryTree(vector<int> pre,vector<int> in){
	int inLen=in.size();
	if(inLen==0){
		return NULL;
	}
	//�������ڵ� ���ڵ��ֵΪ�����������һ��Ԫ��
	TreeNode *root=new TreeNode(pre[0]);
	//������������ҵ����ڵ�Ԫ��ֵ��λ�ã�������

	int rootValIdx=0;
	for(int i=0;i<inLen;i++){
		if(in[i]==pre[0]){
			rootValIdx=i;
			break;
		}
	}
	//�������������� ǰ��������
	vector<int> leftIn,leftPre,rightIn,rightPre;

	//����������������ڵ���ߵĽڵ�λ�ڶ���������ߣ����ڵ��ұߵĽڵ�λ�ڶ��������ұ�,����������㣬�Զ������ڵ���й鲢
	//�洢��������ǰ������������
	for(int j=0;j<rootValIdx;j++){
		leftIn.push_back(in[j]);
		leftPre.push_back(pre[j+1]);
	}
	//�洢��������ǰ������������
	for(int k=rootValIdx+1;k<inLen;k++){
		rightIn.push_back(in[k]);
		rightPre.push_back(pre[k]);
	}

	//��shell�����˼�����ƣ�ȡ��ǰ�������������ڵ���ߺ��ұߵ�����
	//�ݹ飬�ٶ�������������в��裬��������������������������ֱ��Ҷ�ڵ�
	root->left=reconstructBinaryTree(leftPre,leftIn);
	root->right=reconstructBinaryTree(rightPre,rightIn);
	return root;

}   


void Solution::push(int node){
	stack1.push(node);
}
int Solution::pop(){
		if(stack2.empty()){
			while(!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		int result=stack2.top();
		stack2.pop();
		return  result;
}


int Solution::minNumberInRotateArray(vector<int> rotateArray){
	if(rotateArray.size()==0)
		return 0;
	for(int i=0;i<rotateArray.size()-1;i++){
		if((rotateArray[i]>rotateArray[i+1]))
			return rotateArray[i+1];	
	}
	return rotateArray[0];
}

int Solution::minNumberInRotateArray2(vector<int> rotateArray){
	int size=rotateArray.size();
	if(size==0)
		return 0;
	int left=0,right=size-1,mid=0;
	//rotateArray[left]>=rotateArray[right]ȷ����ת
	while(rotateArray[left]>=rotateArray[right]){
		//�ֽ��  �ҵ�����СԪ�ص�λ�ã���Ϊright��
		if(right-left==1){
			mid=right;
			break;
		}
		mid=left+(right-left)/2;

		//rotateArray[left] rotateArray[right] rotateArray[mid]�������ʱ���޷�ȷ��
		//�м�Ԫ��������ǰ��Ļ��Ǻ���ĵ��������� ֻ��˳�����
		if(rotateArray[left]==rotateArray[right]&&rotateArray[right]==rotateArray[mid]){
			return minOrder(rotateArray,left,right);
		}

		//�м�Ԫ��λ��ǰ��ĵ��������� ��ʱ��СԪ��λ���м�Ԫ�صĺ���
		if(rotateArray[mid]>=rotateArray[left]){
			left=mid;
		}
		//�м�Ԫ��λ�ں���ĵ��������� ��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
		else{
			right=mid;
		}
	}
	return rotateArray[mid];
}

int Solution::minOrder(vector<int>&rotateArray,int left,int right){
	int result =rotateArray[left];
	for(int i=left+1;i<right;++i){
		if(rotateArray[i]<result)
			result=rotateArray[i];
	}
	return result;
}

int Solution::fabonacci1(int n){
	if(n<=0){
		return 0;
	}

	if (n==1||n==2){
		return 1;
	}
	return fabonacci1(n-1)+fabonacci1(n-2);
}

int Solution::fabonacci2(int n){
	int first=0,second=1;
	while(n--){
		second+=first;
		first=second-first;
	}
	return first;
}

int Solution::jumpFloor(int n){
	int first=0,second=1;
	while(n--){
		second+=first;
		first=second-first;
	}
	return second;
}


int Solution::jumpFloorII(int n){
	return 1<<--n;
}


int Solution::rectCover(int number){
	if(number<=0)
		return 0;
	int first=0,second=1;
	while(number--){
		second+=first;
		first=second-first;
	}
	return second;
}

int  Solution::numberOf1(int n){
	
	int count =0,flag=1;
	/*�ⷨ1*/
	/*
	while(flag!=0){
		if((n&flag)!=0){
			count++;
		}
		flag<<=1;//��Ҫ����32��
	}
	*/

	/*�ⷨ2�����ţ�*/
	while(n!=0){
		count++;
		n=(n-1)&n;//ÿ��������n���ұߵ�1��Ϊ0
	}
	return count;
}

double Solution::power(double base,int exponent){
	double result=1,curr=base;
	int n=0;
	if(exponent>0){
		n=exponent;
	}
	else if(exponent<0){
		n=-exponent;
		if(base==0){
			cout<<"��ĸ����Ϊ0"<<endl;
			return 0;
		}
	}
	else{//exponent==0
		return 1;//0��0�η�
	}
	while(n!=0){
		if((n&1)==1){
			result*=curr;
		}
		curr*=curr;//����
		n>>=1;//����1λ
	}

	return exponent>0?result:1/result;
}

void Solution::swap(int &a,int &b){
	if(a!=b){
		a=a^b;
		b=a^b;
		a=a^b;
	}
}


void Solution::reorderArray(vector<int> &array){
	/*ð�������˼��  ǰż�������ͽ��� ���ӶȺܸ�*/
	//for(int i=0;i<array.size();i++){
	//	for(int j=array.size()-1;j>i;j--){
	//		if(array[j]%2==1&&array[j-1]%2==0){
	//			swap(array[j],array[j-1]);
	//		}
	//	}
	//}

	/*�����µ�����*/
	vector<int> temp;
	vector<int>::iterator itb1,ite1,itb2,ite2;
	itb1=array.begin();

	for(;itb1!=array.end();){
		if(*itb1%2==0){   //����ż�����ͱ��浽�����飬ͬʱ��ԭ������ɾ�� 
			temp.push_back(*itb1);
			itb1=array.erase(itb1);
		}else{
			itb1++;
		}
	}
	itb2=temp.begin();
	ite2=temp.end();
	for(;itb2!=ite2;itb2++){
		array.push_back(*itb2);
	}
	/*ֱ�Ӳ��������˼��  δд*/


}

ListNode* Solution::findKthNodeToTail(ListNode *pListHead,unsigned int k){
	if(pListHead==NULL||k<=0)
		return NULL;

	vector<ListNode *> nodeArray;
	ListNode *p1=pListHead;
	while(p1!=NULL){
		nodeArray.push_back(p1);
		p1=p1->next;
	} 
	if(k>nodeArray.size()){
		return NULL;
	}else{
		return nodeArray[nodeArray.size()-k];
	}
	
}

ListNode * Solution::reverseList(ListNode *pHead){
	if(pHead==NULL)
		return NULL;
	ListNode *pLast=NULL,*pCurr=pHead,*pNext=pCurr->next;
	while(NULL!=pCurr){
		pCurr->next=pLast;
		pLast=pCurr;
		pCurr=pNext;
		pNext=pCurr->next;
	}
	return pLast;
}

ListNode * Solution::mergeList(ListNode *pHead1,ListNode *pHead2){
	if(pHead1==NULL){
		return pHead2;
	}
	if(pHead2==NULL){
		return pHead1;
	}
	
	ListNode *pHead=NULL,*p1=pHead1,*p2=pHead2,*pCurr=NULL;
	/*�ݹ�ⷨ*/
	/*if(p1->val<=p2->val){
		pHead=p1;
		pHead->next=mergeList(p1->next,p2);
	}else{
		pHead=p2;
		pHead->next=mergeList(p1,p2->next);
	}*/

	/*�ǵݹ�ⷨ*/
	while(p1!=NULL&&p2!=NULL){
		if(p1->val<=p2->val){
			if(pHead==NULL){
				pHead=pCurr=p1;
			}else{
				pCurr->next=p1;
				pCurr=pCurr->next;
			}
			p1=p1->next;
		}else{
			if(pHead==NULL){
				pHead=pCurr=p2;
			}else{
				pCurr->next=p2;
				pCurr=pCurr->next;
			}
			p2=p2->next;
		}
	}

	if(p1==NULL){
		pCurr->next=p2;
	}
	if(p2==NULL){
		pCurr->next=p1;
	}
	return pHead;

}

bool Solution::isSubtree(TreeNode* pRootA, TreeNode* pRootB){
	if(pRootA==NULL) 
		return false;
	if(pRootB==NULL)
		return true;
	if(pRootA->val==pRootB->val){
		return isSubtree(pRootA->left,pRootB->left)
			&&isSubtree(pRootA->right,pRootB->right);
	}else{
		return false;
	}

}

bool Solution::hasSubtree(TreeNode* pRootA, TreeNode* pRootB){
	if(pRootA==NULL||pRootB==NULL){
		return false;
	}
	return isSubtree(pRootA,pRootB)||
		hasSubtree(pRootA->left,pRootB)||
		hasSubtree(pRootA->right,pRootB);
}

void Solution::bitTreeMirror(TreeNode *pRoot){
	if(pRoot==NULL)
		return;
	/*�ݹ�ⷨ*/
	/*TreeNode *pNode=pRoot->left;
	pRoot->left=pRoot->right;
	pRoot->right=pNode;

	bitTreeMirror(pRoot->left);
	bitTreeMirror(pRoot->right);*/

	/*�ǵݹ�ⷨ*/
	stack<TreeNode *>stackNode;
	stackNode.push(pRoot);
	while(stackNode.size()){
		TreeNode *tree=stackNode.top();
		stackNode.pop();
		if(tree->left!=NULL||tree->right!=NULL){
			TreeNode *pNode=tree->left;
			tree->left=tree->right;
			tree->right=pNode;
		}

		if(tree->left){
			stackNode.push(tree->left);
		}
		if(tree->right){
			stackNode.push(tree->right);
		}
	}
}

vector<int> Solution::printMatrix(vector<vector<int> > matrix){
	int rows=matrix.size();
	int cols=matrix[1].size();
	vector<int> result;
	if(rows==0&&cols==0)
		return result;
	int left=0,right=cols-1,top=0,bottom=rows-1;

	while(left<=right&&top<=bottom){
		//left to right
		for(int i=left;i<=right;++i){
			result.push_back(matrix[top][i]);
		}
		//top to bottom
		for(int i=top+1;i<=bottom;++i){
			result.push_back(matrix[i][right]);
		}
		//right to left
		if(top!=bottom){
			for(int i=right-1;i>=left;--i){
				result.push_back(matrix[bottom][i]);
			}
		}
		//bottom to top
		if(left!=right){
			for(int i=bottom-1;i>top;--i){
				result.push_back(matrix[i][left]);
			}
		}
		left++,right--,top++,bottom--;	
	}

	/*for(int i=0;i<rows;i++){
	for(int j=0;j<cols;j++){
	result.push_back(matrix[i][j]);
	}
	}*/
	return result;
}

bool Solution::isPopOrder(vector<int> pushV,vector<int> popV){
	if(pushV.size()==0)
		return false;
	vector<int> stack;
	for(int i=0,j=0;i<pushV.size();){
		stack.push_back(pushV[i++]);
		while(j<popV.size()&&stack.back()==popV[j]){
			stack.pop_back();
			j++;
		}
	}
	return stack.empty();
}

vector<int> Solution::printFromTopToBottom(TreeNode* root){
	vector<int> result;
	if(root!=NULL){
		queue<TreeNode *> q;
		TreeNode * rt=root;
		q.push(rt);
		while(!q.empty()){
			rt=q.front();
			q.pop();
			if(!rt){//rt==NULLʱ
				continue;
			}
			result.push_back(rt->val);
			q.push(rt->left);
			q.push(rt->right);
		}
	}
	return result;
}

//û��������������������������
bool Solution::judge(vector<int>& a, int l, int r){
	if(l >= r) 
		return true;
	int i = r;
	while(i > l && a[i - 1] > a[r]) 
		--i;
	for(int j = i - 1; j >= l; --j) {
		if(a[j] > a[r]) 
			return false;
	}
	return judge(a, l, i - 1) && (judge(a, i, r - 1));
}

bool Solution::verifySquenceOfBST(vector<int> sequence){
	/*�ݹ�ⷨ  û��������*/
	/*if(!sequence.size()) 
	return false;
	return judge(sequence, 0, sequence.size() - 1);*/


	/*�ǵݹ�ⷨ*/
	if (!sequence.size())
		return false;
	int size=sequence.size();
	int i = 0;
	while(--size){
		while(sequence[i++]<sequence[size]);
		while(sequence[i++]>sequence[size]);
		if(i<size)
			return false;
		i=0;
	}
	return true;
}

vector<int> path;
vector<vector<int> >allPath;
vector<int> Solution::depthFirstSearch(TreeNode* root,int leftNum/*leftNumΪ���µ���Ŀ*/){
	
	path.push_back(root->val);
	if(leftNum-root->val==0&&!root->left&&!root->right){
		allPath.push_back(path);
	}else{
		if(root->left)
			depthFirstSearch(root->left,leftNum-root->val);
		if(root->right)
			depthFirstSearch(root->right,leftNum-root->val);
	}
	path.pop_back();
	return path;
}

vector<vector<int> > Solution::findPath(TreeNode *root,int expectNumber){
	if(root) 
		depthFirstSearch(root, expectNumber);
	return allPath;
}

RandomListNode* Solution::clone(RandomListNode* pHead){
	if(!pHead)
		return NULL;
	RandomListNode *pCurrNode=pHead;
	
	//��������Node
	while(pCurrNode){
		RandomListNode *pNewNode=new RandomListNode(pCurrNode->label);//����һ���½ڵ�
		pNewNode->next=pCurrNode->next;//���������½ڵ� ����ԭ���֮��
		pCurrNode->next=pNewNode;
		pCurrNode=pNewNode->next;//ָ����������һ�����
	}

	//���Ƹ����½ڵ��random
	pCurrNode=pHead;
	while(pCurrNode){
		RandomListNode *pCloneNode=pCurrNode->next;
		if(pCurrNode->random){
			pCloneNode->random=pCurrNode->random->next;
		}
		pCurrNode=pCloneNode->next;
	}

	//����¾�����
	pCurrNode=pHead;
	RandomListNode *pCloneHead=pCurrNode->next;
	RandomListNode *pCloneNode;
	while(pCurrNode->next){
		pCloneNode=pCurrNode->next;
		pCurrNode->next=pCloneNode->next;
		pCurrNode=pCloneNode;
		//if(pCurrNode->next){
		//	pCurrNode=pCurrNode->next;
		//	pCloneNode->next=pCurrNode->next;	
		//}

	}
	return pCloneHead;
}

TreeNode* Solution::convert(TreeNode* pRootOfTree){
	/*1.�ǵݹ�ⷨ*/
	if(!pRootOfTree)
		return NULL;
	TreeNode* pListHead=NULL;
	TreeNode* pCurrNode=pRootOfTree;
	TreeNode* pPreNode=NULL;
	stack<TreeNode *> stackNode;
	bool isFirst=true;

	while(pCurrNode!=NULL||!stackNode.empty()){
		while(pCurrNode){//�ҵ�����ͷ���
			stackNode.push(pCurrNode);
			pCurrNode=pCurrNode->left;
		}
		pCurrNode=stackNode.top();//��ȡ��ǰ���ָ��
		stackNode.pop();//��ջ

		if(isFirst){
			pListHead=pCurrNode;//˫������ͷָ��
			pPreNode=pCurrNode;
			isFirst=false;
		}else{
			pPreNode->right=pCurrNode;
			pCurrNode->left=pPreNode;
			pPreNode=pCurrNode;
		}

		pCurrNode=pCurrNode->right;//���ʵ�ǰ������һ����㣨�Һ��ӣ�
	}
	return pListHead;
}

void Solution::swap(char &a,char &b){
	if(a!=b){
		a=a^b;
		b=b^a;
		a=a^b;
	}
}

void Solution::swap(char *pa,char *pb){
	char temp=*pa;
	*pa=*pb;
	*pb=temp;
}


/*
void Solution::fullPermulation(vector<string> &ans, int k, string str){//������kλ���п���
	if(k==str.size()-1){
		ans.push_back(str);
	}
	set<char> charSet;//��¼���ֹ����ַ�  ���ظ�
	sort(str.begin()+k,str.end());//���� ��֤���ֵ�˳�����
	for(int i=k;i<str.size();i++){
		if(charSet.find(str[i])==charSet.end()){//ֻ��δ�������Ľ���
			charSet.insert(str[i]);//�����ַ���set
			swap(str[i],str[k]);
			fullPermulation(ans,k+1,str);
			swap(str[i],str[k]);
		}
	}
}

vector<string> Solution::permulation(string str){
	vector<string> result;
	fullPermulation(result,0,str);
	return result;
}
*/



void Solution::permutation(char *pStr){
	if(pStr==NULL)
		return;
	permutation(pStr,pStr);
}

void Solution::permutation(char *pStr,char *pBegin){
	if(*pBegin=='\0'){
		printf("%s\n",pStr);	
	}else{
		for(char *pCh=pBegin; *pCh!='\0';++pCh){
			swap(*pCh,*pBegin);
			permutation(pStr,pBegin+1);
			swap(*pCh,*pBegin);
		}
	}
}

int Solution::moreThanHalfNum(vector<int> numbers){
	if(numbers.size()==0)
		return 0;
	int num=numbers[0],count=1;
	for(int i=1;i<numbers.size();i++){
		if(numbers[i]==num)
			count++;
		else
			count--;
		if(count==0){
			num=numbers[i];
			count=1;
		}
	}
	//��֤
	count=0;
	for (int j=0;j<numbers.size();j++){
		if(numbers[j]==num)
			count++;
	}
	return (count*2>numbers.size())?num:0;
}

vector<int> Solution::getLeastNumbers(vector<int> input, int k){
	/*˼·1��ȫ���� O(nlogn)*/
	
	vector<int> res;
	if(input.empty()||k>input.size()) 
		return res;
	sort(input.begin(),input.end());
	for(int i=0;i<k;i++)
		res.push_back(input[i]);
	return res;
	

    /*˼·2: �������� ʱ�临�Ӷ�O��nlogk��*/


}

int Solution::findGreatestSumOfSubArray(vector<int> array){
	if(array.size()==0){
		return 0;
	}else{
		int total=array[0],maxSum=array[0];
		for(int i=1;i<array.size();i++){
			if(total>=0){
				total+=array[i];
			}else{
				total=array[i];
			}
			if(total>maxSum){
				maxSum=total;
			}
		}
		return maxSum;
	}
	
}

int Solution::numberOf1Between1AndN(int n){
	int ones=0;
	for(long long m=1;m<=n;m*=10){
		ones+=(n/m+8)/10*m+(n/m%10==1)*(n%m+1);
	}
	return ones;
}


bool Solution::compare(const string &str1,const string &str2){
	string s1=str1+str2;
	string s2=str2+str1;
	return s1<s2;
}
string Solution::printMinNumber(vector<int> numbers){
	string minNumStr="";
	if(numbers.size()<=0)
		return minNumStr;
	vector<string> strVec;
	for(int i=0;i<numbers.size();i++){
		stringstream ss;
		ss<<numbers[i];
		string s=ss.str();
		strVec.push_back(s);
	}
	sort(strVec.begin(),strVec.end(),compare);
	for(int i=0;i<strVec.size();i++){
		minNumStr.append(strVec[i]);
	}
	return minNumStr;
}

int Solution::getUglyNumber(int index){
	if(index<7)
		return index;
	vector<int> result(index);
	int t2=0,t3=0,t5=0;
	result[0]=1;
	for (int i=1;i<index;i++){
		result[i]=min(result[t2]*2,min(result[t3]*3,result[t5]*5));
		if(result[i]==result[t2]*2)
			t2++;
		if(result[i]==result[t3]*3)
			t3++;
		if(result[i]==result[t5]*5)
			t5++;
	}
	return result[index-1];
}

int Solution::firstNotRepeatingChar(string str){
	if(str.length()==0)
		return -1;
	unsigned int hashTimes[256]={0};
	for(int i=0;i<str.length();i++){
		hashTimes[str[i]]++;
	}

	for(int i=0;i<str.length();i++){
		if(hashTimes[str[i]==1])
			return i;
	}
	return -1;
}

int Solution::inversePairs(vector<int> data){
	return 0;
}

ListNode* Solution::findFirstCommonNode( ListNode* pHead1, ListNode* pHead2){
	if(pHead1==NULL||pHead2==NULL){
		return NULL;
	}
	ListNode* p1=pHead1,*p2=pHead2;
	while(p1!=p2){
		p1=(p1==NULL?pHead2:p1->next);
		p2=(p2==NULL?pHead1:p2->next);
	}
	return p1;

}

int Solution::getFirstIndex(vector<int> &data,int k,int start,int end){
	if(start>end)
		return -1;
	int mid=start+(end-start)/2;
	if(data[mid]==k){
		if(mid==start||(data[mid-1]!=k)){
			return mid;
		}else{
			end=mid-1;
		}
	}else{
		if(data[mid]>k){
			end=mid-1;
		}else{
			start=mid+1;
		}

	}
	return getFirstIndex(data,k,start,end);
}

int Solution::getLastIndex(vector<int> &data,int k,int start,int end){
	if(start > end)
		return -1;
	int mid = start+(end-start)/2;
	if(data[mid]==k){
		if((mid == end) || (data[mid+1] != k))
			return mid;
		else
			start = mid +1;
	}
	else{
		if(data[mid]>k)
			end = mid-1;
		else
			start = mid+1;
	}
	return getLastIndex(data,k,start,end);
}

int Solution::getNumberOfK(vector<int> data ,int k){
	if(data.empty())
		return 0;
	int count=0;
	int fisrtIdx=getFirstIndex(data,k,0,data.size()-1);
	int lastIdx=getLastIndex(data,k,0,data.size()-1);
	if(fisrtIdx>-1&&lastIdx>-1){
		return lastIdx-fisrtIdx+1;
	}
	return count;
}

int Solution::treeDepth(TreeNode* pRoot){
	/*����1���ݹ鷽��*/
	/*
	if(!pRoot) return 0 ;
	return max(1+treeDepth(pRoot->left), 1+treeDepth(pRoot->right));
	*/
	/*����2����α���  ��¼��μ���*/
	queue<TreeNode *>q;
	if(!pRoot)
		return 0;
	q.push(pRoot);
	int level=0;
	while(!q.empty()){
		level++;//����
		int nodeNum=q.size();//ÿ��ڵ���
		while(nodeNum--){
			TreeNode *tmpNode=q.front();
			q.pop();
			if(tmpNode->left)
				q.push(tmpNode->left);
			if(tmpNode->right)
				q.push(tmpNode->right);
		}
	}
	return level;
}

bool Solution::isBalancedBitree(TreeNode* pRoot){
	/*����1������������ȵĺ��� ��ÿ���ڵ����Һ��ӵ����*/
	/*
	if(!pRoot)
		return true;
	int leftDepth=treeDepth(pRoot->left);
	int rightDepth=treeDepth(pRoot->right);
	int diff=abs(leftDepth-rightDepth);
	if(diff>1)
		return false;
	return isBalancedBitree(pRoot->right)&&isBalancedBitree(pRoot->right);
	*/
	/*����2�����ڷ���1����ý��ĵ������������ʱ����һ�������ٴ��ж�������ƽ����ʱ�ֱ���һ�����ṹ��
	��ɱ�����Ρ���˷�������һ�߱�����һ���ж�ÿ������Ƿ����ƽ����*/
	int depth=0;
	return isBalanced(pRoot,&depth);
}

bool Solution::isBalanced(TreeNode *pRoot,int *depth){
	if(!pRoot){
		*depth=0;
		return true;
	}

	int nLeffDepth,nRightDepth;
	bool bLeft=isBalanced(pRoot->left,&nLeffDepth);
	bool bRight=isBalanced(pRoot->right,&nRightDepth);

	if(bLeft&&bRight){
		int diff=abs(nRightDepth-nLeffDepth);
		if(diff<=1){
			*depth=1+(nLeffDepth>nRightDepth?nLeffDepth:nRightDepth);
			return true;
		}
	}

	return false;
}

void Solution::findNumsAppearOnce(vector<int> data,int* num1,int *num2){
	if(data.empty()||data.size()<2){
		return;
	}
	int temp=0;
	for(int i=0;i<data.size();i++){
		temp^=data[i];
	}

	int indexOf1=findFirstBitIs(temp);
	for(int i=0;i<data.size();i++){
		if(isBit(data[i],indexOf1)){
			*num1^=data[i];
		}else{
			*num2^=data[i];
		}
	}
}

bool Solution::isBit(int num,int indexBit){//�ж�num�ĵ�indexBitΪ�Ƿ�Ϊ1
	num =num>>indexBit;
	return num&0x01==1;
}
int  Solution::findFirstBitIs(int num){//���num�Ķ����Ʊ�ʾ�е�һ��1���ֵ�����
	int indexBit=0;
	while((num&0x01==0)&&(indexBit<32)){
		num=num>>1;
		++indexBit;
	}
	return indexBit;
}

vector<vector<int> > Solution::findContinuousSequence(int sum){
	vector<vector<int> > res;
	if(sum<3)
		return res;
	int l=(int)sqrt(2.0*sum);
	while(l>=2){
		if(2*sum%l==0){//2*sum �ܱ�2����
			int k=2*sum/l;
			if(k%2==0&&l%2!=0||k%2!=0&&l%2==0){//��֤k lһ��Ϊ����һ��Ϊż��
				vector<int> vec;
				int an=(k+l-1)/2;
				int a1=(k-l+1)/2;
				for(int j=a1;j<=an;j++){
					vec.push_back(j);
				}
				res.push_back(vec);
			}
		}
		l--;
	}
	return res;
}

vector<int> Solution::findNumbersWithSum(vector<int> array,int sum){
	vector<int> res;
	int len=array.size();
	int start=0;
	int end=len-1;
	while(start<end){
		if(array[start]+array[end]==sum){
			res.push_back(array[start]);
			res.push_back(array[end]);
			break;
		}else if(array[start]+array[end]<sum){
			start++;
		}else{
			end--;
		}
	}
	return res;
}

string Solution::leftRotateString(string str, int n){
	int len=str.length();
	if(len==0)
		return str;
	/*����1*/
	/*
	n=n%len;
	str+=str;//��������str
	return str.substr(n,len);
	*/
	/*����2*/
	string str1=str;
	n=n%len;
	for(int i=0;i<len;i++){
		str[i]=str1[(i+n)%len];
	}
	return str;
}

string Solution::reverseSentence(string str){
	stack<string> s;
	string result,temp;
	for (int i=0;i<str.size();i++)//���е���������ջ
	{
		if(str[i]!=' '){
			temp+=str[i];
		}else{
			s.push(temp);
			temp.clear();
		}
	}
	s.push(temp);
	while(!s.empty()){
		if(s.size()>1){
			result+=s.top()+" ";
		}else{
			result+=s.top();
		}
		s.pop();
	}
	return result;
}

bool Solution::isContinuous( vector<int> numbers ){
	if(numbers.size()!=5)
		return false;
	int min=14,max=-1,flag=0;
	for(int i=0;i<numbers.size();i++){
		int number=numbers[i];
		if(number<0||number>13)//���ֳ����涨��Χ
			return false;
		if (number==0)
			continue;
		if(((flag>>number)&1)==1)//�з�����ظ�����
			return false;
		flag|=(1<<number);
		if(number>max)
			max=number;
		if(number<min)
			min=number;
		if(max-min>=5)
			return false;
	}
	return true;
}

int Solution::lastRemaining(int n, int m){
	if(n <= 0 && m <= 0) return -1; //��������
	int t = 0;//Ҳ��f1=0
	for(int i = 2; i <= n; i++)//��f2��ʼ f[i]=(f[i]+m)%i
		t = (t + m) % i;
	return t;
}

int Solution::sum1ton(int n){
	int res=n;
	res&&(res+=sum1ton(n-1));
	return res;
}

int Solution::add(int num1, int num2){
	int n1,n2;
	n1=(num1&num2)<<1;
	n2=num1^num2;
	while(n1&n2){
		num1=n1;
		num2=n2;
		n1=(num1&num2)<<1;
		n2=num1^num2;
	}
	return n1|n2;
}

int Solution::strToInt(string str){
	if(str.size()==0)
		return 0;
	int i=0,res=0,flag=1;//flag��ʶ������
	if(str[0]=='-'){
		flag=-1;//����
		i++;
	}else if(str[0]=='+'){
		i++;
	}

	for(;i<str.size();i++){
		if(str[i]<'0'||str[i]>'9'){
			return 0;
		}
		res=res*10+str[i]-'0';
	}

	return res*flag;
}


bool Solution::duplicate(int numbers[], int length, int* duplication){
	bool *flag=new bool[length];//����һ����־����
	memset(flag,0,sizeof(bool)*length);//��䲻�ܵ�  ��̬������ڴ��ʼֵ�ǲ�ȷ����
	for(int i=0;i<length;i++){

		if(flag[numbers[i]]==true){
			*duplication=numbers[i];
			return true;
		}

		flag[numbers[i]]=true;

	}
	return false;
}

vector<int> Solution::multiply(const vector<int>& A){
	int n=A.size();
	vector<int> B(n);
	int factor=1;
	for(int i=0;i<n;i++){
		B[i]=factor;
		factor*=A[i];
	}
	factor=1;
	for(int i=n-1;i>=0;i--){
		B[i]*=factor;
		factor*=A[i];
	}
	return B;
}


bool Solution::match(char* str, char* pattern){
        if(str==NULL||pattern==NULL)
            return false;
        return matchCore(str,pattern);
}

bool Solution::matchCore(char* str, char* pattern){
    if(*str=='\0'&&*pattern=='\0')
        return true;
    if(*str!='\0'&&*pattern=='\0')
        return false;
    if(*(pattern+1)=='*')
    {
        if(*pattern==*str||(*pattern=='.'&&*str!='\0'))
/*
            matchCore(str,pattern+2):ģʽ��δƥ��
            matchCore(str+1,pattern):ģʽ���Ѿ�ƥ��ɹ�������ƥ����һ���ַ���
            matchCore(str+1,pat+2)��ģʽ���Ѿ��ɹ�ƥ�䣬���Ҳ�ƥ����һ���ַ�������  ע������ matchCore(str+1,pat+2)�ظ������ˣ��������Ѿ�ȥ������лл@chlq��ָ�� */
            return matchCore(str+1,pattern)||matchCore(str,pattern+2);
        else
            return matchCore(str,pattern+2);
    }
    if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
        return matchCore(str+1,pattern+1);
    return false;
}

bool Solution::isNumeric(char* string){
	/*
	int status;
	int cflags =REG_EXTENDED;
	char* pattern = "^[\\+-]?[0-9]*(\\.[0-9]*)?([eE][\\+-]?[0-9]+)?$";//����������ʽ
	regmatch_t pmatch[1];
	regex_t reg;//��ű�����������ʽ
	regcomp(&reg,pattern,cflags);
	status = regexec(&reg,string,1,pmatch,0);//ƥ��������ʽ
	if(status==REG_NOMATCH) 
		return false;
	regfree(&reg);//�ͷ�������ʽ
	*/
	return true;
}


map<char,int> mapdata;
vector<char> vecstream;
//Insert one char from stringstream
void Solution::insert(char ch)
{
	vecstream.push_back(ch);
	mapdata[ch]++;
}
//return the first appearence once char in current stringstream
char Solution::firstAppearingOnce()
{
	vector<char>::iterator it;
	for(it=vecstream.begin();it!=vecstream.end();it++){
		if(mapdata[*it]==1)
			return *it;
	}
	return '#';
}

ListNode* entryNodeOfLoop(ListNode* pHead){
	if(!pHead)
		return NULL;
	ListNode *pCurr=pHead;
	set<ListNode *> nodeSet;
	while(pCurr!=NULL){
		//���Ľ�β��
		if(nodeSet.find(pCurr)!=nodeSet.end()){
			return pCurr;
		}
		nodeSet.insert(pCurr);
		pCurr=pCurr->next;
	}
	 return pCurr;
}

ListNode* deleteDuplication(ListNode* pHead){
	if(!pHead)
		return NULL;
	ListNode *pNewHead=new ListNode(0);//����һ���µ�ͷ����������ͷ���ǰ��
	pNewHead->next=pHead;
	ListNode *pPre=pNewHead,*pCurr=pHead;

	while(pCurr!=NULL){
		//�������������ϵ�ֵ��ͬ�Ľ��
		if((pCurr->next!=NULL)&&(pCurr->val==pCurr->next->val)){
			ListNode *pTemp=pCurr;//�ݴ浱ǰ���
			int tempVal=pCurr->val;
			//Ѱ�Һ��滹��ûֵ��ȵĽ��
			while((pCurr!=NULL)&&(pCurr->val==tempVal)){
				pTemp=pCurr;
				pCurr=pCurr->next;
				delete pTemp;
			}
			pPre->next=pCurr;
		}else{//��ֵ��ͬ�Ľ��
			pPre=pPre->next;
			pCurr=pCurr->next;
		}
	}
	ListNode *pNode= pNewHead->next;
	delete pNewHead;
	return pNode;
}

TreeLinkNode* Solution::getNext(TreeLinkNode* pNode){
	if(pNode==NULL)
		return NULL;
	if(pNode->right!=NULL){//��ǰ������������ ��������һ��������������������㣨��������£�
		pNode=pNode->right;
		while(pNode->left!=NULL){
			pNode=pNode->left;
		}
		return pNode;
	}
	while(pNode->next!=NULL){//���������������ĸ��ڵ�ʱ  pNode->next==NULL
		TreeLinkNode* pRoot=pNode->next;
		if(pRoot->left==pNode){//û�����������ҵ�һ����ǰ�ڵ��Ǹ��ڵ����ӵĽڵ�
			return pRoot;
		}
		pNode=pNode->next;
	}
	return NULL;//�˵��˸��ڵ���û�ҵ����򷵻�null
}

bool Solution::isSymmetrical(TreeNode* pRoot){
	return isSymmetrical(pRoot,pRoot);
}

bool Solution::isSymmetrical(TreeNode* pRoot1,TreeNode* pRoot2){
	if(pRoot1==NULL&&pRoot2==NULL)
		return true;
	if(pRoot1==NULL||&pRoot2==NULL)
		return false;
	if(pRoot1->val!=pRoot2->val)
		return false;
	return isSymmetrical(pRoot1->left,pRoot2->right)&&isSymmetrical(pRoot1->right,pRoot2->left);
}

vector<vector<int> > Solution::printBitree(TreeNode* pRoot){
	vector<vector<int> >  res;
	if(!pRoot)
		return res;
	stack<TreeNode *>s1,s2;
	vector<int> temp;
	s1.push(pRoot);
	while(true){
		while(!s1.empty()){
			TreeNode *ptr=s1.top();
			s1.pop();
			if(!ptr) continue;
			s2.push(ptr->left);
			s2.push(ptr->right);
			temp.push_back(ptr->val);
		}
		if(temp.empty()){
			break;
		}
		res.push_back(temp);
		temp.clear();
		while(!s2.empty()){
			TreeNode *ptr=s2.top();
			s2.pop();
			if(!ptr) continue;
			s1.push(ptr->right);
			s1.push(ptr->left);
			temp.push_back(ptr->val);
		}
		if(temp.empty()){
			break;
		}
		res.push_back(temp);
		temp.clear();
	}
	return res;
}

vector<vector<int> > Solution::printBitreeUpDown(TreeNode* pRoot){
	vector<vector<int >> res;
	if(!pRoot)
		return res;
	queue<TreeNode *> q;
	q.push(pRoot);
	while(!q.empty()){
		int start=0,end=q.size();
		vector<int> vec;
		while(start++<end){
			TreeNode *ptr=q.front();
			q.pop();
			vec.push_back(ptr->val);
			if(ptr->left)
				q.push(ptr->left);
			if(ptr->right)
				q.push(ptr->right);
		}
		res.push_back(vec);
	}
	return res;
}


char* Solution::serializeBitree(TreeNode *root){
	
	if(!root)
		return (char *)'#';
	string val=to_string((long long)root->val);
	val.push_back(' ');
	char *left=serializeBitree(root->left);
	char *right=serializeBitree(root->right);
	char *res=new char(strlen(left)+strlen(right)+val.size());
	strcpy(res,val.c_str());
	strcat(res,left);
	strcat(res,right);
	return res;
	
}

TreeNode* Solution::deserializeBitree(char *str){
	if(*str=='#'){
		str++;
		return NULL;
	}
	int val=0;
	while(*str!=' '){
		val=val*10+(*(str++)-'0');//�ַ���-->��������
	}
	str++;

	TreeNode * root=new TreeNode(val);
	root->left=deserializeBitree(str);
	root->right=deserializeBitree(str);
	return root;
}

TreeNode* Solution::kthNode(TreeNode* pRoot, int k){
	if(!pRoot||k<=0)
		return NULL;
	stack<TreeNode *> nodeStack;
	TreeNode *p=pRoot;
	while(!nodeStack.empty()||p){
		if(p){
			nodeStack.push(p);
			p=p->left;
		}else{
			p=nodeStack.top();
			nodeStack.pop();
			if(k--==0)
				return p;
			p=p->right;
		}	
	}
	return NULL;
}

void Solution::insertNum(int num)
{

}

double Solution::getMedianNum()
{ 
	return 0.0;
}

vector<int> Solution::maxInWindows(const vector<int>& num, unsigned int size){
	vector<int> maxVec;
	deque<int> q;
	if(num.size()<=0||size<=0||size>num.size())
		return maxVec;
	/**����1����������*/
	/*
	for (auto left = num.begin(), right = left + size;true; ++left, ++right)
	{
		auto help = max_element(left, right);
		maxVec.push_back(*help);
		if (right == num.end()) {
			break;
		}
	}
	return maxVec;
	*/

	/**����2��˫�����*/
	for (int i=0; i!=num.size(); ++i) {
		while (!q.empty()&&num[q.back()]<=num[i])
			q.pop_back();
		if (!q.empty()&&i-q.front()>=size)
			q.pop_front();
		q.push_back(i);
		if (i+1>=size)
			maxVec.push_back(num[q.front()]);
	}
	return maxVec;

}


bool Solution::DFS(char* matrix, int rows, int cols,int i,int j, char* str){
	if(!str||!(*str))// �����ͷ��˵����ƥ��ɹ�
		return true;
	int index=i*cols+j;
	bool res=false;
	// �жϵ�ǰλ���Ƿ�Ӧ�ü���
	if((i>=0)&&(i<rows)&&(j>=0)&&(j<cols)&&(matrix[index]==*str)){
		matrix[index]='\0';
		res=DFS(matrix,rows,cols,i-1,j,str+1)
			||DFS(matrix,rows,cols,i+1,j,str+1)
			||DFS(matrix,rows,cols,i,j-1,str+1)
			||DFS(matrix,rows,cols,i,j+1,str+1);
		matrix[index]=*str;	
	}
	return res;
}

bool Solution::hasPath(char* matrix, int rows, int cols, char* str){
	for(int i=0;i<rows;i++)
		for(int j=0;j<cols;j++){
			if(DFS(matrix,rows,cols,i,j,str))
				return true;
		}
	return false;
}


 int Solution::movingCount(int threshold, int rows, int cols){
	vector<vector<int> >flag(rows,vector<int>(cols,0));
	return movingHelper(threshold,rows,cols,0,0,flag);
 }

 int Solution::getSum(int number){
	 int sum=0;
	 while(number>0){
		 sum+=number%10;
		 number/=10;
	 }
	 return sum;
 }

 int Solution::movingHelper(int threshold,int rows,int cols,int i,int j,vector<vector<int> > &flag){
	 if(i>=0&&i<rows&&j>=0&&j<cols&&(getSum(i)+getSum(j)<=threshold)&&flag[i][j]==0){
		flag[i][j]=1;
		return movingHelper(threshold,rows,cols,i-1,j,flag)
			+movingHelper(threshold,rows,cols,i+1,j,flag)
			+movingHelper(threshold,rows,cols,i,j-1,flag)
			+movingHelper(threshold,rows,cols,i,j+1,flag)
			+1;
	 }
	 return 0;
 }
