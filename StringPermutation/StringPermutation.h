#ifndef __STRING_PERMUTATION_H__
#define __STRING_PERMUTATION_H__

#include<iostream>  
#include<assert.h>  
using namespace std;

void permutation(char *pStr,char*pBegin);
void permutation2(char *pStr,int k,int m);
bool isSwap(char *pBegin,char *pEnd);
void permutation3(char *pStr,char*pBegin);

void reverse(char *pBegin,char*pEnd);
bool nextPermutation(char a[]);
int cmp(const void* a,const void *b);
#endif