#include <iostream>
#include "cpu.h"
using namespace std;
typedef struct VoidStruct{

}VoidStruct;
bool checkCPU(){
	short test=0x1234;
	if(*((char *)&test)==0x12){//如果是大端模式返回真
		return  true;
	}else{
		return  false;
	}

}

void getDataTypeByteNum(){

	cout<<"SizeOf(char):"<<sizeof(char)<<endl;
	cout<<"SizeOf(short):"<<sizeof(short)<<endl;
	cout<<"SizeOf(int):"<<sizeof(int)<<endl;
	cout<<"SizeOf(long):"<<sizeof(long)<<endl;
	cout<<"SizeOf(float):"<<sizeof(float)<<endl;
	cout<<"SizeOf(double):"<<sizeof(double)<<endl;
	cout<<"SizeOf(bool):"<<sizeof(bool)<<endl;
	cout<<"SizeOf(void *):"<<sizeof(void *)<<endl;
	cout<<"SizeOf(VoidStruct):"<<sizeof(VoidStruct)<<endl;
	cout<<"SizeOf(VoidStruct *):"<<sizeof(VoidStruct *)<<endl;
}


