#ifndef __SORT__H__
#define __SORT__H__
#define N 10

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void print(int *pData,int n);
void swap(int *a, int *b);
void swap1(int &a, int &b);
void swap2(int &a, int &b);



void bubblesort1(int a[],int n);
void bubblesort2(int a[],int n);
void bubblesort3(int a[],int n);
int *bubblesort4(int *pData,int count);

void insertsort1(int a[],int n);
void insertsort2(int a[],int n);
void insertsort3(int a[],int n);
int *insertsort4(int *pData,int count);

void shellsort1(int a[], int n);
void shellsort2(int a[], int n);
void shellsort3(int a[], int n);

void selectsort1(int a[],int n);
int *selectsort2(int *pData,int n);

//int *insertsort(int *,int);
int *quicksort(int *,int,int);
int *quick_sort(int *,int,int);
void mergearray(int a[], int first, int mid, int last, int temp[]);
void mergesort(int a[], int first, int last, int temp[]);
int *mergeSort(int*, int);
void MinHeapFixup(int a[], int i);
void MinHeapAddNumber(int a[], int n, int nNum);
void MinHeapFixdown(int a[], int i, int n);

void MinHeapDeleteNumber(int a[], int n);
void MakeMinHeap(int a[], int n);
void MinheapsortTodescendarray(int a[], int n);

#endif