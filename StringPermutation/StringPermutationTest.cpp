#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#include <math.h>  
#include "StringPermutation.h"

int main(){

	char str[]="abcd";
	int num=1;
	qsort(str,strlen(str),sizeof(char),cmp);
	do{
		printf("µÚ%d¸öÅÅÁĞ£º %s\n",num++,str);
	}while(nextPermutation(str));
	system("pause");
	return 0;
}