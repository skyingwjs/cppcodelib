#include <stdio.h>  
#include <string.h>
#include <stdlib.h>
#include "sort.h"
int data[]={3,1,4,2,5,7,6};
void resetInputData(int data[],int n){
	if(n=7){
		data[0]=3;
		data[1]=1;
		data[2]=4;
		data[3]=2;
		data[4]=5;
		data[5]=7;
		data[6]=6;
	}
}

int main(int argc,char **argv){

	int *pData=data;
	int n=sizeof(data)/4;
	int i;
	
	printf("*******冒泡排序测试**************");
	
	printf("\n\n");
	printf("*******冒泡排序方法1：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	bubblesort1(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******冒泡排序方法2：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	bubblesort2(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******冒泡排序方法3：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	bubblesort3(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******冒泡排序方法4：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	pData=bubblesort4(pData,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n\n\n");
	resetInputData(data,n);
	
	printf("*******直接插入排序测试**********");
	printf("\n\n");
	printf("*******插入排序方法1：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	insertsort1(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******插入排序方法2：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	insertsort2(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******插入排序方法3：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	insertsort3(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******插入排序方法4：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	insertsort4(pData,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*********希尔排序测试************");
	printf("\n\n");
	printf("*******希尔排序方法1：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	shellsort1(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******希尔排序方法2：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	shellsort2(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******希尔排序方法3：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	shellsort3(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*********选择排序测试************");
	printf("\n\n");
	printf("*******选择排序方法1：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	selectsort1(data,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	printf("\n\n");
	resetInputData(data,n);
	printf("*******选择排序方法2：**********\n");
	printf("原始数组:  ");
	print(pData,n);
	pData=selectsort2(pData,n);
	printf("\n排序后数组：");
	print(pData,n);
	
	//printf("\n\n");
	//printf("*******选择排序测试**********\n");
	//resetInputData(data,n);
	//printf("原始数组:  ");
	//print(pData,n);
	//pData=choicesort(data,n);
	//printf("\n排序后数组：");
	//print(pData,n);
	
	resetInputData(data,n);
	   printf("\n\n*******4.快速排序测试1**********\n");
	pData=quicksort(data,0,n-1);
	printf("\n排序后数组：");
	for(i=0;i<n;i++){
		printf("%d  ",pData[i]);	
	}
	
	
	   resetInputData(data,n);
	   printf("\n\n*******4.快速排序测试2**********\n");
	pData=quick_sort(data,0,n-1);
	printf("\n排序后数组：");
	for(i=0;i<n;i++){
		printf("%d  ",pData[i]);	
	}
	
	resetInputData(data,n);
	   printf("\n\n*******5.归并排序测试**********\n");
	if(pData=mergeSort(data,n)){
	printf("\n排序后数组：");
	for(i=0;i<n;i++){
		 printf("%d  ",pData[i]);	
	 }	
	}
	
	
	printf("\n\n*******6.堆排序测试**********\n");
	MakeMinHeap(data,n);//堆有序化  建立堆
	MinheapsortTodescendarray(data,n);
	printf("\n排序后数组：");
	for(i=0;i<n;i++){
		printf("%d  ",data[i]);	
	}	
	

	return 0;

}