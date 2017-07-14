#include "StringPermutation.h"
void permutation(char *pStr,char*pBegin){

	assert(pStr && pBegin);
	if(*pBegin=='\0'){
		printf("%s\n",pStr);
	}else{
		for(char *pCh=pBegin;*pCh!='\0';pCh++){
			swap(*pBegin,*pCh);
			permutation(pStr,pBegin+1);
			swap(*pBegin,*pCh);
		}
	}
}

void permutation2(char *pStr,int k,int m){
	assert(pStr);

	if(k==m){
		static int num=1;
		printf("第%d个排列： %s\n",num++,pStr);
	}else{

		for(int i=k;i<=m;i++){
			swap(*(pStr+k),*(pStr+i));
			permutation2(pStr,k+1,m);
			swap(*(pStr+k),*(pStr+i));
		}
	}
}

/*去掉重复的全排列的递归实现*/

//在[nBegin,nEnd)区间中是否有字符与下标为pEnd的字符相等  
bool isSwap(char *pBegin,char *pEnd){
	char *p;
	for(p=pBegin;p<pEnd;p++){
		if(*p==*pEnd)
			return false;
	}
	return true;
}

void permutation3(char *pStr,char *pBegin){

	assert(pStr);
	if(*pBegin=='\0'){
		static int num=1;
		printf("第%d个排列： %s\n",num++,pStr);
	}else{
		for(char *pCh=pBegin;*pCh!='\0';pCh++){
			if(isSwap(pBegin,pCh)){
				swap(*pBegin,*pCh);
				permutation3(pStr,pBegin+1);
				swap(*pBegin,*pCh);
			}
		}
	}
}

/*字符串排列的非递归实现*/

void reverse(char *pBegin,char*pEnd){
	while(pBegin<pEnd){
		swap(*pBegin++,*pEnd--);
	}
}

bool nextPermutation(char a[]){
	assert(a);
	char *p,*q,*pFind;
	char *pEnd=a+strlen(a)-1;

	if(a==pEnd)
		return false;

	p=pEnd;
	while(p!=a){
		q=p;
		p--;

		if(*p<*q){//找降序的相邻2数,前一个数即替换数    
		//从后向前找比替换点大的第一个数  
			pFind=pEnd;
			while(*pFind<*p)
				--pFind;

			swap(*p,*pFind);

			//替换点后的数全部反转
			reverse(q,pEnd);
			return true;
		}
	}

	reverse(a,pEnd);//如果没有下一个排列,全部反转后返回false  
	return false;
}

int cmp(const void* a,const void *b){

	return int(*(char*)a-*(char *)b);
}