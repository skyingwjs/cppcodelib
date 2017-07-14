#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "singlelinklist.h"


//1.初始化单链表 即置单链表的表头指针为Null

void initList(Node *pNode){
	pNode=NULL;
	printf("initList函数执行，链表初始化成功\n");
}

//2.创建链表 当输入负数时表示结束创建
Node *createList(Node * pNode){	
	Node *p1,*p2;
	p1=p2=(Node *)malloc(sizeof(Node));
	memset(p1,0,sizeof(Node));
	scanf("%d",&p1->element);
	p1->next=NULL;
	while(p1->element>0){
		if(NULL==pNode){
			pNode=p1;
		}
		else{
			p2->next=p1;
			p2=p1;
		}
		p1=(Node*)malloc(sizeof(Node));
		memset(p1,0,sizeof(Node));
		scanf("%d",&p1->element);
		p1->next=NULL;
	}
	p2->next=NULL;
	return pNode;
}

//3.打印链表，链表的遍历
void printList(Node * pNode){
	if(NULL==pNode){
		printf("printList函数执行，链表为空！\n")	;
		return ;
	}
	else{
		while(pNode){
			printf("%d\t",pNode->element);
			pNode=pNode->next;	
		}		
	}
	printf("\n");
}

//4.清除链表中所有元素，即释放链表中所有节点，使其成为一个空表,并使得头指针值为NULL
int clearList(Node **pNode){
	Node *pNext,*pTemp;
	pTemp=*pNode;
	while(pTemp){
		pNext=pTemp->next;
		free(pTemp);
		pTemp=pNext;
	}
	*pNode=NULL;
	return 1;
}

//5.返回单链表的长度
int sizeList(Node* pNode){
	int i=0;
	while(pNode){
		i++;
		pNode=pNode->next;
	}
	return i;
}

//6.检查链表是否为空，若空则返回1  非空则返回0
int isEmptyList(Node *pNode){
	if(!pNode){
		printf("isEmptyList函数执行，链表为空\n");
		return 1;
	}
	else{
		printf("isEmptyList函数执行，链表非空\n");
		return 0;
	}

}

//7.返回链表中的第pos个节点的元素
elemType getElement(Node *pNode,int pos){
	int i=0;
	if(pos<1){
		printf("getElement函数执行，pos值非法\n");
		return 0;
	}
	if(NULL==pNode){
		printf("getElement函数执行，链表尾空\n");
		return 0;
	}
	while(pNode){
		i++;
		if(i==pos)
			return pNode->element;
		pNode=pNode->next;
	}
	if(i<pos)
		printf("getElement函数执行，pos值超出链表长度\n");
		return 0;
}

//8.从单链表中查找与给定值x相等的第一个元素，若查找成功则返回该节点的data域的存储地址，否则返回NULL
elemType *getElemAddr(Node *pNode,elemType elemValue){
	if(elemValue<=0){
		printf("getElementAddr函数执行，给定值不合法\n");
		return NULL;
	}
	if(NULL==pNode){
		printf("getElementAddr函数执行，链表为空。\n");
		return NULL;
	}
	while(pNode){
		if(pNode->element==elemValue){
			printf("getElementAddr函数执行，元素%d的地址为%d\n",elemValue,&(pNode->element));
			return &(pNode->element);
		}
		pNode=pNode->next;
			
	}
	printf("getElementAddr函数执行，在链表中为找到%d值\n",elemValue);
	return NULL;
}

//9.把单链表中第pos个节点的值改为elemValue的值，若修改成功则返回1，否则返回0
int modifyElem(Node *pNode,int pos,elemType elemValue){
	int i=0;
	printf("modifyElem函数执行，即将把链表中的第%d个元素的值修改为%d\n",pos,elemValue);

	if(pNode==NULL){
		printf("modifyElem函数执行，链表为空");
	}
	if(pos<1){
		printf("modifyElem函数执行，pos值非法");
		return 0;
	}
	if(elemValue<1){
		printf("modifyElem函数执行，elemValue值非法");
		return 0;
	}
	while(pNode){
		i++;
		if(i==pos){
			pNode->element=elemValue;
			return 1;
		}
		pNode=pNode->next;
	
	}
	if(i<pos){
		printf("modifyElem函数执行，pos值超出链表长度");
	}
	return 0;
}

//10.向单链表的表头插入一个元素
int insertHeadList(Node **pNode,elemType elemInserted){
	Node *pHead,*pLast;
	if(NULL==*pNode){
		printf("insertHeadList函数执行，链表为空");
		return 0;
	}
	if(elemInserted<1){
		printf("insertHeadList函数执行，插入值不合法");
		return 0;
	}
	//pNode为传入的参数  pNode是一个指向数据类型为Node *的指针（Node *本身也是指针类型，这种指针类型是指向Node类型的指针）
	//所以*pNode就是Node*型指针变量 其值就是Node类型变量的地址  
	pLast=*pNode;

	pHead=(Node*)malloc(sizeof(Node));
	memset(pHead,0,sizeof(Node));
	pHead->element=elemInserted;
	pHead->next=pLast;

	*pNode=pHead;
	return 1;
}

//11.向单链表的末尾添加一个元素

int insertLastList(Node **pNode,elemType elemInserted){
	Node *pLast,*pTemp;
	if(NULL==*pNode){
		printf("insertHeadList函数执行，链表为空");
		return 0;
	}
	if(elemInserted<1){
		printf("insertHeadList函数执行，插入值不合法");
		return 0;
	}
	//把*pNode先赋值给pTemp，后面的操作（例如循环链表到最后一个节点）主要是对pTemp进行操作，
	//否则返回*pNode的时候，将返回链表*pNode在当前指针后面的部分，而不是整个链表。			
	pTemp=*pNode;

	//因为pTemp与*pNode指向同一个链表，所以对pTemp进行节点改动即是对*pNode作改动
	pLast=(Node*)malloc(sizeof(Node));
	memset(pLast,0,sizeof(Node));
	pLast->element=elemInserted;
	pLast->next=NULL;

    //循环链表至最后一个节点
	while(pTemp->next){
		pTemp=pTemp->next;
	}
    //把新增节点加入到链表中
	pTemp->next=pLast;

	return 1;
}

//12.向单链表中第pos个结点位置插入元素为x的结点，若插入成功返回１，否则返回０
int insertList(Node **pNode,int pos,elemType elemInserted){
	Node *pLast,*pInserted,*pTemp;
	int i=0;
    if(NULL == *pNode)
    {
        printf("insertList函数执行，链表为空\n");
        return 0;
    }
    if(elemInserted < 1)
    {
        printf("insertList函数执行，elemInserted值非法\n");
        return 0;
    }
    if(pos < 1)
    {
        printf("insertList函数执行，pos值非法\n");
        return 0;
    }
	//把*pNode先赋值给pTemp，后面的操作（例如循环链表到最后一个节点）主要是对pTemp进行操作，
	//否则返回*pNode的时候，将返回链表*pNode在当前指针后面的部分，而不是整个链表。
    pTemp=*pNode;
	//因为pTemp与*pNode指向同一个链表，所以对pTemp进行节点改动即是对*pNode作改动
	pInserted=(Node*)malloc(sizeof(Node));
	memset(pInserted,0,sizeof(Node));
	pInserted->element=elemInserted;
	pInserted->next=NULL;

	//循环链表至pos节点
	while(pTemp->next!=NULL){
		i++;
		if(i==pos){
			pLast->next=pInserted;	//让上一个节点的next指向插入节点
			pInserted->next=pTemp;	//让插入节点的next指向下一节点
			break;
		}
		pLast=pTemp;  //记住上一个节点的位置
		pTemp=pTemp->next;
	}

	return 1;

}


//13.从单链表中删除表头结点，并把该结点的值返回，若删除失败则停止程序运行
elemType deleteHeadList(Node **pNode){
	elemType currVal;
	Node *pTemp;

	if(NULL==*pNode){
		printf("DeleteHeadList函数执行，链表为空\n");
		return 0;
	}

	pTemp=*pNode;
	currVal=(*pNode)->element;
	*pNode=(*pNode)->next;

	pTemp->next=NULL;
	free(pTemp);

	return currVal;
}


//14.从单链表中删除表尾结点并返回它的值，若删除失败则停止程序运行
elemType deleteLastList(Node **pNode){
	elemType currVal;
	Node *pTemp,*pLast;

	if(NULL==*pNode){
		printf("DeleteLastList函数执行，链表为空\n");
		return 0;
	}

	pTemp=*pNode;
	while(pTemp->next!=NULL){
		pLast=pTemp;
		pTemp=pTemp->next;
	}

	pLast->next=NULL;
	currVal=pTemp->element;

	free(pTemp);

	return currVal;
}


//15.从单链表中删除第pos个结点并返回它的值，若删除失败则停止程序运行

elemType deleteList(Node **pNode,int pos){
	elemType currVal;
	int i=0;

	Node *pTemp,*pLast,*pNext;
    if(NULL == *pNode)
    {
        printf("DeleteLastList函数执行，链表为空\n");
        return 0;
    }
    if(pos < 1)
    {
        printf("DeleteList函数执行，pos值非法\n");
        return 0;
    }
	pTemp=*pNode;
	while(pTemp!=NULL){
		i++;
		if(i==pos){
			break;
		}
		pLast=pTemp;
		pTemp=pTemp->next;
	}
	pNext=pTemp;
	pNext=pNext->next;
	pLast->next=pNext;
	currVal=pTemp->element;
	free(pTemp);

	return currVal;
}

//16.从单链表中删除值为x的第一个结点，若删除成功则返回1,否则返回0
int deleteXList(Node **pNode,elemType elemVal){
	Node *pTemp,*pLast,*pNext;
	int i=0;
	if(NULL==*pNode){
		printf("DeleteXList函数执行，链表为空\n");
		return 0;
	}
	if(elemVal<1){
		printf("DeleteXList函数执行，elemVal函数非法\n");
		return 0;
	}

	pTemp=*pNode;

	while(pTemp!=NULL){
		if(pTemp->element==elemVal){
			i=1;
			break;
		}
		pLast=pTemp;
		pTemp=pTemp->next;
	}
	if(i==0){
		printf("DeleteXList函数执行，链表中没有值为%d的结点\n",elemVal);
		return 0;
	}

	pNext=pTemp;
	pNext=pNext->next;
	pLast->next=pNext;

	free(pTemp);
	return 1;
}


//17.交换2个元素的位置   交换成功返回1  否则返回0
int exchangeList(Node **pNode,int pos1,int pos2){
	Node *pTemp,*pFirst,*pSecond;
	int p;
	int i=0;
	if(NULL==*pNode){
		printf("exchangeList函数执行，链表为空\n");
		return 0;
	}
	if(pos1<1||pos2<1){
		printf("exchangeList函数执行，pos值不合法\n");
		return 0;
    }

	pTemp=*pNode;

	while(pTemp!=NULL){
		i++;
		if(i==pos1){
			pFirst=pTemp;
		}
		else if(i==pos2){
			pSecond=pTemp;
		}
		pTemp=pTemp->next;
	}

	p=pFirst->element;
	pFirst->element=pSecond->element;
	pSecond->element=p;
}


//18.将单链表进行排序   将序排序（选择排序）
int sortList(Node **pNode)
{
	Node *pTemp;
	int Listsize = sizeList(*pNode);
	int i;
    if(NULL == *pNode)
    {
        printf("sortList函数执行，链表为空\n");
        return 0;
    }
    pTemp = *pNode;
    //循环: 用for循环来取代指针循环，因为指针循环一次后，下次起始的指针将自动转到下一节点，而我们还想从第一个元素开始
    for(i=0; i < Listsize; i++)
    {
        Node *pCurr, *pLast;
		int k;
        pCurr = pLast = pTemp;
		
        for(k=0; k < Listsize-i; k++)//每次循环最小值都移到最后

        {
            int p = 0;
           
            if(pLast->element < pCurr->element)
            {
				//交换两个节点元素
                p = pLast->element;
                pLast->element = pCurr->element;
                pCurr->element = p;
            }
            pLast = pCurr;
            pCurr = pCurr->next;
        }
    }
}


//19.向有序单链表中插入元素x结点，使得插入后仍然有序,正确插入返回1 否则返回0 ,假设现在已知一个降序的单链表
int insertXList(Node **pNode,elemType elemInserted){
	Node *pInserted,*pTemp,*pLast;
	if(NULL==*pNode){
		printf("insertXList函数执行，链表为空\n");
		return 0;
	}
	if(elemInserted<1){
		printf("insertXList函数执行，插入元素不合法\n");
		return 0;
	}

	pLast=pTemp=*pNode;//把*pNode先赋值给pTemp，后面的操作（例如循环链表到最后一个节点）主要是对pTemp进行操作，否则返回*pNode的时候，将返回链表*pNode在当前指针后面的部分，而不是整个链表。
    //因为pTemp与*pNode指向同一个链表，所以对pTemp进行节点改动即是对*pNode作改动

	pInserted=(Node *)malloc(sizeof(Node));
	memset(pInserted,0,sizeof(Node));
	pInserted->element=elemInserted;
	pInserted->next=NULL;
	

	//寻找该插入的节点
	while(pTemp!=NULL){
		
		if(pTemp->element<elemInserted){
			pLast->next=pInserted;
			pInserted->next=pTemp;
			break;
		}
		pLast=pTemp;
		pTemp=pTemp->next;
	}

	return 1;

}

