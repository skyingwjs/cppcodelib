#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "singlelinklist.h"


//1.��ʼ�������� ���õ�����ı�ͷָ��ΪNull

void initList(Node *pNode){
	pNode=NULL;
	printf("initList����ִ�У������ʼ���ɹ�\n");
}

//2.�������� �����븺��ʱ��ʾ��������
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

//3.��ӡ��������ı���
void printList(Node * pNode){
	if(NULL==pNode){
		printf("printList����ִ�У�����Ϊ�գ�\n")	;
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

//4.�������������Ԫ�أ����ͷ����������нڵ㣬ʹ���Ϊһ���ձ�,��ʹ��ͷָ��ֵΪNULL
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

//5.���ص�����ĳ���
int sizeList(Node* pNode){
	int i=0;
	while(pNode){
		i++;
		pNode=pNode->next;
	}
	return i;
}

//6.��������Ƿ�Ϊ�գ������򷵻�1  �ǿ��򷵻�0
int isEmptyList(Node *pNode){
	if(!pNode){
		printf("isEmptyList����ִ�У�����Ϊ��\n");
		return 1;
	}
	else{
		printf("isEmptyList����ִ�У�����ǿ�\n");
		return 0;
	}

}

//7.���������еĵ�pos���ڵ��Ԫ��
elemType getElement(Node *pNode,int pos){
	int i=0;
	if(pos<1){
		printf("getElement����ִ�У�posֵ�Ƿ�\n");
		return 0;
	}
	if(NULL==pNode){
		printf("getElement����ִ�У�����β��\n");
		return 0;
	}
	while(pNode){
		i++;
		if(i==pos)
			return pNode->element;
		pNode=pNode->next;
	}
	if(i<pos)
		printf("getElement����ִ�У�posֵ����������\n");
		return 0;
}

//8.�ӵ������в��������ֵx��ȵĵ�һ��Ԫ�أ������ҳɹ��򷵻ظýڵ��data��Ĵ洢��ַ�����򷵻�NULL
elemType *getElemAddr(Node *pNode,elemType elemValue){
	if(elemValue<=0){
		printf("getElementAddr����ִ�У�����ֵ���Ϸ�\n");
		return NULL;
	}
	if(NULL==pNode){
		printf("getElementAddr����ִ�У�����Ϊ�ա�\n");
		return NULL;
	}
	while(pNode){
		if(pNode->element==elemValue){
			printf("getElementAddr����ִ�У�Ԫ��%d�ĵ�ַΪ%d\n",elemValue,&(pNode->element));
			return &(pNode->element);
		}
		pNode=pNode->next;
			
	}
	printf("getElementAddr����ִ�У���������Ϊ�ҵ�%dֵ\n",elemValue);
	return NULL;
}

//9.�ѵ������е�pos���ڵ��ֵ��ΪelemValue��ֵ�����޸ĳɹ��򷵻�1�����򷵻�0
int modifyElem(Node *pNode,int pos,elemType elemValue){
	int i=0;
	printf("modifyElem����ִ�У������������еĵ�%d��Ԫ�ص�ֵ�޸�Ϊ%d\n",pos,elemValue);

	if(pNode==NULL){
		printf("modifyElem����ִ�У�����Ϊ��");
	}
	if(pos<1){
		printf("modifyElem����ִ�У�posֵ�Ƿ�");
		return 0;
	}
	if(elemValue<1){
		printf("modifyElem����ִ�У�elemValueֵ�Ƿ�");
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
		printf("modifyElem����ִ�У�posֵ����������");
	}
	return 0;
}

//10.������ı�ͷ����һ��Ԫ��
int insertHeadList(Node **pNode,elemType elemInserted){
	Node *pHead,*pLast;
	if(NULL==*pNode){
		printf("insertHeadList����ִ�У�����Ϊ��");
		return 0;
	}
	if(elemInserted<1){
		printf("insertHeadList����ִ�У�����ֵ���Ϸ�");
		return 0;
	}
	//pNodeΪ����Ĳ���  pNode��һ��ָ����������ΪNode *��ָ�루Node *����Ҳ��ָ�����ͣ�����ָ��������ָ��Node���͵�ָ�룩
	//����*pNode����Node*��ָ����� ��ֵ����Node���ͱ����ĵ�ַ  
	pLast=*pNode;

	pHead=(Node*)malloc(sizeof(Node));
	memset(pHead,0,sizeof(Node));
	pHead->element=elemInserted;
	pHead->next=pLast;

	*pNode=pHead;
	return 1;
}

//11.�������ĩβ���һ��Ԫ��

int insertLastList(Node **pNode,elemType elemInserted){
	Node *pLast,*pTemp;
	if(NULL==*pNode){
		printf("insertHeadList����ִ�У�����Ϊ��");
		return 0;
	}
	if(elemInserted<1){
		printf("insertHeadList����ִ�У�����ֵ���Ϸ�");
		return 0;
	}
	//��*pNode�ȸ�ֵ��pTemp������Ĳ���������ѭ���������һ���ڵ㣩��Ҫ�Ƕ�pTemp���в�����
	//���򷵻�*pNode��ʱ�򣬽���������*pNode�ڵ�ǰָ�����Ĳ��֣���������������			
	pTemp=*pNode;

	//��ΪpTemp��*pNodeָ��ͬһ���������Զ�pTemp���нڵ�Ķ����Ƕ�*pNode���Ķ�
	pLast=(Node*)malloc(sizeof(Node));
	memset(pLast,0,sizeof(Node));
	pLast->element=elemInserted;
	pLast->next=NULL;

    //ѭ�����������һ���ڵ�
	while(pTemp->next){
		pTemp=pTemp->next;
	}
    //�������ڵ���뵽������
	pTemp->next=pLast;

	return 1;
}

//12.�������е�pos�����λ�ò���Ԫ��Ϊx�Ľ�㣬������ɹ����أ������򷵻أ�
int insertList(Node **pNode,int pos,elemType elemInserted){
	Node *pLast,*pInserted,*pTemp;
	int i=0;
    if(NULL == *pNode)
    {
        printf("insertList����ִ�У�����Ϊ��\n");
        return 0;
    }
    if(elemInserted < 1)
    {
        printf("insertList����ִ�У�elemInsertedֵ�Ƿ�\n");
        return 0;
    }
    if(pos < 1)
    {
        printf("insertList����ִ�У�posֵ�Ƿ�\n");
        return 0;
    }
	//��*pNode�ȸ�ֵ��pTemp������Ĳ���������ѭ���������һ���ڵ㣩��Ҫ�Ƕ�pTemp���в�����
	//���򷵻�*pNode��ʱ�򣬽���������*pNode�ڵ�ǰָ�����Ĳ��֣���������������
    pTemp=*pNode;
	//��ΪpTemp��*pNodeָ��ͬһ���������Զ�pTemp���нڵ�Ķ����Ƕ�*pNode���Ķ�
	pInserted=(Node*)malloc(sizeof(Node));
	memset(pInserted,0,sizeof(Node));
	pInserted->element=elemInserted;
	pInserted->next=NULL;

	//ѭ��������pos�ڵ�
	while(pTemp->next!=NULL){
		i++;
		if(i==pos){
			pLast->next=pInserted;	//����һ���ڵ��nextָ�����ڵ�
			pInserted->next=pTemp;	//�ò���ڵ��nextָ����һ�ڵ�
			break;
		}
		pLast=pTemp;  //��ס��һ���ڵ��λ��
		pTemp=pTemp->next;
	}

	return 1;

}


//13.�ӵ�������ɾ����ͷ��㣬���Ѹý���ֵ���أ���ɾ��ʧ����ֹͣ��������
elemType deleteHeadList(Node **pNode){
	elemType currVal;
	Node *pTemp;

	if(NULL==*pNode){
		printf("DeleteHeadList����ִ�У�����Ϊ��\n");
		return 0;
	}

	pTemp=*pNode;
	currVal=(*pNode)->element;
	*pNode=(*pNode)->next;

	pTemp->next=NULL;
	free(pTemp);

	return currVal;
}


//14.�ӵ�������ɾ����β��㲢��������ֵ����ɾ��ʧ����ֹͣ��������
elemType deleteLastList(Node **pNode){
	elemType currVal;
	Node *pTemp,*pLast;

	if(NULL==*pNode){
		printf("DeleteLastList����ִ�У�����Ϊ��\n");
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


//15.�ӵ�������ɾ����pos����㲢��������ֵ����ɾ��ʧ����ֹͣ��������

elemType deleteList(Node **pNode,int pos){
	elemType currVal;
	int i=0;

	Node *pTemp,*pLast,*pNext;
    if(NULL == *pNode)
    {
        printf("DeleteLastList����ִ�У�����Ϊ��\n");
        return 0;
    }
    if(pos < 1)
    {
        printf("DeleteList����ִ�У�posֵ�Ƿ�\n");
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

//16.�ӵ�������ɾ��ֵΪx�ĵ�һ����㣬��ɾ���ɹ��򷵻�1,���򷵻�0
int deleteXList(Node **pNode,elemType elemVal){
	Node *pTemp,*pLast,*pNext;
	int i=0;
	if(NULL==*pNode){
		printf("DeleteXList����ִ�У�����Ϊ��\n");
		return 0;
	}
	if(elemVal<1){
		printf("DeleteXList����ִ�У�elemVal�����Ƿ�\n");
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
		printf("DeleteXList����ִ�У�������û��ֵΪ%d�Ľ��\n",elemVal);
		return 0;
	}

	pNext=pTemp;
	pNext=pNext->next;
	pLast->next=pNext;

	free(pTemp);
	return 1;
}


//17.����2��Ԫ�ص�λ��   �����ɹ�����1  ���򷵻�0
int exchangeList(Node **pNode,int pos1,int pos2){
	Node *pTemp,*pFirst,*pSecond;
	int p;
	int i=0;
	if(NULL==*pNode){
		printf("exchangeList����ִ�У�����Ϊ��\n");
		return 0;
	}
	if(pos1<1||pos2<1){
		printf("exchangeList����ִ�У�posֵ���Ϸ�\n");
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


//18.���������������   ��������ѡ������
int sortList(Node **pNode)
{
	Node *pTemp;
	int Listsize = sizeList(*pNode);
	int i;
    if(NULL == *pNode)
    {
        printf("sortList����ִ�У�����Ϊ��\n");
        return 0;
    }
    pTemp = *pNode;
    //ѭ��: ��forѭ����ȡ��ָ��ѭ������Ϊָ��ѭ��һ�κ��´���ʼ��ָ�뽫�Զ�ת����һ�ڵ㣬�����ǻ���ӵ�һ��Ԫ�ؿ�ʼ
    for(i=0; i < Listsize; i++)
    {
        Node *pCurr, *pLast;
		int k;
        pCurr = pLast = pTemp;
		
        for(k=0; k < Listsize-i; k++)//ÿ��ѭ����Сֵ���Ƶ����

        {
            int p = 0;
           
            if(pLast->element < pCurr->element)
            {
				//���������ڵ�Ԫ��
                p = pLast->element;
                pLast->element = pCurr->element;
                pCurr->element = p;
            }
            pLast = pCurr;
            pCurr = pCurr->next;
        }
    }
}


//19.�����������в���Ԫ��x��㣬ʹ�ò������Ȼ����,��ȷ���뷵��1 ���򷵻�0 ,����������֪һ������ĵ�����
int insertXList(Node **pNode,elemType elemInserted){
	Node *pInserted,*pTemp,*pLast;
	if(NULL==*pNode){
		printf("insertXList����ִ�У�����Ϊ��\n");
		return 0;
	}
	if(elemInserted<1){
		printf("insertXList����ִ�У�����Ԫ�ز��Ϸ�\n");
		return 0;
	}

	pLast=pTemp=*pNode;//��*pNode�ȸ�ֵ��pTemp������Ĳ���������ѭ���������һ���ڵ㣩��Ҫ�Ƕ�pTemp���в��������򷵻�*pNode��ʱ�򣬽���������*pNode�ڵ�ǰָ�����Ĳ��֣���������������
    //��ΪpTemp��*pNodeָ��ͬһ���������Զ�pTemp���нڵ�Ķ����Ƕ�*pNode���Ķ�

	pInserted=(Node *)malloc(sizeof(Node));
	memset(pInserted,0,sizeof(Node));
	pInserted->element=elemInserted;
	pInserted->next=NULL;
	

	//Ѱ�Ҹò���Ľڵ�
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

