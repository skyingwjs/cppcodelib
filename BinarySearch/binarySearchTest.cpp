#include "BinarySearch.h"

int main(){
	int a[]={1,1,1,2,4,8,10};
	int res=-1;
	BinarySearch bs;
	res=bs.binarySearch(a,7,2);
	cout<<"binarySearch(a,7,2): "<<res<<endl;

	res=bs.firstGreatOrEqual(a,7,2);
	cout<<"firstGreatOrEqual(a,7,2): "<<res<<endl;

	system("pause");
	return 0;
}
