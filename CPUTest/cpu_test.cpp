#include <stdio.h>  
#include "cpu.h"

int main(){
	if(checkCPU())
		cout<<"Big Endian"<<endl;
	else
		cout<<"Little Endian"<<endl;

	getDataTypeByteNum();

	system("pause");
	return 0;
}