#ifndef __SINGLELINLIST_H__
#define __SINGLELINLIST_H__

typedef int elemType;
typedef struct Node{
	elemType element;
	struct Node *next;
}Node;

void initList(Node *pNode);
Node *createList(Node *pNode);
void printList(Node *pNode);
int clearList(Node **pNode);
int sizeList(Node *pNode);
int isEmptyList(Node *pNode);
elemType getElement(Node *pNode,int pos);
elemType *getElemAddr(Node *pNode,elemType elemValue);
int modifyElem(Node *pNode,int pos,elemType elemValue);
int insertHeadList(Node **pNode,elemType elemInserted);
int insertLastList(Node **pNode,elemType elemInserted);
int insertList(Node **pNode,int pos,elemType elemInserted);
elemType deleteHeadList(Node **pNode);
elemType deleteLastList(Node **pNode);
elemType deleteList(Node **pNode,int pos);
int deleteXList(Node **pNode, elemType elemVal);
int exchangeList(Node **pNode,int pos1,int pos2);
int sortList(Node **pNode);
int insertXList(Node **pNode,elemType elemInserted);

#endif


