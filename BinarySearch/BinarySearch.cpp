#include "BinarySearch.h"

int BinarySearch::binarySearch(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key==a[mid]){
			return mid;
		}else if(key<a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return -1;
}

int BinarySearch::firstGreatOrEqual(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<=a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return start<=n-1?start:-1;
}

int BinarySearch::firstGreat(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return start<=n-1?start:-1;
}

int BinarySearch::firstIndex(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<=a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return (start<=n-1)&&(a[start]==key)?start:-1;
}

int BinarySearch::lastIndex(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return (start-1>=0)&&(a[start-1]==key) ? start-1:-1;

}
int BinarySearch::firstLess(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<=a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return (start-1>=0)?start-1:-1;
}

int BinarySearch::getCount(int* a,int n,int key){
	
	int first = firstGreatOrEqual2(a, n, key);  
	int last = firstGreat2(a, n, key);  
	return last - first; 
}

int BinarySearch::firstGreatOrEqual2(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<=a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return start;
}

int BinarySearch::firstGreat2(int* a,int n,int key){
	int start=0,end=n-1,mid=0;

	while(start<=end){
		mid=start+((end-start)>>1);
		if(key<a[mid]){
			end=mid-1;
		}else{
			start=mid+1;
		}
	}

	return start;
}